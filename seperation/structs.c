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

        return popData;
}

int priority(struct stackNode *target, char com) {
        char result = (target -> next) -> data;
        if (result =='*')
                result += 5;
        else if (result == '+')
                result += 2;
        
        if (com == '*')
                com += 5;
        else if (result == '+')
                result += 2;
        
        if (result < com)
                return 2;
        else if (result == com)
                return 1;
        return 0;
}

void initQueue(struct queueNode* head) {
    head = NULL; //큐가 비어있음
}

//큐가 비어 있는지 확인하는 함수
int isEmpty(struct queueNode* head) {
    return head -> next == NULL; //큐에 노드가 없음
}


//큐에 데이터 추가
void push(struct queueNode *head, struct inforNode *data) {
        struct queueNode* newQNode = (struct queueNode*)malloc(sizeof(struct queueNode));
        if (newQNode == NULL) {
                printf("메모리 할당 불가");
                return;
        }
        newQNode->data = data;  //queueNode에 inforNode 저장
        newQNode->next = head -> next;
        head -> next = newQNode;

}

//큐에서 데이터 제거
//struct inforNode* data : 큐에 저장된 데이터 => pop함수의 반환형을 struct inforNode로 설정
struct inforNode* pop(struct queueNode* head) {
        if (isEmpty(head)) {
                printf("Queue가 비어있습니다.");
                return NULL;
        }
        struct queueNode* temp = head->next; //현재 head 임시 저장, free한 후에도 head 접근 가능
        struct inforNode* data = temp -> data;
        head -> next = temp -> next;
        
        free(temp);
        return data;
}

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
