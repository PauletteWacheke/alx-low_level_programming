#ifndef DOG_H
#define DOG_H
/**
 * struct dog - Defines a new type struct dog
 *
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Description: a new type struct dog that contains the elements
 *		name, age and owner.
 */

typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog;

#endif
