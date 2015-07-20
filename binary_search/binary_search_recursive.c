//Binary Search using Recursive method
#include <stdio.h>

int BinarySearch(int A[],int low,int high,int x){
    if (low > high) return -1;
    int mid = low + (high-low)/2; //low+high can overflow
    if(x == A[mid]) return mid;   // Found X, return (exit)
    else if(x < A[mid]) return BinarySearch(A, low, mid-1,x); //X kies before mid
    else return BinarySearch(A, mid+1, high, x);   //X lies after mid
}


int main(){
    int A[] = {2,4,5,7,13,14,15,23};
    printf("Enter a number: ");
    int x; scanf("%d",&x);
    int index = BinarySearch(A,0,8,x);
    if(index != -1) printf("Number %d is at index %d",x,index);
    else printf("Number %d not found",x);
}

