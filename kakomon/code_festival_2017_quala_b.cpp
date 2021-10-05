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
    ll N, M, K;
    cin >> N >> M >> K;
    for (size_t i = 0; i <= N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            if (i*j + (N-i)*(M-j) == K){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}