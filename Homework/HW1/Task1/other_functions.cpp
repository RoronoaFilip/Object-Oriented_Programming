#include "other_functions.h"
#include "HexViewer.h"
#include "interface.h"

void initializeConsoleInterface() {
  //* Quick Menu:
  std::cout << "Commands:" << std::endl;
  std::cout << ">view - View the whole Information" << std::endl;
  std::cout << ">change *Index* *Byte* - Changes the Byte on the Index with "
               "the new Byte "
            << std::endl;
  std::cout << ">remove - Remove the last Byte" << std::endl;
  std::cout << ">add *Byte* - Adds the Byte to the End" << std::endl;
  std::cout << ">save - Saves the File to the Current File" << std::endl;
  std::cout << ">save as *File Path* - Saves the File to the new File"
            << std::endl;
  std::cout << ">exit - Terminates the Program" << std::endl;
  std::cout << std::endl;

  while (true) {
    char filePath[25];
    std::cout << "Enter File Path: ";
    std::cin >> filePath;

    std::ifstream file(filePath, std::ios::binary);

    std::cin.ignore();
    if (!file.is_open()) {
      std::cout << "Error opening File in read form! Please try again!"
                << std::endl;
      continue;
    } else if (file.is_open()) {
      std::cout << "File opened successfully!" << std::endl;
    }

    HexViewer hexViewer(file);

    std::cout << std::endl << "File loaded successfully!" << std::endl;

    while (true) {
      ConsoleInterface interface;

      std::cout << std::endl;
      std::cin.getline(interface.input, 50);

      if (!interface.validateInput()) {
        std::cout << "Invalid command! Please try again!" << std::endl;
        continue;
      }

      interface.getCommand();

      if (interface.checkCommand(">exit")) {

        file.close();
        break;
      } else if (interface.checkCommand(">view")) {
        hexViewer.view();
      } else if (interface.checkCommand(">change")) {
        char *index = interface.getInfoToSpaceOnlyDigits();
        if (!hexViewer.validateIndex(index)) {
          std::cout << "Invalid Index! Please try again!" << std::endl;
          delete[] index;
          continue;
        } else {
          char *editInfo = interface.getInfoToTerminateZero();
          if (hexViewer.validateByte(editInfo)) {
            hexViewer.changeIndexByte(index, editInfo);

            delete[] index;
            delete[] editInfo;
            std::cout << "Info changed successfully!" << std::endl;
          } else {
            std::cout << "Invalid Byte! Please try again!" << std::endl;
            delete[] index;
            delete[] editInfo;
            continue;
          }
        }

      } else if (interface.checkCommand(">remove")) {

        hexViewer.remove();

        std::cout << "Info removed successfully!" << std::endl;

      } else if (interface.checkCommand(">add")) {
        char *addInfo = interface.getInfoToTerminateZero();
        if (hexViewer.validateByte(addInfo)) {
          hexViewer.add(addInfo);

          delete[] addInfo;
          std::cout << "Info added successfully!" << std::endl;
        } else {
          std::cout << "Invalid Byte! Please try again!" << std::endl;
          delete[] addInfo;
          continue;
        }

      } else if (interface.checkCommand(">save")) {

        if (!interface.isThereFilePath()) {
          char *as = interface.getInfoToSpace(); //* Skip "as" in "save as"
          char *inputFilePathForWrite = interface.getInfoToTerminateZero();

          hexViewer.save(inputFilePathForWrite);

          delete[] inputFilePathForWrite;
          delete[] as;
        } else {
          hexViewer.save(filePath);
        }

        std::cout << "File saved successfully!" << std::endl;
      } else {
        std::cout << "Invalid command! Please try again!" << std::endl;
        continue;
      }
    }
    file.close();
    return;
  }
}