#include "Casino.h"

//* My Abs Function
int Casino::myAbs(int n) const {
  return n >= 0 ? n : -n;
}

//* Check if the Number is a Degree of 2
bool Casino::isNumDegreeOfTwo(int n) const {
  return (n != 0 && !(myAbs(n) & (myAbs(n) - 1)));
}

//* Is the number a Prime Number
bool Casino::isPrime(int num) const {
  int border = sqrt(num);

  for (int i = 2; i <= border; i++)
    if (num % i == 0) {
      return false;
    }

  return true;
}

//* Check if number is even
bool Casino::isEven(const int n) const { return (n % 2 == 0); }

//* Check in Guess is correct
bool Casino::checkGuess(Player &currentPlayer, const BetType betType,
                        const double bet) const {
  int num;

  switch (betType) {
  case BetType::isPrime:
    if (isPrime(currentNumber)) {
      currentPlayer.addThreeTimes(bet);

      return true;
    }
    break;

  case BetType::isOdd:
    if (!isEven(currentNumber)) {
      currentPlayer.addDouble(bet);

      return true;
    }
    break;

  case BetType::isEven:
    if (isEven(currentNumber)) {
      currentPlayer.addDouble(bet);

      return true;
    }
    break;

  case BetType::isPowerOfTwo:
    if (isNumDegreeOfTwo(currentNumber)) {
      currentPlayer.addThreeTimes(bet);

      return true;
    }
    break;

  case BetType::isHigher:
    std::cout << "Enter a Number between 20 and 60: ";

    std::cin >> num;

    while (num < 20 || num > 60) {
      std::cout << "Invalid Number! Try again!" << std::endl;
      std::cin >> num;
    }

    if (num < currentNumber) {
      currentPlayer.addOneFourth(bet);
      return true;
    }
    break;

  case BetType::isLower:
    std::cout << "Enter a Number between 20 and 60: ";

    std::cin >> num;

    while (num < 20 || num > 60) {
      std::cout << "Invalid Number! Try again!" << std::endl;
      std::cin >> num;
    }

    if (num > currentNumber) {
      currentPlayer.addOneFourth(bet);
      return true;
    }

    break;

  case BetType::isSameAs:

    std::cout << "Enter your number: ";
    std::cin >> num;

    while (num < 0) {
      std::cout << "Invalid Number! Try again!" << std::endl;
      std::cin >> num;
    }

    return num == currentNumber;
    break;

  default:
    break;
  }

  return false;
}

//* Get new Random Number
void Casino::nextRound() {
  srand(time(NULL));
  currentNumber = 1 + (rand() % 100);
}

//* Game Menu
void Casino::printMenu() const {
  std::cout << "Guesses:" << std::endl
            << "0 for Even" << std::endl
            << "1 for Odd" << std::endl
            << "2 for Prime" << std::endl
            << "3 for Power of Two" << std::endl
            << "4 to enter a Number that the current Number is lower than"
            << std::endl
            << "5 to enter a Number that the current Number is higher than"
            << std::endl
            << "6 to guess the Number" << std::endl
            << "7 to exit" << std::endl
            << "h to print the Menu again" << std::endl
            << std::endl;
}

//! public:

Casino::Casino() { currentNumber = 0; }

//* Get the Current Number
const int Casino::getCurrentNumber() const {
  return currentNumber;
}

//* Play
void Casino::play(Player &currentPlayer) {
  if (currentNumber == 0) {
    nextRound();
  }

  printMenu();

  while (true) {
    BetType betType = currentPlayer.makeBetType(); //* Make a Type of Bet

    if (betType == BetType::exit) { //* Check Bet Type
      return;
    } else if (betType == BetType::help) { //* Check Bet Type
      printMenu();
      continue;
    }

    double bet = currentPlayer.makeBet(); //* Bet Money

    std::cout << std::endl;

    if (checkGuess(currentPlayer, betType, bet)) { //* If Guess is Correct
      std::cout << "Correct!" << std::endl;
    } else { //* if Guess is Wrong
      std::cout << "Wrong!" << std::endl;

      currentPlayer.setMoney(currentPlayer.getMoney() - bet); //* Update Money

      if (currentPlayer.getMoney() == 0) { //* Check left Money
        std::cout << "Current Number was " << currentNumber << std::endl
                  << "No money! Bye!" << std::endl;
        return;
      }
    }

    //* Print Results
    std::cout << "Current Number was " << getCurrentNumber() << std::endl
              << "Current Money: " << currentPlayer.getMoney() << std::endl
              << "============================================================"
              << std::endl;

    nextRound();
  }

  return;
}
