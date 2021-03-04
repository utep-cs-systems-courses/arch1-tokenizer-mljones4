#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

int space_char(char c)
{
  if((c == ' ' || c == '\t') && c != '\0') //returns 1 if there is a space and not a zero term
    {
      return 1;
    }

  return 0;
}

int non_space_char(char c)
{
  if((c != ' ' && c != '\t') && c != '\0') //returns 1 if there is not a space and not a zero term

    {
      return 1;
    }

  return 0; 
}

char *word_start(char *str)
{
  char *temp = str;
  
  if(*temp == '\0')//if on the zero term, don't continue
    {
      temp = 0;
    }else if (non_space_char(*temp))//if already on a non-space character, exit
    {
      return temp;
    }
      
  while(space_char(*temp) || *temp=='\n')// keep traversing spaces until reaching non-space char
    {
      temp++;
    }

  return temp;
}

char *word_terminator(char *word)
{
  char *temp = word;

  while(non_space_char(*temp) && *temp!='\n')//traverse non-space characters until space char
    {
      temp++;
    }

  return temp;
}


int count_words(char *str)
{
  char *temp = str;
  int wcount = 0;

  while(space_char(*temp))//traverse spaces in beginning of string
    {
      temp++;
    }
  
  while(*temp && *temp!='\n')//keep going until the end of the string
    {
      wcount++;//increment word count

      while(non_space_char(*temp))//traverse non-space characters
	{
	  temp++;
	}

      while(space_char(*temp))//traverse space characters
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
  char **tokens = (char **)malloc(sizeof(char *)*len);
  
  int i = 0;
  
  for(; i < len-1; i++)
    {

      tempEnd = word_terminator(temp);
      
      *(tokens + i) = copy_str(temp, tempEnd-temp);
      
      temp = word_start(tempEnd);

    }

  *(tokens + len-1) = 0;

  return tokens;
}

void print_tokens(char **tokens)
{
  int i = 0;

  while(*(tokens + i) != 0)
    {
      printf("%s\n", *(tokens + i));

      i++;
    }

}

void free_tokens(char **tokens)
{
  char** temp = tokens;
  int i = 0;
  
  while(*(tokens+i))
    {
      free(*(tokens+i));

      i++;
    }
    
  free(tokens);
}
