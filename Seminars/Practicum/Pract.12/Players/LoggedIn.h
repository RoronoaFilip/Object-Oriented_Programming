#pragma once
#include "FilipString.h"
#include "Player.h"

class LoggedIn : public Player {
  FilipString pass;

public:
  LoggedIn(const int newId, const FilipString &newPass);

  bool checkPass(const FilipString &checkPass) const;

  virtual bool levelUp();

  virtual ~LoggedIn();
};