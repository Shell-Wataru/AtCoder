#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
using namespace std;

long long gcd(long long a, long long b){
    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

int main()
{
    // 整数の入力
    long long N,A,B,C,D,i;
    cin >> N;
    for (int i = 0;i<N;i++){
        cin >> A >> B >> C >> D;
        if (A < B){
            cout << "No" << endl;
        }else if (D < B){
            cout << "No" << endl;
        }else {
            long long gcd_of_BD = gcd(B,D);
            long long amari = (A - C) % gcd_of_BD;
            long long min_zaiko;
            if (A <= C){
                min_zaiko = A - B;
            }else if (amari == 0){
                min_zaiko = C + gcd_of_BD - B;
            }else{
                min_zaiko = C + amari - B;
            }
            // cout << "gcd" << gcd_of_BD << endl;
            // cout << "amari:"<< amari << endl;
            // cout << "min_zaiko:" << min_zaiko << endl;
            if (min_zaiko >= 0){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }

            // if (min_zaiko + D >= B){
            //     cout << "Yes" << endl;
            // }else{
            //     cout << "No" << endl;
            // }
        }
    }
    return 0;
}