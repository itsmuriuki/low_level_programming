#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "holberton.h"
/**
 *read_textfile - reads a text file and prints it to the POSIX stdout
 *@filename: the file name of the file to be read
 *@letters: the number of letters to read and print
 *
 *Return: the number of letters read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int filedes;
	ssize_t bytesread;
	ssize_t byteswritten;
	ssize_t bytes = letters;
	char buf[letters];

	if (filename == NULL)
		return (0);

	filedes = open(filename, O_RDWR);
	if (filedes == -1)
		return (0);

	bytesread = read(filedes, buf, letters);
	if (errno == EINTR || bytesread > bytes)
		return (0);

	byteswritten = write(1, buf, bytesread);

	if (byteswritten == -1 || byteswritten > bytes)
		return (0);
	if (byteswritten != bytesread)
		return (0);
	close(filedes);
	return (byteswritten);
}
