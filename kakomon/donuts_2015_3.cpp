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
#include <stack>
using namespace std;
using ll = long long;

int solve()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }

    stack<ll> s;
    for(int i = 0;i < N;i++){
        cout << s.size() << endl;
        while(!s.empty() && s.top() < A[i]){
            s.pop();
        }
        s.push(A[i]);
    }

    return 0;
}

int main()
{
    // // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
