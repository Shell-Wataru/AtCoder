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


int main()
{
    ll N;
    cin >> N;
    deque<ll> A;
    for (size_t i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    ll ans = 0;
    for(int i = 0;i < (N -1)/2;i++){
        auto front_itr = A.begin();
        ll front1 = *front_itr;
        ++front_itr;
        ll front2 = *front_itr;
        auto back_itr = A.rbegin();
        ll back1 = *back_itr;
        ++back_itr;
        ll back2 = *back_itr;
        if (2 * front1 + front2  < 2 * back1 + back2){
            A.pop_front();
            A.pop_front();
            A.front() += front1 + front2 + 2;
            ans += 2 * front1 + front2 + 1;
        }else{
            A.pop_back();
            A.pop_back();
            A.back() += back1 + back2 + 2;
            ans += 2 * back1 + back2 + 1;
        }
    }
    cout << ans << endl;
    return 0;
}