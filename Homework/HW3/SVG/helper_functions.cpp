#include "helper_functions.h"
#include "ShapeFactory.h"
#include "SvgShapes.h"
#include <iostream>

void printMainMenu() {
	std::cout << "MENU:" << std::endl
		<< "1 - Print all Shapes " << std::endl
		<< "2 - Create a Shape" << std::endl
		<< "3 - Erase a Shape" << std::endl
		<< "4 - Translate" << std::endl
		<< " 5 - Within" << std::endl
		<< "6 - Point In" << std::endl
		<< "7 - Print Areas" << std::endl
		<< "8 - Print Perimeters" << std::endl
		<< "s - Save File" << std::endl
		<< "q - Quit" << std::endl;
}

void consoleInterface() {

	ShapeFactory shapeFact;
	SvgShapes myShapes;
	std::cout << "Enter File Name" << std::endl;
	FilipString fileName;
	std::cin >> fileName;
	myShapes.readFile(fileName.getCharPointer());

	while (true) {
		printMainMenu();

		std::cout << "Enter your choice:" << std::endl;
		char symbol;
		std::cin >> symbol;

		char shapeSymbol;
		size_t index;
		double x;
		double y;

		switch (symbol) {
		case '1':
			myShapes.displayShapes();
			break;
		case '2':
			std::cout << std::endl
				<< "r - Rectangle" << std::endl
				<< "c - Circle" << std::endl
				<< "l - Line" << std::endl;
			std::cin >> shapeSymbol;

			if (shapeSymbol == 'r') {
				Rectangle* rectTemp = shapeFact.createRectangleFromConsole();
				myShapes.addRectangle(*rectTemp);
				delete rectTemp;
			} else if (shapeSymbol == 'c') {
				Circle* circleTemp = shapeFact.createCircleFromConsole();
				myShapes.addCircle(*circleTemp);
				delete circleTemp;
			} else if (shapeSymbol == 'l') {
				Line* lineTemp = shapeFact.createLineFromConsole();
				myShapes.addLine(*lineTemp);
				delete lineTemp;
			}
			break;
		case '3':
			std::cout << "Enter the Shape Number you want to erase:" << std::endl;
			std::cin >> index;
			if (myShapes.erase(index - 1)) {
				std::cout << "Shape deleted!" << std::endl;
			} else {
				std::cout << "Shape coudn't get deleted!" << std::endl;
			}
			break;
		case '4':
			std::cout << "Enter the Shape Number you want to erase. To translate all "
				"type \'a\':"
				<< std::endl;
			std::cin >> shapeSymbol;
			if (shapeSymbol >= '1' && shapeSymbol <= '9') {
				myShapes.translate(shapeSymbol - '0' - 1);
			} else {
				myShapes.translate();
			}
			break;
		case '5':
			std::cout << "Enter the shape you want to use. 'r' for Rectangle and 'c' "
				"for Circle:"
				<< std::endl;
			std::cin >> shapeSymbol;

			if (shapeSymbol == 'r') {
				Rectangle* rectTemp = shapeFact.createRectangleFromConsole();
				myShapes.printWithinRectangle(*rectTemp);
				delete rectTemp;
			} else if (shapeSymbol == 'c') {
				Circle* circleTemp = shapeFact.createCircleFromConsole();
				myShapes.printWithinCircle(*circleTemp);
				delete circleTemp;
			}
			break;
		case '6':
			std::cout << "Enter x:" << std::endl;
			std::cin >> x;
			std::cout << "Enter y:" << std::endl;
			std::cin >> y;
			myShapes.printAllPointIn(x, y);
			break;
		case '7':
			myShapes.printAreas();
			break;
		case '8':
			myShapes.printPerimeters();
			break;
		case 'q':
			return;
			break;
		case 's':
			myShapes.saveFile();
			break;
		}
	}
}
