#include "calculator.c"

struct inforNode *init() 
{
        struct inforNode *number = malloc(sizeof(struct inforNode));
        number -> natural = malloc(sizeof(struct list));
        number -> decimal = malloc(sizeof(struct list));
        number -> data = '+'; 

        natural_number -> head = NULL;
        natural_number -> tail = NULL;
        decimal_number -> head = NULL;
        decimal_number -> tail = NULL;

        return number;
}
    
  
