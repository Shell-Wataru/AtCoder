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


int main()
{
    // 整数の入力
    ll N,sum;
    vector<ll> waters;
    cin >> N;
    for(int i = 1;i<=N;i++){
        ll a;
        cin >> a;
        if (i % 2 == 1){
            sum+=a;
        }else{
            sum-=a;
        }
        waters.push_back(a);
    }

    for (int i = 0;i<N;i++){
        if ( i  == 0){
            cout << sum;
        }else{
            sum = - sum + 2 * waters[i-1];
            cout << " " << sum;
        }
    }
    cout << endl;
    return 0;

}