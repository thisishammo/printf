#include"main.h"
/**
 * binary_handler - prints a number in binary
 * @n: number to be converted to binary
 * Return: nothing
 */
void binary_handler(int n)
{
	int ascii;
	char c;

	if (n < 2)
	{
	}
	else
	{
		binary_handler(n / 2);
		ascii = ((n % 2) + 48);
		c = (char)ascii;
		_putchar(&c);
	}
}
/**
 * number_handler - prints a number in decimal form
 * @n: number to be printed
 * Return: nothing
 */
void number_handler(int n)
{
	int ascii;
	char neg = '-';
	char quotient;

	if (n < 0)
	{
		_putchar(&neg);
		n *= -1;
		if (n <= 9)
		{
			ascii = ((n % 10) + 48);
			quotient = (char)ascii;
			_putchar(&quotient);
		}
		else
		{
			number_handler(n / 10);
			ascii = ((n % 10) + 48);
			quotient = (char)ascii;
			_putchar(&quotient);
		}
	}
	else
	{
		if (n <= 9)
		{
			ascii = ((n % 10) + 48);
			quotient = (char)ascii;
			_putchar(&quotient);
		}
		else
		{
			number_handler(n / 10);
			ascii = ((n % 10) + 48);
			quotient = (char)ascii;
			_putchar(&quotient);
		}
	}
}
/**
 * octal_handler - prints a number in octal form
 * @n: number to be converted to octal
 * Return: nothing
 */
void octal_handler(unsigned int n)
{
	unsigned int ascii;
	char c;

	if (n < 8)
	{
		ascii = ((n % 8) + 48);
		c = (char)ascii;
		_putchar(&c);
	}
	else
	{
		octal_handler(n / 8);
		ascii = ((n % 8) + 48);
		c = (char)ascii;
		_putchar(&c);
	}
}
/**
 * hex_handler - prints a number in hexadecimal
 * @n: number to be converted to hexadecimal
 * @state: the state either in capital
 * Return: nothing
 */
void hex_handler(unsigned int n, int state)
{
	int ascii;
	char c;

	if (n < 16)
	{
		ascii = ((n % 16) + 48);
		if (ascii >= 58 && ascii <= 63)
		{
			ascii = (state != 0) ? ascii + 7 : ascii + 39;
			c = (char)ascii;
			_putchar(&c);
		}
		else
		{
			c = (char)ascii;
			_putchar(&c);
		}
	}
	else
	{
		hex_handler(n / 16, state);
		ascii = ((n % 16) + 48);
		if (ascii >= 58 && ascii <= 63)
		{
			ascii = (state != 0) ? ascii + 7 : ascii + 39;
			c = (char)ascii;
			_putchar(&c);
		}
		else
		{
			c = (char)ascii;
			_putchar(&c);
		}
	}
}
/**
 * unsigned_handler - prints a unsigned numbers
 * @n: number to be printed
 * Return: nothing
 */
void unsigned_handler(unsigned int n)
{
	unsigned int ascii;
	char c;

	if (n < 10)
	{
		ascii = ((n % 10) + 48);
		c = (char)ascii;
		_putchar(&c);
	}
	else
	{
		unsigned_handler(n / 10);
		ascii = ((n % 10) + 48);
		c = (char)ascii;
		_putchar(&c);
	}
}
