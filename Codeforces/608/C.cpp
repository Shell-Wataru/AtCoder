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
ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll n,sx,sy;
    cin >> n >> sx >> sy;

    ll ue,shita,hidari,migi;
    ue = 0;
    shita = 0;
    hidari = 0;
    migi = 0;
    for(int i = 0;i< n;i++){
        ll x,y;
        cin >> x >> y;
        if (x > sx){
            migi++;
        }
        if (x < sx){
            hidari++;
        }
        if (y > sy){
            ue++;
        }
        if (y < sy){
            shita++;
        }
    }

    if (ue >= migi && ue >= hidari && ue >= shita){
        cout << ue << endl;
        cout << sx << " " << sy + 1 << endl;
    }else if (shita >= migi && shita >= hidari && shita >= ue){
        cout << shita << endl;
        cout << sx << " " << sy - 1 << endl;
    }else if (migi >= ue && migi >= hidari && migi >= shita){
        cout << migi << endl;
        cout << sx + 1 << " " << sy << endl;
    }else{
        cout << hidari << endl;
        cout << sx - 1 << " " << sy << endl;
    }
    return 0;
}
