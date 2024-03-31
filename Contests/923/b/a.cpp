#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;


int main (int argc, char *argv[]){
    int t;
    cin >> t;
    while (t--) {
        int n,aux;

        cin >> n;
        vector<int> a;
        map<char,int> m;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            a.push_back(aux);
        }
        char c;
        int cpos = 0;
        for (int i = 0; i < n; i++) {
            if(a[i] == 0){
                c = 'a' + cpos;
                cout << c;
                m[c]++;
                cpos++;
            }
            else {
                for (auto &j : m) {
                    if(j.second == a[i]){
                        cout << j.first;
                        j.second++;
                        break;
                    }
                }
            }
        } 
        cout << endl;



    }
    return 0;
}
