#include "Player.h"

Player::Player(int newId) {
  id = newId;
  points = 1;
  yourStar = Star::level1;
}

void Player::addPoints(const int add) { points += add; }

void Player::goUpOneStar() {
  switch (yourStar) {
  case Star::level1:
    yourStar = Star::level2;
    break;
  case Star::level2:
    yourStar = Star::level3;
    break;
  case Star::level3:
    yourStar = Star::level4;
    break;
  case Star::level4:
    yourStar = Star::level5;
    break;
  case Star::level5:
    break;
  default:
    yourStar = Star::level1;
    break;
  }
}

void Player::setPoints(const size_t newPoints) { points = newPoints; }

size_t Player::getPoints() const { return points; }
int Player::getId() const { return id; }
Star Player::getStar() const {
  Star temp;
  temp = yourStar;
  return temp;
}

Player::~Player() {}