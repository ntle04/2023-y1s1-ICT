#include <stdio.h>
int main(){
	int studentNumber = 0, mark;
	printf("Enter Student ID: \n");
	scanf("%d", &studentNumber);
	while (studentNumber != -1) {
        	printf("Enter Mark: \n");
        	scanf("%d", &mark);
        	switch (mark) {
			case 75 ... 100:
                		printf("Grade = A\n");
                		break;
            		case 65 ... 74:
                		printf("Grade = B\n");
                		break;
            		case 55 ... 64:
                		printf("Grade = C\n");
                		break;
            		case 45 ... 54:
                		printf("Grade = D\n");
                		break;
            		case 0 ... 44:
                		printf("Grade = F\n");
                		break;}
        	printf("Enter Student ID: \n");
        	scanf("%d", &studentNumber);}
	return 0;
}
