#include "vector.h"
#include <exception>

void vector::free() {
	delete[] data;
}

void vector::copyFrom(const vector& other) {
	size = other.size;
	capacity = other.capacity;

	data = new int[capacity];

	for (int i = 0; i < size; i++)
		data[i] = other.data[i];
}

void vector::resize() {
	capacity = 2 * capacity;

	int* newMemory = new int[capacity];

	for (int i = 0; i < size; i++)
		newMemory[i] = data[i];

	delete[] data;
	data = newMemory;
}

void vector::swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
};

vector::vector() {
	size = 0;
	capacity = 8;
	data = new int[capacity];
}

vector::vector(const vector& other) {
	copyFrom(other);
}

vector& vector::operator=(const vector& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

size_t vector::getSize() const {
	return size;
}

void vector::push_back(int elem) {
	if (size == capacity)
		resize();

	data[size++] = elem;
}

void vector::pop_back() {
	--size;
}

void vector::clear() {
	free();
	size = 0;
	capacity = 8;
	data = new int[capacity];
}

void vector::reverse() {
	int index = size - 1;
	for (size_t i = 0; i < size / 2; ++i) {
		swap(data[i], data[index--]);
	}
}

void vector::selectionSort() {
	for (size_t i = 0; i < size - 1; i++) {
		int minElementIndex = i;

		for (size_t j = i + 1; j < size; j++) {
			if (data[j] < data[minElementIndex]) {
				minElementIndex = j;
			}
		}

		if (minElementIndex != i) {
			swap(data[i], data[minElementIndex]);
		}
	}
}

int& vector::operator[](size_t index) {
	// if (index >= size)
	// throw std::exception("out of range");

	return data[index];
}

const int vector::operator[](size_t index) const {
	// if (index >= size)
	// throw std::exception("out of range");

	return data[index];
}

vector::~vector() {
	free();
}

size_t vector::findItem(const int item) {
	for (size_t i = 0; i < size; ++i) {
		if (data[i] == item) {
			return i;
		}
	}

	return capacity;
}

std::ostream& operator<<(std::ostream& stream, const vector& myVector) {
	for (size_t i = 0; i < myVector.getSize(); ++i) {
		stream << myVector[i] << " ";
	}

	return stream;
}
