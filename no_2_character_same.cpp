/*
    Link - https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/

    There are two problems related to this question.

    Problem Statement :- Rearrange characters in a string such that no two adjacent are same

    In one problem you have to just say Yes or No whether the string is convertible in
    which no two adjacent characters are same.

    Sol - In this just check whether the maximum frquency chracter is less then n / 2 
        where n is length of string then it is Yes otherwise No.

    Other problem is to print the converted string if possible.

    Sol - In this max heap is required and the top element is popped and added to answer
        and prev variable is maintained which stores the previous visited element.
        If the prev element frequency is more than 0, then it is pushed in to heap.

        O(n)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
struct Key{
    int cnt;
    char val;
    bool operator<(const Key &k)const {
        return cnt < k.cnt;
    }
};
void solve(){
    string s;
    cin >> s;
    priority_queue<Key> pq;
    
    int h[26] = {0};
    for(auto x : s) h[x - 'a']++;

    for(char i = 'a'; i <= 'z'; i++){
        if(h[i - 'a']){
            pq.push(Key{h[i - 'a'], i});
        }
    }

    string ans = "";

    Key prev{-1, '#'};

    while(!pq.empty()){
        Key k = pq.top();
        pq.pop();
        ans += k.val;
        if(prev.cnt > 0){
            pq.push(prev);
        }
        k.cnt--;
        prev = k;
    }
    if(ans.size() != s.size()){
        cout << "NP";
    }else{
        cout << ans << '\n';
    }
    
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
