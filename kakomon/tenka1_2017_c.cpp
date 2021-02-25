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
    ll N;
    cin >> N;
    for(int h = 1;h <=3500;h++){
        if (4*h <= N){
            continue;
        }
        for(int n = 1;n <=3500;n++){
            ll bunshi = 4*h*n  - N*n - N*h;
            ll bumbo = N*h*n;
            if (bunshi > 0 && bumbo % bunshi == 0){
                ll w = bumbo/bunshi;
                cout << h << " " << n << " " << w << endl;
                return 0;
            }
        }
    }
    return 0;
}