#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/* for convert_number() */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;
/**
* struct liststr - singly linked list
* @num: the number field
* @str: a string
* @nxt: points to the next node
*/
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *nxt;
} list_t;

/**
* struct passinfo - contains pseudo-arguements to pass into a function,
* @arg: a string generated from getline with arguements
* @argv:an array of strings from arg
* @path: a string path
* @argc: the argument count
* @line_count: the error count
* @err_num: the error code for exit()s
* @linecount_flag: if on count this line of input
* @fname: the program filename
* @env: linked list local copy of environ
* @environ: custom modified copy of environ from LL env
* @history: the history node
* @alias: the alias node
* @environ_changed: on if environ was changed
* @status: the return status of the last exec'd command
* @cmd_buf: pointer address, on if chaining
* @cmd_buf_type: CMD_type ||, &&, ;
* @readfd: the fd from which to read line input
* @histcount: the history line number count
*/

typedef struct passinfo
{
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_count;
int err_num;
int linecount_flag;
char *fname;
list_t *env;
list_t *history;
list_t *alias;
char **environ;
int environ_changed;
int status;
char **cmd_buf; 
int cmd_buf_type; 
int readfd;
int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
0, 0, 0}

/**
* struct builtin - contains a builtin string and related function
* @type: the builtin command flag
* @func: the function
*/

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* main.c */
int main(int ac, char **av);

/* builtin.c */
int _myexit(info_t *info);

/* builtin1.c */
int _myalias(info_t *);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);

/* parser.c */
int is_cmd(info_t *, char *);
char *find_path(info_t *, char *, char *);

/* memory.c */
int bfree(void **ptr);

/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* new myexit */
int get_exit_status(info_t *info);
int has_argument(info_t *info);
int convert_argument(char *argument);
void handle_invalid_input(info_t *info);
void set_exit_status(info_t *info, int exit_status);

/* my cd.c */
int _mycd(info_t *info);
char *get_dest_dir(info_t *info);
int change_directory(char *dest_dir);
void handle_chdir_error(info_t *info, char *dest_dir);
void update_pwd_env(info_t *info);

/* myalias */
void alias_operation_mode(info_t *info);
void list_aliases(info_t *info);
int is_listing_mode(info_t *info);
int _myalias(info_t *info);
int print_alias(list_t *node);
int set_alias(info_t *info, char *str);

/* mysetenv.c */
int _setenv(info_t *info, char *var, char *value);
int can_set_env_var(info_t *info, char *var);
void unset_existing_var(info_t *info, char *var);
char *make_env_string(char *var, char *value);
void add_env_var(info_t *info, char *env_string);

/*toem_getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* toem_getinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* toem_getenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);


/* toem_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* toem_environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* toem_vars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* new functions */
char *get_dest_dir(info_t *info);
int change_directory(char *dest_dir);
void handle_chdir_error(info_t *info, char *dest_dir);
void update_pwd_env(info_t *info);

/* myMain.c */
int main(int ac, char **av);
void initialize_shell(info_t *info, int ac, char **av);
int start_shell(info_t *info);
void cleanup_shell(info_t **info);

#endif


