#include "calculator.h"

void plus(struct listNode *front, struct listNode *rear)
{
        struct listNode *head = malloc(sizeof(struct listNode));
        char alpha = '0';

        while (1) {
                if (front -> previous != NULL && rear -> previous != NULL) {
                        char x = listrpop(front);
                        char y = listrpop(rear);
                }
                else
                        break;


                listlpush(head,(x+y)%10+48+alpha%48);

                if (x+y-96 >= 10)
                        alpha = '1';
                else
                        alpha = '0';
        }

        if (alpha == '1')
                listlpush(head, alpha);

        if (front -> previous == NULL) {
                free(front -> next);
                free(front);
                rear -> next = head;
                return rear;
        }
        else if (rear -> previous == NULL) {
                free(rear -> next);
                free(rear);
                front -> next = head;
                return front;
        }
        else
                return head;
}
