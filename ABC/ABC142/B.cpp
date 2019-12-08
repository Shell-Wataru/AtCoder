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
    cin >> N >> K;
    total = 0;
    for(int i = 0;i<N;i++){
        ll h;
        cin >> h;
        if(h >= K){
            total++;
        }
    }

    cout << total << endl;
    return 0;
}