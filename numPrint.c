#include "shell.h"

/**
  * unsignedPrint - fun print unsigned number
  * @num: number to print
  * Return: void
  */

void unsignedPrint(unsigned int num)
{
	unsigned int n = num;

	if ((n / 10) > 0)
		numPrint(n / 10);

	_putchar(n % 10 + '0');
}

/**
  * numPrint - fun print integer
  * @num: integer to print
  * Return: void
  */

void numPrint(int num)
{
	unsigned int n = num;

	if (num < 0)
	{
		_putchar('-');
		n = -n;
	}

	if ((n / 10) > 0)
		unsignedPrint(n / 10);

	_putchar(n % 10 + '0');
}
