// Line 1-8 are included in all .cpp files to check for memory leaks
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "SvgParser.h"

FilipString SvgParser::getTag() { return getInfoToSpace(); }
void SvgParser::setLine(const char *newLine) { line = FilipString(newLine); }
void SvgParser::clearLine() { line.clear(); }

FilipString SvgParser::getInfoToSpace() {
  size_t size = 0;
  while (line[size] != ' ' && line[size] != '>') {
    ++size;
  }

  char *toReturn = new char[size + 1];
  size_t i = 0;
  while (i < size) {
    toReturn[i] = line[i];
    ++i;
  }

  toReturn[i] = '\0';
  FilipString temp(toReturn);

  delete[] toReturn;
  return temp;
}
double SvgParser::getInfoBetweenQuote(const size_t start) {
  size_t index = start;

  if (index + 1 == line.getSize()) {
    return 0;
  }

  while (line[index] != '\"') {
    ++index;
  }
  ++index;

  char raw[100];
  size_t rawIndex = 0;

  while (line[index] != '\"') {
    raw[rawIndex++] = line[index];
    ++index;
  }
  raw[rawIndex] = '\0';

  return atof(raw);
}
FilipString SvgParser::getInfoBetweenQuoteText(const size_t start) {
  size_t index = start;

  if (index + 1 == line.getSize()) {
    return FilipString("");
  }

  while (line[index] != '\"' && line[index] != '\0' && line[index] != '>') {
    ++index;
  }
  ++index;

  char *raw = new char[100];
  size_t rawIndex = 0;

  while (line[index] != '\"') {
    if (line[index] >= '0' && line[index] <= '9') {
      delete[] raw;
      return nullptr;
    }
    raw[rawIndex++] = line[index];
    ++index;
  }

  raw[rawIndex] = '\0';

  FilipString temp(raw);

  delete[] raw;

  return temp;
}

double SvgParser::getX(const size_t start) {
  size_t index = start;

  while (line[index] != 'x' && line[index] != '\0' && line[index] != '>') {
    ++index;
  }

  return getInfoBetweenQuote(index);
}
double SvgParser::getY(const size_t start) {
  size_t index = start;

  while (line[index] != 'y' && line[index] != '\0' && line[index] != '>') {
    ++index;
  }

  return getInfoBetweenQuote(index);
}
double SvgParser::getWidth() {
  size_t index = 0;

  while (line[index] != 'w' && line[index] != '\0' && line[index] != '>') {
    ++index;
  }

  return getInfoBetweenQuote(index);
}
double SvgParser::getHeight() {
  size_t index = 0;

  while (line[index] != 'h' && line[index] != '\0' && line[index] != '>') {
    ++index;
  }

  return getInfoBetweenQuote(index);
}

double SvgParser::getRadius() {
  size_t index = 0;

  while (line[index] != 'x') {
    ++index;
  } 
  while (line[index] != 'r') {
    ++index;
  }

  return getInfoBetweenQuote(index);
}
FilipString SvgParser::getStroke() {
  size_t index = 0;

  while (line[index] != 's' && line[index] != '\0' && line[index] != '>') {
    ++index;
  }

  return getInfoBetweenQuoteText(index);
}
FilipString SvgParser::getFill() {
  size_t index = 0;

  while (line[index] != 'f' && line[index] != '\0' && line[index] != '>') {
    ++index;
  }

  return getInfoBetweenQuoteText(index);
}
double SvgParser::getStrokeWidth() {
  size_t index = 0;

  while (line[index] != '-' && line[index] != '\0' && line[index] != '>') {
    ++index;
  }

  return getInfoBetweenQuote(index);
}