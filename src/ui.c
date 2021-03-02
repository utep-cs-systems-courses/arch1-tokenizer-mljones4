#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX_LIMIT 100

int main()
{
  char input[MAX_LIMIT];
  List *userStrings = init_history(); 
  
  while(1)
    {  
      puts("Type your sentence here, or type 'q' to quit, or type 'p' to print your previous entries:");
      printf(">");

      fgets(input, MAX_LIMIT, stdin);

      if(strcmp(input, "q\n") == 0)
	{
	  free_history(userStrings);
	  
	  puts("Goodbye");

	  return 0;
	  
	}else if(strcmp(input, "p\n") == 0)
	{
	  print_history(userStrings);

	  continue;
	  
	}else if(input[0] == '!')
	{
	  printf("%s", get_history(userStrings, atoi(input+1)));

	  continue;
	}
      
      printf("%s", input);

      add_history(userStrings, input);
      
      char** tokens = tokenize(input);
      print_tokens(tokens);
      free_tokens(tokens);
    }
}
