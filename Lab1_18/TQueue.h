#pragma once
#include<iostream>

#include"Header.h"
class TQueue {
private:
	double* queue;				//массив с данными
	int count;					//счетчик элементов
public:
	TQueue();					//конструктор по умолчанию
	TQueue(const TQueue& object);//конструктор копирования
	~TQueue();					//деструктор
	void push(const double&);	//добавить элемент в очередь
	double pop();				//удалить элемент из очереди
	bool isEmpty() const;		//пустая ли очередь?
	void print()const;			//вывод
};

//перегрузка ввода
static istream& operator>>(istream& in, TQueue& object)
{
	string i="";
	in >> i;
	if (ifNumber(i))						//Проверяем число или нет
	{
		double item = stringToDouble(i);	//Преобразуем строку в дробь
		object.push(item);					//Добавляем в очередь
		return in;
	}
	cout << "Вы ввели не число. Повтори ввод: ";
	in >> object;							//Повторяем ввод, пока не будет число
	return in;
}

