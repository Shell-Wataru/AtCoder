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
    // 整数の入力
    ll T1,T2,A1,A2,B1,B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    ll first_step = T1 * (A1 - B1);
    ll total = T1 * (A1 - B1) + T2 * (A2 - B2);
    // cout << first_step << " " << total << endl;
    // cout << first_step / total << endl;
    // cout << first_step % total << endl;
    if (total == 0){
        cout << "infinity" << endl;
    }else if (first_step > 0 && total < 0){
        total = - total;
        if (first_step % total == 0){
            cout << 2 * first_step/total << endl;
        }else{
            cout << 2 * (first_step/total) + 1 << endl;
        }
    }else if (first_step < 0 && total > 0){
        first_step = - first_step;
        if (first_step % total == 0){
            cout << 2 * first_step/total << endl;
        }else{
            cout << 2 * (first_step/total) + 1 << endl;
        }
    }else {
        cout << 0 << endl;
    }
    return 0;
}