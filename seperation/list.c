


#include "calculator.h"

void listrpush(struct list *target, char data) //리스트 tail에 데이터 추가하는 함수
{
        struct listNode *pushNode = malloc(sizeof(struct listNode)); //새 노드를 위한 메모리 동적 할당

        pushNode -> next = NULL; // 새 노드의 next를 NULL로 설정.
        pushNode -> previous = target -> tail; // 새 노드의 previous를 tail로 설정
        pushNode-> data = data; // 새 노드에 전달된 데이터 저장

        if (target -> tail != NULL) // 리스트에 원래 tail이 있다면 tail의 next를 새 노드로 연결
                target -> tail -> next = pushNode;
        else //없다면 head를 새노드로 설정
                target -> head = pushNode;
        target -> tail = pushNode; // tail을 새 노드로 갱신
}

void listlpush(struct list *target, char data) // 리스트 head에 데이터를 추가하는 함수
{
        struct listNode *pushNode = malloc(sizeof(struct listNode)); // 메모리 동적 할당.

        pushNode->next = target->head; //새노드의 next를 head로 설정
        pushNode->previous = NULL; // 새 노드의 previous를 NULL로 설정
        pushNode->data = data; //노드에 데이터 저장

        if (target->head != NULL) //리스트에 원래 head가 있으면 head의 previous를 새 노드로 연결
                target->head->previous = pushNode;
        else // 없다면 tail을 새 노드로 설정.
                target->tail = pushNode; 

        target->head = pushNode; // head를 새 노드로 갱신
}
char listrpop(struct list *target) // tail에서 데이터를 제거하고 pop하는 함수
{
        struct listNode *popNode = target -> tail; // 현재 tail을 pop노드로 저장

        char popData = popNode-> data; //제거할 노드의 데이터를 저장

        if (popNode -> previous == NULL) { // 리스트에 노드가 하나만 있을 때
                target -> head = NULL; //head == NULL
                target -> tail = NULL; //tail == NULL
        } else {
                popNode -> previous -> next = NULL; // 이전 노드의 next를 NULL로 설정
                target -> tail = popNode -> previous; // tail을 이전 노드로 갱신
        }

        free(popNode); // 제거한 노드의 메모리를 free

        return popData;
}

char listlpop(struct list *target) // head에서 데이터를 제거하고 pop하는 함수
{
        struct listNode *popNode = target->head; // head를 pop노드로 저장

        char popData = popNode->data; 
        if (popNode->next == NULL) { //리스트에 노드가 하나만 있을 때
                target->head = NULL; // head == NULL
                target->tail = NULL; // tail == NULL
        } else {
                popNode->next->previous = NULL; // 다음 노드의 previous를 NULL로 설정
                target->head = popNode->next; //head를 다음 노드로 업데이트
        }

        free(popNode);

        return popData;
}


