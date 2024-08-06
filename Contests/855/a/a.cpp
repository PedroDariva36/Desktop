#include <bits/stdc++.h>
#include <cctype>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<char> a(n);     
        for(auto &i: a) {
            cin >> i;
            i = tolower(i);
        }

        bool f = 1;
        char last = '-'; 
        for (int i = 0; i < n; i++) {
            if(a[i] == last) continue;
            if(last != a[i]){
                if(last == '-'){
                    if(a[i] != 'm'){
                        f = 0;
                        break;
                    } 
                    last = 'm'; 
                    continue;
                } 
                if(last == 'm'){
                    if(a[i] != 'e'){
                        f = 0;
                        break;
                    } 
                    last = 'e'; 
                    continue;
                }
                if(last == 'e'){
                    if(a[i] != 'o'){
                        f = 0;
                        break;
                    } 
                    last = 'o'; 
                    continue;

                }  
                if(last == 'o'){
                    if(a[i] != 'w'){
                        f = 0;
                        break;
                    } 
                    last = 'w'; 
                    continue;


                }
                if(last == 'w'){
                    f = 0; 
                    break; 
                }
            } 
        }
        if(last != 'w') f = 0; 


        cout << (f? "YES":"NO") << endl;



    }
    return 0;
}
