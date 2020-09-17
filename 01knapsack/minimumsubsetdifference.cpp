//
// Created by Cherry on 9/16/2020.
#include <iostream>

bool knapsack(int arr[4], int sum, int n, int dp[100][100]);

using namespace std;

int main() {
    int arr[]={1,6,13,5};
    int sum=0;
    for(int i=0;i<4;i++){
        sum+=arr[i];
    }

    int dp[100][100];
    for (int j = 0; j < 100; ++j) {
        for (int i = 0; i < 100; ++i) {
            dp[i][j]=-1;
        }
    }
    for(int i=sum/2;i<=sum;i++){
        bool a=false;
        a=knapsack(arr,i,4,dp);
        if(a){
            cout<<abs(((sum)-(sum-i))-(sum-i));
            break;
        }
    }
    return 0;
}

bool knapsack(int arr[4], int sum, int n, int dp[100][100]) {
    bool a,b;
    if(sum==0){
        return true;
    }
    if(sum!=0&&n==0){
        return false;
    }
    if(dp[sum][n]!=-1){
        return dp[sum][n];
    }
    if(arr[n-1]<=sum){
        a=knapsack(arr,sum-arr[n-1],n-1,dp);
        b=knapsack(arr,sum,n-1,dp);
        return dp[sum][n]= a||b;
    }
    else{
        b=knapsack(arr,sum,n-1,dp);
    }
}
