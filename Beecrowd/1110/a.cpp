#include <bits/stdc++.h>
#include <deque>
#include <iostream>

using namespace std;




int n, aux;
int main (int argc, char *argv[]){
        
    while (cin >> n) {
        if (n == 0) break;

        queue<int> q;
        queue<int> d;
        for (int i = 1; i <= n; i++) q.push(i);

        while (q.size() > 2) {
            d.push(q.front());
            q.pop();
            aux = q.front(); q.pop();
            q.push(aux);
        }
        d.push(q.front());
        q.pop();
        
        cout << "Discarded cards: "<< d.front();
        d.pop();
        while(!d.empty()) {
            cout <<", " << d.front();
            d.pop();
        }
        cout << endl;
        
        cout << "Remaining card: " << q.front() <<endl;
    }


    return  0;
}
