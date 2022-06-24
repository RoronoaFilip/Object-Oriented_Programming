#include "User.h"

void User::freeMemory() {
	delete[] writenBooks;
	delete[] readBooks;
}

void User::copyFrom(const User& other) {
	capacityWriten = other.capacityWriten;
	sizeWriten = other.sizeWriten;
	writenBooks = new int[capacityWriten];
	for (size_t i = 0; i < sizeWriten; ++i) {
		writenBooks[i] = other.writenBooks[i];
	}

	capacityRead = other.capacityRead;
	sizeRead = other.sizeRead;
	readBooks = new int[capacityRead];
	for (size_t i = 0; i < sizeRead; ++i) {
		readBooks[i] = other.readBooks[i];
	}
}

void User::resizeWriten() {
	capacityWriten *= 2;
	int* temp = new int[capacityWriten];

	for (size_t i = 0; i < sizeWriten; ++i) {
		temp[i] = writenBooks[i];
	}

	delete[] writenBooks;
	writenBooks = temp;
}
void User::resizeRead() {
	capacityRead *= 2;
	int* temp = new int[capacityRead];

	for (size_t i = 0; i < sizeRead; ++i) {
		temp[i] = readBooks[i];
	}

	delete[] readBooks;
	readBooks = temp;
}

int User::checkIfBookExists(const int index) const {
	for (size_t i = 0; i < sizeRead; ++i) {
		if (readBooks[i] == index) {
			return i;
		}
	}

	return -1;
}

//* Default Constructor
User::User() : username(), password(), fileName() {
	capacityWriten = 8;
	writenBooks = new int[capacityWriten];
	sizeWriten = 0;

	capacityRead = 8;
	readBooks = new int[capacityRead];
	sizeRead = 0;
}

//* Constructor
User::User(const FilipString& newUsername, const FilipString& newPassword) :
	username(newUsername), password(newPassword), fileName(newUsername) {
	fileName.concatenate(".txt");

	capacityWriten = 8;
	writenBooks = new int[capacityWriten];
	sizeWriten = 0;

	capacityRead = 8;
	readBooks = new int[capacityRead];
	sizeRead = 0;
}

//* Constructor for File
User::User(const char* filePath) : fileName(filePath) {
	readUserFromFile();
}

//* Copy Constructor
User::User(const User& other) : username(other.username),
password(other.password), fileName(other.fileName) {
	copyFrom(other);
}

//* Operator=
User& User::operator=(const User& other) {
	if (this != &other) {
		username = other.username;
		password = other.password;
		fileName = other.fileName;

		freeMemory();

		copyFrom(other);
	}

	return *this;
}

//* Move Constructor
User::User(User&& other) :
	username(other.username), password(other.password), fileName(other.fileName) {
	capacityWriten = other.capacityWriten;
	writenBooks = other.writenBooks;
	other.writenBooks = nullptr;
	sizeWriten = other.sizeWriten;

	capacityRead = other.capacityRead;
	readBooks = other.readBooks;
	other.readBooks = nullptr;
	sizeRead = other.sizeRead;
}

//* Move Operator=
User& User::operator=(User&& other) {
	if (this != &other) {

		username = other.username;
		password = other.password;
		fileName = other.fileName;

		freeMemory();
		capacityWriten = other.capacityWriten;
		writenBooks = other.writenBooks;
		other.writenBooks = nullptr;
		sizeWriten = other.sizeWriten;

		capacityRead = other.capacityRead;
		readBooks = other.readBooks;
		other.readBooks = nullptr;
		sizeRead = other.sizeRead;
	}

	return *this;
}

//* Destructor
User::~User() {
	freeMemory();
}

bool User::operator==(const User& other) const {
	return username == other.username && password == other.password;
}

//* Pass in a Book and start Reading
size_t User::readBook(const Book& book) {
	size_t returnInt = book.read();

	return returnInt;
}

size_t User::addReadBook(const int index)
{
	if (!isRead(index)) {
		if (sizeRead >= capacityRead) {
			resizeRead();
		}
		readBooks[sizeRead++] = index;
	}

	return 1;
}

Book User::writeBook() const {
	std::cout << "Enter Book Name: " << std::endl;
	FilipString newName;
	std::cin >> newName;

	std::cout << "Enter Book Author Name: " << std::endl;
	FilipString authorName;
	std::cin >> authorName;

	Book temp(newName, authorName);

	FilipString pageTemp;
	size_t pageNum = 1;

	FilipString line;
	while (line != ">q") {
		if (line == ">q") {
			break;
		}
		std::cout << "To go to next Page type \">n\" | To Finish type \"q\" | !Both must be on a new Line!\nCurrently Writing Page " << pageNum << std::endl;

		while (true) {
			line.clear();
			std::cin >> line;

			if (line == ">n") {
				temp.addPage(pageTemp);
				pageTemp.clear();
				++pageNum;
				break;
			}
			else if (line == ">q") {
				temp.addPage(pageTemp);
				break;
			}

			pageTemp.concatenate(line);
		}
	}

	return temp;
}

