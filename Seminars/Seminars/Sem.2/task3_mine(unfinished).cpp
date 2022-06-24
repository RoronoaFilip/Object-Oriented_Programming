// Задача 3 : Напишете програма, която чете comma - separated values(CSV)
// файл със студенти със следните 4 полета : Първо име, Фамилно име, Имейл, Факултетен номер.

// Със стартирането на програмата потребителят да въвежда име на файл,
// който да бъде зареден в паметта.Напишете функция,
// която след зареждане на файла да отпечатва на стандартния изход информация за студента при подаден факултетен номер.
// Напишете функция, която по подаден факултетен номер и низ, променя email - a на студента,
// който има дадения факултетен номер, с подадения низ.Напишете функцията,
// която приема низ(име на файл) и запазва студентите в същия формат(CSV).
// Т.е.при повторно пускане на програмата да може да прочете новия генериран файл.Да се реализира прост интерфейс,
// с който да се извикват написаните фунцкии през конзолата :

// Пример(входът от потребителя започва с '>') :

// underline
// underline |Open file : > students.csv
// underline |File successfully opened!
// underline |>print 80000 Name = Stefan Velkov, Email : stefan @yahoo.com, FN : 80000
// underline |>edit 80000 Krum
// underline |>print 80000
// underline |Name = Krum Velkov, Email : stefan @yahoo.com, FN : 80000 > save students2.csv file students2.csv successfully saved !

#include <fstream>
#include <iostream>

using namespace std;

// DONE: Create interface. Get commands from input. Execute Commands
// TODO: Create a function that edits Student info (for example email)

//* Transform String to Integer
int transformStringToInt(const char *word) {
    int integer = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        if (word[i] >= '0' && word[i] <= '9') {
            integer = integer * 10 + (word[i] - '0');
        }
    }

    return integer;
}

//* Get Student Info
int getFN(const char *line) {
    int index = 0;
    int commaCount = 0;

    while (1) {
        ++index;
        if (line[index] == ',') {
            break;
        }
    }

    ++index;

    while (1) {
        ++index;
        if (line[index] == ',') {
            break;
        }
    }

    ++index;

    while (1) {
        ++index;
        if (line[index] == ',') {
            break;
        }
    }

    ++index;

    char fn[1024];
    int fnIndex = 0;
    for (int i = index; line[i] != '\0'; ++i) {
        fn[fnIndex++] = line[i];
    }
    fn[fnIndex] = '\0';
    return transformStringToInt(fn);
}
char *getFirstName(const char *line) {
    char *firstName = new char[10];
    int index = 0;
    while (line[index] != ',') {
        firstName[index] = line[index];
        ++index;
    }

    firstName[index] = '\0';
    return firstName;
}
char *getLastName(const char *line) {
    char *lastName = new char[10];
    int index = 0;
    int indexLastName = 0;

    while (1) {
        ++index;
        if (line[index] == ',') {
            break;
        }
    }

    ++index;

    while (line[index] != ',') {
        lastName[indexLastName++] = line[index];
        ++index;
    }

    lastName[indexLastName] = '\0';
    return lastName;
}
char *getEmail(const char *line) {
    char *email = new char[20];
    int index = 0;
    int indexEmail = 0;

    while (1) {
        ++index;
        if (line[index] == ',') {
            break;
        }
    }

    ++index;

    while (1) {
        ++index;
        if (line[index] == ',') {
            break;
        }
    }

    ++index;

    while (line[index] != ',') {
        email[indexEmail++] = line[index];
        ++index;
    }

    email[indexEmail] = '\0';
    return email;
}

//* Printing Student Info
void printCharPointer(const char *ptr) {
    for (int i = 0; ptr[i] != '\0'; ++i) {
        cout << ptr[i];
    }
}
void printStudentInfo(const char *line) {
    char *firstname = getFirstName(line);
    char *lastName = getLastName(line);
    char *email = getEmail(line);
    int fn = getFN(line);

    cout << "Name: ";
    printCharPointer(firstname);
    cout << " ";
    printCharPointer(lastName);
    cout << " ";
    cout << "Email: ";
    printCharPointer(email);
    cout << " ";
    cout << "FN: " << fn << endl;

    delete firstname;
    delete lastName;
    delete email;
}
void printStudentBasedOnFN(const int &fn) {
    fstream file("students.csv", fstream::in);

    if (!file.is_open()) {
        cout << "Error";
        return;
    }

    char line[1024];
    int fileFN = 0;

    while (file.getline(line, 1024)) {

        fileFN = getFN(line);

        if (fileFN == fn) {
            printStudentInfo(line);
            file.close();
            return;
        }
    }
    cout << "No such Student found" << endl;
    file.close();
}

