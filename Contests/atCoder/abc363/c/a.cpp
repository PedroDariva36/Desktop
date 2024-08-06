#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;

bool cp(string s)
{
    string a = s;
    reverse(all(a));
    return !s.compare(a);
}




int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    string a;
    ll sum = 0;
    cin >> a; 
    sort(all(a));
    do{
        bool g = 1;  
        for(int j = 0; j <= n-k; j++){
            if(cp(a.substr(j,k))){ 
                g = 0;
                break;
            }
        }
        if(g) sum++;
    } 
    while(next_permutation(all(a)));


    cout << sum << endl;
    

    return 0;
}
