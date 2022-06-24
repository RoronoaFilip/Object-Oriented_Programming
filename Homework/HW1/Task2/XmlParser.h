#pragma once
const int LineSize = 1024;
const int TagAndInfoSize = 50;

struct XmlParser {
  char line[LineSize];
  int currentIndex;
  char *tag;
  char *info;

  XmlParser();
  ~XmlParser();

  //* Get the Tag from the current Line
  void getTag();

  //* Get the Info from the Line
  void getInfo();

  //* Check what the Tag from the File is
  bool checkTag(const char *inputTag) const;

  //* Get the Lenght of the Line
  int getLineLenght() const;

private:
  //* Get the Lenght Of Something
  int getLenght(const char *word) const;
};