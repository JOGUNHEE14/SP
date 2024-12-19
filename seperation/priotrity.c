#include "calculator.h"

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
        
        if (result < com)
                return 2;
        else if (result == com)
                return 1;
        return 0;
}
