#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

long long keta;
string ans;

// 整数の入力
int getDigit(vector<int> digits){
    int digitLow = -1;
    if (digits.size()== 0){
        digitLow = 0;
    }
    int digitHigh = 9;
    int j;
    while (digitLow +1 != digitHigh) {
        cout << "? ";
        for (j= 0;j<digits.size();j++){
                cout << digits[j];
        }
        cout << (digitLow + digitHigh)/2;
        for (j= 0;j< keta - digits.size() + 1;j++){
            cout << 9;
        }
        cout << endl <<flush;

        cin >> ans;
        if (ans == "Y"){
            digitHigh = (digitLow + digitHigh)/2;
        }else{
            digitLow = (digitLow + digitHigh)/2;
        }
    }
    return digitHigh;
}
int main()
{
    int i;
    string ans2;
    long long ketaLow1 = 0;
    long long ketaHigh1 = 11;
    long long ketaLow2 = 0;
    long long ketaHigh2 = 11;

    while (ketaLow1 +1 != ketaHigh1) {
        cout << dec << "? ";
        for (i= 0;i< (ketaLow1 + ketaHigh1)/2;i++){
            cout << 9;
        }
        cout << endl << flush;
        cin >> ans;
        if (ans == "Y"){
            ketaHigh1 = (ketaLow1 + ketaHigh1)/2;
        }else{
            ketaLow1 = (ketaLow1 + ketaHigh1)/2;
        }
    }

    while (ketaLow2 +1 != ketaHigh2) {
        cout << dec << "? " << (long long)(pow(10,(ketaLow2 + ketaHigh2)/2)) << endl <<flush;
        cin >> ans;
        if (ans == "N"){
            ketaHigh2 = (ketaLow2 + ketaHigh2)/2;
        }else{
            ketaLow2 = (ketaLow2 + ketaHigh2)/2;
        }
    }

    if (ketaLow1 != ketaLow2){
        cout << "tigau" << endl;
        if (ketaLow2 == 10){
            keta = ketaLow1;
        }else{
            keta = ketaLow2;
        }
    }else{
        keta = ketaLow1;
    }

    vector<int> digits;
    for (i = keta;i >= 0;i--){
        digits.push_back(getDigit(digits));
    }

    cout << "! ";
    for (i=0;i<=keta;i++){
        cout << digits[i];
    }
    cout << endl <<flush;

    return 0;
}