class RMQ{
    int MAX_N;

    public:
        int *dat;

        RMQ(int size = 100000){
            MAX_N = size;
            dat = new int[size*4];
            for (int i =1;i< 2*MAX_N;i++){
                dat[i] = INT_MAX;
            }
        }

        void update(int index,int x){
            for (int i= index+MAX_N; i>0; i>>=1) {
            //iが対応するインデックス
                if (i >= MAX_N){
                    dat[i] = x;
                }else{
                    dat[i] = min(dat[i*2],dat[i*2+1]);
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

};