#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define pip pair<int, pii>
#define f first
#define s second


using namespace std;


vector<pair<pip,string>> a;
map<string, pip> m;
stack<pair<pip, string>> s;
string aux;
pip u;
int main (int argc, char *argv[]){ 
    while(getline(cin, aux)){
        getline(cin, aux);
        m[aux].f += 1;
        getline(cin, aux);
        m[aux].s.f += 1;
        getline(cin, aux);
        m[aux].s.s += 1;
    }
        
    for (auto i : m) a.push_back({i.second, i.first}); 
    sort(a.rbegin(), a.rend());
    cout << "Quadro de Medalhas" << endl; 
    



    pip last = a[0].f;
    s.push(a[0]);


    for (int i = 1; i < a.size(); i++) {
        if (a[i].f == last) s.push(a[i]);
        
        else {
            last = a[i].f;
            while (!s.empty()) {
                cout << s.top().s << " " << s.top().f.f << " " << s.top().f.s.f << " " <<  s.top().f.s.s << endl; s.pop();
            }
            s.push(a[i]);
        }
    }


    while (!s.empty()) {
        cout << s.top().s << " " << s.top().f.f << " " << s.top().f.s.f << " " <<  s.top().f.s.s << endl; s.pop();
    }

    return 0;
}
