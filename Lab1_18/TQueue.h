#pragma once
#include<iostream>

#include"Header.h"
class TQueue {
private:
	double* queue;				//������ � �������
	int count;					//������� ���������
public:
	TQueue();					//����������� �� ���������
	TQueue(const TQueue& object);//����������� �����������
	~TQueue();					//����������
	void push(const double&);	//�������� ������� � �������
	double pop();				//������� ������� �� �������
	bool isEmpty() const;		//������ �� �������?
	void print()const;			//�����
};

//���������� �����
static istream& operator>>(istream& in, TQueue& object)
{
	string i="";
	in >> i;
	if (ifNumber(i))						//��������� ����� ��� ���
	{
		double item = stringToDouble(i);	//����������� ������ � �����
		object.push(item);					//��������� � �������
		return in;
	}
	cout << "�� ����� �� �����. ������� ����: ";
	in >> object;							//��������� ����, ���� �� ����� �����
	return in;
}

