/*
Problem Link = https://practice.geeksforgeeks.org/problems/huffman-encoding/
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
struct Node{
    Node *left, *right;
    int count;
};
Node *newNode(){
    Node *tmp = new Node();
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->count = 0;
    return tmp;
}
void preorder(Node *root, string &s){
    if(root == NULL) return;
    if(!root->left && !root->right){
        cout << s << ' ';
    }
    if(root->left){
        s += '0';
        preorder(root->left, s);
        s.erase(s.size() - 1);
    }
    if(root->right){
        s += '1';
        preorder(root->right, s);
        s.erase(s.size() - 1);
    }
}
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(n);
    auto comp = [](pair<int, Node*> &p1, pair<int, Node*> &p2){
        return p1.first > p2.first;
    };
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, decltype(comp)> min_heap(comp);
    for(int i = 0; i < n; i++){
        cin >> cnt[i];
        Node *tmp = newNode();
        tmp->count = cnt[i];
        min_heap.push({cnt[i], tmp});
    }

    // while(!min_heap.empty()){
    //     cout << min_heap.top().second->val << '-' << min_heap.top().first << '\n';
    //     min_heap.pop();
    // }

    while(min_heap.size() > 1){
        Node *leftNode = min_heap.top().second;
        min_heap.pop();
        Node *rightNode = min_heap.top().second;
        min_heap.pop();
        Node *tmp = newNode();
        tmp->left = leftNode;
        tmp->right = rightNode;
        tmp->count = leftNode->count + rightNode->count;
        min_heap.push({tmp->count, tmp});
    }
    Node *root = min_heap.top().second;
    string code;
    preorder(root, code);
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
