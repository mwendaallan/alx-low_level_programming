#include "hash_tables.h"

/**
 * key_index - give the index of a key
 * @key: (const unsigned char) the key
 * @size: (unsigned long int) size of the array of the hash table
 *
 * Description: This function gives the index of a key
 * Return: key index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int i;

	i = hash_djb2(key);

	return (i % size);
}
