#include<iostream>
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
ll BASE_NUM =  1000000007;

int main()
{
    // 整数の入力
    ll N,A;
    vector<map<int,int>> shougens;
    cin >> N;
    for(int i = 0;i< N;i++){
        cin >> A;
        map<int,int> shougen;
        for(int j = 0;j< A;j++){
            ll x,y;
            cin >> x >> y;
            x--;
            shougen[x] = y;
        }
        shougens.push_back(shougen);
    }

    ll best = 0;
    for (int bit = 0; bit < (1<<N); ++bit) {
        bool is_clear = true;
        ll clear_count = 0;
        for (int i = 0; i < N; ++i) {
            if (bit & (1<<i)) {
                clear_count++;
                for (auto p: shougens[i]){
                    ll x = p.first;
                    ll y = p.second;
                    if ( (bit & (1<<p.first)) && y == 0){
                        is_clear = false;
                        break;
                    }else if(!(bit & (1<<p.first)) && y == 1){
                        is_clear = false;
                        break;
                    }
                }
            }
        }
        if (is_clear){
            best = max(best,clear_count);
        }
    }
    cout << best << endl;
    return 0;
}