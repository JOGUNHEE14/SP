#include "calculator.h"

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

void listlpush(struct list *target, char data)
{
        struct listNode *pushNode = malloc(sizeof(struct listNode));

        pushNode->next = target->head;
        pushNode->previous = NULL;
        pushNode->data = data;

        if (target->head != NULL)
                target->head->previous = pushNode;
        else
                target->tail = pushNode;

        target->head = pushNode;
}
char listrpop(struct list *target)
{
        struct listNode *popNode = target -> tail;

        char popData = popNode-> data;

        if (popNode -> previous == NULL) {
                target -> head = NULL;
                target -> tail = NULL;
        } else {
                popNode -> previous -> next = NULL;
                target -> tail = popNode -> previous;
        }

        free(popNode);

        return popData;
}

char listlpop(struct list *target)
{
        struct listNode *popNode = target->head;

        char popData = popNode->data;
        if (popNode->next == NULL) {
                target->head = NULL;
                target->tail = NULL;
        } else {
                popNode->next->previous = NULL;
                target->head = popNode->next;
        }

        free(popNode);
}
        return popData;
}


