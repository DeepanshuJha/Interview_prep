/*
    Link - https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/?track=sp-dynamic-programming&batchId=152

    Problem - Maximum sum increasing subsequence

    Sol - dp[i] = means maximum sum of increasing subsequence till i

            intitialize dp[i] = a[i];

            then if(a[j] < a[i]) dp[i] = max(dp[i], dp[i] + a[i]);
                if(ans < dp[i]) ans = dp[i];
    
    Complexity - O(n^2);
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    int dp[n];
    for(int i = 0; i < n; i++) cin >> v[i], dp[i] = v[i];
    int ans = dp[0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(v[j] < v[i]){
                dp[i] = max(dp[i], dp[j] + v[i]);
                ans = max(ans, dp[i]);
            }
        }
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