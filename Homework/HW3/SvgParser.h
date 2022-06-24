#pragma once
#include "FilipString.h"
#include "ShapesCollection.h"

class SvgParser {
  static FilipString line;

  static FilipString getInfoToSpace();
  static double getInfoBetweenQuote(const size_t start = 0);
  static FilipString getInfoBetweenQuoteText(const size_t start = 0);

public:
  SvgParser() = default;

  static void setLine(const char *newLine);
  static void clearLine();

  //* Get Stuff from line
  static FilipString getTag();
  static double getX(const size_t start = 0);
  static double getY(const size_t start = 0);
  static double getWidth();
  static double getHeight();
  static double getRadius();
  static FilipString getStroke();
  static FilipString getFill();
  static double getStrokeWidth();
};

__declspec(selectany) FilipString SvgParser::line;