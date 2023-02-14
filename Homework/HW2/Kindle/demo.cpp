#include "Kindle.h"
#include <iostream>

int main() {
  //* There is a Folder "Example_Kindle_Files" that has example Files of how a Kindle would be saved
  //* Typing the name "kindle1" in the Program wouldn't load it because the Files are in a different Directory
  //* Even if one of the Files is missing or is slitely changed than the whole Program wouldn't Work
  //* The User has no access to the Files and can only change the Files by Registering new Users or by Changing a Book

  while (true) {
    std::cout << "Enter the name of the Kindle you want to load. " << std::endl
              << "If such Kindle doesn't exist it will get created with no Users and Books" << std::endl
              << "To exit type \"exit\" or 'e'" << std::endl;
    FilipString name = "kindle1";
    std::cin >> name;
    if (name == "exit" || name == "e") {
      return 0;
    }
    Kindle kindle1(name);
    kindle1.login();
    std::cout << std::endl;
  }

  return 0;
}