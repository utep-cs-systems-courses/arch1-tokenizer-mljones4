#include <stdio.h>
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

  //get length of str
  int i = 0;
  for(; str[i]!='\0'; i++)
    {
    }

  node->str = (char *) malloc(sizeof(char) * (i+1));

  //copy parameter str into the str of the node
  i=0;
  for(; str[i]!='\0'; i++)
    {
      node->str[i] = str[i];
    }

  node->str[i+1] = '\0';

  //change the head of the list to be the new node
  node->next = list->root;
  node->id = list->root->id + 1;

  list->root = node;
}

char *get_history(List *list, int id)
{
  Item *node = list->root;

  while(node->id)//loop through each node until the node with the specific id is found, return str
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

  while(node->id)//loop through each node and print the string they hold
    {
      printf("%d. %s\n", node->id, node->str);

      node = node->next;
    }
}

void free_history(List *list)
{
  Item *node = list->root;
  Item *temp;
  
  while(node)//loop through each node and free them
    {
      temp = node;
      node = node->next;
      
      free(temp);
    }

  free(list);
}
