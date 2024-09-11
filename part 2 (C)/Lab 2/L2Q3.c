#include <stdio.h>
int square1(int num);
void square2(int num, int *result);

int main(){
    int number, result=0;
    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("square1(): %d\n", square1(number));
    square2(number, &result);
    printf("square2(): %d\n", result);
    return 0;
}

int square1(int num){
    int count, sum=0, digit=1;
    if (num > 0)
        for(count=1; count <= num; count++){
            sum += digit+2;}
    return sum;
}

void square2(int num, int *result){
    int count, digit=1;
    if (num > 0)
        for(count=1; count <= num; count++){
            *result += digit+2;}
}
