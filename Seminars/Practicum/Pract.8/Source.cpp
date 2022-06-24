#include "vector.h"
#include <iostream>

int main() {
	vector v;
	for (int i = 0; i < 8; ++i) {
		std::cin >> v[i];
	}

	std::cout << v.findItem(5);

	return 0;
}
