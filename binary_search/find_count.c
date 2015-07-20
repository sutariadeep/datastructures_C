//Binary Search to find count of an element in a sorted array
#include <stdio.h>
#include <stdbool.h>

int FindCount(int A[],int n,int x, bool searchFirst){
    int low = 0;
    int high = n-1;
    int result = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if (x == A[mid]) {
            result = mid;
            if(searchFirst)
                high = mid - 1;   //This is for first occurence
            else
                low = mid + 1;  //This is for last occurence
        }
        else if (x < A[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return result;
}


int main(){
    int A[] = {1,1,3,3,5,5,5,5,5,9,9,11};
    printf("Enter a number: ");
    int x; scanf("%d",&x);
    int firstIndex = FindCount(A,sizeof(A)/sizeof(A[0]),x, true);
    if (firstIndex == -1){
        printf ("Count of %d is %d",x,0);
    }
    else{
        int lastIndex = FindCount(A,sizeof(A)/sizeof(A[0]),x, false);
        printf("Count of %d is %d",x,lastIndex-firstIndex+1);
    }
}

