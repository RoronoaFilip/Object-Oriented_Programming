#include "other_functions.h"

//* Start the Interface
void initializeInterface() {
  //* Quick Menu:
  std::cout << "Commands:" << std::endl;
  std::cout << ">print - Prits the whole Information to the Console"
            << std::endl;
  std::cout << ">edit *Fn* *Attribute* *New Info* - Edits the Attribute of the "
               "Student with that FN with the Info"
            << std::endl;
  std::cout << ">sort *Attribute* - Sorts the Students based on that Attribute"
            << std::endl;
  std::cout << ">save - Saves the Students to the current File" << std::endl;
  std::cout << ">save as *File Path* - Saves the File to the new File"
            << std::endl;
  std::cout << ">exit - Terminates the Program" << std::endl;
  std::cout << std::endl;

  while (true) {
    char filePath[SIZE];

    std::cout << "Enter file name: ";
    std::cin >> filePath;

    std::ifstream file(filePath);

    std::cin.ignore();

    if (file.is_open()) {
      std::cout << "File opened successfully" << std::endl;
    } else if (!file.is_open()) {
      std::cout << "Error opening File in read form! Please try again!"
                << std::endl;
      continue;
    }

    std::cout << std::endl;

    classOfStudents students(file);
    if (students.countOfStudents == 0) {
      std::cout << "All Students had invalid Info!" << std::endl;
    } else {
      std::cout << "File loaded successfully" << std::endl;
    }

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
        return;
      } else if (interface.checkCommand(">print")) {

        if (students.countOfStudents == 0) {
          std::cout << "No Students were loaded! Nothing to print!"
                    << std::endl;
          continue;
        }

        students.print();
      } else if (interface.checkCommand(">save")) {

        if (students.countOfStudents == 0) {
          std::cout << "No Students were loaded! Nothing to save!" << std::endl;
          continue;
        } else if (!interface.isThereFilePath()) {
          char *as = interface.getInfoToSpace(); //* Skip "as" in "save as"
          char *inputFilePathForWrite = interface.getInfoToTerminateZero();

          students.saveStudentsToFile(inputFilePathForWrite);

          delete[] inputFilePathForWrite;
          delete[] as;
        } else {
          students.saveStudentsToFile(filePath);
        }

        std::cout << "File saved successfully!" << std::endl;
      } else if (interface.checkCommand(">edit")) {

        if (students.countOfStudents == 0) {
          std::cout << "No Students were loaded! Nothing to edit!" << std::endl;
          continue;
        }

        char *studentFn = interface.getInfoToSpaceOnlyDigits();

        if (!students.checkIfFnExists(studentFn)) {
          std::cout << "Fn doesn't exist! Please try again!" << std::endl;
          continue;
        } else {
          char *attributeToEdit = interface.getInfoToSpace();

          if (!students.doesAttributeToEditExist(attributeToEdit)) {
            std::cout << "Such Info to edit doesn't exist! Please try again!"
                      << std::endl;

          } else {
            char *editInfo = interface.getInfoToTerminateZero();

            if (students.isEditInfoValid(editInfo, attributeToEdit)) {
              students.editInfo(editInfo, attributeToEdit, studentFn);

              std::cout << "Info edited successfully!" << std::endl;
            } else {
              std::cout << "Error! Data not in correct Format!" << std::endl;
            }

            delete[] editInfo;
          }

          delete[] attributeToEdit;
        }

        delete[] studentFn;
      } else if (interface.checkCommand(">sort")) {
        if (students.countOfStudents == 0) {
          std::cout << "No Students were loaded! Nothing to sort!" << std::endl;
          continue;
        }

        char *attributeToSort = interface.getInfoToTerminateZero();

        students.sort(attributeToSort);
        std::cout << "Students successfully sorted!" << std::endl;

        delete[] attributeToSort;
      } else {
        std::cout << "Invalid command! Please try again!" << std::endl;
        continue;
      }
    }

    file.close();
    return;
  }
}