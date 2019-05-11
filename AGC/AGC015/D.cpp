#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <bitset>
using namespace std;

int main()
{
    long long A,B,i,firstA,firstB,r,k;
    cin >> A >> B;
    bitset<60> bitA(A);
    bitset<60> bitB(B);
    r = -1;
    k= -1;
    for (i=59;i>=0;i--){
        if (bitA.test(i)!= bitB.test(i)){
            r = i;
            break;
        }else{
            bitA.reset(i);
            bitB.reset(i);
        }
    }
    A = bitA.to_ullong();
    B = bitB.to_ullong();

    if (r== -1){
        cout << 1 << endl;
    }else{
        for (i=r-1;i>=0;i--){
            if (bitB.test(i)){
                k = i;
                break;
            }
        }

        if (pow(2,k+1) >= A){
            cout << dec <<(long long)((1LL<<(r+1)) - A) << endl;
        }else{
            cout << dec << (2 * (long long)((1LL<<r) - A) + (1LL<<(k+1))) <<endl;
        }
    }

    return 0;
}