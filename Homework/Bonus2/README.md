## **WordCollection**  
 Релизирайте клас - множество(**без повторение**) от думи от малки/главни латински букви и цифри. В колекцията ви търсенето трябва да е с логаритмична сложност.
 Предефинирайте оператори:
 
- += и +. Събиране на две колекции.
- -= и -. От думите на лявата колекция, се премахват тези, които участват в дясната.
- [], който приема дума и връща дали стрингът е в колекцията (очакваме логаритмично време).
- *= за добавяне на дума
- /= за премахване на дума.
- << (поток за изход. Отпечатва всички думи в сортиран вид).
- \>\> (поток за вход. Приема думa, която да се добави в речника).
**Важно!** Копирането на стрингове е бавна операция! Помислете как да организирате данните, за да имате логаритмично търсене на дума и при добавяне на нова дума да правите **минимален брой копирания** на стрингове!

```c++
int main()
{
	StringPool dict;  
	((dict *= "Ivan") *= "Petur") *= "Alex";  
  
	std::cout << dict << std::endl; // {Alex, Ivan, Petur}
	std::cout << dict["Alex"] << " " << dict["abc"] << std::endl; // 1 0
  
	StringPool dict2;
	((dict2 *= "Zebra") *= "Alex");
  
	StringPool result = dict + dict2;
	std::cout << result << std::endl; // {Alex, Ivan, Petur, Zebra}
  
	StringPool result2 = dict - dict2;
	std::cout << result2 << std::endl; // {Ivan, Petur}
  
	"NewWOrd" >> result2;
	result2 /= "NonExistingWord";
  
	std::cout << result2 << std::endl;  //{Ivan, NewWOrd, Petur}
  
	"Job" >> result2; 
	std::cout << result2 << std::endl;  //{Ivan, Job, NewWOrd, Petur}
}
