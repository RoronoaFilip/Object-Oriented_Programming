#include "Engine.h"

Engine::Engine() {}

Engine::Engine(const int newHp) {
  setHp(newHp);
}

void Engine::setHp(const int newHp) {
  if (newHp < 0) {
    hp = 0;
  } else {
    hp = newHp;
  }
}
const int Engine::getHp() const {
  return hp;
}

std::ostream &operator<<(std::ostream &stream, Engine &engine) {
  stream << "HP: " << engine.hp << '\n';
}
