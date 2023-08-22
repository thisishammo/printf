#ifndef MAIN_H
#define MAIN_H
int _strlen(const char *str);
void _putchar(void *c);
void binary_handler(int n);
void number_handler(int n);
void octal_handler(unsigned int n);
void hex_handler(unsigned int n, int state);
void unsigned_handler(unsigned int n);
char *rev_string(char *str);
char *rot13(char *str);
void pointer_handler(unsigned int n);
int _printf(const char *f, ...);
#endif
