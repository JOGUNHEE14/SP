#include "calculator.h"

struct inforNode* minus(struct inforNode *front, struct inforNode *rear) {
    struct inforNode *result = init();

    char beta = '0';  // 자릿수 빼기
    char resultt;
    char x;
    char y;
    int com = 0; // front랑 rear 중 뭐가 큰지 구분 front가 크거나 같을시 1, rear가 클시 2

    // front와 rear 값 비교
    struct listNode* naturalFront = front->natural->head;
    struct listNode* naturalRear = rear->natural->head;
    struct listNode* decimalFront = front->decimal->head;
    struct listNode* decimalRear = rear->decimal->head;

    while (1) {
        if (naturalFront == NULL && naturalRear != NULL) {
            com = 2;
            break;
        } else if (naturalFront != NULL && naturalRear == NULL) {
            com = 1;
            break;
        } else if (naturalFront == NULL && naturalRear == NULL) {
            com = 3; // 자연수의 자릿수가 같을경우 com=3으로 넘어감감
            break;
        }
        naturalFront = naturalFront->next;
        naturalRear = naturalRear->next;
    }

    // 다시 써야 돼서 초기화
    naturalFront = front->natural->head;
    naturalRear = rear->natural->head;

	//앞자리부터 하나씩 꺼내어 크기비교
    if (com == 3) {
        while (1) {
            if (naturalFront == NULL && naturalRear == NULL) {
                com = 4; //자연수부분도 같을 시 com=4로 넘어감
                break;
            }

            x = naturalFront->data;
            y = naturalRear->data;

            if (x > y) {
                com = 1;
                break;
            } else if (y > x) {
                com = 2;
                break;
            }
            naturalFront = naturalFront->next;
            naturalRear = naturalRear->next;
        }
    }

    // 소수점 자릿수 맞추기 위해 0 채우기
    while (decimalFront != NULL || decimalRear != NULL) {
        if (decimalFront == NULL) {
            listrpush(front->decimal, '0'); // 상위 리스트의 head를 수정
        }
        if (decimalRear == NULL) {
            listrpush(rear->decimal, '0'); // 상위 리스트의 head를 수정
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
	//소수부분 앞자리부터 하나씩꺼내 크기비교교
    if (com == 4) {
        while (decimalFront != NULL && decimalRear != NULL) {
            x = decimalFront->data;
            y = decimalRear->data;

            if (x > y) {
                com = 1;
                break;
            } else if (y > x) {
                com = 2;
                break;
            }
            decimalFront = decimalFront->next;
            decimalRear = decimalRear->next;
        }
    }
 	//두 수가 같을경우
    if (com==4) {
	com = 1;
    }
    decimalFront = front->decimal->tail;
    decimalRear = rear->decimal->tail;

    // 뺄셈 시작
    if (com == 1) {
        if (front->decimal->tail != NULL && rear->decimal->tail != NULL) {
            x = listrpop(front->decimal);
            y = listrpop(rear->decimal);

            resultt = (x < y) ? (x + 10 - y) + 48 : (x - y) + 48;
            listlpush(result->decimal, resultt);
            (x < y) ? beta = '1' : '0';
        }

        while (1) {
            if (front->decimal->tail != NULL && rear->decimal->tail != NULL) {
                x = listrpop(front->decimal);
                x = x - beta % 48;
                y = listrpop(rear->decimal);
                if (y > x) {
			beta = '1';
		}
 		else if (x>=y) {
			beta = '0';
		}

                resultt = (x < y) ? (x + 10 - y) + 48 : (x - y) + 48;
                listlpush(result->decimal, resultt);
            } else {
                break;
            }
        }

        // 자연수 부분 계산
        struct listNode* naturalFront = front->natural->tail;
        struct listNode* naturalRear = rear->natural->tail;

        while (1) {
            if (front->natural->tail != NULL || rear->natural->tail != NULL) {
                x = (front->natural->tail != NULL) ? listrpop(front->natural) : '0';
                x = x - beta % 48;
                y = (rear->natural->tail != NULL) ? listrpop(rear->natural) : '0';
                if (y > x) {
			beta = '1';
		}
 		else if (x>=y) {
			beta = '0';
		}

                resultt = (x < y) ? (x + 10 - y) + 48 : (x - y) + 48;
                listlpush(result->natural, resultt);
            } else {
                break;
            }
        }
    }
	//rear가 클시 y에서 x빼는 식으로 변경
    if (com == 2) {
        if (front->decimal->tail != NULL && rear->decimal->tail != NULL) {
            x = listrpop(front->decimal);
            y = listrpop(rear->decimal);

            resultt = (y < x) ? (y + 10 - x) + 48 : (y - x) + 48;
            listlpush(result->decimal, resultt);
            (x > y) ? beta = '1' : '0';
        }

        while (1) {
            if (front->decimal->tail != NULL && rear->decimal->tail != NULL) {
                x = listrpop(front->decimal);
                y = listrpop(rear->decimal);
                y = y - beta % 48;
                if (y < x) {
			beta = '1';
		}
 		else if (y>=x) {
			beta = '0';
		}

                resultt = (y < x) ? (y + 10 - x) + 48 : (y - x) + 48;
                listlpush(result->decimal, resultt);
            } else {
                break;
            }
        }

        // 자연수 부분 계산
        struct listNode* naturalFront = front->natural->tail;
        struct listNode* naturalRear = rear->natural->tail;

        while (1) {
            if (front->natural->tail != NULL || rear->natural->tail != NULL) {
                x = (front->natural->tail != NULL) ? listrpop(front->natural) : '0';
                y = (rear->natural->tail != NULL) ? listrpop(rear->natural) : '0';
                y = y - beta % 48;
                if (y < x) {
			beta = '1';
		}
 		else if (y>=x) {
			beta = '0';
		}

                resultt = (y < x) ? (y + 10 - x) + 48 : (y - x) + 48;
                listlpush(result->natural, resultt);
            } else {
                break;
            }
            result->data = '-'; //결과가 음수이므로 데이터에 -부호 저장
        }
    }

    free(front->natural);
    free(front->decimal);
    free(rear->natural);
    free(rear->decimal);
    free(front);
    free(rear);

    return result;
}
