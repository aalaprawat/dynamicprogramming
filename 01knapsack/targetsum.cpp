//target sum with given signs of plus/minus
// Created by Cherry on 9/17/2020.
#include <iostream>

int dp[100][100];
int knapsack(int arr[4], int target, int sum, int n,int dp[100][100]);

using namespace std;

int main() {
    int arr[]={1,1,1,1};
    int sum=1,target=sum;
    for (int j = 0; j < 100; ++j) {
        for (int i = 0; i < 100 ; ++i) {
            dp[i][j]=-1;
        }
    }
    cout << knapsack(arr,target,0,4,dp);
}

int knapsack(int arr[4], int target, int sum, int n,int dp[100][100]) {
    int a,b;

    if(dp[sum][n]!=-1){
        return dp[sum][n];
    }
    if(n==0&&target!=sum){
        return dp[sum][n]= 0;
    }
    if(n==0&&target==sum){
        return dp[sum][n]=1;
    }
    a=knapsack(arr,target,sum+arr[n-1],n-1,dp);
    b=knapsack(arr,target,sum-arr[n-1],n-1,dp);
    return dp[sum][n]=a+b;
}

