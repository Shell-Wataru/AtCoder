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
    ll N;
    bool creatable = true;
    vector<ll> H;
    cin >> N;
    for (int i = 0;i< N;i++){
        ll h;
        cin >> h;
        H.push_back(h);
    }

    H[0]--;
    for (int i = 1;i < N;i++){
        if (H[i-1] < H[i]){
            H[i]--;
        }

        if (H[i] < H[i-1]){
            creatable = false;
            break;
        }
    }
    if (creatable){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}