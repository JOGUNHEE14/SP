#include "calculator.h"

//*의 아스키코드가 42이고 /의 아스키코드가 47이므로 곱셈을 받았다면 곱셈의 아스키코드에 5를 더하여 나눗셈과 같은 수를 가지도록 한다.
//덧셈도 마찬가지로 2를 더하여 뺄셈의 아스키코드와 동일하게 만든다.
int priority(struct stackNode *target, char com) {
        char result = (target -> next) -> data;
        if (result =='*')
                result += 5;
        else if (result == '+')
                result += 2;
        
        if (com == '*')
                com += 5;
        else if (com == '+')
                com += 2;
        // 연산자가 스택 맨 위 연산자보다 우선순위가 높다면 2를 반환, 같다면 1을 반환, 낮다면 0을 반환한다.
        if (result < com)
                return 2;
        else if (result == com)
                return 1;
        return 0;
}
