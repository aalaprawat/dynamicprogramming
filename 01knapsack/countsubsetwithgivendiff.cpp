//count all the subset with a given difference
// Created by Cherry on 9/17/2020.
#include <iostream>

using namespace std;

int dp[100][100];
int knapsack (int arr[4],int sum,int n,
              int dp[100][100]){
    int a,b;
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
        a=knapsack(arr,sum-arr[n-1],n-1,dp);
        b=knapsack(arr,sum,n-1,dp);

        return dp[sum][n]=a+b;
    }
    else{
        b=knapsack(arr,sum,n-1,dp);
    }
}



int main() {
    int arr[]={1,1,2,3};
    int sum=0,diff=1;
    for (int i = 0; i < 4 ; ++i) {
        sum+=arr[i];
    }
    sum=sum-diff;
    for (int j = 0; j < 100; ++j) {
        for (int i = 0; i < 100 ; ++i) {
            dp[i][j]=-1;
        }
    }
    if(sum%2!=0){
        cout<<0;
    }


    else{
        cout<<knapsack(arr,sum/2,4,dp);
    }
    return 0;
}
