/*
    Link - https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/

    Problem - Egg Dropping Puzzle

    Sol - W(n, k) = 1 + max{min(W(n - 1, k - 1), W(n, k - x)) for x = 1, 2, 3,..k};

    Complexity - O(n^3)
*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
int dp[100][100];
int topdown(int eggs, int f){
    if(eggs > 0 && f == 0) return dp[eggs][f] = 0;
    if(eggs == 1) return dp[eggs][f] = f;
    if(dp[eggs][f] != -1) return dp[eggs][f];
    int ans = INT_MAX;
    for(int i = 1; i <= f; i++){
        ans = min(ans, 1 + max(topdown(eggs - 1, i - 1), topdown(eggs, f - i)));
    }
    return dp[eggs][f] = ans;
}
void bottomup(){
    int eggs, f;
    cin >> eggs >> f;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= f; i++) dp[0][i] = 0;
    for(int i = 0; i <= eggs; i++) dp[i][0] = 0;
    for(int i = 0; i <= f; i++) dp[1][i] = i;
    for(int i = 2; i <= eggs; i++){
        for(int j = 2; j <= f; j++){
            dp[i][j] = INT_MAX;
            for(int x = 1; x <= j; x++){
                dp[i][j] = min(dp[i][j], 1 + max(dp[i - 1][x - 1], dp[i][j - x]));
            }
        }
    }
    cout << dp[eggs][f];
}
void solve(){
    int eggs, f;
    cin >> eggs >> f;
    memset(dp, -1, sizeof(dp));
    cout << topdown(eggs, f);
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        // solve();
        bottomup();
        cout << '\n';
    }
	return 0;
}
