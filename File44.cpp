// File44.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Даны три файла одного и того же типа, но разного размера.Заменить содержимое самого длинного файла на 
//содержимое самого короткого.


#include "pch.h"
#include <iostream>
#include <stdio.h>

using namespace std;
#pragma warning(disable : 4996)

int flen(char* name) {
	FILE*f = fopen(name, "rb");
	if (f == NULL) {
		return -1;
	}
	fseek(f, 0, SEEK_END);
	int len= ftell(f);
	fclose(f);
	return len;

}
int main()
{
	/*int len1, len2, len3;
	int num1, num2, num3;
	cin >> len1 >> len2 >> len3;*/
	

	/*cout << "Ready to write\n";
	for (int i = 0; i < len1; i++)
	{
		cin >> num1;
		fwrite(&num1, sizeof(int), 1, f1);
	}*/

	char names[3][20] = { "file1.txt" ,"file2.txt" ,"file3.txt" };
	int len[3];
	for (int i = 0; i < 3; i++) {
		len[i] = flen(names[i]);
		if (len[i] == -1)
		{
			cout << "error\n";
			return 0;
		}
		cout << len[i] << endl;
	}

	int Nmax = 0, Nmin = 0;
	for (int i = 1; i < 3; i++) {
		if (len[i] > len[Nmax]) Nmax = i;
		if (len[i] < len[Nmin]) Nmin = i;
	}
	cout << Nmax << " " << Nmin << endl;

	FILE*fw = fopen(names[Nmax], "wb");
	FILE*fr = fopen(names[Nmin], "rb");

	char*  buf = new char[len[Nmin]+1];
	fread(buf, sizeof(char), len[Nmin], fr);
	fwrite(buf, sizeof(char), len[Nmin], fw);
	fclose(fr);
	fclose(fw);

	
	
	//char str1[1000], str2[1000], str3[1000];
	
	
	/*
	char ch;
	while ((ch = getc(f1)) != EOF) {
		len1++;
		cout << ch << " ====";
	}

	cout << "len1=" << len1 << endl;*/

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
