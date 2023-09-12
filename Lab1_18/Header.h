#pragma once
#include <string>
#include <sstream>
using namespace std;
//������� ������ � �����
static double stringToDouble(const string s)
{
	istringstream i(s);				//������, ������� ����� ��� �������� ������ � ��������� ����������
	double str;
	i >> str;
	return str;
}
//�������� ����� ��� ���
static bool ifNumber(string str) {
	for (char el : str)
	{
		if (el != 46 && el != 45 && (el < 48 || el > 57))	//���� ������ �� ����� ��� �� �����
		{
			return false;									//���������� ����, ��� ��������� �� �����
		}
	}
	return true;
}
//�������� ����� ��� ��� � �������� �����
static double inVariable(string str) {			
	while (!ifNumber(str))									//����� ��� ���?
	{
		cout << "��� �� �����, ��������� ����: ";
		cin >> str;											//���� �����
		cout << endl;
	}
	return stoi(str);
}