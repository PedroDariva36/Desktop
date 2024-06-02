#include <bits/stdc++.h>
#include <map>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    string n; 
    cin >> n;
    map<char, int> m;
    for (auto i : n) m[i]++; 
    
    if(m['O'] != 1 || m['X'] != 2)
        cout << "?" << endl;
    else if (n[1] == 'X') {
        cout << "Alice" << endl;
    }
    else cout << "*" << endl;





    return 0;
}
