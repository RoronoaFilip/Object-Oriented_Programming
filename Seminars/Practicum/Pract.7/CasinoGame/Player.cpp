#include "Player.h"

void Player::free() {
  delete[] name;
  delete[] password;
}

void Player::copyFrom(const Player &other) {
  name = new char[strlen(other.name) + 1];
  password = new char[strlen(other.password) + 1];

  strcpy(name, other.name);
  strcpy(password, other.password);
}

//* Validate Password
bool Player::isPasswordValid(const char *newPassword) const {
  return (password == nullptr || strcmp(newPassword, password) == 0);
}

//! public:

//* Constructor
Player::Player(const char *newName, const char *newPassword, const int newAge,
               const double newMoney, const char *oldPassword) : name(nullptr), password(nullptr) {
  setName(newName);
  setPassword(newPassword, oldPassword);
  setAge(newAge);
  setMoney(newMoney);
}

//* Copy Constructor
Player::Player(const Player &other) { copyFrom(other); }

//* Operator=
Player &Player::operator=(const Player &other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }

  return *this;
}

//* Destructor
Player::~Player() { free(); }

//! Setters ================================================
void Player::setName(const char *newName) {
  if (name == newName) {
    return;
  }

  delete[] name;
  name = new char[strlen(newName) + 1];
  strcpy(name, newName);
}

void Player::setPassword(const char *newPassword, const char *oldPassword) {
  if (!isPasswordValid(oldPassword)) {
    return;
  }

  delete[] password;

  password = new char[strlen(newPassword) + 1];
  strcpy(password, newPassword);
}

void Player::setAge(int newAge) {
  age = newAge;
}

void Player::setMoney(double newMoney) {
  money = newMoney;
}

//! Getters ===================================================
const char *Player::getName() const {
  return name;
}

// const char *getPassword() const { return password; }

const int Player::getAge() const { return age; }

const double Player::getMoney() const { return money; }

//! Add money ===============================================
void Player::addOneFourth(const double bet) {
  money += bet / 4;
}
void Player::addOneHalf(const double bet) {
  money += bet / 2;
}
void Player::addDouble(const double bet) {
  money += bet * 2;
}
void Player::addThreeTimes(const double bet) {
  money += bet * 3;
}
void Player::addTimesOneHundred(const double bet) {
  money += bet * 100;
}

//! Make Bets ===============================================
//* Get Bet Type
BetType Player::makeBetType() const {
  char input;
  std::cout << "Enter your guess: " << std::endl;
  std::cin >> input;

  switch (input) {
  case 'h':
    return BetType::help;
    break;
  case '0':
    return BetType::isEven;
    break;
  case '1':
    return BetType::isOdd;
    break;
  case '2':
    return BetType::isPrime;
    break;
  case '3':
    return BetType::isPowerOfTwo;
    break;
  case '4':
    return BetType::isLower;
    break;
  case '5':
    return BetType::isHigher;
    break;
  case '6':
    return BetType::isSameAs;
    break;
  case '7':
    return BetType::exit;
    break;
  default:
    break;
  }

  return BetType::exit;
}

//* Make Bet
double Player::makeBet() const {
  double bet;
  std::cout << "Enter your bet: " << std::endl;
  std::cin >> bet;

  while (bet <= 0 || bet > money) { //* Validate Bet
    std::cout << "Not enough Money! Please try again!" << std::endl;
    std::cin >> bet;
  }

  return bet;
}