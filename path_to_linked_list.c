#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct List_node
{
	char *val;
	struct List_node *next;
} List_node;

/**
 * main - adds the PATH directories in singly linked list
 *
 * Return: 0
 */
int main(void)
{
	extern char **environ;
	char *dir;
	char *path;
	List_node node;
	List_node *tmp;
	List_node *head;

	head = &node;
	tmp = head;
	path = getenv("PATH");
	dir = strtok(path, ":");
	if (dir == NULL)
		return (1);

	while (dir != NULL)
	{
		tmp->val = dir;
		dir = strtok(NULL, ":");
		if (dir == NULL)
		{
			tmp->next = NULL;
			break;
		}
		tmp->next = malloc(sizeof(List_node));
		tmp = tmp->next;
	}

	while(head != NULL)
	{
		printf("%s\n", head->val);
		head = head->next;
	}

	return (0);
}
