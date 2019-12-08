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
    ll N,K,total;
    total = 0;
    vector<ll> takoyaki;
    cin >> N;
    for(int i = 0;i<N;i++){
        ll h;
        cin >> h;
        takoyaki.push_back(h);
    }

    for(int i = 0;i<N;i++){
        for(int j = i+1;j<N;j++){
            total += takoyaki[i] * takoyaki[j];
        }
    }
    cout << total << endl;
    return 0;
}