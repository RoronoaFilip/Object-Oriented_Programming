#include "XmlParser.h"

XmlParser::XmlParser() {
  tag = nullptr;
  info = nullptr;
  currentIndex = 0;
}
XmlParser::~XmlParser() {
  delete[] tag;
  delete[] info;
}

//! public:
//* Get the Tag from the current Line
void XmlParser::getTag() {
  delete[] tag;
  tag = new char[TagAndInfoSize];
  int tagIndex = 0;

  while (line[currentIndex] != '<') {
    ++currentIndex;
  }

  ++currentIndex;

  while (line[currentIndex] != '>') {
    tag[tagIndex++] = line[currentIndex++];
    if (line[currentIndex] == '\0') {
      break;
    }
  }

  currentIndex++;
  tag[tagIndex] = '\0';
}

//* Get the Info from the Line
void XmlParser::getInfo() {
  delete[] info;
  info = new char[TagAndInfoSize];
  int infoIndex = 0;

  while (line[currentIndex] != '<') {
    info[infoIndex++] = line[currentIndex++];
  }

  info[infoIndex] = '\0';
}

//* Check what the Tag from the File is
bool XmlParser::checkTag(const char *inputTag) const {
  if (inputTag[0] == '\0') {
    return false;
  }
  int thistagLenght = getLenght(tag);
  int fileTagLenght = getLenght(inputTag);

  if (thistagLenght != fileTagLenght) {
    return false;
  }

  for (int i = 0; tag[i] != '\0'; ++i) {
    if (tag[i] != inputTag[i]) {
      return false;
    }
  }

  return true;
}

//* Get the Lenght of the Line
int XmlParser::getLineLenght() const { return getLenght(line); }

//! private:
//* Get the Lenght Of Something
int XmlParser::getLenght(const char *word) const {
  int count = 0;
  for (int i = 0; word[i] != '\0'; ++i) {
    ++count;
  }

  return count;
}