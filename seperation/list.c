#include "calculator.c"

void listrpush(struct listNode *target, char data)
{
        struct listNode *pushNode = malloc(sizeof(struct listNode));
        struct listNode *nextNode = target -> next;

        pushNode -> next = nextNode;
        pushNode -> previous = target;
        target -> next = pushNode;                                                                                              
        nextNode -> previous = pushNode;
}

void listlpush()
{
}

char listrpop(struct listNode *target)
{
        char popData;
        struct listNode *popNode = target -> next;

        target -> next = listNode -> next;
        listNode                                                                                                        ~                
