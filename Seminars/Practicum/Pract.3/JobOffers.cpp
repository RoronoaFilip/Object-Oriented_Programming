#include <fstream>
#include <iostream>

const int SIZE = 25;

struct JobOffer {
    char name[SIZE];
    int teamCount;
    int daysFree;
    long long salary;
};

// Input Offer
void inputJobOffer(JobOffer &myOffer) {
    std::cout << "Enter Company name: ";
    std::cin.ignore();
    std::cin.getline(myOffer.name, SIZE);
    std::cout << "Enter Project Team Count: ";
    std::cin >> myOffer.teamCount;
    std::cout << "Enter Number of Days free of Work: ";
    std::cin >> myOffer.daysFree;
    std::cout << "Enter Salary: ";
    std::cin >> myOffer.salary;
    std::cout << std::endl;
}

// Print Offer
void printOffer(const JobOffer &myOffer) {
    std::cout << "Company name: " << myOffer.name << std::endl;
    std::cout << "Project Team Count: " << myOffer.teamCount << std::endl;
    std::cout << "Days free of Work: " << myOffer.daysFree << std::endl;
    std::cout << "Company's salary Offer: " << myOffer.salary << std::endl;
    std::cout << std::endl;
}

// Transform String to Integer
int transformStringToInt(const char *word) {
    int number = 0;

    for (int i = 0; word[i] != '\0'; ++i) {
        number = number * 10 + (word[i] - '0');
    }

    return number;
}

// Safe Offers to File
void writeOfferOnFile(const JobOffer &myOffer) {
    std::ofstream file("JobOffers.data", std::ios::binary | std::ios::app);

    if (!file.is_open()) {
        std::cout << "Error Opening File";
        return;
    }

    int sizeOfString = sizeof(myOffer.name);

    file.write((const char *)&sizeOfString, sizeof(int));
    file.write((const char *)&myOffer.name, sizeOfString);
    file.write((const char *)&myOffer.teamCount, sizeof(myOffer.teamCount));
    file.write((const char *)&myOffer.daysFree, sizeof(myOffer.daysFree));
    file.write((const char *)&myOffer.salary, sizeof(myOffer.salary));

    file.close();
}
void inputAndSafeNOffers(const int &n) {

    for (int i = 0; i < n; ++i) {
        JobOffer myOffer;
        inputJobOffer(myOffer);
        writeOfferOnFile(myOffer);
    }
}

// Get Count of Offer from File
int getCountOfOffersFromFile(const char *filePath) {
    std::ifstream file(filePath, std::ios::binary);

    if (!file.is_open()) {
        return 0;
    }

    int countOfOffers = 0;

    char line[1024];
    while (!file.eof()) {
        file.getline(line, 1024);
        ++countOfOffers;
    }

    file.close();
    return countOfOffers;
}

// Filter Job Offers and Print them to Console
void getJobOfferInfo(std::ifstream &file, JobOffer &myOffer) {
    int sizeOfString;

    file.read((char *)&sizeOfString, sizeof(sizeOfString));
    file.read((char *)&myOffer.name, sizeOfString);
    file.read((char *)&myOffer.teamCount, sizeof(myOffer.teamCount));
    file.read((char *)&myOffer.daysFree, sizeof(myOffer.daysFree));
    file.read((char *)&myOffer.salary, sizeof(myOffer.salary));
}
void filterOffers(const char *filePath, long long minSalary) {
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Filtering Offers_______________________" << std::endl;
    std::cout << std::endl;

    const int countOfOffers = getCountOfOffersFromFile(filePath);

    std::ifstream file(filePath, std::ios::binary);

    if (!file.is_open()) {
        std::cout << "Error opening File";
        return;
    }

    while (!file.eof()) {
        JobOffer myOffer;

        getJobOfferInfo(file, myOffer);

        if (myOffer.salary >= minSalary) {
            printOffer(myOffer);
        }

        file.peek();
    }

    file.close();
}

// Check if such a Company has made an Offer
bool areStringsEqual(const char *str1, const char *str2) {
    for (int i = 0; str1[i] != '\0'; ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}
bool doesOfferExist(const char *filePath, const char *checkName) {
    std::ifstream file(filePath, std::ios::binary);

    if (!file.is_open()) {
        std::cout << "Error opening File";
        return 0;
    }

    while (!file.eof()) {
        JobOffer myOffer;

        getJobOfferInfo(file, myOffer);

        if (areStringsEqual(myOffer.name, checkName)) {
            return true;
        }
    }
    file.close();
    return false;
}

// Check if Perfect Offer exists and add it to a new File
void addPerfectOfferToFile(const char *filePath, const JobOffer &myOffer) {
    std::ofstream file(filePath, std::ios::app);

    if (!file.is_open()) {
        std::cout << "Error opening Perfect Offer File";
        return;
    }

    file << myOffer.name << ',' << myOffer.teamCount << ',' << myOffer.daysFree << ',' << myOffer.salary << std::endl;

    file.close();
}
void perfectOffer(const char *filePath, const int maxCoworkers, const int minVacancyDays, const int minSalary) {
    std::ifstream file(filePath, std::ios::binary);

    if (!file.is_open()) {
        std::cout << "Error opening File";
        return;
    }

    while (!file.eof()) {
        JobOffer myOffer;

        getJobOfferInfo(file, myOffer);

        if (myOffer.daysFree >= minVacancyDays && myOffer.salary >= minSalary && myOffer.teamCount <= maxCoworkers) {
            printOffer(myOffer);
            addPerfectOfferToFile("PerfectOffers.csv", myOffer);
        }
    }
    file.close();
    return;
}

int main() {
    // std::cout << "Enter Number of Companies: ";
    // int n;
    // std::cin >> n;

    // inputAndSafeNOffers(n);

    filterOffers("JobOffers.data", 800);

    // if (doesOfferExist("JobOffers.data", "dqwdqwdqwqw")) {
    //     std::cout << "An Offer has been made from this Company" << std::endl;
    // } else {
    //     std::cout << "No Offer has been made from this Company: " << std::endl;
    // }

    // perfectOffer("JobOffers.csv", 20, 2, 200);

    return 0;
}