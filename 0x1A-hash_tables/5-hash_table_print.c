#include "hash_tables.h"

/**
* hash_table_print - prints a hash table
* @ht: hash table
*
* Description: This function prints a hash table
* Return: 0
**/
void hash_table_print(const hash_table_t *ht)
{
	unsigned int i, byts, n_byts;
	hash_node_t **array = NULL;
	hash_node_t *t = NULL;
	char *key, *value;

	if (ht == NULL)
		return;
	array = ht->array;
	printf("{");

	n_byts = 0;
	for (i = 0; i < ht->size; i++)
	{
		if (array[i])
			n_byts++;
	}

	byts = 0;
	for (i = 0; i < ht->size; i++)
	{
		if (array[i])
		{
			t = array[i];
			key = array[i]->key;
			value = array[i]->value;
			while (array[i])
			{
				printf("'%s': '%s'", key, value);
				array[i] = array[i]->next;
				if (array[i])
					printf(", ");
			}
			if (byts != n_byts - 1)
				printf(", ");
			array[i] = t;
			byts++;
		}
	}

	printf("}\n");
}
