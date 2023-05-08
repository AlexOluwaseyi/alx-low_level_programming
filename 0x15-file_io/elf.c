#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

#define MAX_ELF_FUNCTIONS 5

typedef void (*elf_func_t)(const Elf64_Ehdr *);

/**
 * print_magic - prints magic
 * @ehdr: pointer to ehdr
 */

static void print_magic(const Elf64_Ehdr *ehdr)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", ehdr->e_ident[i]);
	printf("\n");
}

/**
 * print_class - prints class
 * @ehdr: pointer to ehdr
 */

static void print_class(const Elf64_Ehdr *ehdr)
{
	printf("  Class:                             %s\n", ehdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
}

/**
 * print_data - prints data
 * @ehdr: pointer to ehdr
 */

static void print_data(const Elf64_Ehdr *ehdr)
{
	printf("  Data:                              %s\n", ehdr->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
}

/**
 * print_osabi - prints OS/ABI
 * @ehdr: pointer to ehdr
 */

static void print_osabi(const Elf64_Ehdr *ehdr)
{
	printf("  OS/ABI:                            ");
	switch (ehdr->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX System V ABI\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX ABI\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD ABI\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux ABI\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris ABI\n");
			break;
		case ELFOSABI_AIX:
			printf("AIX ABI\n");
			break;
		case ELFOSABI_IRIX:
			printf("IRIX ABI\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD ABI\n");
			break;
		case ELFOSABI_TRU64:
			printf("Tru64 UNIX ABI\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM architecture ABI\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) ABI\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}
}

/**
 * print_abiversion - prints ABI Version
 * @ehdr: pointer to ehdr
 */

static void print_abiversion(const Elf64_Ehdr *ehdr)
{
	printf("  ABI Version:                       %d\n", ehdr->e_ident[EI_ABIVERSION]);
}


static void (*elf_functions[MAX_ELF_FUNCTIONS])(const Elf64_Ehdr *) = {
	print_magic,
	print_class,
	print_data,
	print_osabi,
	print_abiversion
};

/**
 * main - the main program
 * @argc: number of arguments
 * @argv: arrays of arguments
 * Return: Exit status.
 */

int main(int argc, char **argv)
{
	FILE *fp;
	Elf64_Ehdr ehdr;
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "rb");
	if (!fp)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	if (fread(&ehdr, sizeof(ehdr), 1, fp) != 1)
	{
		perror("fread");
		exit(EXIT_FAILURE);
	}

	printf("ELF Header:\n");

	for (i = 0; i < MAX_ELF_FUNCTIONS; i++)
	{
		elf_functions[i](&ehdr);
	}

	fclose(fp);
	return (EXIT_SUCCESS);
}
