#include "calculator.c"

void listrpush(struct listNode *target, char data)
{
        struct listNode *pushNode = malloc(sizeof(struct listNode));

        pushNode-> data = data
        
        struct listNode *preNode = target -> previous;

        pushNode -> next = target;
        pushNode -> previous = preNode;
        target -> previous = pushNode;                                                                                              
        preNode -> next = pushNode;
}

void listlpush(struct listNode *target, char data)
{
        struct listNode *pushNode = malloc(sizeof(struct listNode));

        pushNode -> data = data
        
        struct listNode *nextNode = target -> next;

        pushNode ->previous = target;
        pushNode ->next = nextNode;

        preNode->previous = pushNode;
        target->next = pushNode;
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
        char popData;
        struct listNode *popNode = target -> next;
        struct listNode *nextNode = popNode -> next;

        nextNode->previous = target;
        target -> next = nextNode;

        free(popNode);

        return popData;
}
