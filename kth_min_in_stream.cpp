/*
    Link - https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream/0/

    Sol - use min-heap to get kth smallest/largest as heap will be of size k, 
        so root will be always kth element. O(log(k))
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
void solve(){
    int k, n;
    cin >> k >> n;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(pq.size() < k){
            pq.push(x);
            if(pq.size() == k) cout << pq.top() << ' ';
            else cout << -1 << ' ';
        }else if(pq.size() == k){
            if(pq.top() < x){
                pq.pop();
                pq.push(x);
            }
            cout << pq.top() << ' ';
        }
    }
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
