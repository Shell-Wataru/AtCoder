#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;
int f(int now,int t,int a,int b,int c,bool isPlus,int startX,int X){
    int nowF;
    if (startX < a){
        nowF = a + c;
    }else if(startX < b){
        nowF = startX + c;
    }else{
        nowF = b + c;
    }
    if (isPlus){
        return min(nowF + (t - now),X);
    }else{
        return max(nowF - (t - now),0);
    }
    return 0;
}
int main()
{
    // 整数の入力
    long long X,K,Q,N,a_i,i,t_i,r_i,a,b,c,now;
    bool isPlus = false;
    queue<long long>R;

    cin >> X >> K;

    for (i= 0; i< K ; i++) {
        cin >> r_i;
        R.push(r_i);
    }

    a = 0;
    b = X;
    c = 0;
    now = 0;

    cin >> Q;
    for (i= 0;i<Q;i++){
        cin >> t_i >> a_i;
        while(t_i > R.front() && R.size() != 0){
            if (a != b){
                if (isPlus){
                    b = min(b,max(2 * X -  ((b + c) + (R.front() -now)),0ll));
                    a = min(a,b);
                    c = min(c + (R.front() - now),X);
                }else{
                    a = max(a,min((R.front() - now) - (a+c) ,X));
                    b = max(a,b);
                    c = max(c - (R.front() - now),-X);
                }
            }else{
                c = f(now,R.front(),a,b,c,isPlus,0,X);
                a = 0;
                b = 0;
            }
            now = R.front();
            R.pop();
            isPlus = !isPlus;
        }
        cout << f(now,t_i,a,b,c,isPlus,a_i,X) << endl;
    }

    return 0;
}