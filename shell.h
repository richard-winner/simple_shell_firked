#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <sys/types.h>


/* Read and Write of a Buff */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* Channing cmd */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for number conversion */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* Using system getline  */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @str: a string
 * @num: the number field
 * @next: points to the next node
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;


/**
 * struct passinfo - Entails pseudo-arg to be passed via funtion
 * @err_num: An Error code for exit()
 * @argc: An arg count
 * @env: Local copy of linked list env
 * @path: A path of string for correct command
 * @env_changed: If there is a change of environment
 * @cmd_buf_type:  &&, || CMD_type
 * @status: Return status of exe command
 * @line_count: Error count
 * @arg: Str generated from getline containing arg
 * @histcount: Line number count history
 * @history: Node history
 * @linecount_flag: Counts line of input
 * @argv: Array of str generated from argument
 * @environ: Modified copy of env
 * @fname: Name of file
 * @readfd: Read line input fd
 * @alias: Node alias
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
	int env_changed;
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
 * @func: Means Function
 * struct builtin - Encompassing a builtin str and related functions
 * @type: command flag for builtin
 */

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* for toem_shloop.c */
void find_cmd(info_t *);
void fork_cmd(info_t *);
int hsh(info_t *, char **);
int find_builtin(info_t *);


/* for loophsh_.c */
int loophsh(char **);

/* for errors_.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* for str_.c */
int _strlen(char *);
char *_strcat(char *, char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);

/* for str_1.c */
char *_strcpy(char *, char *);
int _putchar(char);
char *_strdup(const char *);
void _puts(char *);

/* for parser.c */
char *dup_chars(char *, int, int);
int is_cmd(info_t *, char *);
char *find_path(info_t *, char *, char *);


/* for exits_.c */
char *_strchr(char *, char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);

/* for tokeniz.c */
char **strtow2(char *, char);
char **strtow(char *, char *);


/* for memory.c */
int bfree(void **);

/* for atoi.c */
int is_delim(char, char *);
int _isalpha(int);
int interactive(info_t *);
int _atoi(char *);

/* for errors1.c */
char *convert_number(long int, int, int);
void print_error(info_t *, char *);
void remove_comments(char *);
int print_d(int, int);
int _erratoi(char *);

/* for realloc.c */
void ffree(char **);
char *_memset(char *, char, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);

/* for builtin.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* for builtin_1.c */
int _myalias(info_t *);
int _myhistory(info_t *);

/* for getinfo.c */
void set_info(info_t *, char **);
void free_info(info_t *, int);
void clear_info(info_t *);


/* for environ_.c */
int populate_env_list(info_t *);
int _mysetenv(info_t *);
char *_getenv(info_t *, const char *);
int _myunsetenv(info_t *);
int _myenv(info_t *);

/* for getline.c */
ssize_t get_input(info_t *);
void sigintHandler(int);
int _getline(info_t *, char **, size_t *);

/* for getenv_.c */
char **get_environ(info_t *);
int _setenv(info_t *, char *, char *);
int _unsetenv(info_t *, char *);


/* for lists.c */
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
void free_list(list_t **);

/* for lists1.c */
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
ssize_t get_node_index(list_t *, list_t *);

/* for history.c */
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
char *get_history_file(info_t *info);

/* for vars.c */
int replace_string(char **, char *);
int replace_alias(info_t *);
int is_chain(info_t *, char *, size_t *);
int replace_vars(info_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);

#endif

