#include <bits/stdc++.h>
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
        string a;
        string b;
        cin >> a >> b;
        vector<int> m(b.size());  
        
        int sum = 1000;
        for (int i = 0; i < b.size(); i++) {
        int aux = i;         
            for (int j = 0; j < a.size(); j++) {
                if(aux < b.size() && a[j] == b[aux]) aux++; 
            }        
            sum = min(sum, (int)(a.size() + b.size()) - aux + i);        

        }
        cout << sum << endl;

    }
    return 0;
}
