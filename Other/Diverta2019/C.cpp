#include<iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;

int main()
{
    // 整数の入力
    long long N,stable,headB,tailA,headtailAB;
    stable = 0;
    headB = 0;
    tailA = 0;
    headtailAB = 0;
    cin >> N;
    for (int i = 0;i< N;i++){
        string s;
        cin >> s;
        for (int j = 1; j < s.size();j++){
            if (s[j] == 'B' && s[j-1] == 'A'){
                stable++;
            }
        }
        if (s[0] == 'B' && s[s.size() -1] != 'A'){
            headB++;
        }
        if (s[0] != 'B' && s[s.size() -1] == 'A'){
            tailA++;
        }
        if (s[0] == 'B' && s[s.size() -1] == 'A'){
            headtailAB++;
        }
    }
    // cout << stable << " " << headB << " " << tailA << " " << headtailAB << endl;
    if (headtailAB > 0){
        if (headB != tailA){
            cout << stable + max(headtailAB - 1LL,0LL) + min(headB,tailA) + 1 << endl;
        }else{
            if (headB == 0){
                cout << stable + max(headtailAB - 1LL,0LL) + min(headB,tailA) << endl;
            }else{
                cout << stable + max(headtailAB - 1LL,0LL) + min(headB,tailA) + 1 << endl;
            }
        }
    }else{
        cout << stable + min(headB,tailA) << endl;
    }
    return 0;
}