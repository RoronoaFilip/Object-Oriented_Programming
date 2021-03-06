# Разделна компилация. Абстракция. Копиращ конструктор и оператор=

## Разделна компилация.

![enter image description here](https://camo.githubusercontent.com/28dc183568fa5f05a944d8ec4f3033c8ee08e4c87b6c19ae051dc55ea7979f69/68747470733a2f2f692e6962622e636f2f664436584c4a4d2f436f6d70696c6174696f6e2e706e67)

Една програма на С++ може да бъде разбита в множество файлове, които се **компилират независимо един от друг**, т.е. осъществява се **разделна компилация**. В резултат на компилацията се получават няколко **обектни файла** (файлове с разширение **.obj**). Изпълнимият код напрограмата (файл с разширение .ехе) се получава след свързване на обектните файлове (**Linking**).

За да се възполваме максимално от разделната компилация, разделяме класовете на **.h** и **.cpp** файлове. Навсякъде където ще работим с класа, ще включваме **само .h файла.** По този начин, ако променим реализацията на някоя от функциите на класа, ще се **прекомпилира само този файл**.

![enter image description here](https://i.ibb.co/N9RnMHv/sss.png)

## Копиращ конструктор и оператор =
Заедно с конструктора по подразбиране и деструктора във всеки клас се дефинират и следните член-функции:
 -  Копиращ конструктор - конструктор, който приема обект от същия клас и създава новият обект като негово копие.
 - Оператор= - функция/оператор, който приема  обект от същия клас и променя данните на съществуващ обект от същия клас (обектът от който извикваме функцията.

**Забележка:** Копиращият конструктор създава нов обект, а оператор= модифицира вече съществуващ такъв!

### Пример с копиращ конструктор.

```c++
#include <iostream>

struct A
{
	A(int a)
	{
		std::cout << "Constructor with one int parameter of A" << std::endl;
	}

	A(const A& other)
	{
		std::cout << "Copy constructor of A" << std::endl;
	}

	~A()
	{
		std::cout << "Destructor of A" << std::endl;
	}
};

void f(A object)
{ //Copy constructor of A
	std::cout << "f()" << std::endl;
} //Destructor of A

void g(A& object)
{ 
	std::cout << "g()" << std::endl;
}

int main()
{
	A obj(3); //Constructor with one int parameter of A
	f(obj);
	g(obj);

} //Destructor of A
 ```
