#include <stdio.h>

int main(){
    int i, n1, n2, n3, height = 0;
    printf("Enter the height: \n");
    scanf("%d", &height);
    printf("Pattern:");
    for (i = 1; i <= height; i++){
        if (i%3 == 0) {
            printf("\n");
            for(n3 = 1; n3 <= i; n3++){
                printf("3"); } }
        else if (i%3 == 2) {
            printf("\n");
            for(n2 = 1; n2 <= i; n2++){
                 printf("2");} }
        else if (i%3 == 1) {
            printf("\n");
            for(n1 = 1; n1 <= i; n1++){
                 printf("1");} }
    }
    return 0;
}
