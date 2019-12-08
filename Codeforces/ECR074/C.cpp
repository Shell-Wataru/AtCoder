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

void solve()
{
    ll h, n;
    cin >> h >> n;
    vector<ll> P;
    for (int i = 0; i < n; i++)
    {
        ll p;
        cin >> p;
        if (i == 0)
        {
            P.push_back(p);
        }
        else if (P.back() == p + 1)
        {
            P.push_back(p);
        }
        else
        {
            P.push_back(p.back);
            P.push_back(p);
        }
    }

    vector<ll> min_counts(P.size(), 0);
    for(int i = 1;i< P.size();i++){
        if (i == 1){
            if (P[i] == -1){
                min_counts[i] =0;
            }else{
                min_counts[i] == min_counts[i-1] + 1;
            }
        }else{
            if (P[i] == -1){
                min_counts[i] = min(min_counts[i-1] ,min_counts[i-2]);
            }else{
                if (P[i-1]== -1){
                    min_counts[i] == min_counts[i-1] + 1;
                }else{

                }
            }
        }
    }

    return;
}

int main()
{
    // 整数の入力
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        solve();
    }
    return 0;
}
