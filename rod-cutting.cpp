#include<bits/stdc++.h>
using namespace std;
//dp array
int dp[1005][1005];
//unbounded knapsack implementation
int unbounded_knapsack(int n, int s, int v[], int w[]){
    //base case
    if(n==0 || s ==0 ) return 0;

    //memoization
    if(dp[n][s]!=-1){
        return dp[n][s];
    }

    if(w[n-1]<= s){
        int choice1 = v[n-1]+ unbounded_knapsack(n, s-w[n-1], v, w);
        int choice2= unbounded_knapsack(n-1, s, v, w);
        dp[n][s]= max(choice1, choice2);
        return dp[n][s];
    }
    else{
        return  dp[n][s]=unbounded_knapsack(n-1, s, v, w);
    }
    
}

int main(){
    int n;
    cin>>n;
     for(int i=0; i<=n; i++){
        for(int j=0; j<= n; j++){
            dp[i][j]= -1;
        }
    }
    int v[n], w[n];
    for(int i=0; i<n; i++){
        cin>>v[i];
        w[i]=i+1;
    }
    cout<<unbounded_knapsack(n,n, v,w)<<endl;


    return 0;
}