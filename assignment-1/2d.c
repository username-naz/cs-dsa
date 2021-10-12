#include<stdio.h>

int main(){
    int i,j;
    printf("Rows and Columns: ");
    scanf("%d %d", &i, &j);
    int oneD[i*j], twoD[i][j];
    
    for (int n = 0; n < i*j; n++) {
        scanf("%d", oneD + n);
    }
    
    for(int n = 0; n<i;n++)
        for(int m = 0; m<j;m++)
            twoD[i][j] = oneD[n*j + m];
    

    return 0;
}