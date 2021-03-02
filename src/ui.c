#include <stdio.h>
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

      if(input[0] == 'q')
	{
	  if(input[1] == '\n')
	    {
	      free_history(userStrings);
	  
	      puts("Goodbye");

              return 0;
	    }
	  
	}else if(input[0] == 'p')
	{
	  if(input[1] == '\n')
	    {
	      print_history(userStrings);
	      
	      continue;
	    }
	  
	}else if(input[0] == '!')
	{
	  printf("%s\n", get_history(userStrings, atoi(input+1)));

	  continue;
	}
      
      printf("%s", input);

      add_history(userStrings, input);
      
      char** tokens = tokenize(input);
      print_tokens(tokens);
      free_tokens(tokens);
    }
}
