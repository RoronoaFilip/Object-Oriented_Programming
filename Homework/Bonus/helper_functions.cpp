//* Get the Lenght of a Number
int getNumberLenght(int n) {
  int lenght = 0;
  while (n) {
    ++lenght;
    n /= 10;
  }

  return lenght;
}

//* Transform Int to Array of it's Digits
int *transformIntToArr(int n) {
  int numLenght = getNumberLenght(n);

  int *arr = new int[numLenght];
  int index = numLenght - 1;

  for (int i = index; i >= 0; --i) {
    arr[i] = n % 10;
    n /= 10;
  }

  return arr;
}

//* Reverse the Number
int reverseNumber(int n) {
  int reversed = 0;

  if (n >= -9 && n <= 9) {
    return n;
  }

  while (n) {
    reversed = reversed * 10 + n % 10;
    n /= 10;
  }

  return reversed;
}

//* Check if the Number is a Palindrome
bool isNumPalindrome(const int n) { return n == reverseNumber(n); }

//* Check if the Num has different Ciphers
bool isNumWithDiffCiphers(int n) {
  if (n >= -9 && n <= 9) {
    return true;
  }

  int lenght = getNumberLenght(n);
  int *arr = transformIntToArr(n);

  for (int i = 0; i < lenght; ++i) {
    for (int j = i + 1; j < lenght; ++j) {
      if (arr[i] == arr[j]) {
        return false;
      }
    }
  }

  return true;
}

//* My Abs Function
int myAbs(int n) { return n >= 0 ? n : -n; }

//* Check if the Number is a Degree of 2
bool isNumDegreeOfTwo(int n) { return !(myAbs(n) & (myAbs(n) - 1)); }

//* Check if the Number is Prime
bool isPrime(const int n) {
  if (n == 0 || n == 1 || n < 0) {
    return false;
  }

  if (n == 2) {
    return true;
  }

  if (n % 2 == 0) {
    return false;
  }

  for (int i = 2; i < n / 2; ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}