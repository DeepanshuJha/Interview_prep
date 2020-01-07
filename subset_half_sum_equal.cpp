/*
    Link - https://practice.geeksforgeeks.org/problems/subset-sum-problem/0/?track=sp-dynamic-programming&batchId=152

    Problem - Given a set of numbers, check whether it can be partitioned into 
            two subsets such that the sum of elements in both subsets is same or not.

    Sol - Top down 
            take sum of whole array and then if sum is odd then it is not possible
            otherwise check
            
            if(ith element <= sum) topdown(sum - a[i]) 
            if(sum at any point is 0) then return true;
            else check by other elements;

    Complexity - O(sum * n);
*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
bool topdown(int idx, int sum, int n, vector<int> &a){
    if(idx == n) return (sum == 0);
    if(sum == 0) return true;
    if(sum < 0) return false;
    for(int i = idx + 1; i < n; i++){
        if(topdown(i, sum - a[i], n, a))
            return true;
    }
    return false;
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    if(sum & 1){
        cout << "NO";
        return;
    }
    sum /= 2;
    if(topdown(-1, sum, n, a)) cout << "YES";
    else cout << "NO";
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
