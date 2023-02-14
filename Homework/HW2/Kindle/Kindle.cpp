#include "Kindle.h"

int Kindle::checkIfUserExists(const User& other) const {
	for (size_t i = 0; i < users.getSize(); ++i) {
		if (users[i] == other) {
			return i;
		}
	}

	return -1;
}

int Kindle::checkIfBookExists(const Book& other) const {
	for (size_t i = 0; i < books.getSize(); ++i) {
		if (books[i] == other) {
			return i;
		}
	}

	return -1;

}

size_t Kindle::printMenu() const {
	std::cout << "Menu:" << std::endl
		<< "h - print Menu again" << std::endl
		<< "e - exit the Program" << std::endl
		<< "1 - read a Book" << std::endl
		<< "2 - write a Book" << std::endl
		<< "3 - comment a Book" << std::endl
		<< "4 - read Comments of a Book" << std::endl
		<< "5 - Rate a Book" << std::endl
		<< "6 - See the Rating of a Book" << std::endl
		<< "7 - Rewrite a Book\n" << std::endl;


	return 1;
}

size_t Kindle::checkUsername(const FilipString& username) const {
	for (size_t i = 0; i < username.getSize(); ++i) {
		if (username[i] == ' ') {
			return 0;
		}
	}
	return 1;
}

//* Default Constructor
Kindle::Kindle() : name(), fileName(), books(), users() {}

Kindle::Kindle(const FilipString& newName) : name(newName), fileName(newName) {
	fileName.concatenate(".txt");

	readKindleFromFile();
}

//* Copy Constructor
Kindle::Kindle(const Kindle& other) : name(other.name), fileName(other.fileName),
books(other.books), users(other.users) {}

//* Operator=
Kindle& Kindle::operator=(const Kindle& other) {
	if (this != &other) {
		name = other.name;
		fileName = other.fileName;

		books = other.books;
		users = other.users;
	}

	return *this;
}

//* Move Constructor
Kindle::Kindle(Kindle&& other) : name(other.name), fileName(other.fileName),
books(other.books), users(other.users) {}

//* Move Operator=
Kindle& Kindle::operator=(Kindle&& other) {
	if (this != &other) {
		name = other.name;
		fileName = other.fileName;

		books = other.books;
		users = other.users;
	}

	return *this;
}

//* Destructor
Kindle::~Kindle() {
	writeKindleToFile();
}

//* Add a Book
size_t Kindle::addBook(const Book& newBook) {

	books.push_back(newBook);

	return 1;
}

//* Register a new User from Console
User Kindle::registerUserFromConsole() {
	FilipString newUsername = "    ";
	FilipString newPassword;
	while (true) {
		std::cout << "Enter Username: " << std::endl;
		std::cin >> newUsername;
		if (checkUsername(newUsername) == 0) {
			std::cout << "\nInvalid Username! Don't use Spaces!\n" << std::endl;
			continue;
		}

		std::cout << "Enter Password: " << std::endl;
		std::cin >> newPassword;

		break;
	}


	User temp(newUsername, newPassword);

	return temp;
}

int Kindle::loginAsExistingUser(User& currentUser) {
	int index = -1;
	FilipString newUsername;
	FilipString newPassword;

	while (true) {
		std::cout << "Enter Username: " << std::endl;
		std::cin >> newUsername;

		if (newUsername == "b") {
			return 0;
		}

		std::cout << "Enter Password: " << std::endl;
		std::cin >> newPassword;

		User temp(newUsername, newPassword);
		index = checkIfUserExists(temp);

		if (index == -1) {
			std::cout << "Invalid Username or Password! Please Try again\n" << std::endl;
			newUsername.clear();
			newPassword.clear();
		}
		else {
			newUsername.clear();
			newPassword.clear();
			break;
		}
	}

	currentUser = users[index];

	return 1;
}

