#include "HexViewer.h"

HexViewer::HexViewer() {
  fileInfo = nullptr;
  fileSize = 0;
}

HexViewer::HexViewer(std::ifstream &file) {
  fileSize = getFileSize(file);
  fileInfo = new int[fileSize];

  for (int i = 0; i < fileSize; ++i) {
    fileInfo[i] = (int)file.get();
  }

  currentIndex = fileSize - 1;

  file.clear();
  file.seekg(0);
}

HexViewer::HexViewer(const char *filePath) {

  std::ifstream file(filePath, std::ios::binary);

  fileSize = getFileSize(file);
  fileInfo = new int[fileSize];

  currentIndex = fileSize - 1;

  if (!file.is_open()) {
    std::cout << "Error opening File in read form!" << std::endl;
    return;
  }

  for (int i = 0; i < fileSize; ++i) {
    fileInfo[i] = file.get();
  }

  file.close();
}

HexViewer::~HexViewer() { delete[] fileInfo; }

//* Print the Info
void HexViewer::view() const {
  //* In Hex
  for (int i = 0; i < fileSize; ++i) {
    // std::cout << std::dec << (int)fileInfo[i] << " ";
    char *hexByte = parseHexToString(fileInfo[i]);
    std::cout << hexByte << " ";
    delete[] hexByte;
  }

  std::cout << std::endl;

  //* If it is a Letter cout Letter, else cout '.'
  for (int i = 0; i < fileSize; ++i) {
    if ((fileInfo[i] >= 'A' && fileInfo[i] <= 'Z') ||
        (fileInfo[i] >= 'a' && fileInfo[i] <= 'z')) {
      std::cout << (char)fileInfo[i] << " ";
    } else {
      std::cout << '.' << " ";
    }
  }
  std::cout << std::endl;
}

//* Validate Index
bool HexViewer::validateIndex(const char *index) const {
  int intIndex = parseStringToInt(index);
  return (intIndex <= currentIndex);
}

//* Validate Index
bool HexViewer::validateByte(const char *byte) const {
  for (int i = 0; byte[i] != '\0'; ++i) {
    if (!isHex(byte[i])) {
      return false;
    }
  }
  return true;
}

//* Change the Info by Index
void HexViewer::changeIndexByte(const char *index, const char *newByte) {
  int intIndex = parseStringToInt(index);
  int hexByte = parseStringToHex(newByte);

  fileInfo[intIndex] = hexByte;
}

//* Remove last byte
void HexViewer::remove() {
  int *newArr = copyArr(fileInfo, fileSize - 1, fileSize - 1);
  delete[] fileInfo;
  fileInfo = newArr;
  --fileSize;
}

//* Add Value at the end
void HexViewer::add(const char *newByte) {
  int hexByte = parseStringToHex(newByte);

  int *newArr = copyArr(fileInfo, fileSize, fileSize + 1);

  newArr[fileSize++] = hexByte;

  delete[] fileInfo;
  fileInfo = newArr;
}

//* Save the Info to File
void HexViewer::save(const char *filePath) {
  std::ofstream file(filePath, std::ios::binary | std::ios::trunc);

  if (!file.is_open()) {
    std::cout << "Error opening File in write form!" << std::endl;
    return;
  }

  for (int i = 0; i < fileSize; ++i) {
    file.write((const char *)(fileInfo + i), 1);
  }

  file.close();
}

//! private:

//* Is Symbol Hex Digit
bool HexViewer::isHex(const char symbol) const {
  return (symbol >= '0' && symbol <= '9') || (symbol >= 'A' && symbol <= 'F') ||
         (symbol >= 'a' && symbol <= 'f');
}

//* Parse Hex Symbol
int HexViewer::parseHexSymbol(const char symbol) const {
  if (symbol >= '0' && symbol <= '9') {
    return symbol - '0';
  } else if (symbol >= 'A' && symbol <= 'F') {
    return symbol - 55;
  }
  if (symbol >= 'a' && symbol <= 'f') {
    return symbol - 87;
  }
  return 0;
}

//* Parse String to Int
int HexViewer::parseStringToInt(const char *word) const {
  int num = 0;

  for (int i = 0; word[i] != '\0'; ++i) {
    num = num * 10 + (word[i] - '0');
  }

  return num;
}

//* Parse Decimal Number to Hexadecimal
int HexViewer::parseStringToHex(const char *string) {
  int hex = 0;
  int index = getStrLenght(string) - 1;
  int degree = 1;
  for (int i = index; i >= 0; --i) {
    hex += parseHexSymbol(string[i]) * degree;
    degree *= 16;
  }

  return hex;
}

//* Parse Hexadecimal Number to Decimal
char *HexViewer::parseHexToString(int hex) const {
  char *hexString = new char[100];
  if (hex == 0) {
    hexString[0] = '0';
    hexString[1] = '\0';
    return hexString;
  }
  int index = 0;
  int diff = 'A' - 10;
  while (hex) {
    int buffer = hex % 16;
    if (buffer < 10) {
      hexString[index++] = buffer + '0';
    } else {
      hexString[index++] = buffer + diff;
    }

    hex /= 16;
  }

  hexString[index] = '\0';

  //* Reverse the String
  for (int i = 0; i < index / 2; ++i) {
    char symbol = hexString[i];
    hexString[i] = hexString[index - 1];
    hexString[index - 1] = symbol;
    --index;
  }

  return hexString;
}

//* Get the Size of The File
int HexViewer::getFileSize(std::ifstream &file) {
  int size = 0;
  while (!file.eof()) {
    file.get();
    ++size;
  }

  file.clear();
  file.seekg(0);

  return size - 1;
}

//* Copy Array
int *HexViewer::copyArr(const int *arrToCopy, const int upTo,
                        const int newArrSize) const {

  int *newArr = new int[newArrSize];
  for (int i = 0; i < upTo; ++i) {
    newArr[i] = arrToCopy[i];
  }

  return newArr;
}

//* Get the Lenght of a String
int HexViewer::getStrLenght(const char *word) {
  int lenght = 0;

  for (int i = 0; word[i] != '\0'; ++i) {
    ++lenght;
  }

  return lenght;
}