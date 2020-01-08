/*
    Link - https://practice.geeksforgeeks.org/problems/rod-cutting/0/?track=sp-dynamic-programming&batchId=152

    Problem - Rod Cutting

    Sol - Very simple just work on length if we cut k length from x length rod then add
            cost of k i.e cost[k] and then do similarly for left length

            dp[i] = max(dp[i], dp[i - x] + cost[x] for x = 0, 1....n - 1);

    Complexity - O(n^2)
*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
int dp[102];
int TD(int len, int n, vector<int> &v){
    if(len == 0) return dp[len] = 0;
    if(dp[len] != - 1) return dp[len];
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(len - i >= 0){
            ans = max(ans, TD(len - i, n, v) + v[i - 1]);
        }
    }
    return dp[len] = ans;
}
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << TD(n, n, v);
}
void BU(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    memset(dp, 0, sizeof(dp));

    dp[0] = 0;
    for(int len = 1; len <= n; len++){
        for(int j = 0; j < n; j++){
            if(len - j - 1 >= 0){
                dp[len] = max(dp[len], dp[len - j - 1] + v[j]);
            }
        }
    }
    cout << dp[n];
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        // solve();
        BU();
        cout << '\n';
    }
	return 0;
}
