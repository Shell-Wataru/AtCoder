#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int main()
{
    ll n,k;
    cin >> n >> k;
    set<ll> current = {0};
    for (size_t i = 0; i < n; i++)
    {
        set<ll> next ={};
        for(int j = 0;j < k;j++){
            ll t;
            cin >> t;
            for(auto c:current){
                next.insert(c ^ t);
            }
        }
        current = next;
    }
    if (current.find(0) == current.end()){
        cout << "Nothing" << endl;
    }else{
        cout << "Found" << endl;
    }
  return 0;
}
