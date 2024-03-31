#include <bits/stdc++.h>
#include <bits/utility.h>
#include <climits>
#include <string>


using namespace std;


int main (int argc, char *argv[]){
    
    vector<int> a;
    string s;
    getline(cin,s); 
    s.pop_back();
    s.erase(s.begin());
    stringstream ss(s);
    for (int i; ss >> i;) {
        a.push_back(i);
        if (ss.peek() == ',' || ss.peek() == ' ')
            ss.ignore();
    }
    
    int max = INT_MIN;
    int index = -1;
    for (int i = 0; i < a.size(); i++) {
        int n = a[i];
        int sum = 0;
        while(n > 0) {
            int mod = n % 10;
            sum+= mod;
            n = n / 10;
        } 
        
        if(sum > max){
            max = sum;
            index = 1;
        }
    }
        cout << index<<" ("<<a[index]<<")"<<endl;

    return 0;
}
