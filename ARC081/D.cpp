#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long long N,colors,beforeType,i;
    string S1,S2;
    vector<long long> A;
    cin >> N;
    cin >> S1;
    cin >> S2;
    beforeType = -1;

    if (S1[0] == S2[0]){
        colors = 3;
        beforeType = 1;
        i = 1;
    }else{
        colors = 6;
        beforeType = 2;
        i = 2;
    }

    for (;i<N;i++){
        if (S1[i] == S2[i]){
            if (beforeType == 1){
                colors = (colors * 2)% 1000000007;
            }else{
                colors = colors;
            }
            beforeType = 1;
        }else{
            if (S1[i] == S1[i-1]){
                if (beforeType == 1){
                    colors = (colors * 2) %1000000007;
                }else{
                    colors = (colors * 3)% 1000000007;
                }
                beforeType = 2;
            }
        }
    }

    cout << colors << endl;
    return 0;
}