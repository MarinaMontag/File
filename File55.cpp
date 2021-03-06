// File55.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Дана строка S0, целое число N (≤ 4) и N файлов целых чисел с именами S1, …, SN. Объединить их содержимое в новом 
//файле-архиве с именем S0, последовательно записывая в него следующие данные: размер (число эле-ментов) первого 
//исходного файла и все элементы этого файла, размер вто-рого исходного файла и все его элементы, …, размер N-го 
//исходного файла и все его элементы.

#include "pch.h"
#include <iostream>
#include <conio.h>
using namespace std;
#pragma warning(disable : 4996)

const int str_size = 100;

//int SIZE(FILE*f)
//{
//	int counter = 0;
//	char*str = new char[str_size];
//	while (!feof(f))
//	{
//		fgets(str, str_size, f);
//	}
//	for (int i = 0; i < strlen(str); i++)
//		if (str[i] == ' ')counter++;
//	counter++;
//	return counter;
//}

int amount_of_symbols(FILE*f)
{

	fseek(f, 0, SEEK_END);
	int len = ftell(f);
	return len;
}

char* record(FILE*f) 
{
	char*str = new char[str_size];
	fread(str, sizeof(char), amount_of_symbols(f),f);
	fclose(f);
	return str;
}



int main()
{
	int n = 3, num1, num2, num3;
	FILE*S1 = fopen("file1.txt", "rb");
	FILE*S2 = fopen("file2.txt", "rb");
	FILE*S3 = fopen("file3.txt", "rb");
	FILE*S = fopen("file.txt", "wb");

	int len1= amount_of_symbols(S1);
	int len2 = amount_of_symbols(S2);
	int len3 = amount_of_symbols(S3);

	fwrite(&len1, sizeof(int), 1, S);
	fwrite(record(S1), sizeof(char), len1, S);

	fwrite(&len2, sizeof(int), 1, S);
	fwrite(record(S2), sizeof(char), len2, S);

	fwrite(&len3, sizeof(int), 1, S);
	fwrite(record(S3), sizeof(char), len3, S);
	fclose(S);
	fclose(S1);
	fclose(S2);
	fclose(S3);
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
