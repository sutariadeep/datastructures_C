//Binary Search to find first and last occurrence of a number
#include <stdio.h>

int BinarySearch(int A[],int n,int x){
    int low = 0;
    int high = n-1;
    int result = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if (x == A[mid]) {
            result = mid;
            high = mid - 1;   //This is for first occurence
            //low = mid + 1;  //This is for last occurence
        }
        else if (x < A[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return result;
}


int main(){
    int A[] = {2,4,10,10,10,18,20};
    printf("Enter a number: ");
    int x; scanf("%d",&x);
    int index = BinarySearch(A,7,x);
    if(index != -1) printf("Number %d is at index %d",x,index);
    else printf("Number %d not found",x);
}

