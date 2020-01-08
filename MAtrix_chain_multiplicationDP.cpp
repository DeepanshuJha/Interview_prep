/*
    Link - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0/?track=sp-dynamic-programming&batchId=152

    Problem - Matrix Chain Multiplication

    Sol - We solve for every length to make sloution of n length

        dp[i][j] means solution of matrix[i.....j]

        dp[i][j] = dp[i][k] + dp[k][j] + v[i] * v[k] * v[j];

    Complexity - O(n^3)
*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
void solve(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    ll dp[n][n];

    memset(dp, 0, sizeof(dp));

    for(int len = 2; len < n; len++){
        for(int i = 0; i + len < n; i++){
            int j = i + len;
            dp[i][j] = INT_MAX;
            for(int k = i + 1; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[i] * v[k] * v[j]);
            }
        }
    }
    cout << dp[0][n - 1];
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
