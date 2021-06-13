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

int main()
{
    string S;
    cin >> S;
    while(S.size() > 1){
        ll ans = 0;
        for(auto c:S){
            ans += c - '0';
        }
        S = to_string(ans);
    }
    cout << S[0] - '0' << endl;
    return 0;
}
