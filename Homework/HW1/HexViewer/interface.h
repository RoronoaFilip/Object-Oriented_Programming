#pragma once
const int InterfaceCommandSize = 25;
const int InterfaceInputSize = 1024;
class ConsoleInterface {
public:
  char *input;
  char *command;
  int currentInputIndex;

  ConsoleInterface();
  ~ConsoleInterface();

  //* Gets Command from the Input
  void getCommand();

  //* Validate Input
  bool validateInput() const;

  //* Check what Command is input
  bool checkCommand(const char *inputCommand) const;

  //* Check if a File Path has been input
  bool isThereFilePath() const;

  //* Get the File Path from the Input
  char *getInfoToSpaceOnlyDigits();

  //* Get Attribute to edit
  char *getInfoToSpace();

  //* Get Info from Input up to '\0'
  char *getInfoToTerminateZero();

private:
  //* Check if the Strings are the same
  bool areStringsEqual(const char *arr1, const char *arr2) const;

  //* Get the Lenght of Something
  int getLenght(const char *word) const;
};