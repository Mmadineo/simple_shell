#include "shell.h"

int _setenv(info_t *info, char *var, char *value)
{
	if (!can_set_env_var(info, var))
		return (0);

	unset_existing_var(info, var);

	char *env_string = make_env_string(var, value);

	add_env_var(info, env_string);
	free(env_string);

	return (0);
}

int can_set_env_var(info_t *info, char *var)
{
	return (var != NULL && value != NULL);
}

void unset_existing_var(info_t *info, char *var)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, var);

		if (p && *p == '=')
		{
			delete_node_at_index(&(info->env), node);
			break;
		}
		node = node->nxt;
	}
}

char *make_env_string(char *var, char *value)
{
	char *env_string = malloc(strlen(var) + strlen(value) + 2);

	strcpy(env_string, var);
	strcat(env_string, "=");
	strcat(env_string, value);

	return (env_string);
}

void add_env_var(info_t *info, char *env_string)
{
	add_node_end(&(info->env), env_string, 0);
}
