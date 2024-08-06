#include <bits/stdc++.h>
#include <unistd.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


double eu_dist(double a,double b,double c,double x,double y,double z){
    return sqrt( (a-x)*(a-x) + (b-y)*(b-y) + (c-z)*(c-z) );
}


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
   
    double a, b, c;

    
    while (cin >> a >> b >> c) {
        if(a == 0 && b == 0 && c == 0) break;
        
        vector<array<double,3>> k;
        k.pb({a,b,c});
        for (int i = 0; i < 3; i++) {
            cin >> a >> b >> c;
            k.pb({a,b,c});
        }
        
        vector<array<double,3>> w, l;

        w.pb({eu_dist(k[0][0],k[0][1],k[0][2],k[1][0],k[1][1],k[1][2]),0,1}); 
        w.pb({eu_dist(k[0][0],k[0][1],k[0][2],k[2][0],k[2][1],k[2][2]),0,2}); 
        w.pb({eu_dist(k[0][0],k[0][1],k[0][2],k[3][0],k[3][1],k[3][2]),0,3});
        w.pb({eu_dist(k[1][0],k[1][1],k[1][2],k[2][0],k[2][1],k[2][2]),1,2});
        w.pb({eu_dist(k[2][0],k[2][1],k[2][2],k[3][0],k[3][1],k[3][2]),2,3});      
        w.pb({eu_dist(k[1][0],k[1][1],k[1][2],k[3][0],k[3][1],k[3][2]),1,3});

    
        sort(all(w));
        double m = 0;
        for (auto i: w) {
            m += i[0]; 
        }
        m /= 6;
        for (auto i: w) {
            l.pb({abs(i[0]-1),i[1],i[2]});
        }
        sort(rall(l));
        map<int,int> t;
        
        t[l[0][1]]++;
        t[l[0][2]]++;
        t[l[1][1]]++;
        t[l[1][2]]++;
       
       int asw = 1;
        for (auto i: t) {
            if(i.second == 2){
                asw = i.first+1;
            } 
        }        

        cout << asw << endl;



    }
    return 0;
}
