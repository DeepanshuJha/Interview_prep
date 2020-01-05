/*
    Link - https://practice.geeksforgeeks.org/problems/activity-selection/0/?track=sp-greedy&batchId=152

    Problem - Activity Selection

    Approach -  In this we sort the array by second value, we assume all first value as 
                start value and second value as finish value.
             -  Then we pick those value whose finish value is greater then the cur finish value and
                start value is also greater then cur finish value.

    Complexity - O(nlog(n))
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
void solve(){
    int n;
    cin >> n;
    vector<int> st(n), ed(n);
    for(int i = 0; i < n; i++) cin >> st[i];
    for(int i = 0; i < n; i++) cin >> ed[i];
    
    vector<pair<int, int> > activity;
    
    for(int i = 0; i < n; i++){
        activity.push_back({st[i], ed[i]});
    }
    
    sort(activity.begin(), activity.end(), [](pair<int, int> p1, pair<int, int> p2){
        return p1.second <= p2.second;
    });
    
    int cur = activity[0].second;
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(activity[i].first >= cur){
            ans++;
            cur = activity[i].second;
        }
    }
    cout << ans << '\n';
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