#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    int t;
    cin >> t;
    while (t--) {
        int n,a,b,x;
        vector<int> v;

        cin >> n >> a >> b;
        
        int nSum = 0;
        int bSum = 0;
        int aSum = 0;

        

        for (int i = 0; i < n; i++) {
            cin >> x;
            nSum += x;
            v.push_back(x);
        }
        
        sort(v.rbegin(),v.rend());
        
        for (int i = 0; i < b; i++) bSum += v[i];
        aSum = nSum - bSum;
        
        int asw = aSum - bSum;
        
//        cout << asw << endl;


        for (int i = 0; i < a; i++) {
            bSum -= v[i];
            if((i+b) < v.size()) {
                aSum -= v[i+b];
                bSum += v[i+b];
            }
            
//          cout << aSum << " " << bSum << endl;


            asw = max(aSum-bSum,asw);
        }
        cout << asw << endl;
    }

    

    return 0;
}
