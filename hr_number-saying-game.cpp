//https://www.hackerrank.com/contests/wasedajitsugyo-scienceclub-festival-contest2019/challenges/number-saying-game
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
//        Welcome to My Coding Space! @hamayanhamayan
//---------------------------------------------------------------------------------------------------

int N, M;
//---------------------------------------------------------------------------------------------------
int grundy[1010101];
void labo() {
    grundy[N - 1] = 0;
    rrep(cu, N - 2, 0) {
        set<int> se;
        rep(d, 1, M + 1) {
            int to = cu + d;
            if (to <= N - 1) se.insert(grundy[to]);
        }
        while(0 < se.count(grundy[cu])) grundy[cu]++;
    }

    rep(i, 0, N) printf("g[%d] = %d\n", i, grundy[i]);
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;

    //labo(); return;

    if ((N - 1) % (M + 1) == 0) cout << "egg" << endl;
    else cout << "yopipa" << endl;
}

/* ///////////////////////// writeup1 start
# 前提知識
- [Grundy数](https://www.hamayanhamayan.com/entry/2017/02/27/025050)
///////////////////////// writeup2 start
Nim派生問題感がある。
だが、Nimと違うのが最後の数を言ったほうが負けという所。
といっても、Grundy数は使えそうなので、使ってみる。
grundy[cu] := 自然数がcuまで言われているときのgrundy数
N-1で回ってくるとNとしか言えないので、grundy[N-1]=0
あとは、これ基準で作っていく。
問題となるのが、配列の区間の中で最小で区間に含まれない数を高速に取ってくる方法である。
しかし、データ構造を使おうにも制約が結構厳しい。
実験したら、規則性見えるアレか？

```
N=25, M=5
g[0] = 0
g[1] = 5
g[2] = 4
g[3] = 3
g[4] = 2
g[5] = 1
g[6] = 0
g[7] = 5
g[8] = 4
g[9] = 3
g[10] = 2
g[11] = 1
g[12] = 0
g[13] = 5
g[14] = 4
g[15] = 3
g[16] = 2
g[17] = 1
g[18] = 0
g[19] = 5
g[20] = 4
g[21] = 3
g[22] = 2
g[23] = 1
g[24] = 0
```

これは明らかですねぇ…

```
N=14, M=3
g[0] = 1
g[1] = 0
g[2] = 3
g[3] = 2
g[4] = 1
g[5] = 0
g[6] = 3
g[7] = 2
g[8] = 1
g[9] = 0
g[10] = 3
g[11] = 2
g[12] = 1
g[13] = 0
```

g[0]=0となるには、1+周期×？=Nになってればいい。
周期はM+1なので、1+(M+1)×？=Nになってる必要あり。
(M+1)×？=N-1なので、N-1がM+1で割り切れるときに0になる。
N-1がM+1で割り切れるなら先手の負け（egg勝ち）、そうでないなら後手が負け（yopipa勝ち）。
確かにMで割った余りに切りそえていく、まねっこ方針を使えば必勝できそうか。
///////////////////////// writeup2 end */
