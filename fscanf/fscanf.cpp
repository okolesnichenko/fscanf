// fscanf.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#pragma warning(disable: 4996)

using namespace std;

int fscanf_my(FILE *stream, const char *format, ...)
{
	int i = 0, j = 0, m = 0, l = 0,
		d = 0;
	double f = 0;
	int count = 0;

	char buffer[20];
	char word[20];

	//Получим содержимое файла в буфер
	fgets(buffer, 20, stream);

	//Список аргументов
	va_list arguments;
	 
	//Инициализация по явному параметру format
	va_start(arguments, format);

	//Рассмотрим все строки .формата 
	//Форматы в моем методе %d %s %f
	while ((bool)format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 's':
				m = 0;
				//Выделим память под слово
				word[0]='\0';
				//Split
				while (buffer[j] != ' ' & buffer[j] != '\0')
				{
					word[m] = buffer[j];
					j++;
					m++;
				}
				word[m] = '\0';
				//Можно и с помощью memcpy
				strcpy(va_arg(arguments, char *), word);
				count++;
				break;
			case 'd':
				m = 0;
				word[0] = '\0';
				while (buffer[j] != ' ' & buffer[j] != '\0')
				{
					word[m] = buffer[j];
					m++;
					j++;
				}
				word[m] = '\0';
				//d = atoi(word);
				while (word[l])
				{
					if (isdigit(word[l])) {
						d = 10*d + (word[l] - '0');
					}
					l++;
				}
				memcpy(va_arg(arguments, int *), &d, sizeof(int));
				count++;
				break;
			case 'f':
				m = 0;
				word[0] = '\0';
				while (buffer[j] != ' ' & buffer[j] != '\0')
				{
					word[m] = buffer[j];
					m++;
					j++;
				}
				word[m] = '\0';
				f = strtod(word, NULL);
				memcpy(va_arg(arguments, double *), &f, sizeof(double));
				count++;
				break;
			default:
				//..
				break;
			}
			//счетчик
			j++;
		}
		//
		i++;
	}

	va_end(arguments);

	return count;
}

int main()
{
	int d = 0;
	double f = 0;
	char s[20] = "";
	char v[20] = "";
	FILE *fp;
	//C:\\Users\\Oleg\\Desktop\\Projects\\C++\\1\\fscanf\\fscanf\\Debug\\data.txt
	fp = fopen("C:\\Users\\Oleg\\Desktop\\Projects\\C++\\1\\fscanf\\fscanf\\Debug\\data.txt", "r+");

	//cout << fscanf(fp, "%s %s %d", v, s, &d);
	cout << fscanf_my(fp, "%s %s %d %f", s, v, &d, &f);

	fclose(fp);
	return 0;
}
