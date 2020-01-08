/*
    Link - https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0/?track=sp-dynamic-programming&batchId=152

    Problem - Knapsack with Duplicate items

    Sol - In this we have whole items array all the time so a item can be repetedly selected
            so we need only 1 D array dp[i]

            dp[i] = max(dp[i], dp[i - wt[j]] for j = 0 .... n - 1);

    Complexity - O(nW);
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
void solve(){
    int n, w;
    cin >> n >> w;
    vector<int> val(n), wt(n);
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    for(int i = 0; i < n; i++){
        cin >> wt[i];
    }
    int ans = 0;
    int dp[w + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= w; i++){
        for(int j = 0; j < n; j++){
            if(i - wt[j] >= 0){
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);
            }
        }
    }
    cout << dp[w];
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