#include "Book.h"

//* Get File Name
const FilipString Book::getFileName() const {
	return fileName;
}

//! public:
//* Default Constructor
Book::Book() : name(), author(), fileName(), comments(),
commentators(), pages(), ratings() {
	avarageRate = 0;
}

//* Constructor
Book::Book(const FilipString newName, const FilipString newAuthor) {
	name = newName;
	author = newAuthor;

	fileName.concatenate(name);
	fileName.concatenate(" by ");
	fileName.concatenate(author);
	fileName.concatenate(".txt");
}

Book::Book(const char* filePath) : fileName(filePath) {
	readBookFromFile(filePath);
}

//* Copy Constructor
Book::Book(const Book& other) : name(other.name), author(other.author),
fileName(other.fileName), pages(other.pages), comments(other.comments),
commentators(other.commentators), avarageRate(other.avarageRate) {}

//* Operator=
Book& Book::operator=(const Book& other) {
	if (this != &other) {
		name = other.name;
		author = other.author;

		fileName = other.fileName;

		pages = other.pages;

		comments = other.comments;
		commentators = other.commentators;

		ratings = other.ratings;
		avarageRate = other.avarageRate;
	}

	return *this;
}

//* Move Constructor
Book::Book(Book&& other) : name(other.name), author(other.author),
fileName(other.fileName), pages(other.pages), comments(other.comments),
commentators(other.commentators), avarageRate(other.avarageRate) {}

//* Move Operator=
Book& Book::operator=(Book&& other) {
	if (this != &other) {
		name = other.name;
		author = other.author;

		fileName = other.fileName;

		pages = other.pages;

		comments = other.comments;
		commentators = other.commentators;

		ratings = other.ratings;
	}

	return *this;
}

bool Book::operator==(const Book& other) const
{
	return author == other.author && name == other.name;
}

//* Operator<<
std::ostream& operator<<(std::ostream& stream, const Book& book) {
	for (size_t i = 0; i < book.pages.getSize(); ++i) {
		stream << book.pages[i] << '\n';
	}

	return stream;
}

//* Print the Book
size_t Book::print() const {
	std::cout << name << " by " << author << std::endl;

	printPages();

	return 1;
}

//* Read the Book
size_t Book::read() const {
	std::cout << "Now reading: " << name << " by " << author << std::endl;

	char symbol = '0';
	size_t currentPage = 1;
	while (symbol != 'q') {
		std::cout << std::endl;
		size_t pageErrorValidation = printPage(currentPage);

		if (pageErrorValidation == 2) {
			std::cout << "This is the last Page! You have read the Book\n" << std::endl;
			return 2;
		}
		else if (pageErrorValidation == 1) {
			std::cout << "n|p: ";
			std::cin >> symbol;
		}
		else if (pageErrorValidation == 0) {
			std::cout << "This is the first page!\n" << std::endl;
			printPage(1);
			std::cout << "n|p: ";
			std::cin >> symbol;
			currentPage = 1;
		}

		if (symbol == 'n') {
			++currentPage;
		}
		else if (symbol == 'p') {
			--currentPage;
		}
		else if (symbol == 'q') {
			std::cout << '\n';
			return 1;
		}
		else {
			std::cout << "Error! Current Page is " << currentPage << std::endl << std::endl;
		}
	}

	return 1;
}

//* Add a new Page
size_t Book::addPage(const Page& newPage) {
	pages.push_back(newPage);

	return 1;
}

//* Print a certain Page
size_t Book::printPage(const size_t pageNumber) const {
	if (pageNumber <= 0) {
		return 0;
	}
	if (pageNumber > pages.getSize()) {
		return 2;
	}

	std::cout << pages[pageNumber - 1] << std::endl;

	return 1;
}

//* Print all Pages
size_t Book::printPages() const {
	for (size_t i = 0; i < pages.getSize(); ++i) {
		std::cout << "Page " << i + 1 << ":\n"
			<< pages[i] << std::endl;
	}

	return 1;
}

