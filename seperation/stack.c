#include "calculator.h"

//노드를 추가하는 함수
void stackpush(struct stackNode *target, char data)
{
        struct stackNode *pushNode = malloc(sizeof(struct stackNode));

        pushNode -> next = target -> next;
        pushNode -> data = data;
        target -> next = pushNode;
}

//노드에 저장된 데이터를 리턴하고 저장공간 해제
char stackpop(struct stackNode *target)
{
        char popData;
        struct stackNode *popNode = target -> next;

        target -> next = popNode -> next;
        popData = popNode -> data;

        free(popNode);

        return popData;
}
