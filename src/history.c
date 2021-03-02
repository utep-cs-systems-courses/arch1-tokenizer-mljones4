#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  Item *node = (Item *) malloc(sizeof(Item));
  
  List *head = (List *) malloc(sizeof(List));

  head->root = node;

  return head;
}

void add_history(List *list, char *str)
{
  Item *node = (Item *) malloc(sizeof(Item));
  node->str = (char *) malloc(sizeof(char) * strlen(str));
  
  strcpy(node->str, str);
  
  node->next = list->root;
  node->id = list->root->id + 1;

  list->root = node;
}

char *get_history(List *list, int id)
{
  Item *node = list->root;

  while(node->id)
    {
      if(node->id == id)
	{
	  return node->str;
	}

      node = node->next;
    }

  return "Entry not found, try again.";
}

void print_history(List *list)
{
  Item *node = list->root;

  while(node->id)
    {
      printf("%d. %s\n", node->id, node->str);

      node = node->next;
    }
}

void free_history(List *list)
{
  Item *node = list->root;
  Item *temp;
  
  while(node)
    {
      temp = node;
      node = node->next;
      
      free(temp);
    }

  free(list);
}
