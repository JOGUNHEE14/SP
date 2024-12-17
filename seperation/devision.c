#include "calculator.h"

// 안 만들 가능성 높음 !!!!!!!!!!!!!
struct inforNode *devision(struct inforNode *front, struct inforNode *rear)
{
        struct inforNode *result = init();

        // 결과값 부호 설정
        if ((front -> data == '+' && rear -> data == '+') || (front -> data == '-' && rear -> data == '-'))
                result -> data = '+';
        else
                result -> data = '-';
        
        // 자리수 맞추기
        while (front -> decimal -> head != NULL && rear -> decimal -> head != NULL) {
                if (front -> decimal -> head != NULL)
                        listrpush(front -> natural, listlpop(front -> decimal));
                else
                        listrpush(front -> natural, '0');

                if (rear -> decimal -> head != NULL)
                        listrpush(rear -> natural, listlpop(rear -> decimal));
                else
                        listrpush(rear -> natural, '0');
        }
        
        if (front -> decimal -> head == NULL  );

        
        
        
  
        free(front -> natural);
        free(front -> decimal);
        free(rear -> natural);
        free(rear -> decimal);
        free(front);
        free(rear);

        return result;
}