int Book::checkIfRatingExists(const Rating& other) const {
	for (size_t i = 0; i < ratings.getSize(); ++i) {
		if (ratings[i] == other) {
			return i;
		}
	}

	return -1;
}

//* Change an existing Page
size_t Book::changePage(const size_t pageNumber, const Page& editedPage) {
	if (pageNumber <= 0 || pageNumber > pages.getSize() + 1) {
		return 0;
	}

	if (pageNumber == pages.getSize() + 1) {
		pages.push_back(editedPage);
		return 1;
	}

	pages[pageNumber - 1] = editedPage;

	return 1;
}

//* Save the Book to File
size_t Book::saveBookToFile() const {
	std::ofstream file(fileName.getCharPointer(), std::ios::trunc);

	if (!file.is_open()) {
		return 0;
	}

	file << name << '\n'
		<< author << '\n';

	file << pages.getSize() << '\n';
	for (size_t i = 0; i < pages.getSize(); ++i) {
		file << "> " << pages[i] << " |\n";
	}

	file << commentators.getSize() << '\n';
	for (size_t i = 0; i < commentators.getSize(); ++i) {
		file << commentators[i] << ' ' << comments[i] << '\n';
	}

	file << ratings.getSize() << '\n';
	for (size_t i = 0; i < ratings.getSize(); ++i) {
		file << ratings[i] << "\n";
	}

	file.close();

	return 1;
}

void Book::setName(const FilipString& newName) {
	name = newName;
}

void Book::setName(FilipString&& newName) {
	name = newName;
}

void Book::setAuthor(const FilipString& newAuthor) {
	author = newAuthor;
}

void Book::setAuthor(FilipString&& newAuthor) {
	author = newAuthor;
}

//* Read Pages from File
size_t Book::readBookFromFile(const char* filePath) {
	std::ifstream file(filePath);

	if (!file.is_open()) {
		return 0;
	}

	FilipString line;

	file >> line;
	name = line;

	file >> line;
	author = line;

	int sizePages;
	file >> sizePages;

	file >> line;

	for (int i = 0; i < sizePages; ++i) {
		file >> line;
		const char* ptr = line.substring(3, line.getSize() - 2);
		pages.push_back(Page(ptr));

		delete[] ptr;
	}

	line.clear();

	int commentsSize;
	file >> commentsSize;

	file >> line;

	for (int i = 0; i < commentsSize; ++i) {
		char temp[100];

		file.getline(temp, 100, ' ');
		commentators.push_back(FilipString(temp));

		file.getline(temp, 100);
		comments.push_back(FilipString(temp));
	}

	int sizeRatings;
	file >> sizeRatings;

	file >> line;

	for (int i = 0; i < sizeRatings; ++i) {
		Rating temp;
		file >> temp;
		ratings.push_back(temp);
	}

	calculateAvarageRating();

	file.close();

	return 1;
}

//* Add a Comment
size_t Book::addComment(const FilipString& newComment, const FilipString& user) {
	comments.push_back(newComment);
	commentators.push_back(user);

	return 1;
}

//* Print all the Comments along with the Commentators
size_t Book::printComments() const {
	std::cout << std::endl;
	for (size_t i = 0; i < comments.getSize(); ++i) {
		std::cout << commentators[i] << " wrote " << comments[i] << std::endl;
	}

	std::cout << std::endl;

	return 1;
}

size_t Book::addRating(const int rate, const FilipString& name) {
	if (checkIfRatingExists({ name, rate }) != -1) {
		return 1;
	}

	ratings.push_back({ name, rate });

	calculateAvarageRating();

	return 1;
}

size_t Book::calculateAvarageRating() {
	if (ratings.getSize() == 0) {
		avarageRate = 0;
		return 1;
	}

	double newAvarageRate = 0;

	for (size_t i = 0; i < ratings.getSize(); ++i) {
		newAvarageRate += ratings[i].getRate();
	}

	avarageRate = newAvarageRate / ratings.getSize();

	return 1;
}

const double Book::getAvarageRate() const {
	return avarageRate;
}

size_t Book::deletePage(const size_t pageIndex)
{
	pages.remove(pageIndex);
	return 1;
}
