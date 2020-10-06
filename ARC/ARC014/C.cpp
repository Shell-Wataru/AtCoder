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
    ll R=0,G=0,B=0;
    for (size_t i = 0; i < N; i++)
    {
        char c;
        cin >> c;
        if (c == 'R'){
            R++;
        }else if(c == 'G'){
            G++;
        }else{
            B++;
        }
    }
    cout << (R % 2) + (G % 2) + (B % 2) << endl;
    return 0;
}