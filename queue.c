#include "calculator.h"

//큐 초기화 함수
void initQueue(struct queueNode** head, struct queueNode** tail) {
    *head = NULL; //큐가 비어있음
    *tail = NULL; //큐가 비어잇음
}

//큐가 비어 있는지 확인하는 함수
int isEmpty(struct queueNode* head) {
    return head -> next == NULL; //큐가 비어있음, head = 더미 노드(데이터 X)
}


//큐에 데이터 추가
void push(struct queueNode *head, struct inforNode *data) {
        struct queueNode* newQNode = (struct queueNode*)malloc(sizeof(struct queueNode));
        if (newQNode == NULL) {
                printf("메모리 할당 불가");
                return;
        }
        newQNode -> data = data;  //큐에 inforNode 저장
        newQNode -> next = head -> next; //newQNode 큐에 연결(head > newQNode > 큐)
        target -> next = newQNode; //target의 next를 newQNode로 연결

}

//큐에서 데이터 제거
//struct inforNode* data : 큐에 저장된 데이터
//pop함수의 반환형을 struct inforNode로 설정
struct inforNode* pop(struct queueNode* head) {
        if (isEmpty(*head)) {
                printf("Queue가 비어있습니다.");
                return NULL;
        }
        struct queueNode* temp = head -> next; //head->next 임시 노드(temp)에 저장, free한 후에도 head 접근 가능
        struct inforNode* data = temp -> data; // 저장된 데이터 추출
        head -> next = temp -> next; // 다음 노드로 head->next 갱신
        
        free(temp);
        return data;
}


