#include "Award.h"

Award::Award(const size_t newPoints, const FilipString &newFileName)
    : neededPoints(newPoints), fileName(newFileName) {}

Award::~Award() {}

void Award::setNeededPoints(const size_t points) { neededPoints = points; }
void Award::setFileName(const FilipString &newFileName) {
  fileName = newFileName;
}

size_t Award::getPoints() const { return neededPoints; }
const char *Award::getFileName() const { return fileName.getCharPointer(); }