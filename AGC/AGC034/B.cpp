#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    string S;
    cin >> S;
    ll count = 0;
    ll start = 0;
    ll N = S.size();
    ll As = 0;
    for (int i = 0;i<N;i++){
        if(i != 0 && (
                (S[i-1] == 'B' && S[i] == 'B' )
                || (S[i-1] == 'C' && S[i] == 'C' )
                || (S[i-1] == 'B' && S[i] == 'A' )
                || (S[i-1] == 'A' && S[i] == 'C' )
            )
        ){
            As = 0;
        }

        if(S[i] == 'A'){
            As++;
        }else if (S[i-1] == 'B' && S[i] == 'C'){
            count += As;
        }
    }
    cout << count << endl;
    return 0;
}