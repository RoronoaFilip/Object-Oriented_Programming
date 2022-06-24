#include "Duelist.h"
#include "MagicCard.h"
#include "MonsterCard.h"
#include <iostream>

int main() {
  Duelist player1("Seto Kaiba");

  MagicCard mirrorForce("Mirror Force", "A Trap Spell that Blocks DMG and sends it back", "trap");

  MagicCard magicalCilynders("Magical Cylinders", "A Spell that consumes incoming DMG and redirects it randomly", "spell");

  MonsterCard blueEyesWhiteDragon("Blue Eyes White Dragon", 3000, 2500);

  MonsterCard darkMagician("Dark Magician", 2600, 2000);

  player1.addMagicCard(mirrorForce);
  player1.addMonsterCard(blueEyesWhiteDragon);

  player1.addMagicCard(magicalCilynders);
  player1.addMonsterCard(darkMagician);

  player1.addMonsterCard(blueEyesWhiteDragon);
  player1.addMonsterCard(blueEyesWhiteDragon);

  Duelist player2;
  player2 = player1;

  MagicCard polimerization("Polimerization", "Combines 2 Monsters", "Spell");

  player2.addMagicCard(polimerization);

  player2.print();

  return 0;
}