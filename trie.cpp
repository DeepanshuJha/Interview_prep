#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int K = 27;
struct node{
    node * next[K];
    int ending;
};

node * newNode(){
    node * temp = new node();
    for(int i = 0; i < K; i++)
        temp -> next[i] = NULL;
    temp -> ending = 0;
    return temp;
}
node * root;

void insert(string s){
    int n = s.size();
    node * temp = root;
    for(int i = 0; i < n; i++){
        int id = s[i] - 'a';
        if(temp -> next[id] == NULL){
            temp -> next[id] = newNode();
        }
        temp = temp -> next[id];
    }
    (temp -> ending)++;
}

bool check(string s){
    int n = s.size();
    node *temp = root;
    for(int i = 0; i < n; i++){
        int id = s[i] - 'a';
        if(temp -> next[id] != NULL){
            temp = temp -> next[id];
        }else return 0;
    }
    return ((temp -> ending) > 0);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    root = newNode();
    string s, x;
    cin >> s >> x;
    insert(s);
    cout << check(s) << " " << check(x);
    return 0;
}