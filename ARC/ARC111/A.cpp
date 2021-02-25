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
    ll N,M;
    cin >> N >> M;
    vector<ll> sss;
    map<ll,ll> where;
    ll amari = 1;
    ll i = 0;
    while(where.find(amari) == where.end()){
        where[amari] = i;
        sss.push_back(amari/M);
        amari = amari % M;
        amari *= 10;
        i++;
    }
    cout << sss.size() << endl;
    vector<ll> a;
    map<pair<ll,ll>,ll> found;
    ll a_index = 0;
    ll sss_index = 0;
    ll ans = 0;
    while(found.find({sss_index,ans}) == found.end()){
        found[{sss_index,ans}] = a_index;
        a.push_back(ans);
        ans = (ans * 10 + sss[sss_index]) % M;
        a_index++;
        if (sss_index == sss.size()){
            sss_index = where[amari];
        }else{
            sss_index++;
        }
    }

    cout << a.size() << endl;
    return 0;
}