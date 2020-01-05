/*
    Problem - Find the Largest number with given number of digits and sum of digits

    Complexity - O(d)

    Sol - Greedy Approach is used. We will start filling the positions from left to right
          if the sum > 9 then put 9 otherwise put sum and fill rest positions with 0.
*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x;
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
void solve(){
    int sum, d;
    cin >> sum >> d;
    if(sum == 0){
        (d == 1) ? (cout << 0) : (cout << -1);
        return;
    }
    if(sum > 9 * d){
        cout << -1;
        return;
    }
    vector<int> res(d);

    for(int i = 0; i < d; i++){
        if(sum > 9){
            res[i] = 9;
            sum -= 9;
        }else{
            res[i] = sum;
            sum = 0;
        }
    }

    fprint(res);
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
