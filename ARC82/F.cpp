#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int tIndex(int t,vector<long long> RTotal){
    int upperIndex = RTotal.size();
    int lowerIndex = 0;
    while (upperIndex != lowerIndex + 1){
        if (t >= RTotal[(lowerIndex+upperIndex)/2]){
            lowerIndex = (lowerIndex+upperIndex)/2;
        }else{
            upperIndex = (lowerIndex+upperIndex)/2;
        }

    }

    return lowerIndex;
}

int main()
{
    // 整数の入力
    long long X,K,Q,N,a_i,i,t_i,r_i;
    vector<long long>R;
    vector<long long>XResults;
    vector<long long>ZeroResults;
    vector<long long>XMins;
    vector<long long>ZeroMaxs;

    cin >> X >> K;

    R.push_back(0);
    for (i= 0; i< K ; i++) {
        cin >> r_i;
        R.push_back(r_i);
    }

    long long now = X;
    XResults.push_back(now);
    XMins.push_back(now)
    for (i= 1; i<= K ; i++) {
        if(i % 2 == 1){
            now = max(now - (R[i] - R[i-1]),0ll);
        }else{
            now = min(now + (R[i] - R[i-1]),X);
        }
        XResults.push_back(now);
        XMins.push_back(min(Xmins[i-1],now));
    }

    now = 0;
    ZeroResults.push_back(now);
    ZeroMaxs.push_back(now)
    for (i= 1; i<= K ; i++) {
        if(i % 2 == 1){
            now = max(now - (R[i] - R[i-1]),0ll);
        }else{
            now = min(now + (R[i] - R[i-1]),X);
        }
        ZeroResults.push_back(now);
        XMins.push_back(min(Xmins[i-1],now));
    }


    cin >> Q;
    for (i= 0;i<Q;i++){
        cin >> t_i >> a_i;
        int j = tIndex(t_i,RTotal);
        int minSand = XCalcResult.query(0,j+1);
        if (minSand - (X - a_i) < 0){
            if (j%2 == 0){
                cout << max(zeroCalcResult[j] - (t_i - RTotal[j]),0ll)<< endl;
            }else{
                cout << min(zeroCalcResult[j] + (t_i - RTotal[j]),X)<< endl;
            }
        }else{
            if (j%2 == 0){
                cout << "ss"
                cout << max(XCalcResult.query(j,j+1)- (X - a_i) - (t_i - RTotal[j]),0ll)<< endl;
            }else{
                cout << min(XCalcResult.query(j,j+1)- (X - a_i) + (t_i - RTotal[j]),X) << endl;
            }
        }

    }

    return 0;
}