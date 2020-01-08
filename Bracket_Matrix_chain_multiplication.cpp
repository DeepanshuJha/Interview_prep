/*
    link - https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication/0/?track=sp-dynamic-programming&batchId=152

    Problem - Print Brackets in Matrix chain multipliaction

    Sol - maintain 2d array for brackets
            bracket[i][j] means at which point to split mat[i....j] for minimum cost.
*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
int bracket[105][105];
int dp[105][105];
void print(int i, int j, char &name){
    if(i == j){
        cout << name++;
        return;
    }

    cout << "(";
    print(i, bracket[i][j], name);
    print(bracket[i][j] + 1, j, name);
    cout << ")";
}
int topdown(int i, int j, vector<int> &v){
    if(i == j) return dp[i][j] = 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int tmp = topdown(i, k, v) + topdown(k + 1, j, v) + v[i - 1] * v[k] * v[j];
        if(tmp < ans){
            bracket[i][j] = k;
            ans = tmp;
        }
    }
    return dp[i][j] = ans;
}
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    memset(dp, -1, sizeof(dp));
    memset(bracket, 0, sizeof(bracket));

    topdown(1, n - 1, v);

    char name = 'A';
    print(1, n - 1, name);
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
