#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;

    for(int i = 1; i<= N;i++){
        string S;
        cin >> S;

        ll first4index,ssize;
        string A = "";
        string B = "";

        ssize = S.size();
        for (int j = 0; j < ssize ;j++){
            if (S[j] == '4'){
                first4index = j;
                break;
            }
        };

        for (int j = 0; j < ssize ; j++){
            if (j < first4index){
                A.push_back(S[j]);
            }else{
                if (S[j] == '4'){
                    A.push_back('3');
                    B.push_back('1');
                }else{
                    A.push_back(S[j]);
                    B.push_back('0');
                }
            }
        };

        cout << "Case #" << i << ": " << A << " " << B << endl;
    }

    return 0;
}