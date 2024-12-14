#include "calculator.h"
//수정중임

struct inforNode* plus(struct list *front, struct list *rear)  {
	struct inforNode *result = init();

	char alpha = '0';  // 자릿수더하기
	char resultt;
	struct listNode *cont; //끊기는 소수 자리 수 저장용
	struct listNode *end; // 끊기는 소수자리의 마지막 수

    // 1. 소수점 바로 뒤부터 겹치는 부분위치 찾기
    	struct listNode* decimalFront = front -> head;
    	struct listNode* decimalRear = rear -> head;

    // 겹치는 소수 부분 위치찾기
	if (decimalFront == NULL && deciamlRear == NULL);
	else if (decimalFront == NULL && decimalRear != NULL) {
		cont = decimalRear;
		end = rear -> tail;
	}
	else if (decimalFront != NULL && decimalRear == NULL) {
		cont = decimalFront;
		end = front -> tail;
	}
	else if (decimalFront != NULL && decimalRear != NULL) {
	    	while (decimalFront -> next != NULL && decimalRear -> next != NULL) {
			decimalFront = decimalFront->next;
	        	decimalRear = decimalRear->next;
	    	}
		
		// 끊기는 자리수랑 마지막 수 저장장
		if (decimalFront-> next == NULL && dcimaalRear -> next != NULL) {
			cont = decimalRear -> next;
			end = rear -> tail;
			rear -> tail = decimalRear;
		}
		else if (decimalFront -> next != NULL && decimalRear -> next ==NULL) {
			cont = decimalFront -> next;
			end = front -> tail;
			front -> tail = decimalFront;
		}
		else 
			cont = NULL; // 자리수가 같으면 NULL
			
		
		//수 계산 
		// listrpop을 하면 pop을 할 노드의 앞 노드의 주소가 사라져서 _prev 포인터를 만듬
	    	while (decimalFront != NULL && decimalRear != NULL) {
			struct listNode *decimalFront_prev = decimalFront -> previous;
			struct listNode *decimalRear_prev = decimalRear -> previous;
			
		        char x = listrpop(front -> decimal);
		        char y = listrpop(rear -> decimal);
	        	resultt = (x + y + alpha - 144) % 10 + 48;
	
	        	// 계산 값을 결과의 소수부분에 왼쪽에 푸쉬
	        	listlpush(result->decimal, resultt);

	        	// 자릿수 계산
	        	alpha = (x + y + alpha - 144 >= 10) ? '1' : '0';
	 		decimalFront=decimalFront_prev;
			decimalRear=decimalRear_prev;
		}
		// 자리수가 같으면연결할 필요가 없으니까 제끼기
		if (cont != NULL) {
			// 소수의 마지막 자리와 끊기는 소수의 시작부분 listNode 두개를 연결
			result -> decimal -> tail -> next = cont;
			cont -> previous = result -> decimal -> tail;
			result -> decimal -> tail = end;
		}
	}
		

    // 자연수 부분 계산
    	struct listNode* naturalFront = front -> tail;
    	struct listNode* naturalRear = rear -> tail;

    	while (naturalFront != NULL || naturalRear != NULL) {
        	char x = (naturalFront != NULL) ? listrpop(natural) : '0';
        	char y = (naturalRear != NULL) ? listrpop(rear->  : '0';
        	char resultt = (x + y + alpha - 144) % 10 + 48;

        	listlpush(result -> natural, resultt);

        	alpha = (x + y + alpha - 144 >= 10) ? '1' : '0';

        	if (naturalFront != NULL) naturalFront = naturalFront->previous;
        	if (naturalRear != NULL) naturalRear = naturalRear->previous;
    	}

    // 마지막 올림 처리
    if (alpha == '1') {
        listlpush(result->natural, alpha);
    }
	
    free(front);
    free(rear);	

    return result;
}
