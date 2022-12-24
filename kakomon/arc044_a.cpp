#define _USE_MATH_DEFINES
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

using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    bool is_prime = true;
    if (N == 1)
    {
        cout << "Not Prime" << endl;
        return 0;
    }
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            is_prime = false;
        }
    }
    if (is_prime || (N % 2 != 0 && N % 5 != 0 && N % 3 != 0))
    {
        cout << "Prime" << endl;
    }
    else
    {
        cout << "Not Prime" << endl;
    }
    return 0;
}