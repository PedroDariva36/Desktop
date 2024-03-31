#include <array>
#include <bits/stdc++.h>
#include <bitset>
#include <vector>

using namespace std;


int n,m,z,x,y,c,age[500];
char aux;
bitset<500> marked;


int main (int argc, char *argv[]){
    


    while (cin >> n >> m >> z) {
        vector<int> t[n];
        
        for (int i = 0; i < n; i++) cin >> age[i];
        
        for (int i = 0; i < m; i++){
            cin >> x >> y;
            //g[x-1].push_back(y-1);
            t[y-1].push_back(x-1);
        }
        
        while (z--){
            cin >> aux;
            if (aux == 'T') {
                cin >> x >> y;
                x--;y--;
                //swap(age[x],age[y]);
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < t[i].size(); j++) {
                        if(t[i][j] == x){ 
                            t[i][j] = y; 
                            continue;
                        }
                        if(t[i][j] == y) t[i][j] = x;
                    }
                }
                swap(t[x],t[y]);
                /* 
                for (int i = 0; i < n; i++) {
                    for (auto &v : t[i]) {
                        cout << i << " " << v << endl;
                    } 
                }
                */
                continue;
            }

            


            
            
            marked.reset();
            cin >> x;
            
            /*
            if (x < 1) {
                cout << "sum ting wong" << endl;
            }
            */

            if (t[x-1].size() == 0) {
                cout << "*" << endl;
                continue;
            }
            /*
            for (int i = 0; i < n; i++) {
                cout << "  " << i;
            }
            cout << endl;
            for (int i = 0; i < n; i++) {
                cout << " " << age[i];
            }
            cout << endl;
            */

            int mn = 1000;
            stack<int> s;
            s.push(x-1); 
            while (!s.empty()) {
                c = s.top(); s.pop();
                
                if (marked[c]) continue;
                marked[c] = true;

                for (auto &i : t[c]) {
                    //cout << i << " ";
                    if (age[i] < mn) mn = age[i];
                    s.push(i);
                }
            }
            //cout << endl<< endl;
            cout << mn << endl;
        }



    }


    return 0;
}
