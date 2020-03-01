//https://www.hackerrank.com/contests/yfkpo3-1/challenges/banana-game
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/











//---------------------------------------------------------------------------------------------------
int g[10][10];
void labo() {
    rep(h, 0, 10) rep(b, 0, 10) {
        set<int> se;
        rep(dh, 0, 2) if (0 <= h - dh) {
            rep(db, 0, b + 1) if (0 < dh + db) se.insert(g[h - dh][b - db]);
        }
        while (se.count(g[h][b])) g[h][b]++;
    }

    rep(h, 0, 10) {
        rep(b, 0, 10) printf("%d\t", g[h][b]);
        printf("\n");
    }
}
//---------------------------------------------------------------------------------------------------
int f(int h, int b) {
    int st = b;
    int gr = b * 2 + 1;

    int n = gr - st + 1;
    int gg = 0;
    h++;
    if (h <= n) gg = b + h - 1;
    else {
        gg = gr;
        h -= n;
        if (h % 2 == 1) gg--;
    }
    return gg;
}
//---------------------------------------------------------------------------------------------------
int N;
void _main() {
    //labo();
    //rep(h, 0, 10) rep(b, 0, 10) if (g[h][b] != f(h, b)) printf("NG %d %d\n", h, b);

    cin >> N;
    int tot = 0;
    rep(i, 0, N) {
        int H, B; cin >> H >> B;
        tot ^= f(H, B);
    }

    if (tot == 0) cout << "prd" << endl;
    else cout << "matsu" << endl;
}





/* ///////////////////////// writeup1 start
# Om
- [Grundy](https://www.hamayanhamayan.com/entry/2017/02/27/025050)
///////////////////////// writeup2 start
Grundyです

```
0	1	2	3	4	5	6	7	8	9
1	2	3	4	5	6	7	8	9	10
0	3	4	5	6	7	8	9	10	11
1	2	5	6	7	8	9	10	11	12
0	3	4	7	8	9	10	11	12	13
1	2	5	6	9	10	11	12	13	14
0	3	4	7	8	11	12	13	14	15
1	2	5	6	9	10	13	14	15	16
0	3	4	7	8	11	12	15	16	17
1	2	5	6	9	10	13	14	17	18
```

BŏcHłBۂKB
cɌƁAK킩B
1ĂAn_ŐĂ͐UĂB
̐n_́A0 -> 1, 1 -> 3, 2 -> 5, 3 -> 7Ȃ̂ŁAB*2+1łB
ȍ~́AB*2, B*2+1, B*2, B*2+1, ...ƐUB
悤B

ŊeQ[ɂGrundyvZł̂xoraƂāA0ȂҏB
łȂȂA菟B
///////////////////////// writeup2 end */
