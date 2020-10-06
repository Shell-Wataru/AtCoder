#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

struct line{
    ll x1,y1,x2,y2;
};

int main()
{
    ll N;
    cin >> N;
    vector<line> x,y;
    for (int i = 0; i < N; i++)
    {
        line l;
        cin >>  l.x1 >> l.y1 >> l.x2 >> l.y2;
        if (l.x2 < l.x1){
            swap(l.x1,l.x2);
        }
        if (l.y2 < l.y1){
            swap(l.y1,l.y2);
        }

        if (l.x1 == l.x2){
            y.push_back(l);
        }else{
            x.push_back(l);
        }
    }
    sort(y.begin(),y.end(),[](line l1,line l2){
        return l1.x1 < l2.x1;
    });
    sort(x.begin(),x.end(),[](line l1,line l2){
        return l1.y1 < l2.y1;
    });


    for(int i = 0;i < y.size();i++){
        for(int j = i+1; j< y.size();j++){
            ll y1 = max(y[i].y1,y[j].y1);
            ll y2 = min(y[i].y2,y[j].y2);
            cout << y1 << y2 << endl;
        }
    }
   return 0;
}