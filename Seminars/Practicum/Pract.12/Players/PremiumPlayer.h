#pragma once
#include "FilipString.h"
#include "LoggedIn.h"

class PremiumPlayer : public LoggedIn {
  FilipString name;

public:
  PremiumPlayer(const int newId, const FilipString &newName,
                const FilipString &newPass);

  bool levelUp();
};