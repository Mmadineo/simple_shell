#include "shell.h"
#define INVALID -1
#define success_status 0
#define error_status 2
/**
* _myexit – works like the built in exit cmd.
* @info: structure with arguments.
* Return: -2 on success.
*/
int _myexit(info_t *info)
{
  int exit_status = get_exit_status(info);
  set_exit_status(info, exit_status);
  return -2; 
} 
/**
* get_exit_status – the function gets the exit status.
* @info: structure with arguments.
* Return: The status.
*/
int get_exit_status(info_t *info) 
{
  if (has_argument(info)) {
    int argument_status = convert_argument(info->argv[1]);
    if (argument_status == INVALID) {
      handle_invalid_input(info);
      return error_status; 
    }
    return argument_status; 
  }
  
  return success_status;
}
/**
* has_argument – checks if argv[1] is NULL.
* @info: structure with arguments.
* Return: NULL when true.
*/
int has_argument(info_t *info) 
{
  return info->argv[1] != NULL;
} 
/**
* convert_argument – converts arg to exit status.
* @argument: The argument.
* Return: argument status.
*/
int convert_argument(char *argument)
{
  int argument_status = _erratoi(argument);   
  if (argument_status == -1) 
    return INVALID;
  return argument_status; 
}
/**
* handle_invalid_input – prints error msg when arg is invalid.
* @info: struct with arguments.
* Return: Nothing.
*/
void handle_invalid_input(info_t *info)
{
  print_error(info, "Illegal number: ");
  _eputs(info->argv[1]);
  _eputchar('\n');  
}
/**
* set_exit_status – initializes the exit status.
* @info: struct with arguments.
* @exit_status: The exit status.
*/
void set_exit_status(info_t *info, int exit_status) 
{
  info->err_num = exit_status; 
}

