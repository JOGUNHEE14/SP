#include <stdio.h>
#include <stdlib.h>

struct stackNode {
        struct stackNode *next;
        char data;
};

struct listNode {
        struct listNode *previous;
        struct listNode *next;
        char data;
};

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

void push(struct stackNode *target, char data)
{
        struct stackNode *pushNode = malloc(sizeof(struct stackNode));

        pushNode -> next = target -> next;
        pushNode -> data = data;
        target -> next = pushNode;
}

char pop(struct stackNode *target)
{
        char popData;
        struct stackNode *popNode = target -> next;

        target -> next = popNode -> next;
        popData = popNode -> data;

        free(popNode);

        return popData;
}

int main(void)
{
        char x;
        int l = 0;
        struct stackNode *operator = malloc(sizeof(struct stackNode));

        operator -> next = NULL;

        printf("Input: \n");

        while ((x = getchar()) != '\n') {
                if (x == ' ');

                else if ('0' <= x && x <= '9')
                        printf("%c ", x);

                else if (x == ')') {
                        while (operator -> next != NULL) {
                               char oper = pop(operator);
                               if (oper == '(')
                                       break;
                               printf("%c ", oper);
                        }
                        l-=1;
                }

                else if (x == '(') {
                        push(operator, x);
                        l+=1;
                }

                else if (l != 0 || operator -> next == NULL || priority(operator, x) == 2) {
                        push(operator, x);
                }

                else {
                        while (operator -> next != NULL) {
                                if (priority(operator, x) == 2)
                                        break;
                                printf("%c ", pop(operator));
                        }
                        push(operator, x);
                }
        }
        while (operator -> next != NULL)
                printf("%c ",pop(operator));
        printf("\n");
        return 0;
}
