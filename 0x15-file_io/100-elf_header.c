#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_more_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);

/**
 * check_elf - function that checks for an ELF FILE
 * @e_ident: pointer
 */

void check_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 &&
				e_ident[i] != 'E' &&
				e_ident[i] != 'L' &&
				e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
	if (e_ident[0] == 0x7f && e_ident[1] == 'E' &&
			e_ident[2] == 'L' && e_ident[3] == 'F')
	{
		printf("ELF Header:\n");
	}
}

/**
 * print_magic - function that prints the magic numbers of an ELF header
 * @e_ident: pointer
 *
 * Description: magic numbers are separated by spaces
 *
 */

void print_magic(unsigned char *e_ident)
{
	int i;

	printf(" Magic:  ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%2.2x%s", e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
	}
}

/**
 * print_class - function that prints the class of an ELF header.
 * @e_ident: pointer
 */

void print_class(unsigned char *e_ident)
{
	printf(" Class:                    ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none");
			break;
		case ELFCLASS32:
			printf("ELF32");
			break;
		case ELFCLASS64:
			printf("ELF64");
			break;
	}
	printf("\n");
}

/**
 * print_data - function that prints the data of an ELF header
 * @e_ident: pointer
 */

void print_data(unsigned char *e_ident)
{
	printf(" Data:                    ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian");
		break;
	}
	printf("\n");
}

/**
 * print_version - function that prints version of ELF header
 * @e_ident: pointer
 */

void print_version(unsigned char *e_ident)
{
	printf(" Version:                    %d", e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)");
			break;
		case EV_NONE:
			printf("%s", "");
			break;
	}
			printf("\n");
}

/**
 * print_osabi - function that prints the OS/ABI of ELF header
 * @e_ident: pointer
 */

void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI:                    ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris");
			break;
		case ELFOSABI_AIX:
			printf("Unix - AIX");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64");
			break;
	}
	printf("\n");
}

/**
 * print_more_osabi - function that prints the OS/ABI of an ELF file
 * @e_ident: pointer
 *
 */

void print_more_osabi(unsigned char *e_ident)
{
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_MODESTO:
			printf("Nove11 - Modesto");
			break;
		case ELFOSABI_OPENBSD:
			printf("Unix - OpenBSD");
			break;
		case ELFOSABI_ARM:
			printf("ARM");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App");
			break;
		default:
			printf("<unknown: %x>", e_ident[EI_OSABI]);
			break;
	}
	printf("\n");
}

/**
 * print_abi - function that prints the ABI version of the ELF header
 * @e_ident: pointer
 */
void print_abi(unsigned char *e_ident)
{
	printf("ABI Version:                    %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
 * print_type - function that prints the type of ELF header.
 * @e_ident: pointer
 * @e_type: elf type
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_type >>= 8;
	}
	printf("  Type:                    ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
	printf("\n");
}

/**
 * print_entry - function that prints the entry point of an ELF header
 * @e_ident: pointer
 * @e_entry: elf type
 *
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address:                    ");

	if (e_ident[EI_DATA] != ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	
       if (e_ident[EI_CLASS] == ELFCLASS32)
	       printf("%#x\n", (unsigned int)e_entry);
       else
	       printf("%#lx\n", e_entry);
}

/**
 * close_elf - function that closes elf file
 * @elf: file descriptor
 *
 */

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - function that displays the information in the ELF header at the start
 *	of an elf file.
 * @argc: number of arguments
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success
 * Description: if the file is not an ELF file or function fails, exit 98
 *
 */

int main(int __attribute__((__unused__)) argc, char **argv)
{
	Elf64_Ehdr *header;
	int f, r;
	
	f = open(argv[1], O_RDONLY);
	if (f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(f);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(f, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(f);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_more_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);


	free(header);
	close_elf(f);
	return (0);
}
