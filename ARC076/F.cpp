#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
using namespace std;

int main()
{
    // 整数の入力
    long long N,M,i,L,R,maxDiff;
    vector<vector<long long>> dots;
    deque<long long> stack;
    cin >> N >> M;
    maxDiff = N - M;
    for (i =0;i < N ;i++){
        cin >> L >>R;
        dots.push_back({L,R});
    }
    for (L =0;L <= M ;L++){
        for (R = L + 2; R<= M;R++){
        long seats = 0;
        if (M <= L){
            seats = M;
        }else if(L < M && M < R){
            seats = L;
        }else{
            seats = M - (R - L) + 1;
        }
        long temp = count_if(dots.begin(), dots.end(),[&L,&R](vector<long long> v){
            return v[0] <= L &&  R <= v[1];
        }) - seats;
        if (temp > maxDiff){
            cout << R <<"," <<L << endl;
            maxDiff = temp;
        }
    }
    }

    cout << maxDiff << endl;
    return 0;
}