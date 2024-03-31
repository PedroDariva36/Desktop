#include <bits/stdc++.h>

using namespace std;

int main (int argc, char *argv[]){
    
    int k[] = {1,3,6,10,15};

    int a[31];
    
    for (auto &i : a) {
        i = 20; 
    }

    a[0] = 0;
    for (int i = 1; i <= 30; i++) {
        for (int c : k) {
            if (i-c >= 0) {
               a[i] = min(a[i], a[i-c]+1); 
            } 
        } 
    }
    for (auto i : a) {
        cout << i <<", ";
    }
    cout << endl;

    return 0;
}

