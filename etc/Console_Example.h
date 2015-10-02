#pragma once

#ifdef _WIN32 || _WIN64
	#include <Windows.h>
	#pragma warning (disable : 4996)
#endif

#include <string>
#include <iostream>
namespace console
{
	void set_cursor(int x, int y)
	{
		COORD pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	void set_color(int color, int bgcolor)
	{
		if (color)
			color &= 0xf;
		if (bgcolor)
			bgcolor &= 0xf;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
	}
	void clear()
	{
		system("cls");
	}
	void set_size(const unsigned int cols, const unsigned int lines)
	{
		std::string str = "mode con:cols=" + cols;
		str += " lines=" + lines;
		system(str.c_str());
	}

	void print_diamond(int num)
	{
		for (int i = 0; i < num * 2 - 1; printf("\n", i++))
			for (int j = 0; j < num + (i < num ? i : 2 * (num - 1) - i); printf(j < num - 1 - (i < num ? i : 2 * (num - 1) - i) ? " " : "*", j++));
	}
	void print_increase(int num)
	{
		for (int i = 0; i <= num; printf("\n", i++))
			for (int j = 0; j < i; printf("*", j++));
	}
	void print_decrease(int num)
	{
		for (int i = num; i >= 0; printf("\n", i--))
			for (int j = 0; j < i; printf("*", j++));
	}
	void print_space_increase(int num)
	{
		for (int i = 0; i < num; printf("\n", i++))
			for (int j = 0; j < num; j++<num - i - 1 ? printf(" ") : printf("*"));
	}
	void print_space_decrease(int num)
	{
		for (int i = 0; i < num; printf("\n", i++))
			for (int j = 0; j <= num; j++<num - i ? printf(" ") : printf("*"));
	}
}
