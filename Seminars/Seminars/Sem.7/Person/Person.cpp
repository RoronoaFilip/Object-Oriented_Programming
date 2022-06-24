#pragma once
#include "Person.h"
#include <cstring>


void Person::copyFrom(const Person& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	age = other.age;
}
void Person::free()
{
	delete[] name;
}

Person::Person(const char* name, int age) : age(3)
{
	setName(name);
	setAge(age);
}
Person::Person(const Person& other)
{
	copyFrom(other);
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
const char* Person::getName() const
{
	return name;
}

int Person::getAge() const
{
	return age;
}

void Person::setName(const char* name)
{
	if (this->name == name)
		return;

	delete[] this->name;
	size_t nameLen = strlen(name);
	this->name = new char[nameLen + 1];
	strcpy(this->name, name);
}

void Person::setAge(int age)
{
	this->age = age;
}


Person::~Person()
{
	free();
}
void Person::print() const
{
	std::cout << name << " " << age << std::endl;
}

