#include "3-calc.h"
#include "function_pointers.h"

/**
 * get_op_func - pointer to th efunction that corresponds to the
 * op as a parm.
 * @s: operator passed as argument
 *
 * Return: 0 on success
 *
 */

int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	while (i < 5)
	{
		if (s[0] != '\0' && *(ops[i].op) == *s)
			return (ops[i].f);
		i++;
	}

	i = 0;
	return (0);
}
