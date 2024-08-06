#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend() 
#define pb push_back
using namespace std;

struct Node{
    ll h;
    ll v; 
    Node *l = NULL;
    Node *r = NULL;
} typedef Node;


map<ll,ll> m;

void addNode(Node *root, int v){
    if (v >= root->v) {
        if(root->r == NULL){
            Node *x = new Node;
            x->h = root->h+1;
            x->v = v; 
            root->r = x;
        }
        else addNode(root->r, v);
    }
    else {
        if(root->l == NULL){
            Node *x = new Node;
            x->h = root->h+1;
            x->v = v; 
            root->l = x;
        }
        else addNode(root->l, v); 
    }
}
    
void pNode(Node *root){
    if(root == NULL) return;
    if(m[root->h] == 0){
        m[root->h] = root->v;
    }
    m[root->h] = min(m[root->h],root->v);
    pNode(root->r); 
    pNode(root->l);
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
        
    int n;
    cin >> n;
    Node *root = new Node;
    ll v; 
    cin >> v;
    
    root->h = 0;
    root->v = v;
    for (ll i = 0; i < n-1; i++) {
        cin >> v;
        addNode(root, v);
    }
    pNode(root); 
    
    for (auto i: m) {
        cout << i.first << " " << i.second << endl;
    }


    return 0;
}
