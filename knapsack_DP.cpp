/*
    Link - https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

    Problem - 0/1 Knapsack Problem (you can either take an item or you cannot)

    Complexity - O(nW)

    Sol - In this as we know we can either take a item or we cannot

            1. If we take a item then we will add its value and solve same for other
                items
            2. If we don't take this item then we will solve for all left items

            3. We will consider max of 1, 2 step always

            So dp[i][j] means if we take ith item with j weight left in bag

                if(wt[i] <= j) dp[i][j] = max(val[i] + dp[i][j - wt[i]], dp[i - 1][j])
                else dp[i][j] = dp[i - 1][j];

            Note : We cannot take the item if its weight is more than allowed weight.

    Please see fractional Knapsack Problem (Greedy Approach)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
void solve(){
    int n, W;
    cin >> n >> W;
    vector<int> w(n), val(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < n; i++) cin >> val[i];
    
    vector<vector<int> > dp(n + 1, vector<int>(W + 1, 0));
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(w[i - 1] <= j){
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
            }else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][W];
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << '\n';
    }
	return 0;
}