#pragma once
#include <string>
#include <sstream>
using namespace std;
//перевод строки в дробь
static double stringToDouble(const string s)
{
	istringstream i(s);				//объект, который нужен для передачи строки в различные переменные
	double str;
	i >> str;
	return str;
}
//проверка число или нет
static bool ifNumber(string str) {
	for (char el : str)
	{
		if (el != 46 && el != 45 && (el < 48 || el > 57))	//если символ не точка или не число
		{
			return false;									//возвращаем ложь, или проверяем до конца
		}
	}
	return true;
}
//проверка число или нет с повтором ввода
static double inVariable(string str) {			
	while (!ifNumber(str))									//число или нет?
	{
		cout << "Это не число, повторите ввод: ";
		cin >> str;											//ввод числа
		cout << endl;
	}
	return stoi(str);
}