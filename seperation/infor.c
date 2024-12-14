#include "calculator.h"

struct inforNode *init() 
{
        struct inforNode *number = malloc(sizeof(struct inforNode));
        number -> natural = malloc(sizeof(struct list));
        number -> decimal = malloc(sizeof(struct list));
        number -> data = '+'; 

        number -> natural -> head = NULL;
        number -> natural -> tail = NULL;
        number -> decimal -> head = NULL;
        number -> decimal -> tail = NULL;

        return number;
}
    
  
