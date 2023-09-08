HANDLING A FILE BY ITS DESCRIPTOR:
In Unix type systems, a file descriptor (fd for short) is a small positive integer used as reference to an open file in a process. A process is a currently running program.
However, from the operating system’s point of view, a file is not only a text file as we might think of it as a user. A file can also be a directory or even another type of input/output resource such as a keyboard, a screen, a pipe or a network socket.

By default, each process systematically inherits three open file descriptors :

File Descriptor	Name	<unistd.h>	<stdio.h>
0	Standard Input	STDIN_FILENO	stdin
1	Standard Output	STDOUT_FILENO	stdout
2	Standard Error	STDERR_FILENO	stderr

SYSTEM'S REPRESENTATION OF OPEN FILES:
To represent open files, the system uses three data structures:

> A table of file descriptors per process. Each process has its own table containing a series of indexes, each one referring to an entry in the open file table.
> An open file table, shared between all processes. Each entry in this table contains, among other things, the access mode, an offset describing the current location within the file, and a pointer to the corresponding entry in the inode table. This table also keeps count of the number references there are to this file in all of the file descriptor tables of all processes. When a process closes the file, this reference count is decremented and if it gets to 0, the entry is deleted from the table.
> An inode (index node) table which is also shared between all processes. Each entry in the inode table describes the file in detail: the path to its location on the disk, its size, its permissions, etc.

OPENING OR CREATING A FILE IN C:
To manipulate a file in C, we must first inform the operating system of our intentions with the open function of the <fcntl.h> library. This system call allows us to open an existing file, or create the file if it doesn’t already exist. We must at least specify the path towards the file we’d like to open, as well as the way in which we want to access it:

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);Code language: C++ (cpp)

So there are two versions of this open system call. Their parameters are:

> Pathname: the path towards the file in the form of a string of characters,
> Flags: an integer representing the flags indicating the access mode, which we will take a closer look at below,
> Mode: an integer representing the permissions to give to the file upon creation. This is an “optional” parameter that will be ignored if we don’t ask to create the file if it doesn’t already exist.

The open function returns the newly created file descriptor if the file was successfully added to the inode and open file tables. This file descriptor will typically be larger than 2, since fds 0, 1, and 2, are reserved for the standard input, output and error respectively. However, if there is any issue, for example if we ask to open a file that doesn’t exist, or a file we don’t have permissions for, open will return -1.

THE OPEN ACCESS MODE:
The flags parameter in the open system call allows us to choose the file’s access mode. The <fcntl.h> library contains a large selection of symbolic constants (see the full list in the manual page for open). Among them, the most common ones are:

Symbolic Constant	Description
O_RDONLY	Read only
O_WRONLY	Write only
O_RDWR	Read and write
O_TRUNC	Truncated mode. If the file exists and the access mode allows writing to it (O_WRONLY ou O_RDWR), truncates its contents to 0 size when it is opened, with the effect of overwriting the file.
O_APPEND	Append mode. The file offset is set to the end of the file at each write, with the effect of adding text to the end of the file instead of overwriting it.
O_CREAT	Creates the file if it does not already exist. Its permissions must then be specified in open‘s mode parameter.

For example, we can open a file in read only mode this way:

open("path/to/file", O_RDONLY);Code language: C++ (cpp)

But we can also combine flags with the bitwise | (OR) operator. For example, if we wanted to open a file in truncated write mode, we could do:

open("path/to/file", O_WRONLY | O_TRUNC);Code language: C++ (cpp)

Let’s note that indicating an access mode with O_RDONLY, O_WRONLY or O_RDWR is mandatory. We could not, for example, simply specify O_CREAT without any other indication of an access mode.

CREATING A FILE WITH OPEN'S O_CREAT OPTION:
Open allows us to create a file if the specified file does not already exist. For that, we need to indicate the O_CREAT symbolic constant in its flags parameter. In this case, we must describe in the following optional parameter, mode, which permissions to give the new file.

Symbolic Constant	Decimal	Description
S_IRWXU	700	The owner (user) has read, write and execute rights
S_IRUSR	400	The owner has read rights
S_IWUSR	200	The owner has write rights
S_IXUSR	100	The owner has execute rights
S_IRWXG	070	The group has read, write and execute rights
S_IRGRP	040	The group has read rights
S_IWGRP	020	The group has write rights
S_IXGRP	010	The group has execute rights
S_IRWXO	007	Other users have read, write and execute rights
S_IROTH	004	Others have read rights
S_IWOTH	002	Others have write rights
S_IXOTH	001	Others have execute rights

We might notice that the numbers encoded in these symbolic constants are exactly the same as those we may use with the chmod command to change file permissions.

Of course, we can also combine these symbolic constants with the same bitwise OR operator as before. For example, to create a file in append write only mode with read and write permissions for the owner but only the read permission for the group:

open("path/to/file", O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP);Code language: C++ (cpp)

An alternative to shorten this permissions specification is to directly use their added numeric values, preceded by a 0. The following is exactly equivalent to the previous example:

open("path/to/file", O_WRONLY | O_APPEND | O_CREAT, 0640);Code language: C++ (cpp)

CLOSING A FILE DESCRIPTOR IN C:
When we are done manipulating a file, we must of course de-reference its file descriptor with the close function of the <unistd.h> library. Its prototype could not be simpler:

