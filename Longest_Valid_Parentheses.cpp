/*
    Link - https://leetcode.com/problems/longest-valid-parentheses/

    Problem - Longest Valid Parentheses

    Sol - Stack and tricky

    Complexity - O(n);
*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    stack<int> st;
    st.push(-1);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') st.push(i);
        else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }else{
                ans = max(ans, i - st.top());
            }
        }
    }
    cout << ans;
}
void trick(){
    string s;
    cin >> s;
    int n = s.size();
    int left = 0, right = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') left++;
        else right++;

        if(left == right) ans = max(ans, 2 * right);
        else if(right > left) left = right = 0;
    }
    left = right = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '(') left++;
        else right++;

        if(left == right) ans = max(ans, 2 * left);
        else if(left > right) left = right = 0;
    }
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        // solve();
        trick();
        cout << '\n';
    }
	return 0;
}
