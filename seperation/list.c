#include "calculator.c"

void listrpush(struct list *target, char data)
{
        struct listNode *pushNode = malloc(sizeof(struct listNode));
        
        pushNode -> next = NULL;
        pushNode -> previous = target -> tail;
        pushNode-> data = data;
        
        if (target -> tail != NULL) 
                target -> tail -> next = pushNode;
        else
                target -> head = pushNode;
        target -> tail = pushNode;
}

//수정 해야함
void listlpush(struct listNode *target, char data)
{
        struct listNode *pushNode = malloc(sizeof(struct listNode));

        pushNode -> data = data;
        
        struct listNode *nextNode = target -> next;

        pushNode ->previous = target;
        pushNode ->next = nextNode;

        preNode->previous = pushNode;
        target->next = pushNode;
}

char listrpop(struct list *target)
{
        struct listNode *popNode = target -> tail;

        char popData = popNode-> data;
        popNode -> next = NULL;
        target -> tail = popNode -> previous;

        if (popNode -> previous == NULL)
                target -> head = NULL;
        
        free(popNode);            

        return popData;
}

// 수정해야함
char listlpop(struct listNode *target)
{
        struct listNode *popNode = target -> next;
        struct listNode *nextNode = popNode -> next;

        char popData = popNode-> data;
        
        nextNode->previous = target;
        target -> next = nextNode;

        free(popNode);

        return popData;
}
