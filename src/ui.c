#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#define MAX_LIMIT 100

int main()
{
  char input[MAX_LIMIT];
  
  while(1)
    {  
      puts("Type your sentence here, or type 'q' to quit:");
      printf(">");

      fgets(input, MAX_LIMIT, stdin);

      if(strcmp(input, "q\n") == 0)
	{
	  puts("Goodbye");

	  return 0;
	}
      /*
      printf("%s", input);
      printf("%d\n", count_words(input));
      printf("%d\n", word_start(input));
      printf("%c\n", *word_start(input));
      printf("%d\n", word_terminator(input));
      printf("%c\n", *word_terminator(input));
      printf("%d\n", word_terminator(input+4));
      printf("%c\n", *word_terminator(input+4));
      */
      char** tokens = tokenize(input);
      //print_tokens(tokens);
      //print_tokens(tokens);
      free_tokens(tokens);
    }
}
