#include <bits/stdc++.h>
#include <chrono>
#include <ostream>
#include <queue>
#include <random>
#include <vector>


using namespace std;
int n, aux;


int main (int argc, char *argv[]){
    

    while (cin >> n){
        if (n == 0) break;
        
        while (cin >> aux && aux != 0) {
            queue<int> q, order;
            stack<int> s;
            bool flag = true;
            order.push(aux);
            for (int i = 0; i < n-1; i++) {
                cin >> aux;
                order.push(aux);
            }
            for (int i = 1; i <= n; i++) q.push(i);
           
            while(!order.empty()){
                
                if (!s.empty()) {
                    if(s.top() == order.front()){
                        s.pop();
                        order.pop();
                        continue;
                    }
                    if (q.empty()) {
                        flag = false;
                        break;
                    }

                }

                if (!q.empty()) {
                    if(order.front() == q.front()){
                        order.pop();
                        q.pop();
                        continue;
                    }
                    else {
                        s.push(q.front());
                        q.pop();
                    }
                }

                if (q.empty() && s.top() != order.front()) {
                    flag = false;
                    break;
                }
            }
            if (flag) cout << "Yes" << endl;
            else cout << "No"<< endl;
        }
        cout << endl;
    }


    return 0;
}
