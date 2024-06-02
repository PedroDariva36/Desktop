#include <bits/stdc++.h>
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
    
    if(n[0] == 'o' || n[0] == 'O' || n[0] == 'c' || n[0] == 'C')
        cout << "mas" << endl; 
    if(n[0] == 'i' || n[0] == 'I' || n[0] == 'q' || n[0] == 'Q')
        cout << "mais" << endl; 

    return 0;
}
