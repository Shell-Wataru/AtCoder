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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

struct LRPair
{
    ll from = -1;
    ll to = -1;
    ll centerR = -1;
    ll centerL = -1;
    bool close = false;
};
int main()
{
    // 整数の入力
    ll N;
    string S;
    vector<LRPair> pairs;
    cin >> S;
    vector<ll> counts(S.size(),0);
    LRPair p;
    p.from = 0;
    for (int i = 1; i < S.size(); i++)
    {
        if (S[i-1] == 'R')
        {
            if (S[i] == 'R')
            {

            }
            else
            {
                p.centerL = i;
                p.centerR = i - 1;
            }
        }
        else
        {
            if (S[i] == 'R')
            {
                p.to = i -1;
                pairs.push_back(p);
                LRPair new_p;
                p = new_p;
                p.from = i;
            }
            else
            {
            }
        }
    }
    p.to = S.size() - 1;
    pairs.push_back(p);

    // for(auto p:pairs){
    //     cout << p.from << p.centerR << p.centerL << p.to << endl;
    // }

    ll pair_index = 0;
    for (int i = 0;i<S.size();i++){
        if (pairs[pair_index].to < i){
            pair_index++;
        }
        LRPair &p = pairs[pair_index];
        if (abs(p.centerR - i) % 2 == 0){
            counts[p.centerR]++;
        }else{
            counts[p.centerL]++;
        }
    }

    for(int i = 0;i< S.size();i++){
        if (i == 0){
            cout << counts[i];
        }else
        {
            cout << " " << counts[i];
        }

    }
    cout << endl;
    return 0;
}