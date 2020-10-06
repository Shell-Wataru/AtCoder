#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    long long n,m,N;
    cin >> m >> n >> N;

    ll total = N;
    ll remain = N;
    while(remain >= m){
        ll new_pencil = (remain/m) * n;
        total += new_pencil;
        remain = (remain % m) + new_pencil;
    }

    cout << total << endl;
    return 0;
}