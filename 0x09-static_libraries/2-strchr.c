#include "main.h"
/**
 * *_strchr - locates a character in a string.
 * @s: char 1 pointer
 * @c: char s
 * Return: '\0' or s
 */
char *_strchr(char *s, char c)
{
	int a;

	for (a = 0; s[a] >= '\0'; a++)
	{
		if (s[a] == c)
		{
			return (s + a);
		}
	}
	return ('\0');
}
