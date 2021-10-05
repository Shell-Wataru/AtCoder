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
    ll N, M;
    cin >> N >> M;
    ll two,three,four;
    if (M % 2 == 1){
        three = 1;
        M -= 3;
        N -= 1;
        M /= 2;
        four = M - N;
        two = N - four;
        if (four >= 0 && two >= 0){
            cout << two << " " << three  << " " << four << endl;
        }else{
            cout << -1 << " " << -1  << " " << -1 << endl;
        }
    }else{
        three = 0;
        M /= 2;
        four = M - N;
        two = N - four;
        if (four >= 0 && two >= 0){
            cout << two << " " << three  << " " << four << endl;
        }else{
            cout << -1 << " " << -1  << " " << -1 << endl;
        }
    }
    return 0;
}