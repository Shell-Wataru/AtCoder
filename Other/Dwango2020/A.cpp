
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <map>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll N;
    map<string,ll> data;
    vector<ll> lengthes;
    cin >> N;
    for(int i = 0;i< N;i++){
        string music;
        ll length;
        cin >> music >> length;
        lengthes.push_back(length);
        data[music] = i;
    }
    string X;
    cin >> X;
    ll total = 0;
    for(int i = data[X] + 1;i< N;i++){
        total += lengthes[i];
    }
    cout << total << endl;

    return 0;
}