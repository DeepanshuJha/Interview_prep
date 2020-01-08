/*
    Link - https://practice.geeksforgeeks.org/problems/total-decoding-messages/0/?track=sp-dynamic-programming&batchId=152

    Problem - Total Decoding mesaage

    Sol - very simple just think that if we are selecting ith character then it should be
            in range of '1' to '9';
            - And also we can combine two charcters because range is 1 - 26
            - so if combination of tw characters is in range then consider them
            - at any point if ith character is 0 then solution becomes 0 for that point 
                intdividually;

    Complexity - O(n);
*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
int dp[50];
int topdown(int st, int n, string &s){
    if(s[st] == '0') return dp[st] = 0;
    if(st == n){
        return dp[st] = 1;
    }
    if(dp[st] != -1) return dp[st];
    int ans = 0;
    if(s[st] > '0' && s[st] <= '9') ans += topdown(st + 1, n, s);
    if(s[st] == '1' || (s[st] == '2' && s[st + 1] >= '0' && s[st + 1] <= '6')) ans += topdown(st + 2, n, s);
    return dp[st] = ans;
}
void bottomup(){
    int n;
    cin >> n;
    if(n == 0){
        cout << 1;
        return;
    }
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    // base cases
    dp[0] = 1;
    dp[1] = 1;
    // invalid if num is like '0123...'
    if(s[0] == '0'){
        cout << 0;
        return;
    }
    for(int i = 2; i <= n; i++){
        dp[i] = 0;
        if(s[i - 1] > '0') dp[i] = dp[i - 1];
        if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')) dp[i] += dp[i - 2];
    }
    cout << dp[n];
}
void solve(){
    int n;
    cin >> n;
    if(n == 0){
        cout << 1;
        return;
    }
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << topdown(0, n, s);
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
