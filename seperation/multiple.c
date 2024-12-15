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
        int y = 0;
        int x = 0;
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
        struct listNode *b;
        while (tmpFront != NULL)
        {
                alpha = 0;
                y = tmpFront -> data - '0';
                moveResult = tmpResult;

                if (rear -> decimal -> tail != NULL)
                        moveRear = rear -> decimal -> tail;
                else
                        moveRear = rear -> natural -> tail;

                while (1) {
                        num = moveResult -> data - '0';
                        x = moveRear -> data - '0';
                        total = alpha + num + x * y;
                        alpha = total/10;

                        if (moveResult -> previous == NULL)
                                listlpush(result -> natural, '0');

                        moveResult -> data = total % 10 + 48;
                        if (moveRear -> previous == NULL)
                                break;
                        moveResult = moveResult -> previous;
                        moveRear = moveRear -> previous;

                }
                if (moveRear == rear -> decimal -> head) {
                        if(moveResult -> previous == NULL)
                                listlpush(result -> natural, '0');

                        moveResult = moveResult -> previous;
                        moveRear = rear -> natural -> tail;

                        while (1) {
                                num = moveResult -> data - '0';
                                x = moveRear -> data - '0';
                                total = alpha + num + x * y;
                                alpha = total/10;

                                if (moveResult -> previous == NULL)
                                        listlpush(result -> natural, '0');

                                moveResult -> data = total % 10 + 48;


                                if (moveRear -> previous == NULL)
                                        break;
                                moveResult = moveResult -> previous;
                                moveRear = moveRear -> previous;
                        }
                        b = result ->  natural -> head;
                }
                if (alpha > 0){
                        if (moveResult -> previous == NULL)
                                listlpush(result -> natural, alpha+48);
                        else
                                moveResult -> previous -> data = alpha+48;

                }
                if (tmpFront -> previous != NULL)
                        tmpFront = tmpFront -> previous;
                else if (tmpFront == front -> decimal -> head)
                        tmpFront = front -> natural -> tail;
                else
                        break;

                tmpResult = tmpResult -> previous;

        }
        b = result -> natural -> head;
        printf("-----\n");
        while (b!=NULL) {
                printf("%c",b->data);
                b = b -> next;
        }
        printf("======\n");
        while(rear -> decimal -> head != NULL) {
                if (result -> natural -> tail == NULL)
                        listrpush(result -> natural,'0');
                listlpush(result -> decimal, listrpop(result -> natural));
                listrpop(rear -> decimal);
        }
        while (rear -> natural -> head != NULL)
                listrpop(rear -> natural);

        while(front -> decimal -> head != NULL) {
                if (result -> natural -> tail == NULL)
                        listrpush(result -> natural,'0');
                listlpush(result -> decimal, listrpop(result -> natural));
                listrpop(front -> decimal);
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
