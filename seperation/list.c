#include "calculator.h"

struct inforNode *multiple(struct inforNode *front, struct inforNode *rear)
{
        struct inforNode *result = init();

        struct listNode *tmpResult;
        struct listNode *tmpFront;
        struct listNode *moveRear;
        struct listNode *moveResult;

        int num = 0;
        int alpha = 0;
        int total = 0;
        // 0일 때 빨리 리턴
        if (front -> natural -> head != NULL && front -> natural -> head -> data == '0' && front -> decimal -> head == NULL) {
                listrpush(result -> natural ,'0');
                return result;
        }
        if (rear -> natural -> head != NULL && front -> natural -> head -> data == '0' && front -> decimal -> head ==NULL) {
                listrpush(result->natural,'0');
                return result;
        }

        if (front -> decimal -> tail != NULL)
                tmpFront = front -> decimal -> tail;
        else
                tmpFront = front -> natural -> tail;

        listlpush(result -> natural, '0');
        tmpResult = result -> natural -> tail;

        while (tmpFront != NULL)
        {
                alpha = 0;
                moveResult = tmpResult;
                if (rear -> decimal -> tail != NULL)
                        moveRear = rear -> decimal -> tail;
                else
                        moveRear = rear -> natural -> tail;
                printf("-----------\n");
                while (1) {
                        printf("%c\n",alpha);
                        num = moveResult -> data - '0';
                        total = alpha + num + (moveRear -> data * tmpFront -> data)%48;
                        alpha = total/10;
                        if (moveResult -> previous == NULL)
                                listlpush(result -> natural, '0');
                        moveResult -> data = total%10 + 48;
                        printf("alpah : %d, d : %c\n",alpha, moveResult -> data);
                        if (moveRear -> previous == NULL)
                                break;
                        moveResult = moveResult -> previous;
                        moveRear = moveRear -> previous;

                }
                printf("----------\n");
                if(moveResult -> previous == NULL)
                        listlpush(result -> natural, '0');
                moveResult = moveResult -> previous;
                if (moveRear == rear -> decimal -> head) {
                        moveRear = rear -> natural -> tail;
                        while (1) {
                                printf("%c\n",alpha);
                                num = moveResult -> data - '0';
                                total = alpha + num + (moveRear -> data * tmpFront -> data)%48;
                                alpha = total/10;
                                if (moveResult -> previous == NULL)
                                        listlpush(result -> natural, '0');
                                moveResult -> data = total%10 + 48;
                                printf("alpha : %d, d : %c\n",alpha,moveResult -> data);
                                if (moveRear -> previous == NULL)
                                        break;
                                moveResult = moveResult -> previous;
                                moveRear = moveRear -> previous;
                        }
                }
                if (alpha > 0){
                        if (moveResult -> previous == NULL)
                                listlpush(result -> natural, alpha+48);
                        else
                                moveResult -> previous -> data = alpha+48;
                        printf("d : %c\n",moveResult->previous->data);
                }
                if (tmpFront -> previous != NULL)
                        tmpFront = tmpFront -> previous;
                else if (tmpFront == front -> decimal -> head)
                        tmpFront = front -> natural -> tail;
                else
                        break;

                tmpResult = tmpResult -> previous;

        }
        char x;

        while(rear -> decimal -> head != NULL) {
                if (result -> natural -> tail == NULL)
                        listrpush(result -> natural,'0');
                x = listrpop(result -> natural);
                printf("%c",x);
                listlpush(result -> decimal,x);
                listrpop(rear -> decimal);
                result->natural -> tail = result -> decimal -> head -> previous;
        }
        while (rear -> natural -> head != NULL)
                listrpop(rear -> natural);

        while(front -> decimal -> head != NULL) {
                if (result -> natural -> tail == NULL)
                        listrpush(result -> natural,'0');
                x = listrpop(result -> natural);
                printf("%c",x);
                listlpush(result -> decimal,x);
                listrpop(front -> decimal);
                result -> natural -> tail = result -> decimal -> head -> previous;
        }
        while (front -> natural -> head != NULL)
                listrpop(front -> natural);

        free(front -> natural);
        free(front -> decimal);
        free(rear -> natural);
        free(rear -> decimal);
        free(front);

        return result;
}

