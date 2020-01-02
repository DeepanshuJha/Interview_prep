/*
    Link - https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0/?track=sp-strings&batchId=152

    Longest Palindromic string by DP

    Sol - In this the states are if(j - i > 3) dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1])
                                else dp[i][j] = (s[i] == s[j])
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    string res;
    for(int i = n - 1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(j - i < 3) dp[i][j] = (s[i] == s[j]);
            else if(dp[i + 1][j - 1]) dp[i][j] = (s[i] == s[j]);

            if(dp[i][j] && (res.size() == 0 || res.size() <= j - i + 1)){
                res = s.substr(i, j - i + 1);
            }
        }
    }
    cout << res << '\n';
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