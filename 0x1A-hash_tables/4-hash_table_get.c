#include "hash_tables.h"

/**
 * hash_table_get - retrieve a value associated with a key
 * @ht: const pointer - hash table
 * @key: const char - search key
 *
 * Description: This function that retrieves a value
 * associated with a key
 * Return: value or NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int i;
	hash_node_t *node = NULL;

	if (!ht || !key || !strcmp(key, ""))
		return (NULL);

	i = key_index((const unsigned char *)key, ht->size);
	node = (ht->array)[i];

	while (node)
	{
		if (!strcmp(node->key, (char *)key))
			return (node->value);
		node = node->next;
	}

	return (NULL);
}
