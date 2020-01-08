/*
    Link - https://practice.geeksforgeeks.org/problems/path-in-matrix/0/?track=sp-dynamic-programming&batchId=152

    Problem - Path matrix;

    Sol -Intutive easy dfs or dp;

    Complexity - O(n * n);
*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
int dp[25][25];
int TD(int x, int y, int n, vector<vector<int> > &mat){
    if(x < 0 || x > n || y < 0 || y >= n) return 0;
    if(x == n && (y >= 0 || y < n)) return 0;
    if(dp[x][y] != -1) return dp[x][y];
    int ans = 0;
    ans = mat[x][y] + max(TD(x + 1, y, n, mat), max(TD(x + 1, y + 1, n, mat), TD(x + 1, y - 1, n, mat)));        
    return dp[x][y] = ans;
}
void solve(){
    int n;
    cin >> n;
    vector<vector<int> > mat(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> mat[i][j];
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, TD(0, i, n, mat));
    }
    cout << ans;
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
