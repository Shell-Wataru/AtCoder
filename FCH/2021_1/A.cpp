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
string solve(){
    ll n;
    cin >> n;
    string W;
    cin >> W;
    char last_char = '-';
    ll count = 0;
    for(auto c:W){
        if (c == 'F'){
            continue;
        }else if (last_char == c){
            continue;
        }else{
            count++;
            last_char = c;
        }
    }
    return to_string(max(count-1,0ll));
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