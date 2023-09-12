/*
Lab1_18
Пусть имеется набор действительных чисел (целые и десятичные дроби)  и некоторое число C. Используя очередь, напечатать сначала все элементы, меньшие числа C, а затем большие числа C (если в наборе встретиться С, то его выводить С раз).
*/

#include "TQueue.h"

int main()
{
    setlocale(LC_ALL, "Russian");                           //подключим рус для удобства
    TQueue object;                                          //экземпляр класса очередь (пустой)
    string strC;
    int C;
    cout << "Введите С" << endl;
    cin >> strC;                                            //вводим строку
    C = inVariable(strC);                                   //подробнее о функции в Header.h
    cout << "Введите количестов чисел в наборе" << endl;
    int count = 0;
    string strCount;
    cin >> strCount;                                        //вводим кол-во чисел
    for (int i = 0; i < strCount.length(); ++i)             //цикл аналогичен функции inVariable
    {
        if (strCount[i] != 46 && (strCount[i] <= 48 || strCount[i] >= 57))//но исключает отрицательные числа
        {
            cout << "Это не число, повторите ввод:";
            cin >> strCount;
            i = -1;
        }
    }
    cout << endl;
    count = stoi(strCount);

    for (int i = 0; i < count; ++i)                 //ввод набора чисел
    {
        cout << "Введите число: ";
        cin >> object;
    }
    cout << "-----------------\n";

    TQueue objectMax;                               //очередь для чисел больше С
    double copy = 0;
    while (!object.isEmpty())
    {
        copy = object.pop();                        //вытаскиваем элемент из очереди
        if (copy > C)
        {
            objectMax.push(copy);                   //если число больше, вносим в очерель с числами больше С
        }
        else if (copy < C)
        {
            cout << copy << endl;                   //если меньше - выводим
        }
        else
        {
            double copyC = C;
            copyC = abs(copyC);
            string str = to_string(C) + " ";        //все числа С на одной строке через пробел
            while (copyC--) cout << str;            //выводим С раз число С
            cout << endl;
        }
    }
    while (!objectMax.isEmpty())                    //выводим числа С
    {
        copy = objectMax.pop();
        cout << copy << endl;
    }
}