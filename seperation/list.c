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


// 알아서 push랑 pop좀
