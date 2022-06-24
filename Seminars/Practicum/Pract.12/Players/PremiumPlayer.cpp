#include "PremiumPlayer.h"

PremiumPlayer::PremiumPlayer(const int newId, const FilipString &newName,
                             const FilipString &newPass)
    : LoggedIn(newId, newPass) {
  name = newName;
}

bool PremiumPlayer::levelUp() {
  if (Player::getPoints() >= 256) {
    Player::goUpOneStar();

    Player::setPoints(Player::getPoints() - 256);

    return true;
  }

  return false;
}