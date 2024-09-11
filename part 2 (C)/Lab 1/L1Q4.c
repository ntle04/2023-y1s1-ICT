#include <stdio.h>

int main(){
    int i, j, k;
    double x, denom, nume, term, result = 0;
    printf("Enter x: \n");
    scanf("%lf", &x);
    for (i =0; i <= 10; i++){
        nume = 1;
        for (j = 1; j <= i; j++){
            nume *= x;}
        denom = 1;
        for (k = 1; k <= i; k++){
            denom *= k;}
        term = (nume/denom);
        result+= term;}
    printf("Result = %.2f", result);
    return 0;
}
