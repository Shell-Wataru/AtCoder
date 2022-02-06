#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

bool is_vowel(char c){
    vector<char> vowels = {'A','I','U','E','O'};
    return find(vowels.begin(),vowels.end(),c) != vowels.end();
}
ll solve(){
    string S;
    cin >> S;
    ll ans = numeric_limits<ll>::max();
    for (size_t i = 0; i < 26; i++)
    {
        ll changes = 0;
        char target = 'A' + i;
        for(auto c:S){
            if (c == target){
                continue;
            }else if (is_vowel(c) ^ is_vowel(target)){
                changes += 1;
            }else{
                changes += 2;
            }
        }
        ans = min(ans,changes);
    }
    return ans;
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;
    // cerr << T << endl;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}