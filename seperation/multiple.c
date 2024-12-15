#include "calculator.h"

struct inforNode *multiple(struct inforNode *front, struct inforNode *rear)
{
        struct inforNode *result = init();

        //tmpResult랑 tmpFront는 반복문에서 한번 움직임
        // moveResult랑 moveRear는 계속 움직임
        struct listNode *tmpResult;
        struct listNode *tmpFront;
        struct listNode *moveRear;
        struct listNode *moveResult;

        //num은 결과값에 저장된 자리수에 해당하는숫자
        // alpha는 올림값, y는 tmpResult의 값, x 는 moveRear의 값
        // total은 x와y를 곱한값에 alpha와 num을 더한값
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

        // front에서 움직일 위치 선정(소수가 없으면 정수부터 시작)
        if (front -> decimal -> tail != NULL)
                tmpFront = front -> decimal -> tail;
        else
                tmpFront = front -> natural -> tail;

        listlpush(result -> natural, '0');
        tmpResult = result -> natural -> tail;

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
                if (moveResult -> previous == NULL)
                        listlpush(result -> natural,'0');
        
                if (moveRear == rear -> decimal -> head) {
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
                }
                if (moveResult -> previous == NULL)
                        listlpush(result -> natural, alpha+48);
                else
                        moveResult -> previous -> data = alpha+48;

                if (tmpFront -> previous != NULL)
                        tmpFront = tmpFront -> previous;
                else if (tmpFront == front -> decimal -> head)
                        tmpFront = front -> natural -> tail;
                else
                        break;

                tmpResult = tmpResult -> previous;

        }
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
        if (result -> natural -> head == NULL)
                listlpush(result -> natural,'0');
        else if (result -> natural -> head -> data == '0' && result -> natural -> head -> next != NULL)
                listlpop(result -> natural);

        while(result -> decimal -> tail != NULL) {
                if (result -> decimal -> tail -> data == '0')
                        listrpop(result -> decimal);
                else
                        break;
        }

        free(front -> natural);
        free(front -> decimal);
        free(rear -> natural);
        free(rear -> decimal);
        free(front);

        return result;
}



