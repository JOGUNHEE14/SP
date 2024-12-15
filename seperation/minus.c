#include "calculator.h"

struct inforNode* minus(struct inforNode* front, struct inforNode* rear) {
    struct inforNode *result = init();

    char beta= '0';  // 자릿수빼기
    char resultt;
    char x;
    char y;
    int com = 0; //front 랑 rear중 뭐가큰지 구분 front가 클시1 rear일시 2
    
    //front 와 rear 값 비교
    struct listNode* naturalFront = front->natural->head;
    struct listNode* naturalRear = rear->natural->head;
    struct listNode* decimalFront = front->decimal->head;
    struct listNode* decimalRear = rear->decimal->head;

    while (1) {
	if (naturalFront == NULL && naturalRear != NULL) {
		com = 2;
		break;
	}
	else if (naturalFront != NULL && naturalRear == NULL) {
		com = 1;
		break;
	}
	else if (naturalFront == NULL && naturalRear == NULL) {
		com = 3;
		break;
	}
	naturalFront = naturalFront->next;
	naturalRear = naturalRear->next;
    }
		//다시써야되서 초기화
    naturalFront = front->natural->head;
    naturalRear = rear->natural->head;
    if (com == 3) {
	while (1) {

		if (naturalFront == NULL && naturalRear == NULL) {
			com = 4;
			break;
		}

		x = naturalFront -> data;
		y = naturalRear -> data;

		if (x > y) {
			com = 1;
			break;
		}
		else if (y > x) {
			com = 2;
			break;
		}
		naturalFront = naturalFront->next;
      	        naturalRear = naturalRear->next;
	}
    }
		//소수점 자릿수 맞추기위해 0채우기
    while (decimalFront != NULL || decimalRear != NULL) {
	if (decimalFront == NULL) {
     		listlpush(front->decimal, '0'); // 상위 리스트의 head를 수정
        }
	if (decimalRear == NULL) {
    		listlpush(rear->decimal, '0'); // 상위 리스트의 head를 수정
	}

	if (decimalFront != NULL) {
		decimalFront = decimalFront->next;
	}
	if (decimalRear != NULL) {
		decimalRear = decimalRear->next;	
	}	
    	
    }
	
    decimalFront = front->decimal->head;
    decimalRear = rear->decimal->head;

    if (com == 4) {
	while (decimalFront != NULL && decimalRear != NULL) {
		x = decimalFront -> data;
		y = decimalRear -> data;

		if (x > y) {
			com = 1;
			break;
		}
		else if (y > x) {
			com = 2;
			break;
		}
		decimalFront = decimalFront->next;
      	        decimalRear = decimalRear->next;
	}
    }
	
    decimalFront = front->decimal->tail;
    decimalRear = rear->decimal->tail;
	//뺄셈 시작
    if (com ==1) {
	    while (1) {
		if (decimalFront != NULL && decimalRear != NULL) {
			 x = listrpop(front->decimal);
			 y = listrpop(rear->decimal); 
			 (x - beta%48 < y) ? beta = '1' : '0';
	
			
			resultt = (x - beta%48 < y) ? (x - beta%48 + 10 - y) + 48 : (x - beta%48 - y);
			listlpush(result ->decimal, resultt);
		}	
		else
			break;
		}

   	  // 자연수 부분 계산
   	  struct listNode* naturalFront = front->natural->tail;
          struct listNode* naturalRear = rear->natural->tail;

   	  while (1) {
		if (naturalFront != NULL || naturalRear != NULL) {
			 x = (naturalFront != NULL) ? listrpop(front->natural) : '0';
			 y = (naturalRear != NULL) ? listrpop(rear->natural) : '0';
			 (x - beta%48 < y) ? beta = '1' : '0';
			
		 	 resultt = (x - beta%48 < y) ? (x - beta%48 + 10 - y) + 48 : (x - beta%48 - y);
			 listlpush(result ->natural, resultt);
		}
		else
			break;
		
         }
    }
    if (com ==2) {
	    while (1) {
		if (decimalFront != NULL && decimalRear != NULL) {
			x = listrpop(front->decimal);
			y = listrpop(rear->decimal); 
			(y - beta%48 < x) ? beta = '1' : '0';
	
		
			resultt = (y - beta%48 < x) ? (y - beta%48 + 10 - x) + 48 : (y - beta%48 - x);
			listlpush(result ->decimal, resultt);
		}
		else
			break;
		}

   	  // 자연수 부분 계산
   	  struct listNode* naturalFront = front->natural->tail;
          struct listNode* naturalRear = rear->natural->tail;

   	  while (1) {
		if (naturalFront != NULL || naturalRear != NULL) {
			x = (naturalFront != NULL) ? listrpop(front->natural) : '0';
			y = (naturalRear != NULL) ? listrpop(rear->natural) : '0';
			(y - beta%48 < x) ? beta = '1' : '0';
			
			resultt = (y - beta%48 < x) ? (y - beta%48 + 10 - x) + 48 : (y - beta%48 - x);
			listlpush(result ->natural, resultt);
		}
		else
			break;
		result -> data= '-';
         }

    }
        	
    free(front -> natural);
    free(front -> decimal); 
    free(rear -> natural);
    free(rear -> decimal);
    free(front);
    free(rear);


    return result;
}
