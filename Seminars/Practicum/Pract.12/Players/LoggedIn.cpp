#include "LoggedIn.h"

LoggedIn::LoggedIn(const int newId, const FilipString &newPass)
    : Player(newId) {
  pass = newPass;
}

bool LoggedIn::checkPass(const FilipString &checkPass) const {
  return pass == checkPass;
}

bool isNumDegreeOfTwo(const int num) {
  return num != 0 && ((num & num - 1) == 0);
}
bool LoggedIn::levelUp() {
  switch (Player::getStar()) {
  case Star::level1:
    if (Player::getPoints() >= 256) {
      Player::goUpOneStar();

      Player::setPoints(Player::getPoints() - 256);

      return true;
    }
    break;
  case Star::level2:
    if (Player::getPoints() >= 512) {
      Player::goUpOneStar();

      Player::setPoints(Player::getPoints() - 512);

      return true;
    }
    break;
  case Star::level3:
    if (Player::getPoints() >= 1024) {
      Player::goUpOneStar();

      Player::setPoints(Player::getPoints() - 1024);

      return true;
    }
    break;
  case Star::level4:
    if (Player::getPoints() >= 2048) {
      Player::goUpOneStar();

      Player::setPoints(Player::getPoints() - 2048);

      return true;
    }
    break;
  case Star::level5:
    return true;
    break;
  }
  return false;
}

LoggedIn::~LoggedIn() {}