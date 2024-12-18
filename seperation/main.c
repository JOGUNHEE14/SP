#include "calculator.h"

int main(void)
{
        char pre = '\0'; // x(현재)의 이전 문자자
        char x; //입력을 하나하나 받을 때 쓸 문자열 타입변수
        int gwalho = 0; // 괄호가 스택에 있는지 확인할 때 쓸 변수
        struct stackNode *operator = malloc(sizeof(struct stackNode)); // 스택을 처음 만들 때 operator를 사용해서 push할 예정
        struct queueNode *numbers = malloc(sizeof(struct queueNode)); // listNode에 저장된 숫자와 부호가 저장된 infoNode를 저장할 예정 
        struct inforNode *front_number;
        struct inforNode *rear_number;
        struct inforNode *result_number;
        
        operator -> next = NULL; // operator가 가라키는 포인터 초기화
        numbers -> next = NULL;

        FILE *file = fopen("tmp.txt", "r");
        printf("파일을 정상적으로 열었습니다.\n");

        
        printf("====== Welcome to infinite calculator! ======\n");
        printf("Enter the expression in infix notation.\n");
        printf("Input : ");

        while (1) {
                x = getc(file); // file 포인터를 만들어야함.
                if (x == '\n' || x == EOF || x == '\0')
                        break;
                        
                else if (x == ' '); // 대충 공백처리

                // 대충 숫자면 프린트 -> 숫자를 inforNode를 이용해서 저장해야함
                else if (('0' <= x && x <= '9')) {
                        printf("%c",x);
                        struct inforNode *number = init();
                        
                        //data에 부호 넣어야 하는데 대충 플러스로 함
                        while ('0' <= x && x <= '9') {
                                listrpush(number -> natural, x);
                                x = getc(file);
                                printf("%c",x);
                        }
        
                        if (x == '.') {
                                x = getc(file);
                                printf("%c",x);
                                while ('0' <= x && x <= '9') {
                                        listrpush(number -> decimal, x);
                                        x = getc(file);
                                        printf("%c",x);
                                }
                        }
                        push(numbers, number);
                }       
                
                // 닫는 괄호가 입력으로 들어오면 여는 괄호가 나올 때 까지 연산자 꺼내기
                if (x == ')') {  
                        while (operator -> next != NULL) {
                                char oper = stackpop(operator);
                                if (oper == '(')
                                        break;
                                
                                rear_number = pop(numbers);
                                if (oper = '-') {
                                        if (isEmpty(numbers)) {
                                                rear_number -> data = (rear_number -> data == '+') ? '-' : '+';
                                                push(numbers,rear_number);
                                        }
                                        else {
                                                front_number = pop(numbers);
                                                if (front_number -> data =='-' && rear_number -> data =='+') {
                                                        result_number = plus(front_number,rear_number);
                                                        result_number -> data = '-';
                                                        push(numbers,result_number);
                                                }
                                                else if(front_number -> data == '+' && rear_number -> data =='-') {
                                                        result_number = plus(front_number,rear_number);
                                                        result_number -> data = '+';
                                                        push(numbers,result_number);
                                                }
                                                else {
                                                        result_number = minus(front_number,rear_number);
                                                        push(numbers,result_number);
                                                }
                                        }              
                                }

                                else if (oper == '+') {
                                        if (isEmpty(numbers))
                                                push(numbers,rear_number);
                                        else {
                                                front_number = pop(numbers);
                                                if (front_number -> data == '+' && rear_number -> data == '+') {
                                                        result_number = plus(front_number,rear_number);
                                                        result_number -> data = '+';
                                                        push(numbers,result_number);
                                                }
                                                else {
                                                        result_number = minus(front_number,rear_number);
                                                        push(numbers,result_number);
                                                }
                                        }
                                }
                                else if (oper == '*') {
                                        front_number = pop(numbers);
                                        result_number = multiplication(front_number, rear_number);
                                        push(numbers,result_number);
                                }
                        } 
                        gwalho-=1;
                }

                // 여는 괄호가 들어오면 gwalho에 값을 1늘림
                else if (x == '(') { 
                        //곱셈 기호 생략
                        //숫자 * 괄호 or 괄호 * 괄호 or 음수 부호 * 괄호
                        if (('0' <= pre && pre <= '9') || pre == ')' || pre == '-') {
                                stackpush(operator, '*');
                                pre = x;
                        }
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
                                char oper = stackpop(operator);
                                rear_number = pop(numbers);
                                
                                if (oper = '-') {
                                        if (isEmpty(numbers)) {
                                                rear_number -> data = (rear_number -> data == '+') ? '-' : '+';
                                                push(numbers,rear_number);
                                        }
                                        else {
                                                front_number = pop(numbers);
                                                if (front_number -> data =='-' && rear_number -> data =='+') {
                                                        result_number = plus(front_number,rear_number);
                                                        result_number -> data = '-';
                                                        push(numbers,result_number);
                                                }
                                                else if(front_number -> data == '+' && rear_number -> data =='-') {
                                                        result_number = plus(front_number,rear_number);
                                                        result_number -> data = '+';
                                                        push(numbers,result_number);
                                                }
                                                else {
                                                        result_number = minus(front_number,rear_number);
                                                        push(numbers,result_number);
                                                }
                                        }              
                                }
                                else if (oper == '+') {
                                        if (isEmpty(numbers))
                                                push(numbers,rear_number);
                                        else {
                                                front_number = pop(numbers);
                                                if (front_number -> data == '+' && rear_number -> data == '+') {
                                                        result_number = plus(front_number,rear_number);
                                                        result_number -> data = '+';
                                                        push(numbers,result_number);
                                                }
                                                else {
                                                        result_number = minus(front_number,rear_number);
                                                        push(numbers,result_number);
                                                }
                                        }
                                }
                                else if (oper == '*') {
                                        front_number = pop(numbers);
                                        result_number = multiplication(front_number, rear_number);
                                        push(numbers,result_number);
                                } 
                                if (priority(operator, oper) == 2)
                                        break;
                        }
                        stackpush(operator, x);
                }
        }
        while (operator -> next != NULL) {
                char oper = stackpop(operator);
                if (oper = '-') {
                        if (isEmpty(numbers)) {
                                rear_number -> data = (rear_number -> data == '+') ? '-' : '+';
                                push(numbers,rear_number);
                        }
                        else {
                                front_number = pop(numbers);
                                if (front_number -> data =='-' && rear_number -> data =='+') {
                                        result_number = plus(front_number,rear_number);
                                        result_number -> data = '-';
                                        push(numbers,result_number);
                                }
                                else if(front_number -> data == '+' && rear_number -> data =='-') {
                                        result_number = plus(front_number,rear_number);
                                        result_number -> data = '+';
                                        push(numbers,result_number);
                                }
                                else {
                                        result_number = minus(front_number,rear_number);
                                        push(numbers,result_number);
                                }
                        }              
                }
                else if (oper == '+') {
                        if (isEmpty(numbers))
                                push(numbers,rear_number);
                        else {
                                front_number = pop(numbers);
                                if (front_number -> data == '+' && rear_number -> data == '+') {
                                        result_number = plus(front_number,rear_number);
                                        result_number -> data = '+';
                                        push(numbers,result_number);
                                }
                                else {
                                        result_number = minus(front_number,rear_number);
                                        push(numbers,result_number);
                                }
                        }
                }
                else if (oper == '*') {
                        front_number = pop(numbers);
                        result_number = multiplication(front_number, rear_number);
                        push(numbers,result_number);
                }
        }
        
        result_number = pop(numbers);
        
        printf("\n");
        printf("result : ");
        
        while (result_number->natural->head!=NULL) {
                x = listlpop(result_number->natural);
                printf("%c",x);
        }
        if (result_number -> decimal -> head != NULL) {
                printf(".");
                while (result_number -> decimal -> head!=NULL) {
                        x = listlpop(result_number -> decimal);
                        printf("%c",x);
                }
        }
        printf("\n");
        return 0;
}
