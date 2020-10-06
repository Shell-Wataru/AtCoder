#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator> // std::rbegin, std::rend

using namespace std;
using ll = long long;

int solve()
{
    ll n,x;
    cin >> n >> x;
    set<ll> A;
    for(int i = 0;i < n;i++){
        ll a;
        cin >> a;
        A.insert(a);
    }
    int index = 1;
    while(!(x == 0 && A.find(index) == A.end())){
        if(A.find(index) == A.end()){
            A.insert(index);
            x--;
        }
        index++;
    }
    cout << index - 1<< endl;
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}