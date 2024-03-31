#include<bits/stdc++.h>

using namespace std;

vector<string> a;
vector<string> r;

int main(int argc, char const *argv[])
{
    int n, g;
    cin >> n;
    string s;

    for (int i = 0; i < n; i++){
        cin >> s;
        a.push_back(s);
    }
 
    cin >> g;
    for (int i = 0; i < g; i++){
        cin >> s;
        r.push_back(s);
    }

    for (int i = 0; i < g; i++){
        int ans = 0;
        for (int j = 0; j < n; j++){
            int flag = 0;
            for (int l = 0; l < 5; l++){
                if (r[i][l] == 'X'){
                    if (a[0][l] == a[j][l] || (a[0].find(a[j][l]) != a[0].npos)){
                        flag = 1;
                        break;
                    }
                }
                else if (r[i][l] == '*'){
                    if (a[0][l] != a[j][l]){
                        flag = 1;
                        break;
                    }
                } 
                else {
                    if (a[0][l] == a[j][l] || (a[0].find(a[j][l]) == a[0].npos)){
                        flag = 1;
                        break;
                    }
                }
                
                if (flag) break;
            } 
            if (!flag) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
