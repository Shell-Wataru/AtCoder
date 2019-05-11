#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for(int i = 1; i<= T;i++){
        ll N,ssize;
        cin >> N;
        string S;
        cin >> S;


        ssize = S.size();
        cout << "Case #" << i << ": ";
        for (int j = 0; j < ssize ;j++){
            if (S[j] == 'S'){
                cout << 'E';
            }else{
                cout << 'S';
            }
        };

        cout << endl;
    }

    return 0;
}