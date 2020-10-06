#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    string S;
    cin >> S;
    vector<ll> remove_index;
    ll start = 0;
    ll end = S.length() - 1;
    while(start < end){
        if (S[start] == ')'){
            start++;
            continue;
        }else if(S[end] == '('){
            end--;
        }else{
            remove_index.push_back(start);
            remove_index.push_back(end);
            start++;
            end--;
        }
    }
    sort(remove_index.begin(),remove_index.end());
    if(remove_index.size() == 0){
        cout << 0 << endl;
    }else{
        cout << 1<< endl;
        cout << remove_index.size() << endl;
        for(int i = 0; i < remove_index.size();i++){
            if (i != 0){
                cout << " ";
            }
            cout << remove_index[i] + 1;
        }
        cout << endl;
    }
    return 0;
}
int main()
{
    // ll t;
    // cin >> t;
    // for (int i = 1; i <= t; i++)
    // {
        solve();
    // }
    return 0;
}
