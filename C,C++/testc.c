#include<stdio.h>
int isPerfectSquare(long double x) 
{ 
    long double sr = sqrt(x); 
    if((sr - floor(sr)) == 0)
        return 1;
    else
    {
        return 0;
    }
    
} 
int findSubarraySum(int arr[], int n, int K) 
{ 
    unordered_map<int, int> prevSum; 
  
    int res = 0; 
    int currsum = 0; 
  
    for (int i = 0; i < n; i++) { 
        currsum += arr[i]; 
        if (currsum == K) { 
            res++; 
        } 
        if (prevSum.find(currsum - K) 
            != prevSum.end()) 
            res += (prevSum[currsum - K]); 
  
        prevSum[currsum]++; 
    }  
    return res; 
} 
void countSubarray(int arr[], int n, int K) 
{ 
    for (int i = 0; i < n; i++) { 
        if (isPerfectSquare(arr[i])) { 
            arr[i] = 1; 
        } 
        else { 
            arr[i] = 0; 
        } 
    } 
    printf("%d",findSubarraySum(arr, n, K)); 
} 
int main() 
{ 
    int arr[] = { 2, 4, 9, 2 }; 
    int K = 2; 
    int N = sizeof(arr) / sizeof(arr[0]); 
  
    countSubarray(arr, N, K); 
    return 0; 
} 