/*
    Link - https://practice.geeksforgeeks.org/problems/interleaved-strings/1/?track=sp-strings&batchId=152

    Interleaved Strings

    Complexity - O(mn) 

    Sol - Top Down Approach

        Handle base cases - 
            1. empty strings all are empty
            2. only c is empty
        If c[i] == a[j] then solve for c[i + 1] and a[j + 1]

        If c[i] == b[k] then solve for c[i + 1] and b[k + 1]
   
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
int dp[50][50][50];
bool check(string a, string b, string c, int i, int j, int k){
    if(dp[i][j][k] != -1) return dp[i][j][k];
    if(i == a.size() && j == b.size() && k == c.size()) return dp[i][j][k] = 1;

    if(k == c.size()) return dp[i][j][k] = 0; // c is empty other two are not empty

    return dp[i][j][k] = ((a[i] == c[k] && check(a, b, c, i + 1, j, k + 1)) || (b[j] == c[k] && check(a, b, c, i, j + 1, k + 1))); 
}
void solve(){
    string a, b, c;
    cin >> a >> b >> c;
    memset(dp, -1,sizeof(dp));
    cout << check(a, b, c, 0, 0, 0);
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
