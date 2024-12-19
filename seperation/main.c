#include "calculator.h"

int main(void)
{
        char pre = '\0'; // x(현재)의 이전 문자
        char x = '\0'; //입력을 하나하나 받을 때 쓸 문자열 타입변수
        int sign = 0;
        struct stackNode *operator = malloc(sizeof(struct stackNode)); // 스택을 처음 만들 때 operator를 사용해서 push할 예정
        struct queueNode *numbers = malloc(sizeof(struct queueNode)); // listNode에 저장된 숫자와 부호가 저장된 infoNode를 저장할 예정 
        struct inforNode *front_number;
        struct inforNode *rear_number;
        struct inforNode *result_number;
        
        operator -> next = NULL; // operator가 가라키는 포인터 초기화
        numbers -> next = NULL;

        FILE *file = fopen("tmp.txt", "r");
        if (file != NULL)
                printf("파일을 정상적으로 불러왔습니다.\n");
        else {
                printf("파일 불러오기를 실패했습니다. 사용자입력을 받습니다.\n");
                file = stdin;
        }

        
        printf("====== Welcome to infinite calculator! ======\n");
        printf("Enter the expression in infix notation.\n");
        printf("Input : ");


        while (x!= EOF && x != '\n') {
                x=getc(file);
                
                if (x == ' '); // 대충 공백처리

                // 대충 숫자면 프린트 -> 숫자를 inforNode를 이용해서 저장해야함
                else if (('0' <= x && x <= '9')) {
                        struct inforNode *number = init();
                        if (pre == '-') {
                                number -> data = '-';
                                if (isEmpty(numbers))
                                        stackpop(operator);
                        }
                        pre = x;
                        //data에 부호 넣어야 하는데 대충 플러스로 함
                        while ('0' <= x && x <= '9') {
                                listrpush(number -> natural, x);
                                printf("%c",x);
                                x = getc(file);
                        }
        
                        if (x == '.') {
                                printf("%c",x);
                                x = getc(file);
                        
                                while ('0' <= x && x <= '9') {
                                        listrpush(number -> decimal, x);
                                        printf("%c",x);
                                        x = getc(file);               
                                }
                        }
                        push(numbers, number);
                        ungetc(x,file);
                        continue;
                }       
                
                // 닫는 괄호가 입력으로 들어오면 여는 괄호가 나올 때 까지 연산자 꺼내기
                else if (x == ')') {  
                        printf("%c",x);
                        pre = x; //이전 문자(pre) 업데이트
                        while (operator -> next != NULL) {
                                char oper = stackpop(operator);
                                if (oper == '(')
                                        break;
                                
                                rear_number = pop(numbers);
                                
                                if (oper == '-') {
                                        rear_number -> data = '-';
                                        if (isEmpty(numbers))
                                                stackpop(operator);
                                        push(numbers,rear_number);
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
                                                else if(front_number -> data == '-' && rear_number -> data == '-') {
                                                        result_number = plus(front_number,rear_number);
                                                        result_number -> data = '-';
                                                        push(numbers,result_number);
                                                }
                                                else if (front_number -> data == '+' && rear_number -> data == '-'){
                                                        result_number = minus(front_number,rear_number);
                                                        push(numbers,result_number);
                                                }
                                                else  {
                                                        result_number = minus(rear_number,front_number);
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
                        if (operator->next != NULL && operator -> next -> data == '-')
                                numbers -> next -> data -> data = stackpop(operator);
                        else if (operator->next != NULL && operator -> next -> data == '*') {
                                stackpop(operator);
                                push(numbers,multiplication(pop(numbers),pop(numbers)));
                                if (operator->next != NULL && operator -> next -> data == '-') {
                                        numbers -> next -> data -> data = stackpop(operator);
                                        if (isEmpty(numbers))
                                                stackpop(operator);
                                }
                        }
                }

                // 여는 괄호가 들어오면 무조건 푸쉬
                else if (x == '(') { 
                        printf("%c",x);
                        //곱셈 기호 생략
                        //숫자 * 괄호 or 괄호 * 괄호 or 음수 부호 * 괄호
                        if (('0' <= pre && pre <= '9') || pre == ')') 
                                stackpush(operator, '*');
                        pre = x;
                        stackpush(operator,x);
                }

                // 연산자 순위가 밀리거나 연산자 stack이 비어있으면 푸쉬
                else if (operator -> next == NULL || priority(operator, x) == 2) {
                        printf("%c",x);
                        if (x == '-')
                                stackpush(operator,'+');
                        stackpush(operator,x);
                        pre = x; //이전 문자(pre) 업데이트
                        
                }

                // 넣을 연산자랑 스택에 연산자의 우선순위가 작거나 같으면 가능한 만큼 pop하고 연산자 push
                else if (x=='+'  || x == '*' || x == '/' || x=='-'){
                        pre = x; //이전 문자(pre) 업데이트
                        printf("%c",x);
                        while (operator -> next != NULL) {
                                char oper = stackpop(operator);
                                rear_number = pop(numbers);
                                if (oper == '-') {
                                        rear_number->data = '-';
                                        if (isEmpty(numbers))
                                                stackpop(operator);
                                        push(numbers,rear_number);
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
                                                else if (front_number -> data == '-' && rear_number -> data == '-'){
                                                        result_number = plus(front_number,rear_number);
                                                        result_number -> data = '-';
                                                        push(numbers,result_number);
                                                }
                                                else if (front_number -> data == '+' && rear_number -> data == '-'){
                                                        result_number = minus(front_number,rear_number);
                                                        push(numbers,result_number);
                                                }
                                                else {
                                                        result_number = minus(rear_number,front_number);
                                                        push(numbers,result_number);
                                                }
                                        }
                                }
                                else if (oper == '*') {
                                        front_number = pop(numbers);
                                        result_number = multiplication(front_number, rear_number);
                                        push(numbers,result_number);
                                } 
                                if (operator -> next == NULL || priority(operator, oper) == 2)
                                        break;
                        }
                        if (x == '-')
                                stackpush(operator,'+');
                        stackpush(operator, x);
                }
        }  
        while (operator -> next != NULL) {
                char oper = stackpop(operator);
                rear_number = pop(numbers);

                if (oper == '-') {
                        rear_number->data = '-';
                        if (isEmpty(numbers))
                                stackpop(operator);
                        push(numbers,rear_number);
                }
                else if (oper == '+') {
                        if (isEmpty(numbers)) {
                                push(numbers,rear_number);
                                continue;
                        }
                        else
                                front_number = pop(numbers);
                        
                        if (front_number -> data == '+' && rear_number -> data == '+') {
                                result_number = plus(front_number,rear_number);
                                result_number -> data = '+';
                                push(numbers,result_number);
                        }
                        else if (front_number -> data == '-' && rear_number -> data == '-') {
                                result_number = plus(front_number,rear_number);
                                result_number -> data = '-';
                                push(numbers,result_number);
                        }
                        else if (front_number -> data == '+' && rear_number -> data == '-'){
                                result_number = minus(front_number,rear_number);
                                push(numbers,result_number);
                        }
                        else {
                                result_number = minus(rear_number,front_number);
                                push(numbers,result_number);
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

        if (result_number -> data == '-')
                printf("-");
        
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
        free(operator);
        free(numbers);
        return 0;
}
