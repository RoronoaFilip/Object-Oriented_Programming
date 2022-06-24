#include "kPriorityQueue.hpp"
#include <iostream>

int main() {
  kPriorityQueue<char> q(4); // 4 priorities - 0, 1, 2 и 3.

  q.push('A', 0); // adds A with lowest priority: 0
  q.push('B', 3);
  q.push('x', 2);
  q.push('z', 4);
  q.push('y', 3);
  q.push('6', 6); //* Doesn't get added
  q.push('9', 9); //* Doesn't get added
  q.push('O', 1);
  q.push('P', 2);
  q.push('T', 4);

  // q.push('F', 5); //* Wouldn't get added

  std::cout << q.peek() << std::endl; //* 'z'
  q.pop();

  std::cout << q.peek() << std::endl; //* 'T'
  q.pop();

  std::cout << q.peek() << std::endl; //* 'B'
  q.pop();

  std::cout << q.peek() << std::endl; //* 'y'
  q.pop();

  std::cout << q.peek() << std::endl; //* 'x'
  q.pop();

  std::cout << q.peek() << std::endl; //* 'P'

  std::cout << q.isEmpty() << std::endl; //* False / 0
}