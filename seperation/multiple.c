#include "calculator.h"

// 소수점을 무시하고 곱한뒤 소수점을 옮기는 방식으로 만듬

struct inforNode *multiplication(struct inforNode *front, struct inforNode *rear)
{
        struct inforNode *result = init();

        if ((front -> data == '+' && rear -> data == '+') || (front -> data == '-' && rear -> data == '-'))
                result -> data = '+';
        else
                result -> data = '-';

        //tmpFront는 곱하는 숫자를 한칸씩 늘리는 변수, tmpResult는 tmpFront와 같은 자리수를 따라감
        // moveRear랑 moveResult는 계속 한칸씩 자리수를 늘림

        // ex) front = 1234, Rear = 6789 
        // tmpFront = 4 -> (moveRear = 6, 7 , 8, 9 순서대로 저장)
        // tmpFront = 3 -> 위와 같음
        
        struct listNode *tmpResult;
        struct listNode *tmpFront;
        struct listNode *moveRear;
        struct listNode *moveResult;

        //num : result에 저장된 숫자의 정보를 담을 변수 (계산을 할 자리수에 있는 숫자를 저장)
        // alpha : 곱셈을 하고 올릴 수
        // y : tmpFront로 숫자를 저장, x : moveRear의 숫자를 저장, total : num과 alpha x곱하기y의 더한값 저장.
        int num = 0;
        int alpha = 0;
        int total = 0;
        int y = 0;
        int x = 0;

        char zero;
        
        // 0일 때 빨리 리턴
        if (front -> natural -> head != NULL && front -> natural -> head -> data == '0' && front -> decimal -> head == NULL) {
                listrpush(result -> natural ,'0');
                return result;
        }
        if (rear -> natural -> head != NULL && front -> natural -> head -> data == '0' && front -> decimal -> head ==NULL) {
                listrpush(result->natural,'0');
                return result;
        }

        // tmpFront를 시작할구간 지정(소수부분이 없으면 자연수부터)
        if (front -> decimal -> tail != NULL)
                tmpFront = front -> decimal -> tail;
        else
                tmpFront = front -> natural -> tail;

        // tmpResult의 처음 자리를 지정
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
                
                // 대충 곱하기 
                while (1) {
                        num = moveResult -> data - '0';
                        x = moveRear -> data - '0';
                        total = alpha + num + x * y;
                        alpha = total/10;
                        if (moveResult -> previous == NULL)
                                listlpush(result -> natural, '0');

                        moveResult -> data = total % 10 + 48;
                        if (moveRear -> previous == NULL)
                                listlpush(result -> natural, '0');

                        moveResult -> data = total % 10 + 48;
                        if (moveRear -> previous == NULL)
                                break;
                        moveResult = moveResult -> previous;
                        moveRear = moveRear -> previous;

                }
                // 소수부터 시작했으면 자연수도 곱하기
                if (moveRear == rear -> decimal -> head) {
                        if (moveResult -> previous == NULL)
                                listlpush(result -> natural,'0');
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
                }

                // 올릴 수가 남으면 앞에 추가
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

        // 소수점 옮기기
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
        
        // 자연수 앞자리가 0이 있는거 삭제(0.~ 인경우 제외)
        while (result -> natural -> head != NULL) {
                zero = result -> natural -> head -> data;
                if (zero == '0' && result -> natural -> head -> next != NULL)
                        listlpop(result -> natural);
                else
                        break;
        }
        // 소수부붙 끝자리에 0이있는거 삭제
        while (result -> decimal -> tail !=NULL) {
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