//* Copy File
void copyFile(const char *newFileName) {
    fstream copiedFile(newFileName, fstream::out);
    fstream mainFile("students.csv", fstream::in);

    if (!mainFile.is_open() || !copiedFile.is_open()) {
        cout << "Error";
        return;
    }

    char line[1024];
    while (!mainFile.eof()) {
        mainFile.getline(line, 1024);
        copiedFile << line << endl;
    }

    copiedFile.close();
    mainFile.close();
}

//! For Interface:
//* Validate Input
bool validateInput(const char *input) {
    return input[0] == '>';
}

//* Get Command from the Input
bool compareStrings(const char *str1, const char *str2) {

    for (int i = 0; str2[i] != '\0'; ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }

    return true;
}

//* Get the Name of the File we copy to
char *getCopyFileName(const char *input) {
    char *copyFileName = new char[100];
    int copyFileNameIndex = 0;

    int index = 0;
    while (input[index] != ' ') {
        ++index;
    }
    ++index;

    for (; input[index] != '\0'; ++index) {
        copyFileName[copyFileNameIndex++] = input[index];
    }

    copyFileName[copyFileNameIndex] = '\0';
    return copyFileName;
}

//* Get the Lenght of a String
int getStringLenght(const char *word) {
    int len = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        ++len;
    }

    return len;
}

//* Get the Line Number the Student is on
int getStudentLineNumber(const int &fn) {
    fstream file("students.csv", fstream::in);

    if (!file.is_open()) {
        cout << "Error opening File" << endl;
        return 0;
    }

    char line[1024];
    int lineNumber = 0;

    while (file.getline(line, 1024)) {
        ++lineNumber;
        if (getFN(line) == fn) {
            return lineNumber;
        }
    }

    file.close();
    return 0;
}

//! UNFINISHED
//? How to delete a line in File
//* Replace the Line of the Student with Whitespaces
void replaceLineWithWhitespaces(const int &studentLineNumber) {
    fstream file("students.csv", fstream::in | fstream::out);
    char line[1024];

    int currentLine = 1;

    if (!file.is_open()) {
        cout << "Error opening File" << endl;
        return;
    }

    while (file.getline(line, 1024)) {
        if (currentLine + 1 == studentLineNumber) {
            break;
        }
        ++currentLine;
    }

    for (int i = 0; line[i] != '\n'; ++i) {
        file << ' ';
    }
    file.close();
}

//* Add new Student
void addNewStudent() {
    fstream file("students.csv", fstream::app);

    if (!file.is_open()) {
        cout << "Error opening File" << endl;
        return;
    }

    char firstName[100];
    char lastName[100];
    char email[100];
    char fn[100];

    cout << "Enter Student's first name: ";
    cin >> firstName;
    cout << "Enter Student's last name: ";
    cin >> lastName;
    cout << "Enter Student's email: ";
    cin >> email;
    cout << "Enter Student's Faculty Number: ";
    cin >> fn;

    file << firstName << ',' << lastName << ',' << email << ',' << fn << endl;

    file.close();
}

int main() {

    char input[1024];

    int studentLineNumber = 0;

    bool hasThereBeenAddition = false;

    while (true) {
        cin.getline(input, 1024);

        if (compareStrings(input, ">exit")) {
            break;
        } else if (compareStrings(input, ">print")) {
            const int fn = transformStringToInt(input);
            printStudentBasedOnFN(fn);
            continue;
        } else if (compareStrings(input, ">save")) {
            char *copyFileName = getCopyFileName(input);
            copyFile(copyFileName);
            cout << "File saved successfully" << endl;
            delete[] copyFileName;
            continue;
        } else if (compareStrings(input, ">edit")) {
            const int fn = transformStringToInt(input);
            studentLineNumber = getStudentLineNumber(fn);
            replaceLineWithWhitespaces(studentLineNumber);
            continue;
        } else if (compareStrings(input, ">add")) {
            addNewStudent();
            hasThereBeenAddition = true;
            continue;
        } else if (!compareStrings(input, ">add")) {
            hasThereBeenAddition = false;
            continue;
        } else if (!validateInput(input) && !hasThereBeenAddition) {
            cout << "Invalid Input! Please try again." << endl;
            continue;
        } else {
            cout << "Wrong command! Please try again." << endl;
            continue;
        }
    }

    return 0;
}