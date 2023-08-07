#include "shell.h"
/**
_mycd – works the same as built in cd.
@info: struc with arguments.
Return: 0 on success.
*/
int _mycd(info_t *info) 
{
  char *dest_dir = get_dest_dir(info);
  int chdir_result = change_directory(dest_dir);
  
  if (chdir_result == -1) {
    handle_chdir_error(info, dest_dir);
  } else {
    update_pwd_env(info); 
  }

  return 0; 
}
/**
* get_dest_dir – gets the destination dir.
* @info: struct with arguments.
* Return: directory.
*/
char *get_dest_dir(info_t *info)
{
  char *dir = NULL;
  if (!info->argv[1]) 
    dir = _getenv(info, "HOME="); 
  else if (_strcmp(info->argv[1], "-") == 0)
    dir = _getenv(info, "OLDPWD=");
  else 
    dir = info->argv[1];
  
  return dir; 
}
/**
* change_directory – changes directory.
* @dest_dir: the destination directory.
* Return: 0 on success and -1 on fail.
*/
int change_directory(char *dest_dir) 
{
  int chdir_result = chdir(dest_dir);
  
  if (chdir_result == -1) {
    return -1; 
  } 
  
  return 0; 
}
/**
* handle_chdir_error – prints error msg when cd cmd fails.
* @info: struct with arguments.
* @dest_dir: destination directory.
* Return: Nothing
*/
void handle_chdir_error(info_t *info, char *dest_dir) 
{
  print_error(info, "can't cd to ");
  _eputs(dest_dir);
  _eputchar('\n');
}
/**
* update_pwd_env – updates the pwd and oldpwd variables.
* @info: struct with arguments.
* Return: Nothing.
*/
void update_pwd_env(info_t *info) 
{
char buffer[1024];
  _setenv(info, "OLDPWD", _getenv(info, "PWD="));
  _setenv(info, "PWD", getcwd(buffer, 1024)); 
}

