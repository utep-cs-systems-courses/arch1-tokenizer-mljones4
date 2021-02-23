#include "tokenizer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int space_char(char c)
{
  if((c == ' ' || c == '\t') && c != '\0')
    {
      return 1;
    }

  return 0;
}

int non_space_char(char c)
{
  if((c != ' ' && c != '\t') && c != '\0')

    {
      return 1;
    }

  return 0; 
}

char *word_start(char *str)
{
  char *temp = str;
  
  if(*temp == '\0')
    {
      temp = 0;
    }else if (non_space_char(*temp))
    {
      return temp;
    }
      
  while(space_char(*temp) || *temp=='\n')
    {
      temp++;
    }

  return temp;
}

char *word_terminator(char *word)
{
  char *temp = word;

  while(non_space_char(*temp) && *temp!='\n')
    {
      temp++;
    }

  return temp;
}


int count_words(char *str)
{
  char *temp = str;
  int wcount = 0;

  while(space_char(*temp))
    {
      temp++;
    }
  
  while(*temp && *temp!='\n')
    {
      wcount++;

      while(non_space_char(*temp))
	{
	  temp++;
	}

      while(space_char(*temp))
	{
	  temp++;
	}
    }

  return wcount;
}

char *copy_str(char *inStr, short len)
{
  char *temp = (char *)malloc((1+len)*sizeof(char));

  for(int i = 0; i < len; i++)
    {
      *(temp + i) = *(inStr + i);
    }

    *(temp + len) = '\0';

  return temp;
}

char **tokenize(char* str)
{
  int len = count_words(str) + 1;

  char *temp = word_start(str);
  char *tempEnd;
  char **tokens = (char **)malloc(len);
  
  int i = 0;
  
  for(; i < len-1; i++)
    {

      tempEnd = word_terminator(temp);
      
      *(tokens + i) = copy_str(temp, tempEnd-temp);
      
      temp = word_start(tempEnd);
      printf("this is word #%d: %s\n", (i + 1), *(tokens+i));
    }

  //*(tokens + i) = (char *)malloc(sizeof(char));
  *(tokens + len-1) = 0;

  return tokens;
}

void print_tokens(char **tokens)
{
  int i = 0;

  while(*(tokens + i) != 0)
    {
      printf("%s", *(tokens + i));
           printf("%zu\n", strlen(*(tokens + i)));
      i++;
    }

  //printf("%d", **(tokens + i));
  // printf("%zu\n", strlen(*(tokens + i)));
}

void free_tokens(char **tokens)
{
  char** temp = tokens;
  int i = 0;
  //  puts("Hello\n");
  
  printf("%d\n", tokens[0]);
  printf("%s\n", tokens[0]);
  free(*(tokens+i));
  printf("%d\n", tokens[1]);
  printf("%s\n", tokens[1]);
  free(tokens[1]);
  printf("%d\n", tokens[2]);
  printf("%s\n", tokens[2]);
  free(tokens[2]);
/*  
  while(*(tokens+i)!='\0')
    {
      puts("We are inside free tokens while loop.\n");
      printf("%d\n", tokens[i]);
      printf("%s\n", tokens[i]);
      free(*(tokens+i));

      i++;
    }
*/
  //  free(*(tokens+i));
  free(tokens);

}
