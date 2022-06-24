#pragma once
#include "FilipString.h"

class Award {
  size_t neededPoints;
  FilipString fileName;

public:
  Award() = delete;
  Award(const size_t newPoints, const FilipString &newFileName);

  virtual ~Award();

  virtual void visualize() = 0;

  void setNeededPoints(const size_t points);
  void setFileName(const FilipString &newFileName);

  size_t getPoints() const;
  const char *getFileName() const;
};