/*
Lab1_18
����� ������� ����� �������������� ����� (����� � ���������� �����)  � ��������� ����� C. ��������� �������, ���������� ������� ��� ��������, ������� ����� C, � ����� ������� ����� C (���� � ������ ����������� �, �� ��� �������� � ���).
*/

#include "TQueue.h"

int main()
{
    setlocale(LC_ALL, "Russian");                           //��������� ��� ��� ��������
    TQueue object;                                          //��������� ������ ������� (������)
    string strC;
    int C;
    cout << "������� �" << endl;
    cin >> strC;                                            //������ ������
    C = inVariable(strC);                                   //��������� � ������� � Header.h
    cout << "������� ���������� ����� � ������" << endl;
    int count = 0;
    string strCount;
    cin >> strCount;                                        //������ ���-�� �����
    for (int i = 0; i < strCount.length(); ++i)             //���� ���������� ������� inVariable
    {
        if (strCount[i] != 46 && (strCount[i] <= 48 || strCount[i] >= 57))//�� ��������� ������������� �����
        {
            cout << "��� �� �����, ��������� ����:";
            cin >> strCount;
            i = -1;
        }
    }
    cout << endl;
    count = stoi(strCount);

    for (int i = 0; i < count; ++i)                 //���� ������ �����
    {
        cout << "������� �����: ";
        cin >> object;
    }
    cout << "-----------------\n";

    TQueue objectMax;                               //������� ��� ����� ������ �
    double copy = 0;
    while (!object.isEmpty())
    {
        copy = object.pop();                        //����������� ������� �� �������
        if (copy > C)
        {
            objectMax.push(copy);                   //���� ����� ������, ������ � ������� � ������� ������ �
        }
        else if (copy < C)
        {
            cout << copy << endl;                   //���� ������ - �������
        }
        else
        {
            double copyC = C;
            copyC = abs(copyC);
            string str = to_string(C) + " ";        //��� ����� � �� ����� ������ ����� ������
            while (copyC--) cout << str;            //������� � ��� ����� �
            cout << endl;
        }
    }
    while (!objectMax.isEmpty())                    //������� ����� �
    {
        copy = objectMax.pop();
        cout << copy << endl;
    }
}