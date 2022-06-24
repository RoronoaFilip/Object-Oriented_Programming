#include <fstream>
#include <iostream>
using namespace std;

void writeSumAndProductInFile(const char *fileName, const int &x, const int &y, const int &z) {
    ofstream file(fileName, ios::trunc);

    if (!file.is_open()) {
        cout << "Error";
        return;
    }

    file << x * y * z << " " << x + y + z;
    file.close();
}
void readAndPrintSumAndProduct() {
    ifstream file("result.txt");

    if (!file.is_open()) {
        cout << "Error";
        return;
    }

    char line[1024];
    file.getline(line, 1024);

    int sum = 0;
    int product = 0;
    int i = 0;
    for (; line[i] != ' '; ++i) {
        product = product * 10 + (line[i] - '0');
    }
    for (int j = i + 1; line[j] != '\0'; ++j) {
        sum = sum * 10 + (line[j] - '0');
    }

    cout << product << " " << sum;
    file.close();
}
int lenghtOfFile(const char *fileName) {
    fstream file(fileName, ios::in);

    if (!file.is_open()) {
        cout << "Error";
        return -1;
    }

    int count = 0;
    char symbol;

    while (!file.eof()) {
        file >> symbol;
        ++count;
    }
    file.close();
    return count;
}
int main() {
    int x, y, z;
    cin >> x >> y >> z;
    writeSumAndProductInFile("result.txt", x, y, z);
    readAndPrintSumAndProduct();
    cout << endl;
    cout << lenghtOfFile("result.txt");
    return 0;
}
