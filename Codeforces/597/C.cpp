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

// ll pat(ll n){
//     vector<ll> A;
//     A.push_back[1];
//     A.push_back[1];
//     for(int i = 2;i<n;i++){
//         A.push_back( (A[i-1]+A[i-2]) % BASE_NUM);
//     }
//     return A[n];
// }


int main()
{
    // 整数の入力
    string S;
    cin >> S;

    if (S.find('m') != string::npos){
        cout << 0 << endl;
        return 0;
    }

    if (S.find('w') != string::npos){
        cout << 0 << endl;
        return 0;
    }
    vector<ll> A;
    A.push_back(1);
    A.push_back(1);
    for(int i = 2;i<=S.length();i++){
        A.push_back( (A[i-1]+A[i-2]) % BASE_NUM);
    }

    char last_char = '-';
    ll last_char_length = 0;
    ll patterns = 1;
    for(int i = 0; i < S.length();i++){
        if (S[i] != last_char){
            if (last_char == 'u' || last_char == 'n'){
                patterns = patterns * A[last_char_length] % BASE_NUM;
            }
            last_char = S[i];
            last_char_length = 1;
        }else{
            last_char_length++;
        }
    }
    if (last_char == 'u' || last_char == 'n'){
        patterns = patterns * A[last_char_length] % BASE_NUM;
    }
    cout << patterns << endl;
    return 0;
}
