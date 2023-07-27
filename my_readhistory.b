#include "shell.h"
/**
read_history – reads the history file
@info: structure with arguments.
Return: 0 on success.
*/
int read_history(info_t *info)
{
int fd;
int linecount;
  char *filename = get_history_file(info);
  if (!valid_history_file(filename))
    return 0;

  fd = open_history_file(filename);
  if (fd == -1)
    return 0;

  linecount = read_history_from_file(info, fd);
  close(fd);
  free(filename);
  return linecount;
}
/**
get_history_file – it  gets the history file.
@info: structure with arguments
Return: Nothing.
*/
char *get_history_file(info_t *info);
/**
valid_history_file – checks if file name is valid.
@filename – The file to check.
Return: NULL when not valid.
*/
int valid_history_file(char *filename)
{
return filename != NULL;
}
/**
open_history_file – opens a history file.
@filename: the file to open.
Return: Nothing.
*/
int open_history_file(char *filename);
/**
read_history_from_file – reads commands from history file.
@info: The structure with arguments.
@fd: The file descriptor.
Return:histcount.
*/
int read_history_from_file(info_t *info, int fd)
{
int i;
  char buf[READ_BUF_SIZE + 1];
  int last = 0;

  while (read(fd, buf, READ_BUF_SIZE) > 0) {
    buf[READ_BUF_SIZE] = 0;
    for (i = 0; i < READ_BUF_SIZE; i++)
      if (buf[i] == '\n'){
        build_history_list(info, buf + last, info->histcount++);
        last = i + 1;
      }
  }

  if (last < READ_BUF_SIZE)
    build_history_list(info, buf + last, info->histcount++);
  return info->histcount;
}

