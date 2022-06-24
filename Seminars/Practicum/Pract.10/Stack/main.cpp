#include "FilipStack.hpp"
#include <iostream>

int main() {

  FilipStack<int> stack;
  stack.push(5);
  stack.push(4);
  stack.push(3);
  stack.push(2);
  stack.push(2);
  stack.push(224324);
  stack.push(26545);
  stack.push(4234);
  stack.push(87867);
  stack.push(978678);
  stack.push(2);
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  std::cout << stack.top() << std::endl;
  stack.push(2);
  stack.push(1344235);
  stack.push(6);
  stack.pop();
  std::cout << stack.top() << std::endl;

  return 0;
}
