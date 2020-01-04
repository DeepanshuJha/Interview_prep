/*
    Link - https://practice.geeksforgeeks.org/problems/min-coin/0/?track=sp-greedy&batchId=152

    Problem - Standard Min coin problem

    Sol - Greedy (Not working always) and DP

    ex - (9, 6, 5, 1) amount - 11

    Complexity - O(n^2)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
void solve(){
    int n, amount;
    cin >> n >> amount;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    vector<ll> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= amount; i++){
        for(int j = 0; j < n; j++){
            if(i - v[j] >= 0){
                if(dp[i - v[j]] + 1 < dp[i]){
                    dp[i] = dp[i - v[j]] + 1;
                }
            }
        }
    }
    if(dp[amount] < INT_MAX) cout << dp[amount] << '\n';
    else cout << -1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}