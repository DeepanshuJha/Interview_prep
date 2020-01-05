/*
    Link - https://practice.geeksforgeeks.org/problems/page-faults-in-lru/0/?track=sp-greedy&batchId=152

    Problem - PageFault using LRU

    Complexity - O(n)

    Sol - Use set and map, set is used to store the pages and map is used to store the
          indexes of pages.

        - If set size is full, and page is not found then we have to iterate in set and find the page which is 
          having minimum index value and then remove it and increment the pageFault value

        - If set size is full and page is already there then just update the index.

        - If the set is containing the page then just update the index value in map.

        - If the set size is not full and page is not found then simply add page in set 
          and increase the value of pageFault

*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
void solve(){
    int n;
    cin >> n;
    vector<int> pages(n);
    for(int i = 0; i < n; i++) cin >> pages[i];

    int capacity;
    cin >> capacity;

    unordered_set<int> s;
    unordered_map<int, int> recent;
    int pageFault = 0;
    for(int i = 0; i < n; i++){
        if(s.size() < capacity){
            if(s.find(pages[i]) == s.end()){
                s.insert(pages[i]);
                pageFault++;
            }
            recent[pages[i]] = i;
        }else{
            if(s.find(pages[i]) == s.end()){
                int lru = INT_MAX;
                int page = -1;
                for(auto x : s){
                    if(recent[x] < lru){
                        lru = recent[x];
                        page = x;
                    }
                }
                s.erase(s.find(page));
                s.insert(pages[i]);
                pageFault++;
            }
            recent[pages[i]] = i;
        }
    }
    cout << pageFault << '\n';
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
