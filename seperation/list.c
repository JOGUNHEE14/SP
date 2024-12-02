#include "calculator.c"

void listrpush(struct listNode *target, char data)
{
        struct listNode *pushNode = malloc(sizeof(struct listNode));
        struct listNode *preNode = target -> previous;

        pushNode -> next = target;
        pushNode -> previous = preNode;
        target -> previous = pushNode;                                                                                              
        preNode -> next = pushNode;
}

void listlpush(struct listNode *target, char data)
{
        struct listNode *pushNode = malloc(sizeof(struct listNode));
        struct listNode *preNode = tartget -> previous;

        pushNode ->next = target;
        pushNode ->previous = preNode;

        preNode->next = pushNode;
        target->previous = pushNode;
}

char listrpop(struct listNode *target)
{
        char popData;
        struct listNode *popNode = target -> previous;
        struct listNode *preNode = popNode -> previous;

        preNode -> next = target;
        target -> previous = preNode;
        popData = popNode -> data;
        
        free(popNode);            

        return popData;
}

char listlpop(struct listNode *target)
{
}
