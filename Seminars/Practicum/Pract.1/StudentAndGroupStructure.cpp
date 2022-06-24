#include <iostream>
struct Student {
    int fn;
    int course;
    double grade;
};
double *getGrades(const Student *arr, const int n);
double avarage(const Student *arr, const int n);
struct Group {
    int countOfStudents = 0;
    double avarageGrade = 0;
    Student *arr;
};
double avarage(const Student *arr, const int n) {
    double avarageGrade = 0;
    for (int i = 0; i < n; ++i) {
        avarageGrade += arr[i].grade;
    }
    return avarageGrade / n;
}
bool checkFn(int fn) { return (fn >= 10000 && fn < 100000); }
bool checkCourse(int course) { return (course == 1 || course == 2 || course == 3 || course == 4); }
bool checkGrade(double grade) { return (grade >= 2 && grade <= 6); }
void initStudent(Student &student) {
    std::cout << "Input Student's FN: ";
    std::cin >> student.fn;
    if (!checkFn(student.fn)) {
        while (!checkFn(student.fn)) {
            std::cout << "Invalid Entry. Try again.\n";
            std::cout << "Input Student's FN: ";
            std::cin >> student.fn;
        }
    }
    std::cout << "Input Student's Course: ";
    std::cin >> student.course;
    if (!checkCourse(student.course)) {
        while (!checkCourse(student.course)) {
            std::cout << "Invalid Entry. Try again.\n";
            std::cout << "Input Student's Course: ";
            std::cin >> student.course;
        }
    }
    std::cout << "Input Student's Grade: ";
    std::cin >> student.grade;
    if (!checkGrade(student.grade)) {
        while (!checkGrade(student.grade)) {
            std::cout << "Invalid Entry. Try again.\n";
            std::cout << "Input Student's Grade: ";
            std::cin >> student.grade;
        }
    }
}
void printStudent(const Student &student) {
    std::cout << std::endl;
    std::cout << "Fn: " << student.fn << std::endl;
    std::cout << "Course: " << student.course << std::endl;
    std::cout << "Grade: " << student.grade << std::endl;
}
void printGroup(const Group &one, const int n) {
    for (int i = 0; i < n; ++i) {
        printStudent(one.arr[i]);
    }
}
void readGroup(Group &one, const int n) {
    one.countOfStudents = n;
    for (int i = 0; i < n; ++i) {
        Student st;
        initStudent(st);
        one.arr[i] = st;
    }
    one.avarageGrade = avarage(one.arr, n);
}
double *getGrades(const Student arr[], const int n) {
    double *gradesArr = new double[n];
    for (int i = 0; i < n; ++i) {
        gradesArr[i] = arr->grade;
    }
    return gradesArr;
}
void printNumberOfStudentsWithScholarships(const Group one, const int n, const double scholarship) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (one.arr[i].grade >= scholarship) {
            ++count;
        }
    }
    std::cout << "Number of Students getting a Scholarship: " << count << std::endl;
}
void swap(double &a, double &b) {
    double swap = a;
    a = b;
    b = swap;
}
void swap(Student &a, Student &b) {
    Student swap = a;
    a = b;
    b = swap;
}
void selectionSort(Group &one, const int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minElementIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (one.arr[j].grade > one.arr[minElementIndex].grade) {
                minElementIndex = j;
            }
        }
        if (i != minElementIndex) {
            swap(one.arr[i], one.arr[minElementIndex]);
        }
    }
}
void printSortedStudentsWithScholarships(Group &one, const int n, const double scholarship) {
    selectionSort(one, n);
    int i = 0;
    while (one.arr[i].grade >= scholarship) {
        std::cout << "Number of Student: " << i + 1 << " Grade: " << one.arr[i].grade << std::endl;
        ++i;
    }
}
void printAvarageGradeForGroup(const Group &one) { std::cout << "Avarage Grade is: " << one.avarageGrade << std::endl; }
int main() {
    std::cout << "Input number of Students: ";
    int n;
    std::cin >> n;
    Group one;
    readGroup(one, n);
    double scholarship = 5.5;

    printGroup(one, n);

    std::cout << std::endl;

    printAvarageGradeForGroup(one);

    printNumberOfStudentsWithScholarships(one, n, scholarship);
    printSortedStudentsWithScholarships(one, n, scholarship);

    return 0;
}