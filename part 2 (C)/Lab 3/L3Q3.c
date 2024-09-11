#include <stdio.h>
void reverser1D(int ar[], int size);

int main(){
    int ar[10];
    int size, i;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i = 0; i <= (size-1); i++)
        scanf("%d", &ar[i]);
    reverseAr1D(ar, size);
    printf("reverseAr1D(): ");
    if (size > 0){
        for (i = 0; i < size; i++)
            printf("%d", ar[i]);
    }
    return 0;
}

void reverseAr1D(int ar[], int size){
    int j;
    for (j = 0; j < (size/2); j++){
        int rar = ar[j];
        ar[j] = ar[size - 1 - j];
        ar[size - 1 - j] = rar;
    }
}
