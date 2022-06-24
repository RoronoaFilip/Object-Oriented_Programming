#include <fstream>
#include <iostream>
using namespace std;

struct Pair {
    int x;
    int y;
};

struct Relation {
    Pair *myPairs;
    int relationSize;
    int relationsCount = 0;
};

Pair initPair() {
    Pair myPair;
    cin >> myPair.x >> myPair.y;

    return myPair;
}
Relation createRelation() {
    Relation myRelation;
    myRelation.relationSize = sizeof(myRelation);

    return myRelation;
}
void addToRelation(Relation &myRelation, const Pair &myPair) {
    myRelation.myPairs[myRelation.relationsCount++] = myPair;
}
void initRelation(Relation &myRelation, const int sizeOfRelation) {
    for (int i = 0; i < sizeOfRelation; ++i) {
        Pair myPair = initPair();
        addToRelation(myRelation, myPair);
        myRelation.relationSize = sizeof(myRelation);
    }
}

void printPair(const Pair &myPair) {
    cout << "(" << myPair.x << "," << myPair.y << ") ";
}
void printRelation(const Relation &myRelation) {
    for (int i = 0; i < myRelation.relationsCount; ++i) {
        printPair(myRelation.myPairs[i]);
    }
}

// Write to File
void writePairToFile(const char *fileName, Pair &myPair) {
    fstream file(fileName, ios::out | ios::app);

    if (!file.is_open()) {
        cout << "Error";
        return;
    }

    file << "(" << myPair.x << "," << myPair.y << ") ";

    file.close();
}
void writeRelationToFile(const Relation &myRelation) {
    fstream file("relation.txt", ios::out | ios::trunc);

    if (!file.is_open()) {
        cout << "Error";
        return;
    }

    for (int i = 0; i < myRelation.relationsCount; ++i) {
        writePairToFile("relation.txt", myRelation.myPairs[i]);
    }

    file.close();
}

// Read from File
int countOfPairsInString(const char *line) {
    int count = 0;
    for (int i = 0; line[i] != '\0'; ++i) {
        if (line[i] == '(') {
            ++count;
        }
    }
    return count;
}
int getStringLenght(const char *line) {
    int count = 0;
    for (int i = 0; line[i] != '\0'; ++i) {
        ++count;
    }
    return count;
}
Pair getPairFromString(const char *line, int &index) {
    Pair newPair;
    newPair.x = line[index] - '0';
    index += 2;
    newPair.y = line[index] - '0';

    return newPair;
}
Relation readRelationFromFile(const char *fileName) {
    Relation newRelation;
    ifstream file("relation.txt");

    char line[1024];

    if (!file.is_open()) {
        cout << "Error";
        return newRelation;
    }

    file.getline(line, 1024);
    newRelation.myPairs = new Pair[countOfPairsInString(line)];

    int index = 1;
    int endOfString = getStringLenght(line);

    int newRelationIndex = 0;
    while (index <= endOfString) {
        newRelation.myPairs[newRelationIndex++] = getPairFromString(line, index);
        index += 4;
    }

    file.close();

    newRelation.relationSize = sizeof(newRelation);
    newRelation.relationsCount = newRelationIndex;

    return newRelation;
}
int main() {
    int n;
    cin >> n;
    Relation myRelation = createRelation();
    myRelation.myPairs = new Pair[n];
    initRelation(myRelation, n);

    writeRelationToFile(myRelation);

    Relation newRelation = readRelationFromFile("relation.txt");

    printRelation(newRelation);
    delete[] myRelation.myPairs;
    delete[] newRelation.myPairs;
    return 0;
}