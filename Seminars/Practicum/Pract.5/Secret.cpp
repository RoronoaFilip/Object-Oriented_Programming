#include <iostream>

void copyStrings(char *destination, const char *source) {
  if (destination == nullptr) {
    delete destination;
  } else {
    delete[] destination;
  }

  destination = new char[1024];

  int i = 0;
  for (; source[i] != '\0'; ++i) {
    destination[i] = source[i];
  }

  destination[i] = '\0';
}

int getStringLenght(const char *word) {
  int count = 0;
  for (int i = 0; word[i] != '\0'; ++i) {
    ++count;
  }

  return count;
}

bool areStringsEqual(const char *arr1, const char *arr2) {
  int arr1Lenght = getStringLenght(arr1);
  int arr2Lenght = getStringLenght(arr2);

  if (arr1Lenght != arr2Lenght) {
    return false;
  }

  for (int i = 0; arr1[i] != '\0'; ++i) {
    if (arr1[i] != arr2[i]) {
      return false;
    }
  }

  return true;
}

class Secret {
  char *task;
  char *password;
  int loginFails;

  void tickloginFails() { ++loginFails; }

public:
  Secret() {
    task = new char[1024];
    password = new char[1024];
    copyStrings(this->password, "1234");
    loginFails = 0;
  }

  void setPassword(const char *password, const char *newPassword) {
    if (areStringsEqual(password, newPassword)) {
      copyStrings(this->password, newPassword);
    } else {
      tickloginFails();
    }
  }

  void setTask(const char *newTask, const char *password) {
    if (areStringsEqual(password, this->password)) {
      copyStrings(this->task, task);
    }
  }

  char *getTask(const char *password) {
    if (areStringsEqual(this->password, password)) {
      char *toReturn = new char[1024];
      copyStrings(toReturn, this->task);
      return toReturn;
    } else {
      tickloginFails();
    }
    return nullptr;
  }

  int getLoginFails() { return this->loginFails; }
};

int main() {
  Secret secret;

  secret.setTask("fewiufew", "1234");

  char *arr = secret.getTask("1234");
  for (int i = 0; arr[i] != '\0'; ++i) {
    std::cout << arr[i];
  }
  return 0;
}