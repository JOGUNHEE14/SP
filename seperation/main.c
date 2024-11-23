#include "calculator.h"

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
