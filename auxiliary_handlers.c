#include "main.h"
#include<stdlib.h>
#include<unistd.h>
/**
 * _strlen - determines string length
 * @str: string
 * Return: length of a string
 */
int _strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0' && (str[i] != '%' || str[i] != '\\'))
	{
		i++;
	}
	return (i);
}
/**
 * _putchar - prints a character
 * @c: character to be printed
 * Return: Nothing
 */
void _putchar(void *c)
{
	write(1, c, 1);
}
/**
 * rev_string - reverses the order of a string
 * @str: string to be reversed
 * Return: Reversed string
 */
char *rev_string(char *str)
{
	int len = _strlen(str), i, h = len - 1;
	char *buffer = (char *)malloc(len * sizeof(char));

	for (i = 0; i < len; i++)
	{
		buffer[i] = str[h];
		h--;
	}
	buffer[i + 1] = '\0';
	return (buffer);
}
/**
 * rot13 - encrypts a string using the rot13 cipher
 * @str: string to be encrypted
 * Return: Encrypted string
 */
char *rot13(char *str)
{
	int ascii, i, len = _strlen(str);
	char buffer;
	char *str_buffer = (char *)malloc(sizeof(char) * len);

	for (i = 0; str[i] != '\0'; i++)
	{
		ascii = (int)(str[i]);
		if (ascii >= 65 && ascii <= 90)
		{
			ascii = (ascii <= 78) ? ascii + 13 : ascii - 13;
			buffer = (char)ascii;
			str_buffer[i] = buffer;
		}
		else
		{
			if (ascii >= 97 && ascii <= 122)
			{
				ascii = (ascii <= 110) ? ascii + 13 : ascii - 13;
				buffer = (char)ascii;
				str_buffer[i] = buffer;
			}
		}
	}
	return (str_buffer);
}
/**
 * pointer_handler - prints the address of a particular
 * variable
 * @n: variable
 * Return: Nothing
 */
void pointer_handler(unsigned int n)
{
	char c;
	int a;

	if (n < 16)
	{
		a = ((n % 16) + 48);
		a = (a >= 58 && a <= 63) ? a + 7 : a + 0;
		c = (char)a;
		_putchar(&c);
	}
	else
	{
		pointer_handler(n / 16);
		a = ((n % 16) + 48);
		a = (a >= 58 && a <= 63) ? a + 7 : a + 0;
		c = (char)a;
		_putchar(&c);
	}
}
