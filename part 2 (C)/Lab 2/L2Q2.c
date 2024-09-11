#include <stdio.h>
int digitPos1(int num, int digit);
void digitPos2(int num, int digit, int *result);

int main() {
    int number, digit, result=0;
    printf("Enter the number \n");
    scanf("%d", &number);
    printf("Enter the digit \n");
    scanf("%d", &digit);
    printf("digitPos1: %d\n", digitPos1(number, digit));
    digitPos2(number, digit, &result);
    printf("digitPos2: %d\n", result);
    return 0;
    }

int digitPos1(int num, int digit) {
    int posNum=0;
    do { posNum++;
        if(num%10 == digit){
            break;}
        num /= 10;
    } while(num > 0);
    return posNum;
}

void digitPos2(int num, int digit, int *result){
    int pos = 0;
    *result = 0;
    do{ pos++;
        if(num%10 == digit){
            *result = pos;
            break;}
        num /= 10;
    } while(num > 0);
}
