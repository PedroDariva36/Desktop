#include <bits/stdc++.h>
#include <deque>
#include <vector>

using namespace std;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        

        int n;
        cin >> n;
        vector<int> a; 
        for(int i = n; i > 3; i--)
            a.push_back(i);
        a.push_back(3);
        a.push_back(2);
        a.push_back(1);

        for (auto i : a) {
            cout << i << " "; 
        }
        cout << endl;

        for (int i = 0; i + 1 < n; i++) {
            for(int j = i+1; j + 1 < n; j++){
                if( a[i] % a[j] == 0 & a[i+1] % a[j+1] == 0)
                    cout << i << " " << j << endl;
            }
        } 

        for (auto i : a) {
            cout << i << " "; 
        }
        cout << endl;
    }
    

    return 0;
}
