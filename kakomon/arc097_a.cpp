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

int solve()
{
    string S;
    cin >> S;
    int k;
    scanf("%d", &k);
    set<string> substrings;
    for(int i = 0;i < S.size();i++){
        for(int j = 1;j <= k;j++){
            substrings.insert(S.substr(i,j));
        }
    }
    auto itr = substrings.begin();
    for(int i = 0;i < k-1;i++){
        itr++;
    }
    cout << *itr << endl;
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
