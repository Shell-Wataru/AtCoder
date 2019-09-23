struct change
{
    ll p = -1;
    double a = 1.0;
    double b = 0.0;
};

class SegTree
{
    int MAX_N;
    int highestOneBit(int i)
    {
        i |= (i >> 1);
        i |= (i >> 2);
        i |= (i >> 4);
        i |= (i >> 8);
        i |= (i >> 16);
        return i - (i >> 1);
    }

public:
    change *dat;

    SegTree(int size = 100000)
    {
        int HOB = highestOneBit(size);
        if (HOB != size)
        {
            MAX_N = HOB << 1;
        }
        else
        {
            MAX_N = HOB;
        }
        dat = new change[MAX_N * 2];
        fill(dat, dat + (MAX_N * 2), *(new change));
    }

    void update(int index, change x)
    {
        for (int i = index + MAX_N; i > 0; i >>= 1)
        {
            //iが対応するインデックス
            if (i >= MAX_N)
            {
                dat[i] = x;
            }
            else
            {
                dat[i].a = dat[i * 2].a * dat[i * 2 + 1].a;
                dat[i].b = dat[i * 2].b * dat[i * 2 + 1].a + dat[i * 2 + 1].b;
            }
        }
    }

    change query(int L, int R)
    {
        L += MAX_N;
        R += MAX_N;
        change c;
        for (; L < R; L >>= 1, R >>= 1)
        {
            if (R & 1)
            {
                --R;
                double a = c.a * dat[R].a;
                double b = c.b * dat[R].a + dat[R].b;
                c.a = a;
                c.b = b;
            } //--Rが対応するインデックス
            if (L & 1)
            {
                double a = dat[L].a * c.a;
                double b = dat[L].b * c.a + c.b;
                c.a = a;
                c.b = b;
                L++;
            } //L++が対応するインデックス
        }
        return c;
    }
    void show()
    {
        for (int i = 0; i < MAX_N * 2; i++)
        {
            cout << dat[i].a << " " << dat[i].b << endl;
        }
    }
};
