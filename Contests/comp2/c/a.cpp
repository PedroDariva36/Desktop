#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define pii pair<int,int>
#define f first
#define s second


using namespace std;

int main (int argc, char *argv[]){
    
    string s;
    vector<char>a,b;
    cin >> s;
    
    


    for (auto i : s) {
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
            a.push_back(i);
        }
    }
    
    b = a;
    reverse(b.begin(), b.end());


    if (b == a) {
        cout << "S" << endl;
    }
    else {
        cout <<"N"<<endl;
    }
    


    return 0;
}
