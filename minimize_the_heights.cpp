/*
    Link - https://practice.geeksforgeeks.org/problems/minimize-the-heights/0/?track=sp-greedy&batchId=152

    Problem - Minimize the heights

    Sol - Just sort the array and then find the differnce between min and max
          and then check if any a[i] - k or a[i] + k changes the answer
    
    Compexity - O(nlog(n))
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
void solve(){
    int n, k;
    cin >> k >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    sort(v.begin(), v.end());
    
    int ans = v[n - 1] - v[0]; // initial difference
    int mn = v[0] + k;
    int mx = v[n - 1] - k;
    if(mn > mx) swap(mn, mx); // if all the numbers are same
    
    
    for(int i = 1; i < n - 1; i++){
        int add = v[i] + k; // number is increased
        int sub = v[i] - k; // number is decreased
        
        if(mn <= sub || mx >= add) continue; // if a number is within the range of mn and mx 
                                            // then the difference remains same;
        
        if(mx - sub <= add - mn){ // if at any point the mx - sub is less then add - mn then
            mn = sub;             // mn = sub else mx = add;
        }else mx = add;
    }
    cout << min(ans, mx - mn) << '\n'; 
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