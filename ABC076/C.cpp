#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    string S,T, returnS;
    long i,j;
    cin >> S >> T;
    returnS = "";
    i = 0;
    j = T.length() -1;

    if (S.find(T)!= string::npos){
        replace(S.begin(), S.end(), '?', 'a');
        cout << S << endl;
    }else{
        bool found = false;
        for (i= S.length() - T.length();i>=0;i--){
            for (j = 0;j< T.length();j++){
                if (S[i+j] == '?' || S[i+j] == T[j]){
                    if (j == T.length() - 1){
                        found = true;
                        break;
                    }
                }else{
                    break;
                }
            }
            if (found){
                break;
            }
        }

        if (found){
            long matchEnd = i + T.length() - 1;
            long matchStart = i;
            for (i= S.length() - 1;i>=0;i--){
                if (S[i] == '?' ){
                    if (matchStart <= i && i <= matchEnd){
                        returnS = T[i - matchStart ] + returnS;
                    }else{
                        returnS = "a" + returnS;
                    }
                }else{
                    returnS = S[i] + returnS;
                }
            }
            cout << returnS << endl;
        }else{
            cout << "UNRESTORABLE" << endl;
        }
    }
    return 0;
}