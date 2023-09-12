#include "TQueue.h"
//Конструктор по умолчанию
TQueue::TQueue():count(0) {}
//Деструктор
TQueue::~TQueue()
{
	delete[] queue;
}
//Конструктор копирования
TQueue::TQueue(const TQueue& object)
{
	count = object.count;				//скопировать object в текущий объект
	queue = new double[count];			//выделение памяти для queue
	for (int i = 0; i < count; i++)
	{
		queue[i] = object.queue[i];		//заполнить значениями из object
	}
}
//Добавление в очередь (принимает элемент типа double)
void TQueue::push(const double& item)
{
	double* queueCopy(queue);			//переносим массив в копию
	queue = new double[count+1];		//выделяем новую память
	for (int i = 0; i < count; i++)
	{
		queue[i] = queueCopy[i];		//копируем
	}
	queue[count] = item;
	count += 1;							//добавляем item
	delete[]queueCopy;					//освобождаем память из-пд копии
}
//Удаление из очереди (возврщает элемент типа double)
double TQueue::pop() 
{
	if (count == 0)
		return 0;
	double item = queue[0];
	double* queueCopy(queue);			//переносим массив в копию
	queue = new double[--count];		//выделяем новую память
	for (int i = 0; i < count; i++)
	{
		queue[i] = queueCopy[i+1];		//копируем не с первого элемента
	}
	delete[]queueCopy;					//освобождаем память из-пoд копии
	return item;}
//Проверка на пустоту
bool TQueue::isEmpty() const 
{
	return count == 0;
}
//Вывод в консоль очереди
void TQueue::print() const
{
	for (int i = 0; i < count; ++i) 
	{
		cout << queue[i]<<" ";
	}
}
