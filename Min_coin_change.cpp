/*
    Link - https://practice.geeksforgeeks.org/problems/coin-change/0/?track=sp-dynamic-programming&batchId=152

    Problem - Coin Change

    Approach - Bottom up approach 
                dp[i][j] = ways to have change for ith coin using coins upto j

                2 cases

                1. if(i - coins[j] >= 0) dp[i][j] += dp[i - coins[j]][j];

                2. if(j >= 1) dp[i][j] += dp[i][j - 1]; add ways uptil last coin

            - Top Down Approach

               1. we can either use ith coin
               2. we can discard this coin

               add solution of both
    
    Complexity - O(nm)

*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
int dp[303][303];
int comp(int target, int st, int n, vector<int> &coins){
    if(st == n) return (target == 0);
    if(target < 0) return 0;
    if(dp[target][st] != -1) return dp[target][st];
    if(target == 0) return dp[target][st] = 1;
    int ans = 0;
    for(int i = st; i < n; i++){
        ans += comp(target - coins[i], i, n, coins);
    }
    return dp[target][st] = ans;
}
void topdown(){
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    int target;
    cin >> target;
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += comp(target - coins[i], i, n, coins);
    }
    cout << ans;
}
void bottomup(){
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    int target;
    cin >> target;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) dp[0][i] = 1;
    for(int i = 1; i <= target; i++){
        for(int j = 0; j < n; j++){
            if(i - coins[j] >= 0) dp[i][j] += dp[i - coins[j]][j];
            if(j >= 1) dp[i][j] += dp[i][j - 1];
        }
    }
    cout << dp[target][n - 1];
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        topdown();
        bottomup();
        cout << '\n';
    }
	return 0;
}
