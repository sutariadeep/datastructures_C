//Binary Search to find number of times sorted array is rotateds
#include <stdio.h>


int FindRotationCount(int A[],int n){
    int low = 0;
    int high = n-1;
    while(low <= high){
        if(A[low] <= A[high]) return low;  // Case 1
        int mid = low + (high-low)/2;
        int next = (mid+1)%n, prev = (mid+n-1)%n;
        if(A[mid] <= A[next] && A[mid] <= A[prev])   // Case 2
            return mid;
        else if(A[mid] <= A[high]) high = mid - 1;   //Case 3
        else if(A[mid] >= A[low]) low = mid + 1;   //Case 4
    }
    return -1;
}


int main(){
    int A[] = {4,5,6,7,8,1,2,3};
    int count = FindRotationCount(A,8);
    printf("The array is rotated %d times",count);
}

