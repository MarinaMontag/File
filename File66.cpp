// File66.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Дан строковый файл. Создать новый строковый файл, в котором строки из исходного файла располагались бы в 
//лексикографическом порядке, то есть по возрастанию кодов их символов, начиная с первого символа.

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
#pragma warning(disable : 4996)

const int str_size = 100;

int amount_of_symbols(FILE*f)
{

	fseek(f, 0, SEEK_END);
	int len = ftell(f);
	return len;
}
char* record(FILE*f)
{
	char*str = new char[str_size];
	fread(str, sizeof(char), amount_of_symbols(f), f);
	fclose(f);
	return str;
}


char* sort(FILE*f)
{
	int a;
	char*str = record(f);
	for(int j=1;j<strlen(str);j++)
	for (int i = 0; i < strlen(str)-j; i++) {
		if ((int)str[i] > (int)str[i + 1])
		{
			a = str[i];
			str[i] = str[i + 1];
			str[i + 1] = a;
		}
	}
	return str;
}


int main()
{
	FILE*f1 = fopen("file1.txt", "rb");
	FILE*f2 = fopen("file2.txt", "wb");
	fwrite(sort(f1), sizeof(char), amount_of_symbols(f1), f2);
	fclose(f1);
	fclose(f2);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
