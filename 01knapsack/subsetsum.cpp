//subset sum problem whether a given sum is present as a subarray
// Created by Cherry on 9/16/2020.
#include <iostream>

using namespace std;

bool knapsack(int arr[5], int size, int sum,int dp[20][20]) {
    bool inc,exc;
    if(sum==0){
        return dp[size][sum]=1;
    }
    if(size==0&&sum!=0){
        return dp[size][sum]= 0;
    }
    if(dp[size][sum]!=-1){
        return dp[size][sum];
    }

    if(arr[size-1]<=sum){
        inc=knapsack(arr,size-1,sum-arr[size-1],dp);
        exc=knapsack(arr,size-1,sum,dp);
        return dp[size][sum] = inc || exc;
    }
    else{
        exc=knapsack(arr,size-1,sum,dp);
    }
}

int main() {
    int arr[]={2,3,7,8,10};
    int size=5;
    int sum=13;
    int dp[20][20];
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            dp[i][j]=-1;
        }
    }
    cout<<knapsack(arr,size,sum,dp);
    return 0;
}



