#include <bits/stdc++.h>
#define ll long long
using namespace std;


string l[] ={"AM", "PM"};


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        int k = 0;

        k += (s[0]-'0')*10;
        k += (s[1]-'0');

        if (k > 12) {
            k -= 12;
            if ((k) > 9)
                cout << k;
            else 
                cout << 0 << k;


            for (int i = 2; i < s.size(); i++) {
                cout << s[i]; 
            }
            cout << " " << l[1] << endl;;
        }
        

        else if(k == 12) {
            cout << s << " " << l[1] << endl;
        }
        

        else if (k == 0) {
            cout << "12";
            for (int i = 2; i < s.size(); i++) {
                cout << s[i]; 
            }
            cout << " " << l[0] << endl; 
        }


        else {
            cout << s << " " << l[0] << endl;
        }


        

    }

    return 0;
}
