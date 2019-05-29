#include <iostream>
#include <limits>
#include <math.h>

using namespace std;

int findMaxCross(int A[],int p,int q,int r){
    //max subarray of A[i .. ... mid]
    int pmax = 0;
    int rmax = 0;
    int psum = numeric_limits<long>::min();
    int sum = 0;
    for(int i = q; i >= p; i--){
        sum = sum + A[i];
        if(sum > psum){
            psum = sum;
            pmax = i;
        }
    }
        //max subarray of A[mid+1 ... j]
    int rsum = numeric_limits<long>::min();
    sum = 0;
    for(int j = q + 1; j <= r; j++){
        sum = sum + A[j];
        if(sum > rsum){
            rsum = sum;
            rmax = j;
        }
    
    }
    return (psum + rsum);
}

int findMaxSub(int A[],int p,int r){
    int q = 0;
    int psum = 0, xsum = 0, rsum = 0;

    if (r == p){

        return (A[p]);
    }
    else{
         q = floor((p + r)/2);

         psum= findMaxSub(A, p, q);

         rsum= findMaxSub(A, q + 1, r);

         xsum= findMaxCross(A, p, q, r);
    
    if (psum >= rsum && psum >= xsum){

        return psum;
    }
        else if(rsum >= psum && rsum >= xsum){
            
            return rsum;
        }
        else
        {
            return xsum;
        }
    }
}


int main(){

	int arraySize;

	cin >> arraySize;
    //initialize the array this way from now but ignore this error
	int *A = new int[arraySize];
	
	for(int i=0;i<arraySize;i++)
	{
		cin>>A[i];
	}

    int result = findMaxSub(A,0,arraySize-1);

        cout << result;
}