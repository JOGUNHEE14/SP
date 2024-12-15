#include "calculator.h"

struct inforNode *multiple(struct inforNode *front, struct inforNode *rear)
{
        struct inforNode *result = init();

        struct listNode *tmpResult;
        struct listNode *tmpFront;
        struct listNode *moveRear;
        struct listNode *moveResult;

        char alpha = '0';
        char total = '0';
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
                moveResult = tmpResult;
                if (rear -> decimal -> tail != NULL)
                        moveRear = rear -> decimal -> tail;
                else
                        moveRear = rear -> natural -> tail;

                while (1) {
                        total = (alpha + moveResult -> data + (moveRear -> data * tmpFront -> data)) % 48;
                        alpha = total/10 + 48;
                        if (moveResult -> previous == NULL)
                                listlpush(result -> natural, (total%48)%10+48);
                        else
                                moveResult -> data = (total%48)%10 + 48;
                        if (moveRear -> previous == NULL)
                                break;
                        moveResult = moveResult -> previous;
                        moveRear = moveRear -> previous;
                }
                if (moveRear == rear -> decimal -> head) {
                        moveRear = rear -> natural -> tail;
                        while (1) {
                                total = (alpha + moveResult -> data + (moveRear -> data * tmpFront -> data)) % 48;
                                alpha = total/10 + 48;
                                if (moveResult -> previous == NULL)
                                        listlpush(result -> natural, (total%48)%10 + 48);
                                else
                                        moveResult -> data = (total%48)%10 + 48;
                                if (moveRear -> previous == NULL)
                                        break;
                                moveResult = moveResult -> previous;
                                moveRear = moveRear -> previous;
                        }
                }
		if (alpha > '0')
			listlpush(result -> natural, alpha);
                if (tmpFront -> previous != NULL)
                        tmpFront = tmpFront -> previous;
                else if (tmpFront == front -> decimal -> head)
                        tmpFront = front -> natural -> tail;
                else
                        break;
                if (tmpResult -> previous != NULL)
                        tmpResult = tmpResult -> previous;
        }

        while(rear -> decimal -> head != NULL) {
                result -> decimal -> head = result -> natural -> tail;
                result -> natural -> tail = result -> decimal -> head -> previous;
                if (result -> natural -> tail == NULL)
                        listrpush(result -> natural,'0');
                listrpop(rear -> decimal);
        }
        while (rear -> natural -> head != NULL)
                listrpop(rear -> natural);
        while(front -> decimal -> head != NULL) {
                result -> decimal -> head = result -> natural -> tail;
                result -> natural -> tail = result -> decimal -> head -> previous;
                if (result -> natural -> tail == NULL)
                        listrpush(result -> natural,'0');
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
                                                                                                                                             
