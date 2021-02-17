#include "tokenizer.h"
#include <stdio.h>
#include <string.h>

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
  char *temp = (char *)malloc(sizeof(char)*len);

  for(int i = 0; i < len; ++i)
    {
      *(temp + i) = *(inStr + i);
    }

  *(temp + len) = '\0';
}

char **tokenize(char* str)
{
  int len = count_words(str) + 1;

  char *temp = str;
  char* tempEnd;
  char **tokens = (char *)malloc(len);

  for(int i = 0; i < len; i++)
    {
      tempEnd = word_terminator(temp)
	
      *(tokens + i) = copy_str(temp, &tempEnd-&temp);
      
      temp = word_start(tempEnd);
    }

  return tokens;
}

void print_tokens(char **tokens)
{
  int i = 0;

  while(**(tokens + i) != 0)
    {
      printf("%s", *(token + i));

      i++;
    }

  printf("%d", *(tokens+i));
}

void free_tokens(char **tokens)
{
  int i = 0;
  
  while(**(tokens + i) != 0)
    {
      free(*(tokens + i));

      i++;
    }

  free(*(tokens + i));
  free(tokens);
}










