#include "calculator.h"

void minus(struct listNode *front, struct listNode *rear)
{
        struct listNode *head = malloc(sizeof(struct listNode));
        int beta =  0;

        while (1) {
                if (front -> previous != NULL && rear -> previous != NULL) {
                        char x = listrpop(front);
                        char y = listrpop(rear);
                }
                else
                        break;

                listlpush(head, (x - beta < y) ? (x - y + 10) : (x - y));  

                if (x - beta < y)
                        beta = 1;
                else
                        beta = 0;

        }
        if (beta == 1)
                listlpush(head, beta);

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