int close(int fd);Code language: C++ (cpp)
We supply it with a file descriptor and the system de-references it, and, if no other process has that file opened, deletes it from its open file and inode tables. Upon success, the close function returns 0, but on failure, it returns -1 and sets errno to indicate the error.

However, the close function only closes the file descriptor, it does not delete the file itself! That is unlink‘s prerogative.

DELETING A FILE IN C WITH UNLINK:
If we wish to completely delete a file on the hard drive with a C program, we can use the unlink system call from the <unistd.h> library. Its prototype is :

int unlink(const char *pathname);Code language: C++ (cpp)
All we have to indicate here is the path towards the file and it will be deleted once all processes using it have closed their descriptors referencing it. This system call returns 0 on success or -1 on failure.

Of course, closing and deleting a file right after opening it serves no purpose: we probably want to do something with that opened file. Why not write to it?

WRITING TO A FILE DESCRIPTOR IN C:
Once a file descriptor is opened with an access mode permitting writing, we will be able to write to the file it references thanks to the write system call from the <unistd.h> library. Its prototype is:

ssize_t write(int fd, const void *buf, size_t count);Code language: C++ (cpp)

And its parameters are as follows:

> fd: the file descriptor to write to,
> buf: a pointer to a memory zone to write to the file, typically containing a string of characters,
> count: the number of bytes (i.e. characters) to write, typically the length of the string of characters specified in the previous parameter.

On success, the write function returns the number of bytes it has written, However, upon failure, it returns -1 and sets errno to indicate the error it encountered.

Let’s write a little program to test the behavior of the open, write and close functions:

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int fd;

//	Open a file descriptor for the "test.txt" file, in
//	truncated write only mode, and create the file if it doesn't
//	already exist. Read and write permissions for the owner, read
//	permissions for the group.
	fd = open("test.txt", O_WRONLY | O_TRUNC | O_CREAT, 0640);
//	Stop everything if the file could not be opened
	if (fd == -1)
		return (1);
//	Print the fd of the new file
	printf("fd = %d\n", fd);
//	Write into the file descriptor
	write(fd, "Hello World!\n", 13);
//	Close the file
	close(fd);
	return (0);
}Code language: C++ (cpp)

TRY IT!!
In the output,we can see that the test.txt file was indeed created since it did not exist before we ran the program. And it does contain the sentence we wrote into it with write!

If we want to append text to the end of a file rather than overwriting it, we need to remember that that is not the responsibility of the write function. The access mode specified in the open function (O_TRUNC ou O_APPEND) controls where and how write adds to the file.

READING FROM A FILE DESCRIPTOR IN C:
The read function, from the <unistd.h> library, loads the contents of a file into memory, in part or in full, using its file descriptor. Here is its prototype:

ssize_t read(int fd, void *buf, size_t count);Code language: C++ (cpp)

Its parameters are as follows:

> fd: the file descriptor to read from,
> buf: a pointer towards a memory area where we can temporarily store the read characters,
> count: a size in bytes to read, in other words, the number of characters to read. This size will often correlate with the size of the memory area indicated in the previous parameter.

Then, the read function returns the number of characters that it has read, or -1 in case of error. When the read function reaches the end of the file, it will naturally return 0.

So the read function stops reading when it reaches the number of characters we indicated, or the end of the file (EOF).

Let’s try to open a file in read only mode and read 100 characters at a time until the end of the file:

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char buf[100];	// stores the characters read
	int fd;		// file descriptor to read
	int nb_read;	// stores read's return value
	int count;		// counts the number of reads

//	Open the cat.txt file in read only mode
	fd = open("cat.txt", O_RDONLY);
	if (fd == -1)
		return (1);
//	Initialize the count variables
	nb_read = -1;
	count = 0;
//	Loop as long as read does not return 0 (which would mean that
//	there is nothing more to read in the file)
	while (nb_read != 0)
	{
		// Read 100 characters with read from the
		// opened file descriptor
		nb_read = read(fd, buf, 100);
		// Stop everything if read encounters an error
		if (nb_read == -1)
		{
			printf("Read error!\n");
			return (1);
		}
		// Read does not add the terminating \0
		// We can use the number of read characters as the index
		// of the last character in the string
		buf[nb_read] = '\0';
		// Print the buffer contents after read
		printf("\e[36m%d : [\e[0m%s\e[36m]\e[0m\n", count, buf);
		count++;
	}
//	Close the opened file descriptor
	close(fd);
	return (0);
}Code language: C++ (cpp)

The cat.txt file will contain an extract from Wikipedia:

The cat (Felis catus) is a domestic species of small carnivorous mammal. It is the only domesticated species in the family Felidae and is commonly referred to as the domestic cat or house cat to distinguish it from the wild members of the family. A cat can either be a house cat, a farm cat, or a feral cat; the latter ranges freely and avoids human contact. Domestic cats are valued by humans for companionship and their ability to kill rodents. About 60 cat breeds are recognized by various cat registries.Code language: plaintext (plaintext)

TRY IT AND EXECUTE THIS CODE!

The read function seems to have an integrated bookmark! At each call, read resumes where it left off last time. In truth, the read function does not remember its last position in the file itself: it only increments the file descriptor’s offset.
