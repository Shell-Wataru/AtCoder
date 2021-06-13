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

ll distance(ll a,ll b){
    cout << "? " << a+1 << " " << b+1 << endl;
    ll d;
    cin >> d;
    return d;
}
int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    ll max_d1 = 0;
    ll max_d1_index1 = -1;
    for(int i = 1;i< N;i++){
        ll d = distance(0,i);
        if (d > max_d1){
            max_d1 = d;
            max_d1_index1 = i;
        }
    }
    ll max_d2 = 0;
    for(int i = 0;i< N;i++){
        if (i != max_d1_index1){
            ll d = distance(max_d1_index1,i);
            if (d > max_d2){
                max_d2 = d;
            }
        }
    }
    cout << "! " << max_d2 << endl;
    return 0;
}