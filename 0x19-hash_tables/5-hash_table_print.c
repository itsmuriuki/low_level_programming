#include "hash_tables.h"
/**
 *hash_table_print - prints a hash table in the order they appear
 *in the hash table array
 *@ht: pointer to the hash table
 *
 *Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int iterator = 0;
	hash_node_t *node;
	int multiplenodes = 0;

	if (ht == NULL)
		printf("{}\n");

	if (ht->size == 0 || ht->array == NULL)
		printf("{}\n");

	printf("{");
	while (iterator < ht->size)
	{
		node = ht->array[iterator];
		if (node != NULL)
		{
			if (multiplenodes == 0)
			{
				printf("'%s': '%s'", node->key, node->value);
				multiplenodes = 1;
			}
			else
				printf(", '%s': '%s'", node->key, node->value);
		}
		iterator++;
	}
	printf("}\n");
}
