// Line 1-8 are included in all .cpp files to check for memory leaks
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include "SvgShapes.h"
#include <fstream>

const char FIRST_LINE_OF_FILE[] = "<?xml version=\"1.0\" standalone=\"no\"?>";
const char SECOND_LINE_OF_FILE[] = "<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">";
const char THIRD_LINE_OF_FILE[] = "<svg xmlns=\"http://www.w3.org/2000/svg\">";
const char LAST_LINE_OF_FILE[] = "</svg>";

Rectangle SvgShapes::parseLineToRect(const char* line) const {
	double newX = SvgParser::getX();
	double newY = SvgParser::getY();
	double newHeight = SvgParser::getHeight();
	double newWidth = SvgParser::getWidth();
	FilipString newFill = std::move(SvgParser::getFill());
	FilipString newStroke = std::move(SvgParser::getStroke());
	double newStrokeWidth = SvgParser::getStrokeWidth();

	Rectangle temp(newX, newY, newX + newWidth, newY + newHeight);
	temp.setWidth(newWidth);
	temp.setHeight(newHeight);
	temp.setStroke(newStroke);
	temp.setStrokeWidth(newStrokeWidth);
	temp.setFill(newFill);

	return temp;
}
Circle SvgShapes::parseLineToCircle(const char* line) const {
	double newX = SvgParser::getX();
	double newY = SvgParser::getY();
	FilipString newFill = std::move(SvgParser::getFill());
	FilipString newStroke = std::move(SvgParser::getStroke());
	double newStrokeWidth = SvgParser::getStrokeWidth();
	double newRadius = SvgParser::getRadius();

	Circle temp(newX, newY, newRadius);
	temp.setStroke(newStroke);
	temp.setStrokeWidth(newStrokeWidth);
	temp.setFill(newFill);

	return temp;
}
Line SvgShapes::parseLineToLine(const char* line) const {
	double newX = SvgParser::getX();
	double newY = SvgParser::getY();

	size_t start = 0;
	while (line[start] != 'y') {
		++start;
	}
	//* Move to the end of the First y to start
	//*getting the second x and y

	double newX2 = SvgParser::getX(start + 1);
	double newY2 = SvgParser::getY(start + 1);
	double newStrokeWidth = SvgParser::getStrokeWidth();
	FilipString newStroke = std::move(SvgParser::getStroke());

	Line temp(newX, newY, newX2, newY2, newStrokeWidth);
	temp.setStroke(newStroke);

	return temp;
}

void SvgShapes::addRectangle(const Rectangle& add) {
	shapes.addRectangle(add);
}

void SvgShapes::addCircle(const Circle& add) {
	shapes.addCircle(add);
}

void SvgShapes::addLine(const Line& add) {
	shapes.addLine(add);
}

bool SvgShapes::erase(const size_t index) {
	return shapes.erase(index);
}

void SvgShapes::printAllPointIn(double x, double y) const {
	shapes.allPointIn(x, y);
}


bool SvgShapes::readFile(const char* filePath) {
	fileName = FilipString(filePath);

	std::ifstream file(filePath);

	if (!file.is_open()) {
		std::cout << "Error opening File in read form!";
		return false;
	}

	try {
		char temp[1024];
		file.getline(temp, 1024);
		SvgParser::setLine(temp);

		while (true) {
			if (SvgParser::getTag() == "<svg" || SvgParser::getTag() == "<svg>") {
				break;
			}

			file.getline(temp, 1024);
			SvgParser::setLine(temp);
		}

		while (true) {
			file.getline(temp, 1024);
			SvgParser::setLine(temp);

			if (SvgParser::getTag() == "</svg") {
				break;
			}

			if (SvgParser::getTag() == "<rect") {
				shapes.addRectangle(parseLineToRect(temp));
			} else if (SvgParser::getTag() == "<line") {
				shapes.addLine(parseLineToLine(temp));
			} else if (SvgParser::getTag() == "<circle") {
				shapes.addCircle(parseLineToCircle(temp));
			}
		}


	} catch (...) {
		std::cout << "Error while reading File!" << std::endl;
		return false;
	}




	try {
		file.close();
	} catch (...) {
		std::cout << "Error closing File!";
		return false;
	}

	return true;
}

bool SvgShapes::saveFile(const char* filePath) const {
	if (filePath != nullptr) {
		fileName = FilipString(filePath);
	}

	std::ofstream file(fileName.getCharPointer(), std::ios::trunc);

	if (!file.is_open()) {
		std::cout << "Error opening File in write form!" << std::endl;
		return false;
	}

	try {
		file << FIRST_LINE_OF_FILE << '\n'
			<< SECOND_LINE_OF_FILE << '\n'
			<< THIRD_LINE_OF_FILE << '\n';

		shapes.saveAllToFileStream(file);

		file << LAST_LINE_OF_FILE << '\n';

	} catch (...) {
		std::cout << "Error while saving File!" << std::endl;
		return false;
	}


	try {
		file.close();
	} catch (...) {
		std::cout << "Error closing File!";
		return false;
	}

	return true;
}

void SvgShapes::displayShapes() const { shapes.displayAll(); }

void SvgShapes::printAreas() const {
	shapes.printAreasAll();
}

void SvgShapes::printPerimeters() const {
	shapes.printPerimetersAll();
}

void SvgShapes::translate(const int index) {
	if (index == -1) {
		shapes.translateAll();
		return;
	} else {
		shapes[index]->translate();
	}

	return;
}

void SvgShapes::printWithinCircle(const Circle& shape) const {
	shapes.printAllWithinCircle(shape);
}

void SvgShapes::printWithinRectangle(const Rectangle& shape) const {
	shapes.printAllWithinRectangle(shape);
}
