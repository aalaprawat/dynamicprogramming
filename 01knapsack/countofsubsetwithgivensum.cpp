//count of subset with a given sum
// Created by Cherry on 9/16/2020.
#include <iostream>

int knapsack(int arr[6], int sum, int n, int dp[100][100]);
static int count=0;
using namespace std;

int main() {
    int arr[]={2,3,5,6,8,10};
    int sum=10;
    int dp[100][100];
    for (int j = 0; j < 100; ++j) {
        for (int i = 0; i < 100; ++i) {
            dp[i][j]=-1;
        }
    }
    cout<<knapsack(arr,sum,6,dp);
    cout<<count;
    return 0;
}

int knapsack(int arr[6], int sum, int n, int dp[100][100]) {
    int inc,exc;
    if(sum==0){
        return 1;
    }
    if(n==0&&sum!=0){
        return 0;
    }
    if(dp[sum][n]!=-1){

        return dp[sum][n];
    }
    if(arr[n-1]<=sum){

        inc = knapsack(arr,sum-arr[n-1],n-1,dp);
        exc = knapsack(arr,sum,n-1,dp);

        return dp[sum][n]=inc+exc;
    }
    else{

        exc = knapsack(arr,sum,n-1,dp);
    }
}


