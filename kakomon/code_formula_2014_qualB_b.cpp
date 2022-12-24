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

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

int main()
{
    string N;
    cin >> N;
    ll a = 0;
    ll b= 0;
    reverse(N.begin(),N.end());
    for(int i = 0;i < N.size();i++){
        if (i % 2 == 0){
            a+= N[i] - '0';
        }else{
            b+= N[i] - '0';
        }
    }
    cout << b << " " << a << endl;
    return 0;
}