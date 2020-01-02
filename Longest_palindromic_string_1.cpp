/*
    Link - https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0/?track=sp-strings&batchId=152

    Problem - Longest Palindrome in a string (find substring)

    Complexity - O(n2)

*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
int check(string &s, int x, int y){
    int n = s.size();
    while(x >= 0 && y < n && s[x] == s[y]){
        x--;
        y++;
    }
    return y - x - 1;
}
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    string res;
    int left = 0, right = 0;
    for(int i = 0; i + 1 < n; i++){
        int odd = check(s, i, i);
        int even = check(s, i, i + 1);
        if(odd > right - left + 1){
            left = i - odd / 2;
            right = i + odd / 2;
        }
        if(even > right - left + 1){
            left = i - (even - 1) / 2;
            right = i + even / 2;
        }
    }
    res = s.substr(left, right - left + 1);
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