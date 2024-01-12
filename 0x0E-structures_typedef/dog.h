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

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
/* dog_t *new_dog(char *name, float age, char *owner);*/
/* void free_dog(dog_t *d);*/

#endif
