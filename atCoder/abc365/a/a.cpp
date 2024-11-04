#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
        int n;
        cin >> n;
        

        if(n%4 == 0){
            if(n%100 != 0 || n%400 == 0)
                cout << 366 << endl;
            else 
                cout << 365 << endl;
        } 
        else if(n%100 == 0 && n%400 != 0){
            cout << 365 << endl;
        }
        else cout << 365 << endl;



    return 0;
}