void User::rewriteBook(Book& rewriteThis) const {
	while (true) {
		std::cout << "\nEnter what you want to do: " << std::endl
			<< "To Rewrite the whole Book type '1' | To Rewrite only a certain Page type '2' | To change Name type '3' | To delete a Page type '4'" << std::endl;

		char symbol = '0';
		std::cin >> symbol; std::cin.ignore();

		if (symbol <= '0' || symbol > '4') {
			std::cout << "Error! Please try again!" << std::endl;
			continue;
		}

		int pageNumber = -1;
		FilipString temp;
		switch (symbol) {
		case '1':
			rewriteThis = writeBook();
			break;
		case '2':
			std::cout << "\nEnter the Page you want to Change: ";

			std::cin >> pageNumber; std::cin.ignore();

			std::cout << "\nEnter the new Page: " << std::endl << "> ";
			std::cin >> temp;
			rewriteThis.changePage(pageNumber, Page(temp));
			break;
		case '3':
			std::cout << "\nEnter the new name: ";
			std::cin >> temp;
			rewriteThis.setName(temp);
			break;
		case '4':
			std::cout << "\nEnter the Page you want to delete: ";
			std::cin >> pageNumber;
			rewriteThis.deletePage(pageNumber - 1);
			break;
		default:
			break;
		}
	
		break;
	}


	std::cout << "\nChanges made successfully!\n" << std::endl;
	return;
}

size_t User::addWritenBook(const int index)
{
	if (sizeWriten >= capacityWriten) {
		resizeWriten();
	}

	writenBooks[sizeWriten++] = index;

	return 1;
}

//* Comment the passed in Book
size_t User::comment(Book& commentBook) const {
	std::cout << "Enter your Comment: ";
	FilipString comment;
	std::cin >> comment;

	commentBook.addComment(comment, username);

	return 1;
}

//* Read the Comments of the Book
size_t User::readComments(const Book& readCommentsBook) const {
	readCommentsBook.printComments();

	return 1;
}

//* Write User to File
size_t User::writeUserToFile() const {

	std::ofstream file(fileName.getCharPointer(), std::ios::trunc);

	if (!file.is_open()) {
		return 0;
	}

	file << username << '\n';
	file << password << '\n';

	file << sizeRead << '\n';
	file << capacityRead << '\n';
	for (size_t i = 0; i < sizeRead; ++i) {
		file << readBooks[i] << '\n';
	}

	file << sizeWriten << '\n';
	file << capacityWriten << '\n';
	for (size_t i = 0; i < sizeWriten; ++i) {
		file << writenBooks[i] << '\n';
	}

	file.close();

	return 1;
}

//* Read User from File
size_t User::readUserFromFile() {
	std::ifstream file(fileName.getCharPointer());

	if (!file.is_open()) {
		return 0;
	}

	FilipString temp;

	file >> temp;
	username = temp;

	file >> temp;
	password = temp;

	fileName = username;
	fileName.concatenate(".txt");


	file >> sizeRead;
	file >> capacityRead;

	file >> temp;

	readBooks = new int[capacityRead];
	for (size_t i = 0; i < sizeRead; ++i) {
		file >> readBooks[i];
	}


	file >> sizeWriten;
	file >> capacityWriten;

	file >> temp;

	writenBooks = new int[capacityWriten];
	for (size_t i = 0; i < sizeWriten; ++i) {
		file >> writenBooks[i];
	}

	file.close();

	return 1;
}

//* Get the Name of the File
const FilipString User::getFileName() const {
	FilipString temp = fileName.getCharPointer();
	return temp;
}

size_t User::isRead(const int index) const {
	for (size_t i = 0; i < sizeRead; ++i) {
		if (readBooks[i] == index) {
			return 1;
		}
	}

	return 0;
}

size_t User::isWriten(const int index) const {
	for (size_t i = 0; i < sizeWriten; ++i) {
		if (writenBooks[i] == index) {
			return 1;
		}
	}

	return 0;
}

const FilipString User::makeComment() const {
	std::cout << "Enter your Comment:" << std::endl;
	FilipString comment;
	std::cin >> comment;


	return comment;
}

const FilipString User::getUsername() const {
	return username;
}

const int User::makeRating() const {
	int rating = -1;

	while (true) {
		std::cout << "Enter your Rating:" << std::endl;
		std::cin >> rating;

		if (rating < 0 || rating >10) {
			std::cout << "Invalid Rating! Please Try Again" << std::endl;
			continue;
		}

		break;
	}

	return rating;
}

