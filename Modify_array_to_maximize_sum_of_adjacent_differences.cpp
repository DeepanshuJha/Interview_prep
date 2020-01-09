/*
    Link - https://www.geeksforgeeks.org/modify-array-to-maximize-sum-of-adjacent-differences/

    Problem - You are given a array and you change its value to x where x is 1 <= x <= a[i]
            and you have to find maximum sum of absolute differnece of consecutive elements;

    Sol - make 2 state dp
            dp[n][2] 
            dp[i][0] means sum using i elements where ith element is 1
            dp[i][1] means sum using i elements where ith element is a[i];

            
    Complexity - O(n)
*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int dp[n][2];
    for(int i = 0; i < n; i++){
        dp[i][0] = dp[0][i] = 0;
    }
    for(int i = 0; i + 1 < n; i++){
        dp[i + 1][0] = max(dp[i][0], dp[i][1] + abs(v[i] - 1));
        dp[i + 1][1] = max(dp[i][0] + abs(v[i + 1] - 1), dp[i][1] + abs(v[i + 1] - v[i]));
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]);
	return 0;
}
