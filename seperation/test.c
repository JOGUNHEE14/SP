#include "calculator.h"

int main(void)
{
        FILE *fp = fopen("input.txt","r");
        struct inforNode *number = init();
        char x = getc(fp);
        while ('0' <= x && x <= '9') {
                listrpush(number -> natural, x);
                x = getc(fp);
        }
        x = getc(fp);
        while ('0' <= x && x<= '9') {
                listrpush(number -> decimal, x);
                x = getc(fp);
        }
        x = getc(fp);
        x=getc(fp);
        struct inforNode *number1 = init();

        while ('0' <= x && x <= '9') {
                listrpush(number1 -> natural, x);
                x = getc(fp);
        }
        x=getc(fp);
        while ('0' <= x && x <= '9') {
                listrpush(number1 -> decimal, x);
                x = getc(fp);
        }
        struct inforNode *result = minus(number,number1);


        while (result->natural->head!=NULL) {
                x = listlpop(result->natural);
                printf("%c",x);
        }
        printf(".");
        while (result -> decimal -> head!=NULL) {
                x = listlpop(result -> decimal);
                printf("%c",x);
        }
        return 0;



}
