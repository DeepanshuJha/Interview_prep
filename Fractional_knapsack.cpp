/*
    Link - https://practice.geeksforgeeks.org/problems/fractional-knapsack/0

    Problem - Fractional Knapsack

    Complexity - O(nlog(n))

    Sol - It is a greedy problem so we just sort the data according to value / weight
          ratio in decreasing order.

        - Then if an item is having less weight then required use it fully
          else use it partially (value / weight) * (Weight left).
    
*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
void solve(){
    int n;
    double W;
    cin >> n >> W;
    vector<pair<double, double> > v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), [](const pair<double, double> &p1, const pair<double, double> &p2){
        double x1 = p1.first / p1.second;
        double x2 = p2.first / p2.second;
        return x1 > x2;
    });
    double value = 0;
    for(int i = 0; i < n; i++){
        if(v[i].second <= W){
            value += v[i].first;
            W -= v[i].second;
        }else{
            value += (v[i].first / v[i].second) * (W);
            W = 0;
        }
    }
    cout << fixed;
    cout << setprecision(2) << value;
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
