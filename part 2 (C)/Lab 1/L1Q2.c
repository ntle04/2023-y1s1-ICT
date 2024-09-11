#include <stdio.h>

int main() {
    int lineNo, nLine, nNum;
    float num, ave, sum;
    printf("Enter number of lines: \n");
    scanf("%d", &lineNo);
    for (nLine = 1; nLine <= lineNo; nLine++){
        printf("Enter line %d (end with -1):\n", nLine);
        scanf("%f", &num);
        nNum = 0;
        sum = 0;
        while (num != -1){
            nNum++;
            sum += num;
            scanf("%f", &num);}
        ave = sum/nNum;
        printf("Average = %.2f\n", ave);
    }
    return 0;
}
