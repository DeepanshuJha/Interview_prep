#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 1;
const int M = 1e9 + 7;
struct trie{
    trie *child[26];
    bool isEnd;
};
trie *newNode(){
    trie *root = new trie();
    for(int i = 0; i < 26; i++){
        root->child[i] = NULL;
    }
    root->isEnd = false;
    return root;
}
void insert(trie *root, string s){
    trie *temp = root;
    int n = s.size();
    for(int i = 0; i < n; i++){
        int idx = s[i] - 'a';
        if(temp->child[idx] == NULL){
            temp->child[idx] = newNode();
        }
        temp = temp->child[idx];
    }
    temp->isEnd = true;
}
void dfs(trie *root, string s){
    if(root->isEnd){
        cout << s << ' ';
    }
    for(int i = 0; i < 26; i++){
        if(root->child[i]){
            char ch = i + 'a';
            dfs(root->child[i], s + ch);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        trie *root = newNode();
        cin >> n;
        while(n--){
            string s;
            cin >> s;
            insert(root, s);
        }
        string q;
        cin >> q;
        int f = 0;
        for(int i = 0; i < q.size(); i++){
            int idx = q[i] - 'a';
            if(root->child[idx] != NULL && f == 0){
                string s = q.substr(0, i + 1);
                dfs(root->child[idx], s);
                cout << '\n';
                root = root->child[idx];
            }else{
                f = 1;
                cout << 0 << '\n';
            }
        }
    }
	return 0;
}
