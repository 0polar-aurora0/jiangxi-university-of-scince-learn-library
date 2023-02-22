
#include <stdio.h>
#include <ctype.h>

int main() {
    char c;//此时输入的是整型数字
    while (scanf("%s", c)) {
        if (isdigit(c)) {
           printf("accept\n");
        } else  printf("not accept\n");
    }
    return 0;
}
