#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    long long H,W,N,Sr,Sc;
    string S,T;
    cin >> H >> W >> N;
    cin >> Sr >> Sc;
    cin >> S >> T;
    ll tl,tr,tu,td;
    ll al,ar,au,ad;
    ll sl,sr,su,sd;
    tl = 1;
    tr = W;
    tu = H;
    td = 1;
    al = 0;
    ar = 0;
    au = 0;
    ad = 0;
    sl = Sc;
    sr = Sc;
    su = Sr;
    sd = Sr;


    for(int i = 0; i< N;i++){
        // cout << i << endl;
        if (S[i] == 'L'){
            if (al == 0){
                tl = tl + 1;
            }else{
                al = al - 1;
            }
        }

        if (S[i] == 'R'){
            if (ar == 0){
                tr = tr - 1;
            }else{
                ar = ar - 1;
            }
        }

        if (S[i] == 'U'){
            if (au == 0){
                tu = tu - 1;
            }else{
                au = au - 1;
            }
        }

        if (S[i] == 'D'){
            if (ad == 0){
                td = td + 1;
            }else{
                ad = ad - 1;
            }
        }

        // cout << "tl" << tl << "tr" << tr  << "td" << td << "tu" << tu << endl;
        // cout << "al" << al << "ar" << ar  << "ad" << ad << "au" << au << endl;
        if (!(tl <= sr && sl <= tr && td <= su && sd <= tu && tl <= tr && td <= tu)){
            cout << "NO" << endl;
            return 0;
        }

        if (T[i] == 'L'){
            if (tr + ar  < W){
                ar = ar + 1;
            }else{
                sl = max(sl - 1,tl);
            }
        }

        if (T[i] == 'R'){
            if (tl - al  > 1){
                al = al + 1;
            }else{
                sr = min(sr + 1,tr);
            }

        }

        if (T[i] == 'D'){
            if (tu + au  < H){
                au = au + 1;
            }else{
                sd = max(sd - 1,td);
            }
        }

        if (T[i] == 'U'){
            if (td - ad  > 1){
                ad = ad + 1;
            }else{
                su = max(su + 1,tu);
            }
        }

    }

    cout << "YES" << endl;
    return 0;
}