#include <bits/stdc++.h>
#include <ios>

using namespace std;


int main (int argc, char *argv[]){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string a,b,sub, aux;
    int x,y,t;
    cin >> x >> y >> a >> b;

    cin >> t;
    while (t--) {
        cin >> x >> y;
        int sum = 0;
        sub = b.substr(x-1,y-x+1);
        
        for (int i = 0; i < a.size() - sub.size() ; i++ ) {
            aux = a.substr(i,sub.size());
            if (aux == sub) sum++;
        }
        cout << sum << endl;
    }
    





    return 0;
}