size_t Kindle::login() {
	User currentUser;

	std::cout << "To login type 'l' | To register type 'r' | To exit type 'e': " << std::endl;
	while (true) {
		std::cout << "Enter your Choice: ";

		char symbol;
		std::cin >> symbol; std::cin.ignore();

		if (symbol == 'r') {
			currentUser = registerUserFromConsole();
			std::cout << "Registration Successful!\n" << std::endl;
			break;
		}
		else if (symbol == 'l') {
			int errorCommand = loginAsExistingUser(currentUser);
			if (errorCommand == 0) {
				continue;
			}

			std::cout << "Login Successful!\n" << std::endl;
			break;
		}
		else if (symbol == 'e') {
			return 0;
		}
		else {
			std::cout << "Error! Please Try again!\n" << std::endl; std::cin.ignore();
		}
	}


	printMenu();
	while (true) {
		std::cout << "Enter your Choice: ";
		char symbol;
		std::cin >> symbol; std::cin.ignore();

		if (symbol == 'e') {
			break;
		}

		Book temp;
		int returnCommand = -1;

		switch (symbol) {
		case 'h':
			printMenu();
			break;
		case '1':
			temp = getBookToRead();
			returnCommand = currentUser.readBook(temp);
			if (returnCommand == 2) {
				currentUser.addReadBook(checkIfBookExists(temp));
			}
			break;
		case '2':
			temp = currentUser.writeBook();
			addBook(temp);
			currentUser.addWritenBook(books.getSize() - 1);
			break;
		case '3':
			while (true) {
				std::cout << "\nEnter the Book you want to Comment:" << std::endl;
				int bookToCommentIndex = getBookToRate();

				if (bookToCommentIndex == -2) {
					break;
				}
				else if (bookToCommentIndex == -1) {
					std::cout << "Such Book doesn't exist! Please try again!\n" << std::endl;
					continue;
				}

				books[bookToCommentIndex].addComment(currentUser.makeComment(), currentUser.getUsername());
				break;
			}
			break;
			break;
		case '4':
			while (true) {
				std::cout << "\nEnter the Book you want to read the Comments of" << std::endl;
				int bookToGetCommentsOf = getBookToRate();

				if (bookToGetCommentsOf == -2) {
					break;
				}
				else if (bookToGetCommentsOf == -1) {
					std::cout << "Such Book doesn't exist! Please try again!\n" << std::endl;
					continue;
				}

				books[bookToGetCommentsOf].printComments();
				break;
			}
			break;
		case '5':
			while (true) {
				std::cout << "\nEnter the Book you want to Rate" << std::endl;
				int bookToRateIndex = getBookToRate();

				if (bookToRateIndex == -2) {
					break;
				}
				else if (bookToRateIndex == -1) {
					std::cout << "Such Book doesn't exist! Please try again!\n" << std::endl;
					continue;
				}

				if (currentUser.isRead(bookToRateIndex) == 1) {
					books[bookToRateIndex].addRating(currentUser.makeRating(), currentUser.getUsername());
					std::cout << std::endl;
					break;
				}
				else {
					std::cout << "You have not read this Book yet!" << std::endl
						<< "To go back type 'b' | To try again type 'a' | To read the Book type '1'" << std::endl;
					char symbol2 = '0';
					std::cin >> symbol2; std::cin.ignore();
					if (symbol2 == 'b') {
						break;
					}
					else if (symbol2 == '1') {
						returnCommand = currentUser.readBook(books[bookToRateIndex]);
						if (returnCommand == 2) {
							currentUser.addReadBook(bookToRateIndex); std::cin.ignore();
						}
					}
				}
			}
			break;
		case '6':
			while (true) {
				std::cout << "\nEnter the Book you want to get the Rate of" << std::endl;
				int bookToGetRateOf = getBookToRate();

				if (bookToGetRateOf == -2) {
					break;
				}
				else if (bookToGetRateOf == -1) {
					std::cout << "Such Book doesn't exist! Please try again!\n" << std::endl;
					continue;
				}

				std::cout << '\n' << books[bookToGetRateOf].getAvarageRate() << std::endl << std::endl;
				break;
			}
			break;
		case '7':
			while (true) {
				std::cout << "\nEnter the Book you want to Rewrite" << std::endl;
				int bookToRewrite = getBookToRewrite();

				if (bookToRewrite == -2) {
					break;
				}
 				else if (bookToRewrite == -1) {
					std::cout << "Such Book doesn't exist! Please try again!\n" << std::endl;
					continue;
				}

				if (!currentUser.isWriten(bookToRewrite)) {
					std::cout << "You have not writen this Book!\n" << std::endl;
					continue;
				}
				currentUser.rewriteBook(books[bookToRewrite]);
				break;
			}
			break;
		default:
			std::cout << "Error! Please try again!\n" << std::endl;
			break;
		}
	}


	int index = checkIfUserExists(currentUser);
	if (index == -1) {
		users.push_back(currentUser);
		return 1;
	}

	users[index] = currentUser;
	return 1;
}

