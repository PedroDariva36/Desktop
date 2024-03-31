#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;


int main (int argc, char *argv[]){
    int t;
    char aux;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<char> a;
        for(int i = 0 ; i < n; i++){
            cin >> aux;
            a.push_back(aux);
        }
        
        int first = -1, last = -1;
        for (int i = 0 ; i < n; i++) {
            if(a[i] == 'B'){
                if(first == -1)
                    first = i;
                last = i;
            }
        }
        
        if(first == last){
            cout << 1 << endl;
            continue;
        }
        
        cout <<1 + last - first << endl;


    }
    return 0;
}
