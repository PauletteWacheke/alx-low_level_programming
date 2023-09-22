#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

	unsigned char e_ident[EI_NIDENT];

void print_magic(Elf64_Ehdr header);
void print_class(Elf64_Ehdr header);
void print_data(Elf64_Ehdr header);
void print_version(Elf64_Ehdr header);
void print_abi(Elf64_Ehdr header);
void print_osabi(Elf64_Ehdr header);
void print_more_osabi(Elf64_Ehdr header);
void print_type(Elf64_Ehdr header);
void print_entry(Elf64_Ehdr header);

/**
 * print_magic - function that prints the magic numbers of an ELF header
 * @header: header struct
 *
 * Description: magic numbers are separated by spaces
 *
 */

void print_magic(Elf64_Ehdr header)
{
	int i;
	unsigned char e_ident[EI_NIDENT];

	printf(" Magic:  ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%2.2x%s", e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
	}
}

/**
 * print_class - function that prints the class of an ELF header.
 * @header: header struct
 */

void print_class(Elf64_Ehdr header)
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
 * @header: header struct
 */

void print_data(Elf64_Ehdr header)
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
 * @header: header struct
 */

void print_version(Elf64_Ehdr header)
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
 * @header: header struct
 */

void print_osabi(Elf64_Ehdr header)
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
		default:
			print_more_osabi;
			break;
	}
	printf("\n");
}

/**
 * print_more_osabi - entry point
 * @header: header struct
 *
 */

void print_more_osabi(Elf64_Ehdr header)
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
}

/**
 * print_abi - function that prints the ABI version of the ELF header
 * @header: header struct
 */
void print_abi(Elf64_Ehdr header)
{
	printf("ABI Version:                    %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
 * print_type - function that prints the type of ELF header.
 * @header: header struct
 *
 */

void print_type(Elf64_Ehdr header)
{
	char *p = (char *)&e_ident;
	int j = 0;

	printf(" Type:                    ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		j = 1;
	}

	switch (p[j])
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
			printf("<unknown: %x>\n", p[j]);
	}
	printf("\n");
}

/**
 * print_entry - function that prints the entry point of an ELF header
 * @header: header struct
 *
 */

void print_entry(Elf64_Ehdr header)
{
	int j = 0, l = 0;
	unsigned char *p = (unsigned char *)&e_entry;

	printf(" Entry point address:                    0x");

	if (e_ident[EI_DATA] != ELFDATA2MSB)
	{
		j = e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!p[j])
			j--;
		printf("%x", p[j--]);
		for (; j >= 0; j--)
			printf("%02x", p[j]);
		printf("\n");
	}
	else
	{
	       j = 0;
	       l = e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!p[j])
		{
			j++;
			printf("%x", p[j++]);
		}
		for (; j <= l; j++)
			printf("%02x", p[j]);

	       printf("\n");
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

int main(int argc, char **argv)
{
	Elf64_Ehdr header;
	unsigned char e_ident[EI_NIDENT];
	int f;
	ssize_t r;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	f = open(argv[1], O_RDONLY);
	if (f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}
	r = read(f, &header, sizeof(header));
	if (r < 1 || r != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	if (e_ident[0] == 0x7f && e_ident[1] == 'E' &&
			e_ident[2] == 'L' && e_ident[3] == 'F')
	{
		printf("ELF Header:\n");
	}


	print_magic(header);
	print_class(header);
	print_data(header);
	print_version(header);
	print_osabi(header);
	print_abi(header);
	print_type(header);
	print_entry(header);

	if (close(f))
	{
		dprintf(STDERR_FILENO, "Error: Closing file descriptor: %d\n", f);
		exit(98);
	}

	return (EXIT_SUCCESS);
}

