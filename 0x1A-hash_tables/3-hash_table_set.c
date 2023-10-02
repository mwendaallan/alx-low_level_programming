#include "hash_tables.h"

/**
 * create_node - create a node
 * @key: const char - key
 * @value: const char - value
 *
 * Description: This function creates a node to
 * be added to the hash table
 * Return: A new node
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = (hash_node_t *)malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	if (node->key == NULL)
		return (NULL);

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		return (NULL);
	}
	node->next = NULL;

	return (node);
}

/**
 * check_key - check for key and replace
 * @ht:	hash table
 * @key: char var
 * @value: char var
 * @idx: int var
 *
 * Description: This function checks if key exist
 * and replaces with value
 * Return: O if is is wrong or 1 if ist is success
 */
int check_key(hash_table_t *ht, char *key, char *value, int idx)
{
	hash_node_t *tmp;

	tmp = ht->array[idx];
	do {
		if (strcmp(key, tmp->key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			if (tmp->value == NULL)
				return (1);
			return (1);
		}
		tmp = tmp->next;
	} while (tmp);
	return (0);
}

/**
 * hash_table_set - insert elements to the hash table
 * @ht:	hash table
 * @key:	string key
 * @value:  string value
 *
 * Description: This function added a new node at the beginning
 * of a hash table
 * Return:	0 or 1
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *n;
	int index, node;
	hash_node_t *tmp;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	if (ht->array[index] != NULL)
	{
		node = check_key(ht, (char *)key, (char *)value, index);
		if (node == 1)
			return (1);
	}

	n = create_node(key, value);
	if (n == NULL)
		return (0);
	if (ht->array[index] == NULL)
	{
		ht->array[index] = n;
		return (1);
	}

	tmp = ht->array[index];
	ht->array[index] = n;
	n->next = tmp;

	return (1);
}
