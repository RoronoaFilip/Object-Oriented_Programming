#pragma once
#include <fstream>
#include <iostream>

struct HexViewer {
  int *fileInfo;
  int fileSize;

  HexViewer();

  HexViewer(std::ifstream &file);

  HexViewer(const char *filePath);

  ~HexViewer();

  //* Print the Info
  void view() const;

  //* Validate Index
  bool validateIndex(const char *index) const;

  //* Validate Index
  bool validateByte(const char *byte) const;

  //* Change the Info by Index
  void changeIndexByte(const char *index, const char *newByte);

  //* Remove last byte
  void remove();

  //* Add Value at the end
  void add(const char *newByte);

  //* Save the Info to File
  void save(const char *filePath);

private:
  int currentIndex;

private:
  //* Is Symbol Hex Digit
  bool isHex(const char symbol) const;

  //* Parse Hex Symbol
  int parseHexSymbol(const char symbol) const;

  //* Parse String to Int
  int parseStringToInt(const char *word) const;

  //* Parse Decimal Number to Hexadecimal
  int parseStringToHex(const char *string);

  //* Parse Hexadecimal Number to Decimal
  char *parseHexToString(int hex);

  //* Parse Hexadecimal Number to Decimal
  char *parseHexToString(int hex) const;

  //* Get the Size of The File
  int getFileSize(std::ifstream &file);

  //* Get the Lenght of a String
  int getStrLenght(const char *word);

  //* Copy Array
  int *copyArr(const int *arrToCopy, const int upTo,
               const int newArrSize) const;

  //* Parse Char Arr to Int Arr
  int *parseCharArrToIntArr(const char *arr);
};