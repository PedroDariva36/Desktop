#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define pip pair<int, pii>
#define s second
#define f first

using namespace std;


vector<pair<pip,string>> a;
stack<pair<pip, string>> s;
string aux;
pip u;
int main (int argc, char *argv[]){
    int t = 0; 
    cin >> t;
    while (t--){
        cin >> aux >> u.first >> u.second.first >> u.second.second;
        a.push_back({u,aux});
    }

    sort(a.rbegin(), a.rend());
    pip last = a[0].first;
    s.push(a[0]);
    for (int i = 1; i < a.size(); i++) {
        if (a[i].first == last) s.push(a[i]);

        else {
            last = a[i].first;
            while (!s.empty()) {
                cout << s.top().second << " " << s.top().first.first << " " << s.top().first.second.first << " " <<  s.top().first.second.second << endl;
                s.pop();
            }
            s.push(a[i]);
        }
    }
    while (!s.empty()) {
        cout << s.top().second << " " << s.top().first.first << " " << s.top().first.second.first << " " <<  s.top().first.second.second << endl;
        s.pop();
    }
    return 0;
}
