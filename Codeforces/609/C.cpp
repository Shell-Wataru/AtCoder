#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> digits;
    for(auto c: s){
        digits.push_back(c - '0');
    }


    bool is_greater = false;
    for(int i = 0;i< n;i++){
        if (digits[i] == digits[i % k]){
            continue;
        }else if (digits[i] > digits[i % k]){
            is_greater = true;
            break;
        }else{
            break;
        }
    }
    if (is_greater){
        ll kuriage_index = 1;
        digits[k-kuriage_index]++;
        while(k - kuriage_index >= 0 && digits[k - kuriage_index] > 9){
            if (k - kuriage_index == 0){
                digits[0] = 0;
                digits.insert(digits.begin(),1);
            }else{
                digits[k - kuriage_index] = 0;
                kuriage_index++;
                digits[k - kuriage_index]++;
            }
        }
    }
    cout << digits.size() << endl;
    for(int i = 0;i< digits.size();i++){
        cout << digits[i % k];
    }
    cout << endl;
    return 0;
}
