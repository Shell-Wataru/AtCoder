#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
using namespace std;
using ll = long long;

int solve()
{
    ll B,K,Sx,Sy,Gx,Gy;
    cin >> B >> K >> Sx >> Sy >> Gx >> Gy;;
    ll ans = abs(Sx-Gx)*K + abs(Sy-Gy)*K;
    vector<pair<ll,ll>> BS = {
      {Sx/B*B,Sy},
      {(Sx/B+1)*B,Sy},
      {Sx,Sy/B*B},
      {Sx,(Sy/B+1)*B}
    };
    vector<pair<ll,ll>> BG = {
      {Gx/B*B,Gy},
      {(Gx/B+1)*B,Gy},
      {Gx,Gy/B*B},
      {Gx,(Gy/B+1)*B}
    };
    for(auto bs:BS){
        for(auto bg:BG){
            ll d = -1;
            if (bs.first == bg.first || bs.second == bg.second ||
            (bs.first % B == 0) && (bg.second % B == 0) ||
            (bs.second % B == 0) && (bg.first % B == 0)
            ){
              d = abs(bs.first-Sx)*K
                + abs(bs.second-Sy)*K
                + abs(bg.first-Gx)*K
                + abs(bg.second-Gy)*K
                + abs(bs.first- bg.first)
                + abs(bs.second- bg.second);
            }else if (bs.first/B == bg.first/B){
              ll x1 = bs.first/B*B;
              ll x2 = (bs.first/B+1)*B;
              d = abs(bs.first-Sx)*K
                + abs(bs.second-Sy)*K
                + abs(bg.first-Gx)*K
                + abs(bg.second-Gy)*K
                + abs(bs.second- bg.second)
                + min(bs.first -x1 + bg.first-x1,x2-bs.first +x2-bg.first);
            }else if (bs.second/B == bg.second/B){
              ll y1 = bs.second/B*B;
              ll y2 = (bs.second/B+1)*B;
              d = abs(bs.first-Sx)*K
                + abs(bs.second-Sy)*K
                + abs(bg.first-Gx)*K
                + abs(bg.second-Gy)*K
                + abs(bs.first- bg.first)
                + min(bs.second -y1 + bg.second-y1,y2-bs.second +y2-bg.second);
            }else{
              d = abs(bs.first-Sx)*K
                + abs(bs.second-Sy)*K
                + abs(bg.first-Gx)*K
                + abs(bg.second-Gy)*K
                + abs(bs.first- bg.first)
                + abs(bs.second- bg.second);
            }
            // cout << d << endl;
            ans = min(ans,d);
      }
    }
    cout << ans << "\n";
    return 0;
}

int main()
{
    ll T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
    solve();
    }
    cout << flush;
    return 0;
}
