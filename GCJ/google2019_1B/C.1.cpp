#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;

class RMQ{
    static const int INT_MAX = 2147483647;
    int MAX_N;
    int highestOneBit(int i) {
        i |= (i >>  1);
        i |= (i >>  2);
        i |= (i >>  4);
        i |= (i >>  8);
        i |= (i >> 16);
        return i - (i >> 1);
    }
    public:
        int *dat;
        int *datIndexes;

        RMQ(int size = 100000){
            int HOB = highestOneBit(size);
            if (HOB != size){
                MAX_N = HOB<<1;
            }else{
                MAX_N = HOB;
            }
            dat = new int[MAX_N*2];
            datIndexes = new int[MAX_N*2];
            for (int i =1;i< MAX_N*2;i++){
                dat[i] = INT_MAX;
                datIndexes[i] = -1;
            }
        }

        void update(int index,int x){
            for (int i= index+MAX_N; i>0; i>>=1) {
            //iが対応するインデックス
                if (i >= MAX_N){
                    dat[i] = x;
                    datIndexes[i] = i-MAX_N;
                }else{
                    if (dat[i*2] <= dat[i*2+1]){
                        dat[i] = dat[i*2];
                        datIndexes[i] = datIndexes[i*2];
                    }else{
                        dat[i] = dat[i*2+1];
                        datIndexes[i] = datIndexes[i*2+1];
                    }
                }
            }
        }

        int query(int L,int R){
            L += MAX_N;
            R += MAX_N;
            int minValue = INT_MAX;
            for (;L<R; L>>=1, R>>=1) {
                if(R&1) {
                    --R;
                    if (dat[R] < minValue){
                        minValue = dat[R];
                    }
                } //--Rが対応するインデックス
                if(L&1){
                    if (dat[L] < minValue){
                        minValue = dat[L];
                    }
                    L++;
                }//L++が対応するインデックス
            }
            return minValue;
        }

        pair<int,int> queryWithIndex(int L,int R){
            L += MAX_N;
            R += MAX_N;
            int minValue = INT_MAX;
            int minIndex = -1;
            for (;L<R; L>>=1, R>>=1) {
                if(R&1) {
                    --R;
                    if (dat[R] < minValue){
                        minValue = dat[R];
                        minIndex = datIndexes[R];
                    }
                } //--Rが対応するインデックス
                if(L&1){
                    if (dat[L] < minValue){
                        minValue = dat[L];
                        minIndex = datIndexes[L];
                    }
                    L++;
                }//L++が対応するインデックス
            }
            return make_pair(minValue,minIndex);
        }
};

ll upside_range(ll N,RMQ query,ll index,ll index_value){
    // cout << "upside" << endl;
    // cout << "index_value" << index_value << endl;
    ll high = N;
    ll low = index + 1;
    // cout << "hoge" << query.query(index,low);

    if (query.query(index,low) < index_value){
        // cout << "index" << index;
        return index;
    }else if (query.query(index,high) >= index_value){
        return N;
    }


    while(low+1 < high){
        ll center = (low + high)/2;
        // cout << "high:" << high << "low:"<< low << "center:" << center << ",value:"<< query.query(index,center) << "indexvalue" << index_value << endl;
        if (query.query(index,center) < index_value){
            // cout << "h" << endl;
            high = center;
        }else{
            // cout << "l" << endl;
            low = center;
        }
    }
    // cout << "low "<< low << endl;
    return low;
}

ll downside_range(ll N,RMQ query,ll index,ll index_value){
    // cout << "downside" << endl;
    // cout << "index_value" << index_value << endl;
    ll high = index;
    ll low = -1;

    if (query.query(high,index+ 1) < index_value){
        return index + 1;
    }else if (query.query(0,index+ 1) >= index_value){
        return -1;
    }

    while(low+1 < high){
        ll center = (low + high)/2;
        // cout << "high:" << high << "low:"<< low << "center:" << center << ",value:"<< query.query(center,index+ 1) << "index_value" << index_value << endl;
        if (query.query(center,index+ 1) < index_value){
            // cout << "l" << endl;
            low = center;
        }else{
            // cout << "h" << endl;
            high = center;
        }
    }

    // cout << "high:" << high <<endl;
    return high;
}

ll patterns(ll N,ll K,vector<ll> cs,vector<ll> ds){
    RMQ c_query(cs.size());
    RMQ d_query(ds.size());
    for (int i = 0;i < cs.size();i++){
        // cout << cs[i] << ds[i] << endl;
        c_query.update(i,-cs[i]);
    }
    for (int i = 0;i < ds.size();i++){
        // cout << cs[i] << ds[i] << endl;
        d_query.update(i,-ds[i]);
    }

    ll total = 0;

    for (int i = 1;i < N + 1;i++){
        // cout << "i" << i << endl;
        ll range_to = upside_range(cs.size(),c_query,i+1,- cs[i] + 1);
        ll range_from = downside_range(cs.size(),c_query,i,- cs[i]);
        // cout << "-----------------------range:" <<range_from << "-" << range_to << endl;
        ll p3_from = max(range_from,downside_range(ds.size(),d_query,i,- cs[i] + K + 1));
        ll p3_to = min(range_to,upside_range(ds.size(),d_query,i,- cs[i] + K + 1));
        // cout << "----------p3_from:" << p3_from << ",p3_to:" << p3_to << endl;

        ll p2_to = min(range_to ,upside_range(ds.size(),d_query,i,- cs[i] - K));
        ll p2_from = max(range_from,downside_range(ds.size(),d_query,i,- cs[i] - K));
        // cout << "----------p2_from:" << p2_from << ",p2_to:" << p2_to << endl;
        ll diff = (i - p2_from + 1) * (p2_to - i ) - (i - p3_from + 1) * (p3_to - i );
        total += diff;
        // cout << "=== diff" << diff << endl;
    }
    return total;
}

int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        ll N, K,ci,di;
        cin >> N >> K;
        vector<ll> cs;
        vector<ll> ds;
        ll big_number = 1000000;
        cs.push_back(big_number);
        for (int j = 0; j < N; j++)
        {
            cin >> ci;
            cs.push_back(ci);
        };

        ds.push_back(big_number);
        for (int j = 0; j < N; j++)
        {
            cin >>  di;
            ds.push_back(di);
        };
        ds.push_back(big_number);

        ll p = patterns(N,K,cs,ds);
        cout << "Case #" << i << ": " <<  p << endl;
    }

    return 0;
}