//question of 01 knapsack where value and weight is given
// Created by Cherry on 9/16/2020.
#include <iostream>


using namespace std;

int knapsack(int weight[3], int price[3], int W, int n,int dp[5][100]) {
    int a,b;
    if(n==0||W==0){
        return dp[n][W] = 0;
    }
    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    if(weight[n-1]<=W){
        a=knapsack(weight,price,W-weight[n-1],n-1,dp)+price[n-1];
        b=knapsack(weight,price,W,n-1,dp);
        return dp[n][W]=max(a,b);
    }
    else{
        b=knapsack(weight,price,W,n-1,dp);
    }
}


int main() {
    int dp[5][100];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 100; ++j) {
            dp[i][j]=-1;
        }
    }
    int price[3]={60,100,120};
    int weight[3]={10,20,30};
    int W=50;
    cout<<knapsack(weight,price,W,3,dp);

}
