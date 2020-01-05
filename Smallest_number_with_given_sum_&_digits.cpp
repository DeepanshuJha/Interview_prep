/*
    Link - https://practice.geeksforgeeks.org/problems/smallest-number/0/?track=sp-greedy&batchId=152

    Problem - The task is to find the smallest number with given
              sum of digits as s and number of digits as d.
    
    Complexity - O(d)


    Sol - As we hav to minimize the number so we will start filling position from
        right to left, but theres is a problem
        it might happen that we are not left with sum i.e sum = 0 and poisitons are left

        but the positions can be filled using 0's 

        Ex - sum = 12 , d = 4

        answer is 1029

        For this we have to deduct 1 from sum and then start filling positions from right
        to left in a way such that when sum > 9 then fill it with 9 other wise fill the 
        position with sum and make sum 0.

        If sum = 0 and digits are more than just fill the positions with 0
        and at first position fill it with 1 as we deducted 1 from sum initially

        If sum = 0 and only one position is left then just put 1 there.
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
void solve(){
    int sum, d;
    cin >> sum >> d;
    if(sum == 0){
        (d == 1) ? (cout << "0") : (cout << -1);
        return;
    }
    
    if(sum > 9 * d){
        cout << -1;
        return;
    }
    
    vector<int> res(d);
    
    sum -= 1;
    
    for(int i = d - 1; i > 0; i--){
        if(sum > 9){
            res[i] = 9;
            sum -= 9;
        }else{
            res[i] = sum;
            sum = 0;
        }
    }
    res[0] = sum + 1;
    
    for(auto x : res) cout << x;
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