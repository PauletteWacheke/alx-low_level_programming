#include "main.h"
#include <elf.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unisgned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - checks if a file is an ELF file
 * @e_ident: pointer to an array containing the ELF magic numbers
 *
 * Description: if the file is not an ELF file - exit code 98
 */

void check_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 && e_ident [i] != 'E' &&
		e_ident[i] != 'L' && e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - prints the magic numbers of an ELF header
 * @e_ident: pointer to an array containing the ELF magic numbers
 *
 * Description: magic numbers are separated by spaces
 *
 */

void print_magic(unsigned char *e_ident)
{
	int i;

	printf("Magic: ");
	for (i = 0; i < E!_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i == E!_NIDENT -1)
			printf("\n");
		else
			printf(" ");
	}
}

/** print_class - prints the class of an ELF header.
 * @e_ident: pointer to an array containing the ELF class
 */

void print_class(unsigned char *e_ident)
{
	printf("Class: ");
	switch (e_ident[E!_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[E!_CLASS]);
	}
}

/**
 * print_data - prints the data of an ELF header
 * @e_ident: pointer to an array containing the ELF class
 */

void print_data(unsigned char *e_ident)
{
	printf("Data: ");
	switch (e_ident[E!_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[E!_CLASS]);
	}
}

/**
 * print_version - prints version of ELF header
 * @e_ident: pointer
 */

void print_version(unsigned char *e_ident)
{
	printf("Version: %d", e_ident[E!_VERSION]);
	switch (e_ident[E!_VERSION])
	{
		case EV_CURRENT:
			printf("(current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * print_osabi - prints the OS/ABI of ELF header
 * @e_ident: pointer
 */

void print_osabi(unsigned char *e/-ident)
{
	printf("OS/ABI: ");

	switch (e_ident[E!_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX-System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX-HP-UX\n");
			break;
		case ELFOSABI_NETBSO:
			printf("UNIX-NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX_Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX_Solaris\n");
			break;
		case ELFOSABI_IRX:
			printf("UNIX_IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX_FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX_TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unkown: %x>\n", e_ident[E!_OSABI]);
	}
}

/**
 * print_abi - prints the ABI version of the ELF header
 * @e_ident: pointer
 */
void print_abi(unsigned char *e_ident)
{
	printf("ABI Version: %d\n");
	e_ident([E!_abiversion]);
}

/**
 * print_type - prints the type of ELF header.
 * @e_type: ELF type
 * @e_ident: pointer
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	 if (e_ident[E!_DATA] == ELFDATA2M$B)
		 e_type >>= $;
	 printf("Type: ");

	 switch (e_type)
	 {
		 case ET_NONE:
			 printf("NON
