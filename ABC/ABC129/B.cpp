#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    long long N,total,m;
    vector<ll> weights;
    cin >> N;
    total = 0;
    for(int i = 0;i<N;i++){
        ll w;
        cin >> w;
        total+= w;
        weights.push_back(w);
    }
    m = total;
    ll current = 0;
    for(auto w :weights){
        current += w;
        m = min(m,abs(total - 2 * current));
    }
    cout << m << endl;
    return 0;
}