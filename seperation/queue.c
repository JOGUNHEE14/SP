#include "calculator.h"

//큐 초기화 함수
void initQueue(struct queueNode** head, struct queueNode** tail) {
    *head = NULL; //큐가 비어있음
    *tail = NULL; //큐가 비어잇음
}

//큐가 비어 있는지 확인하는 함수
int isEmpty(struct queueNode* head) {
    return head == NULL; //큐에 노드가 없음
}


//큐에 데이터 추가
void push(struct queueNode** head, struct queueNode** tail,
          struct inforNode* data) {
    struct queueNode* newQNode = (struct queueNode*)malloc(sizeof(struct queueNode));
    if (newQNode == NULL) {
        printf("메모리 할당 불가");
        return;
    }
    newQNode->data = data;  //queueNode에 inforNode 저장
    newQNode->next = NULL;

    if (isEmpty(*head)) {
        //큐가 비어있으면
        *head = newQNode;
        *tail = newQNode;
    } else {
        (*tail)->next = newQNode;
        *tail = newQNode;
    }

}

//큐에서 데이터 제거
//struct inforNode* data : 큐에 저장된 데이터 => pop함수의 반환형을 struct inforNode로 설정
struct inforNode* pop(struct queueNode** head, struct queueNode** tail) {
    if (isEmpty(*head)) {
        printf("Queue가 비어있습니다.");
        return NULL;
    }
    struct queueNode* temp = *head; //현재 head 임시 저장, free한 후에도 head 접근 가능
    struct inforNode* data = temp -> data;
    *head = (*head) -> next;

    free(temp);
    return data;
}