//* Write the Kindle to File
size_t Kindle::writeKindleToFile() const {
	const char* ptr = fileName.getCharPointer();
	std::ofstream file(ptr, std::ios::trunc);

	if (!file.is_open()) {
		return 0;
	}

	file << name << '\n';

	file << books.getSize() << '\n';
	for (size_t i = 0; i < books.getSize(); ++i) {
		file << books[i].getFileName() << '\n';
		books[i].saveBookToFile();
	}

	file << users.getSize() << '\n';
	for (size_t i = 0; i < users.getSize(); ++i) {
		file << users[i].getFileName() << '\n';
		users[i].writeUserToFile();
	}

	file.close();

	return 1;
}

//* Read Books from File
size_t Kindle::readKindleFromFile() {
	std::ifstream file(fileName.getCharPointer());


	if (!file.is_open()) {
		return 0;
	}

	FilipString temp;

	file >> temp;
	name = temp;

	//! Books
	int sizeBooks;
	file >> sizeBooks;

	file >> temp;

	for (int i = 0; i < sizeBooks; ++i) {
		file >> temp;
		books.push_back(Book(temp.getCharPointer()));
	}
	//!

	//! Users
	int sizeUsers;
	file >> sizeUsers;

	file >> temp;

	for (int i = 0; i < sizeUsers; ++i) {
		file >> temp;
		users.push_back(temp.getCharPointer());

	}

	file.close();
	return 1;
}

//* Get Book to Read
Book Kindle::getBookToRead() const {
	while (true) {
		std::cout << "Enter Book Name: " << std::endl;
		FilipString newName;
		std::cin >> newName;

		std::cout << "Enter Book Author Name: " << std::endl;
		FilipString authorName;
		std::cin >> authorName;

		for (size_t i = 0; i < books.getSize(); ++i) {
			if (books[i] == Book(newName, authorName)) {
				return books[i];
			}
		}
		std::cout << "Error! Such Book  doesn't exist! Please try again!\n" << std::endl;
	}


	return Book();
}

int Kindle::getBookToRate() const {
	std::cout << "To go back type 'b'" << std::endl
		<< "Enter Book Name: " << std::endl;
	FilipString bookName;
	std::cin >> bookName;

	if (bookName == "b") {
		return -2;
	}

	std::cout << "Enter Book Author: " << std::endl;
	FilipString bookAuthor;
	std::cin >> bookAuthor;

	if (bookAuthor == "b") {
		return -2;
	}

	Book temp(bookName, bookAuthor);

	for (size_t i = 0; i < books.getSize(); ++i) {
		if (books[i] == temp) {
			return i;
		}
	}

	return -1;
}

int Kindle::getBookToRewrite() const {
	std::cout << "To go back type 'b'" << std::endl
		<< "Enter Book Name: " << std::endl;
	FilipString bookName;
	std::cin >> bookName;

	if (bookName == "b") {
		return -2;
	}

	std::cout << "Enter Book Author: " << std::endl;
	FilipString bookAuthor;
	std::cin >> bookAuthor;

	if (bookAuthor == "b") {
		return -2;
	}

	Book temp(bookName, bookAuthor);

	for (size_t i = 0; i < books.getSize(); ++i) {
		if (books[i] == temp) {
			return i;
		}
	}

	return -1;
}
