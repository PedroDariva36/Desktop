#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


typedef pair<int,char> pic;
int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        
        vector<pic> a,b;

        for (int i = 0; i < s.size(); i++) {
            if(s[i] == 'b'){
                if(a.size()) 
                    a.pop_back();
                continue;
            }
            if(s[i] == 'B'){
                if(b.size()) 
                    b.pop_back(); 
                continue;
            }
            
            if(s[i] >= 'A' && s[i] <= 'Z') 
                b.pb({i,s[i]});
            else
                a.pb({i,s[i]}); 
        }
        
        int i = 0;
        int j = 0;

        while(j < b.size() && i < a.size()){ 
            if(a[i].first < b[j].first){
                cout << a[i].second;
                i++;
                continue;
            }
            else{ 
                cout << b[j].second;
                j++;
                continue;
            }
        }

    
        for (; i < a.size(); i++) {
            cout << a[i].second; 
        }
        for (; j < b.size(); j++) {
            cout << b[j].second; 
        }
        cout << endl;                
         

    }
    return 0;
}
