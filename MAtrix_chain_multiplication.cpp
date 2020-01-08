/*
    Link - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0/?track=sp-dynamic-programming&batchId=152

    Problem - Matrix Chain Multiplication

    Sol - The aim is to place parenthesis at all places and take minimum of all those.

            Ex - ABCD
                (A)BCD
                (AB)(CD)
                (ABC)D

    Complexity - O(n^3);
*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
ll dp[102][102];
ll topdown(vector<ll> &v, int i, int j){
    if(i == j) return dp[i][j] = 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll ans = INT_MAX;

    for(int k = i; k < j; k++){
        ans = min(ans, topdown(v, i, k) + topdown(v, k + 1, j) + v[i - 1] * v[k] * v[j]);
    }
    return dp[i][j] = ans;
}
void solve(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));

    cout << topdown(v, 1, n - 1);
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
