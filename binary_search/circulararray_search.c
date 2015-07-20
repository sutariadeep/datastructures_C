//Binary Search to search element in a circular sorted array
#include <stdio.h>

int CircularArraySearch(int A[],int n,int x){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(x == A[mid]) return mid;   // Case 1: Found X, yeah :)
        if (A[mid] <= A[high]){       // Case 2: right half is sorted
            if (x > A[mid] && x <= A[high])
                low = mid + 1;        // go searching in right sorted half
            else
                high = mid -1;         // go searching left
        }
        else        //Case 3 : left half is sorted
        {
            if(A[low]<=x && x < A[mid])    // go searching in left sorted half
                high = mid - 1;
            else
                low = mid + 1;          // go searching right
        }
    }
    return -1;
}


int main(){
    int A[] = {4,5,6,7,8,1,2,3};
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    int index = CircularArraySearch(A,8,x);
    if (index == -1)
        printf("%d not found in the array",x);
    else
        printf("%d was found at index %d\n",x, index);
}

