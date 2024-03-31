#include <bits/stdc++.h>
#include <vector>
#define ll long long

#define at first
#define def first


using namespace std;



int main (int argc, char *argv[]){
    int t,n;
    cin >> t;    

    while (t--) {
        cin >> n;
        set<int> s;
        pair<long,long> m[n];
        
        for(int i = 0; i < n; i++){
            cin >> m[i].at;
            s.insert(i);
        }

        for(int i = 0; i < n; i++)
            cin >> m[i].def;
        
        long aux;
        for(int i = 0; i < n; i++){
            stack<int> s;

            
        }
        cout << endl;


    }


    return 0;
}
