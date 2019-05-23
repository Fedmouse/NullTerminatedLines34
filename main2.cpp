#include<iostream>
#include<Windows.h>
using namespace std;

void InputLine(char szStr[], const int n);
int  StrLen(char szStr[]);
void UpperCase(char szStr[]);	
void LowerCase(char szStr[]);
void SeloStyle(char szStr[]);
void Capitalize(char szStr[]);
void Shrink(char szStr[]);
bool isPalindrome(char szStr[]);
bool isNumber(char szStr[]);
bool isHexNumber(char szStr[]);
void RemoveSpaces(char szStr[]);
int StringToInt(char szStr[]);

void main()
{
	setlocale(LC_ALL, "");
	system("CHCP 1251");
	system("CLS");
	/*char szStr[] = {'H', 'e', 'l', 'l', 0};
	cout << szStr << endl;
	char szStr1[] = "Hell";
	cout << szStr1 << endl;*/
	const int n = 50;	//Размер строки
	char szStr[n] = {};
	cout << "Введите строку: ";
	//InputLine(szStr, n);
	//cin >> szStr;
	cin.getline(szStr, n);
	cout << szStr << endl;
	cout << sizeof(szStr) << endl;
	cout << StrLen(szStr) << endl;
	/*UpperCase(szStr);
	LowerCase(szStr);
	Capitalize(szStr);*/
	Shrink(szStr);
	cout << isPalindrome(szStr) << endl;
	cout << isNumber(szStr) << endl;
	cout << isHexNumber(szStr) << endl;
	cout << StringToInt(szStr) << endl;
}

void InputLine(char szStr[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(szStr, n);
	SetConsoleCP(867);
}

int  StrLen(char szStr[])
{
	int a = 0;
	for (; szStr[a]; a++);
	return a;
}

void UpperCase(char szStr[])
{
	for (int i = 0; szStr[i]; i++)if(szStr[i]>='a' && szStr[i]<= 'z'||szStr[i] >= 'а' && szStr[i] <= 'я') szStr[i] -= 32;
	cout << szStr << endl;
}

void LowerCase(char szStr[])
{
	for (int i = 0; szStr[i]; i++)if(szStr[i]>='A' && szStr[i]<='Z'|| szStr[i] >= 'А' && szStr[i] <= 'Я')szStr[i] += 32;
	cout << szStr << endl;
}

void SeloStyle(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
	{
		if (i % 2 == 0)
		{
		   if (szStr[i] >= 'a' && szStr[i] <= 'z')szStr[i] -= 32;
		}
		else
		{
			if (szStr[i] >= 'A' && szStr[i] <= 'Z') szStr[i] += 32;
		}
		if (szStr[i] == 'a' || szStr[i] == 'A') szStr[i] = '@';
		if (szStr[i] == 's' || szStr[i] == 'S') szStr[i] = '$';
		if (szStr[i] == 'i' || szStr[i] == 'I') szStr[i] = '1';
		if (szStr[i] == ' ') szStr[i] = '_';
	}
	cout << "Ваш никнейм:  "<<"/\\/\\/\\_" << szStr <<"_/\\/\\/\\"<< endl;
}

void Capitalize(char szStr[])
{
	
	for (int i = 0; szStr[i]; i++)
	{
		if(i==0 && (szStr[i] >= 'a' && szStr[i] <= 'z' || szStr[i] >= 'а' && szStr[i] <= 'я'))  szStr[i] -= 32;
		if(szStr[i] == ' '&&(szStr[i + 1] >= 'a' && szStr[i + 1] <= 'z' || szStr[i + 1] >= 'а' && szStr[i + 1] <= 'я')) szStr[i + 1] -= 32;
	}
	cout << szStr << endl;
}

void Shrink(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
	{
		while (szStr[i] == ' ' && szStr[i+1] == ' ')
		{
			for (int j = i; szStr[j]; j++)
			{
				szStr[j] = szStr[j + 1];
			}
		}
   }
	cout << szStr << endl;
}

bool isPalindrome(char szStr[])
{
	int size = StrLen(szStr);
	char* buffer = new char[size + 1]{};
	for (int i = 0; i < size; i++)buffer[i] = szStr[i];
	LowerCase(buffer);
	RemoveSpaces(buffer);
	size = StrLen(buffer);
	for (int i = 0; i<size/2; i++)
	{
		if (buffer[i] != buffer[size -i-1])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	 return true;
}

bool isNumber(char szStr[])
{
	if (szStr[0] >= '0' && szStr[0] <= '9' || szStr[0] == '-' || szStr[0] == '+');
	else
	{
		return false;
	}
	for (int i = 1; szStr[i]; i++)
	{
		if (szStr[i] >= '0' && szStr[i] <= '9');
		else
		{
			return false;
		}
	}
	return true;
}

bool isHexNumber(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
	{
		if (szStr[i] >= '0' && szStr[i] <= '9' || szStr[i] >= 'a' && szStr[i] <= 'f' || szStr[i] >= 'A' && szStr[i] <= 'F');
		else
		{
			return false;
		}
	}
	return true;
}

void RemoveSpaces(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
	{
		while (szStr[i] == ' ')
		{
			for (int j = i; szStr[j]; j++)
			{
				szStr[j] = szStr[j + 1];
			}
		}
	}
	cout << szStr << endl;
}

int StringToInt(char szStr[])
{
	if (!isNumber(szStr))return 0;
	int decimal = 0;
	int i=0;
	if (szStr[0] == '-' || szStr[0] == '+')
	{
		i = 1;
	}
	for (; szStr[i]; i++)
	{
		decimal += (szStr[i] - 48);
		decimal *= 10;
	}
	decimal /= 10;
	if (szStr[0] == '-')
	{
		decimal = -decimal;
	}
	return decimal;
}