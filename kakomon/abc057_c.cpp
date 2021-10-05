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
#include <stack>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    size_t min_value = numeric_limits<size_t>::max();
    for (size_t i = 1; i *i <= N ; i++)
    {
        if(N % i == 0){
            min_value = min(min_value,max(to_string(i).size(),to_string(N/i).size()));
        }
    }
    cout << min_value << endl;
        return 0;
}