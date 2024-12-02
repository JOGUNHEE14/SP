#include <stdio.h>
#include <stdlib.h>

//연산자 넣을 노드
struct stackNode {
        struct stackNode *next;
        char data;
};

//숫자 넣을 노드
struct listNode {
        struct listNode *previous; // 숫자리스트의 head의 previous 부분에 임시적으로 소수점 시작위치를 저장함
        struct listNode *next;
        char data;
};

//숫자를 저장한 list노드를 저장하는 노드
struct queueNode {
        struct queueNode *next;
        struct inforNode *data;
};

// 큐에 infroNode를 저장해서 사용할 예정. 자연수는 natural_부분에 소수는 decimal_에 저장하고 부호는 data에 저장예정
struct inforNode {
        struct listNode *natural_head;
        struct listNode *natural_tail;
        struct listNode *decimal_head;
        struct listNode *decimal_tail;
        char data;
};

int priority(struct stackNode *target, char com);

void stackpush(struct stackNode *target, char data);
char stackpop(struct stackNode *target);
void plus(struct listNode *front, struct listNode *rear);
