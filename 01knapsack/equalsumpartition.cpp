//check whether an array can be divided into two sub arrays with equal sum
// Created by Cherry on 9/16/2020.
#include <iostream>

bool knapsack(int arr[4], int n, int sum, int dp[100][100]);

using namespace std;

int main() {
    int arr[]={11,11,0};
    int sum=0;
    for (int i = 0; i < 3; ++i) {
        sum+=arr[i];
    }
    int dp[100][100];
    for (int j = 0; j < 100; ++j) {
        for (int i = 0; i < 100; ++i) {
            dp[i][j]=-1;
        }
    }
    if(sum%2==0){
        cout<<knapsack(arr,3,sum/2,dp);
    }
    else{
        cout<< false;
    }
    return 0;
}

bool knapsack(int arr[4], int n, int sum, int dp[100][100]) {
    bool inc,exc;
    if(sum==0){
        return true;
    }
    if(n==0&&sum!=0){
        return false;
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    if(sum>=arr[n-1]){
        inc=knapsack(arr,n-1,sum-arr[n-1],dp);
        exc=knapsack(arr,n-1,sum,dp);
        return dp[n][sum]=inc||exc;
    } else{
        exc=knapsack(arr,n-1,sum,dp);
    }
}

