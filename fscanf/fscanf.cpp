// fscanf.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#pragma warning(disable: 4996)

using namespace std;

int fscanf_my(FILE *stream, char *format, ...)
{
	int i = 0;
	int count = 0;

	format
	va_list agrs; //%d %s
	//va_start(args, )
	while (format[i])
	{
		if (format[i] == '%')
		{
			switch (format[i])
			{
			case 's':
				i++;
				break;
			case 'd': break;
			default:
				i++;
				break;
			}
		}
		else
		{
			cout << "Error";
			break;
		}
	}

	return 0;
}

int main()
{
	int f = 0;
	char s[100];
	FILE *fp;
	fp = fopen("C:\\Users\\Oleg\\Desktop\\Projects\\C++\\1\\fscanf\\fscanf\\Debug\\data.txt", "r+");

	cout << fscanf(fp, "%s %d", s, &f);

	fclose(fp);
    return 0;
}

