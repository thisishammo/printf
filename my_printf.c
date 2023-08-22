#include<stdarg.h>
#include<stdlib.h>
#include "main.h"
/**
 * _printf - prints strings according to a specific format
 * @f: contains the strings to be printed plus the format specifiers
 * Return: string length
 */
int _printf(const char *f, ...)
{
	char *c, *l;
	char slash = '\\', x = 'x', buffer;
	int i, len = _strlen(f), p, ascii, n, count = -1;
	unsigned int a;

	va_list arg;

	va_start(arg, f);
	for (i = 0; i < len; i++)
	{
		if (f[i - 1] == '%' && f[i] == 'c')
		{
			c = va_arg(arg, char *);
			_putchar(&c);
		}
		else
		{
			if (f[i - 1] == '%' && f[i] == 's')
			{
				c = va_arg(arg, char *);
				for (p = 0; c[p] != '\0'; p++)
				{
					buffer = c[p];
					_putchar(&buffer);
				}
			}
			else
			{
				if (f[i - 1] == '%' && (f[i] == 'd' || f[i] == 'i'))
				{
					n = va_arg(arg, int);
					number_handler(n);			
				}
				else
				{
					if (f[i - 1] == '%' && f[i] == 'b')
					{
						n = va_arg(arg, int);
						binary_handler(n);			
					}
					else
					{
						if (f[i - 1] == '%' && f[i] == 'o')
						{
							n = va_arg(arg, int);
							octal_handler(n);			
						}
						else
						{
							if ((f[i - 1] == '%' && (f[i] == 'x')) || (f[i] == 'X'))
							{
								if (f[i] == 'x')
								{
									n = va_arg(arg, int);
									hex_handler(n, 0);
								}
								else
								{
									n = va_arg(arg, int);
									hex_handler(n, 1);
								}
							}
							else
							{
								if (f[i - 1] == '%' && f[i] == 'u')
								{
									a = va_arg(arg, unsigned int);
									unsigned_handler(a);	
								}
								else
								{
									if (f[i - 1] == '%' && f[i] == 'r')
									{
										c = va_arg(arg, char *);
										l = rev_string(c);
										for (p = 0; l[p] != '\0'; p++)
										{
											buffer = l[p];
											_putchar(&buffer);
										}
									}
									else
									{
										if (f[i - 1] == '%' && f[i] == 'R')
										{
											c = va_arg(arg, char *);
											l = rot13(c);
											for (p = 0; l[p] != '\0'; p++)
											{
												buffer = l[p];
												_putchar(&buffer);
											}
										}
										else
										{
											if (f[i - 1] == '%' && f[i] == 'p')
											{
												a = va_arg(arg, unsigned int);
												pointer_handler(a);
											}
											else
											{
												if (f[i - 1] == '%' && f[i] == 'S')
												{
													c = va_arg(arg, char *);
													for (p = 0; c[p] != '\0'; p++)
													{
														buffer = c[p];
														ascii = (int)buffer;
														if ((ascii > 0 && ascii < 32) || ascii >= 127)
														{
															_putchar(&slash);
															_putchar(&x);
															pointer_handler(ascii);
														}
														else
														{
															_putchar(&buffer);
														}
													}
												}
												else
												{
													if (f[i] == '%' && (f[i + 1] == 'c' || f[i + 1] == 's' || f[i + 1] == 'd' || f[i + 1] == 'i' || f[i + 1] == 'b' || f[i + 1] == 'o' || f[i + 1] == 'x' || f[i + 1] == 'X' || f[i + 1] == 'u' || f[i + 1] == 'r' || f[i + 1] == '%' || f[i + 1] == 'S' || f[i + 1] == 'p' || f[i + 1] == 'R'))
													{
														continue;
													}
													else
													{
														buffer = f[i];
														_putchar(&buffer);
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	va_end(arg);
	i = 0;
	while (f[i] != '\0')
	{
		i++;
		count = ((f[i] == '%' || f[i] == '\\') && f[i - 1] != '\\') ? count + 1 : count + 0;
	}
	a = (count != -1) ? i - count : i;
	return (a);
}
