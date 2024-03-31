#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define pii pair<int,int>
#define f first
#define s second


using namespace std;
int n, x, aux;
vector<pii> books;

// GOOD CODE, BUT SPACE HEAVY
/*

int a[1000][1000001];

ll solve(int n, int w){
    if(n == 0){
        if (w > books[n].f) return books[n].s;
        else return 0;
    } 
    if (a[n][w] != -1) return a[n][w]; 
    if (books[n].f > w) return solve(n-1,w);
    
    ll mx = max(books[n].s + solve(n-1, w - books[n].f),solve(n-1,w));
    a[n][w] = mx;
    return mx;

}
*/

int a[1000001];
int main (int argc, char *argv[]){
    
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> aux;
        books.push_back({aux,0});
    } 
    for(int i = 0; i < n; i++) cin >> books[i].s;
    
    for(int i = 0; i <= x; i++) a[i] = 0;
        
    for (int i = 0; i <= n; i++)
        for (int w = x; w >= 0; w--)
            if (w >= books[i].f) 
                a[w] = max(a[w],a[w-books[i].f]+books[i].s);

    cout << a[x] << endl;
   

    return 0;

}

