#include "hash_tables.h"

/**
 * key_index - Provides the index of a key
 * @key: is the key
 * @size: size of the array of the hash table
 *
 * Return: The index of the key
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index_key;

	index_key = (hash_djb2(key) % size);
	return (index_key);
}
