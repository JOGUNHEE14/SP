#include "calculator.h"
//수정중임

struct inforNode* plus(struct inforNode* front, struct inforNode* rear)  {
	struct inforNode* result = init();

	char alpha = '0';  // 자릿수더하기
	char resultt;
	struct listNode *con; //끊기는 소수 자리 수 저장용
	struct listNode *end; // 끊기는 front or rear의 마지막 수 pointer위치

    // 1. 소수점 바로 뒤부터 겹치는 부분위치 찾기
    	struct listNode* decimalFront = front->decimal_head;
    	struct listNode* decimalRear = rear->decimal_head;

    // 겹치는 소수 부분 위치찾기
    	while (decimalFront->next != NULL || decimalRear != NULL) {
		decimalFront = decimalFront->next;
        	decimalRear = decimalRear->next;
    	}	
	// 끊기는 자리수랑 마지막 수 저장장
	if (decimalFront-> next == NULL) {
		con = decimalRear -> next;
		end = front -> decimal_tail;
	}
	else if (decimalRear -> next == NULL) {
		con = decimalFront -> next;
		end = rear -> decimal_tail;
	}
	else {
		con = NULL;
		end = NULL
	}

	//수 계산 
    	while (decimalFront->previous != NULL && decimalRear->previous != NULL) {
		struct listNode *decimalFront_prev = decimalFront -> previous;
		struct listNode *decimalRear_prev = decimalFront -> previous;
	        char x = listrpop(decimalFront)
	        char y = listrpop(decimalRear)
        	resultt = (x + y + alpha - 144) % 10 + 48;

        // 계산된 결과를 결과 리스트에 추가
        	listlpush(result->decimal_head, resultt);
		result -> decimal_head = result -> decimal_head -> previous;

        // 자릿수 계산
        	alpha = (x + y + alpha - 144 >= 10) ? '1' : '0';
 		decimalFront=decimalFront_prev;
		decimalRear=decimalRear_prev;
	}

	inforNode -> head_tail -> next = con;
	result -> decimal_tail = end;

    // 자연수 부분 계산
    	struct listNode* naturalFront = front->natural_tail;
    	struct listNode* naturalRear = rear->natural_tail;

    	while (naturalFront != NULL || naturalRear != NULL) {
        	char x = (naturalFront != NULL) ? naturalFront->data : '0';
        	char y = (naturalRear != NULL) ? naturalRear->data : '0';
        	char resultt = (x + y + alpha - 144) % 10 + 48;

        	listrpush(&result->natural_head, resultt);

        	alpha = (x + y + alpha - 144 >= 10) ? '1' : '0';

        	if (naturalFront != NULL) naturalFront = naturalFront->previous;
        	if (naturalRear != NULL) naturalRear = naturalRear->previous;
    	}

    // 마지막 올림 처리
    if (alpha == '1') {
        listrpush(&result->natural_head, alpha);
    }
	
    struct listNode* temp;
    while (front->decimal_head != NULL) {
        temp = front->decimal_head;
        front->decimal_head = front->decimal_head->next;
        free(temp); 
    }

    while (rear->decimal_head != NULL) {
        temp = rear->decimal_head;
        rear->decimal_head = rear->decimal_head->next;
        free(temp);  
    }

    while (front->natural_head != NULL) {
        temp = front->natural_head;
        front->natural_head = front->natural_head->next;
        free(temp);  
    }

    while (rear->natural_head != NULL) {
        temp = rear->natural_head;
        rear->natural_head = rear->natural_head->next;
        free(temp); 
    }
	
    free(front);
    free(rear);	

    return result->natural_head;
}
