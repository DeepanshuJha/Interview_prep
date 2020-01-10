#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
class Node{
    public:
        Node *left, *right;
        int data;
        int height;
};
Node *newNode(int data){
    Node *tmp = new Node();
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->height = 1;
    return tmp;
}
int height(Node *node){
    if(node == NULL)
        return 0;
    return node->height;
}
int getBalance(Node *node){
    if(node == NULL) return 0;
    return height(node->left) - height(node->right);
}
Node *LR(Node *y){
    Node *x = y->right;
    y->right = x->left;

    x->left = y;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return x;
}
Node *RR(Node *x){
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}
Node *minNode(Node *root){
    if(root == NULL) return NULL;

    Node *tmp = root;
    while(tmp->left != NULL){
        tmp = tmp->left;
    }
    return tmp;
}
Node *insert(Node *root, int data){
    if(root == NULL)
        return newNode(data);
    
    if(data < root->data){
        root->left = insert(root->left, data);
    }else if(data > root->data){
        root->right = insert(root->right, data);
    }else{
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if(balance > 1 && data < root->data){
        return RR(root);
    }
    if(balance > 1 && data > root->data){
        root->left = LR(root->left);
        return RR(root);
    }
    if(balance < -1 && data > root->data){
        return LR(root);
    }
    if(balance < -1 && data < root->data){
        root->right = RR(root->right);
        return LR(root);
    }
    return root;
}
Node *deleteNode(Node *root, int key){
    if(root == NULL) return NULL;

    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }else{
        if(!root->left && !root->right){
            root = NULL;
        }else if(!root->left || !root->right){
            root = root->left ? root->left : root->right;
        }else{
            Node *tmp = minNode(root->right);

            root->data = tmp->data;

            root->right = deleteNode(root->right, tmp->data);
        }
    }

    if(root == NULL) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);
    cout << balance << '\n';

    if(balance > 1 && getBalance(root->left) >= 0){
        return RR(root);
    }
    if(balance > 1 && getBalance(root->left) < 0){
        root->left = LR(root->left);
        return RR(root);
    }
    if(balance < -1 && getBalance(root->right) > 0){
        root->right = RR(root->right);
        return LR(root);
    }
    if(balance < -1 && getBalance(root->right) <= 0){
        return LR(root);
    }
    return root;
}
Node *search(Node *root, int key){
    if(root == NULL) return NULL;
    if(key == root->data) return root;
    else if(key < root->data) return search(root->left, key);
    else return search(root->right, key);
}
void bfs(Node *root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            Node *cur = q.front();
            q.pop();
            cout << cur->data << ' ';
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    Node *root = NULL;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        root = insert(root, x);
    }
    bfs(root);
    root = deleteNode(root, 3);
    cout << '\n';
    bfs(root);
	return 0;
}