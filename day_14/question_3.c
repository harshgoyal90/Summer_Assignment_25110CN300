//  Write a program to Second largest element   

# include<stdio.h>
int main () {
    int i, temp, max1, max2, p1 = 0, p2 = 0, n;
    printf("Enter element in a array : ");
    scanf("%d", &n);

    int A[n];
    for ( i = 0; i < n; i++) {
        printf("Enter Element Number %d : ", i);
        scanf("%d", &A[i]);
    }
     max1 = A[0];
    for (i = 0; i <  n; i++ ) {
        if ( max1 < A[i]) {
            max1 = A[i];
            p1 = i;
        }
    } 
    max2 = 0;
    for (i = 0; i < n; i++) {
        if (max2 < A[i] &&A[i] != max1){
            max2 = A[i];
            p2 = i;
        }
    }
    temp = A[p1];
    A[p1] = A[p2];
    A[p2] = temp;

    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}
