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
#include <set>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll N, M, a, b;
    vector<ll> costs;
    vector<vector<ll>> opens;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        ll a,b;
        cin >> a >> b;
        costs.push_back(a);
        vector<ll> os;
        for(int i = 0;i<b;i++){
            ll o;
            cin >> o;
            os.push_back(o-1);
        }
        opens.push_back(os);
    }

    vector<ll> current_costs(1<<N,BASE_NUM);
    vector<ll> next_costs(1<<N,BASE_NUM);
    current_costs[0] = 0;
    next_costs[0] = 0;
    for(int i = 0;i<M;i++){
        ll open_doors = 0;
        for(auto c:opens[i]){
            open_doors |= 1<<c;
        }
        for(int j = 0;j< 1<<N;j++){
            next_costs[j|open_doors] = min(next_costs[j|open_doors],current_costs[j] + costs[i]);
        }
        copy(next_costs.begin(),next_costs.end(),current_costs.begin());
    }
    if (current_costs[(1<<N) - 1] == BASE_NUM){
        cout << -1 << endl;
    }else{
        cout << current_costs[(1<<N) - 1] << endl;
    }
   return 0;
}