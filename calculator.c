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

//숫자를 저장한 list노드랑 다음 queueNode를 하는 노드
struct queueNode {
        struct queueNode *next;
        struct inforNode *data;
};

// 큐에 infroNode를 저장해서 사용할 예정. 숫자면 head부분에 주소저장, 연산자면 data에 저장.
struct inforNode {
        struct listNode *head;
        char data;
};

//연산자 비교하는 코드 -,+를 같은 레벨, *,/ 를 같은 레벨로 만들고 result와 com에 저장된 연산자 비교해서 리턴
// 아스키 코드 ( *: 42, +: 43, -: 45, /:47)
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

void listrpush() {

}

void listlpush() {

}

char listrpop() {

}

char listlpop() {

}

void queuepush() {

}

char queuepop() {

}



int main(void)
{
        char x; //입력을 하나하나 받을 때 쓸 문자열 타입변수
        int gwalho = 0; // 괄호가 스택에 있는지 확인할 때 쓸 변수
        struct stackNode *operator = malloc(sizeof(struct stackNode)); // 스택을 처음 만들 때 operator를 사용해서 push할 예정

        operator -> next = NULL; // operator가 가라키는 포인터 초기화

        printf("Input: \n");

        while ((x = getchar()) != '\n') {
                if (x == ' '); // 대충 공백처리

                // 대충 숫자면 프린트 -> 숫자를 리스트노드를 이용해서 저장해야함
                else if ('0' <= x && x <= '9')  
                        printf("%c ", x);
                
                // 닫는 괄호가 입력으로 들어오면 여는 괄호가 나올 때 까지 연산자 꺼내기
                else if (x == ')') {  
                        while (operator -> next != NULL) {
                               char oper = stackpop(operator);
                               if (oper == '(')
                                       break;
                               printf("%c ", oper);
                        }
                        gwalho-=1;
                }

                // 여는 괄호가 들어오면 l번의 값을 늘림
                else if (x == '(') { 
                        stackpush(operator, x);
                        gwalho+=1;
                }

                // 여는 괄호가 주어지면 계속 연산자를 넣어야하기 때문에 l이 0이 아니고 스택의 마지막에 저장된 연산자보다 넣을 연산자가 크면 push
                else if (gwalho != 0 || operator -> next == NULL || priority(operator, x) == 2) {
                        stackpush(operator, x);
                }

                // 넣을 연산자랑 스택에 연산자의 우선순위가 작거나 같으면 가능한 만큼 pop하고 연산자 push
                else {
                        while (operator -> next != NULL) {
                                if (priority(operator, x) == 2)
                                        break;
                                printf("%c ", pop(operator));
                        }
                        stackpush(operator, x);
                }
        }
        while (operator -> next != NULL)
                printf("%c ",stackpop(operator));
        printf("\n");
        return 0;
}
