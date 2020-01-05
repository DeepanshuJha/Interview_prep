/*
    Link - https://practice.geeksforgeeks.org/problems/max-length-chain/1/?track=sp-greedy&batchId=152

    Problem - Max Length Chain

    Sol - Approach is to use LIS approach but here as order doesn't matter we can pick
          any two pairs which follow property of (a, b) < (c, d) if(b < c)
          so we have to sort the array with respect to first value
          then use LIS approach 
            dp[j] = max(dp[j], dp[i] + 1) if(p[j].first > p[i].second) 

            O(n^2) DP appoach
    
    Sol - Activity Selectio Approach O(nlog(n))

            In this we sort the array by second value, we assume all first value as 
            start value and second value as finish value.

            then we pick those value whose finish value is greater then the cur finish value and
            start value is also greater then cur finish value.
    
*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;

int maxChainLen(vector<pair<int, int> > &p,int n)
{
    sort(p.begin(), p.end(), [](const pair<int, int> v1, const pair<int, int> v2){
        return v1.first < v2.first;
    });
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(p[j].first > p[i].second){
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    int ans = *max_element(dp.begin(), dp.end());
    return ans;
}
int solve(vector<pair<int, int> > &p, int n){
    sort(p.begin(), p.end(), [](const pair<int, int> p1, const pair<int, int> p2){
        return p1.second < p2.second;
    });
    int len = 1;
    int cur = p[0].second;
    for(int i = 1; i < n; i++){
        if(p[i].first > cur){
            len++;
            cur = p[i].second;
        }
    }
    return len;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    cout << maxChainLen(v, n);
	return 0;
}
