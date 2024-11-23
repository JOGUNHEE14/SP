#include <stdio.h>
#include <stdlib.h>

//연산자 넣을 노드
struct stackNode {
        struct stackNode *next;
        char data;
};

//숫자 넣을 노드
struct listNode {
        struct listNode *previous;
        struct listNode *next;
        char data;
};

//숫자를 저장한 list노드를 저장하는 노드
struct queueNode {
        struct queueNode *next;
        struct inforNode *data;
};

// 큐에 infroNode를 저장해서 사용할 예정. 숫자면 head부분에 주소저장, 연산자면 data에 저장.
struct inforNode {
        struct listNode *head;
        char data;
};

int priority(struct stackNode *target, char com);

void stackpush(struct stackNode *target, char data);
char stackpop(struct stackNode *target);
void plus(struct listNode *front, struct listNode *rear);
