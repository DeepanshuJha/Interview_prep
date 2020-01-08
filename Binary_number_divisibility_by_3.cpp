/*
    Link - https://practice.geeksforgeeks.org/problems/is-binary-number-multiple-of-3/0/?track=sp-dynamic-programming&batchId=152

    Probelem - Check divisibility of binary bumber by 3

    Approach - differnece of set bits at odd and even place is divisible by 3 then
                number is divisible by 3
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
int check(string s){
    int n = s.size();
    
    int odd = 0, even = 0;
    
    for(int i = 0; i < n; i++){
        if(i & 1 && s[i] == '1') odd++;
        else if(i % 2 == 0 && s[i] == '1') even++;
    }
    
    if(abs(even - odd) % 3 == 0) return 1; // if difference is divisible by 3 then the 
    else return 0;                         // number is divisible
}
void solve(){
    string s;
    cin >> s;
    cout << check(s);
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