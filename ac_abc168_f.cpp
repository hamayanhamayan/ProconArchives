//https://atcoder.jp/contests/abc168/tasks/abc168_f
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
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M;
int A[1010], B[1010], C[1010];
int D[1010], E[1010], F[1010];
//---------------------------------------------------------------------------------------------------
vector<int> xdic, ydic;
int W, H;
int tate[5010][5010];
int yoko[5010][5010];
void pre() {
    xdic.push_back(-inf);
    xdic.push_back(inf);
    xdic.push_back(0);
    ydic.push_back(-inf);
    ydic.push_back(inf);
    ydic.push_back(0);
    rep(i, 0, N) {
        xdic.push_back(A[i]);
        xdic.push_back(B[i]);
        ydic.push_back(C[i]);
    }
    rep(i, 0, M) {
        xdic.push_back(D[i]);
        ydic.push_back(E[i]);
        ydic.push_back(F[i]);
    }

    sort(all(xdic));
    xdic.erase(unique(all(xdic)), xdic.end());
    sort(all(ydic));
    ydic.erase(unique(all(ydic)), ydic.end());

    W = xdic.size();
    H = ydic.size();

    rep(i, 0, N) {
        int a = lower_bound(all(xdic), A[i]) - xdic.begin();
        int b = lower_bound(all(xdic), B[i]) - xdic.begin();
        int c = lower_bound(all(ydic), C[i]) - ydic.begin();
        tate[c][a]++;
        tate[c][b]--;
    }
    rep(y, 0, H) rep(x, 1, W) tate[y][x] += tate[y][x - 1];

    rep(i, 0, M) {
        int d = lower_bound(all(xdic), D[i]) - xdic.begin();
        int e = lower_bound(all(ydic), E[i]) - ydic.begin();
        int f = lower_bound(all(ydic), F[i]) - ydic.begin();
        yoko[e][d]++;
        yoko[f][d]--;
    }
    rep(x, 0, W) rep(y, 1, H) yoko[y][x] += yoko[y - 1][x];
}
//---------------------------------------------------------------------------------------------------
bool vis[5010][5010];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
ll calc() {
    ll res = 0;
    queue<pair<int, int>> que;
    int stx = lower_bound(all(xdic), 0) - xdic.begin();
    int sty = lower_bound(all(ydic), 0) - ydic.begin();

    vis[sty][stx] = true;
    que.push({ stx, sty });

    while (!que.empty()) {
        int ix, iy;
        tie(ix, iy) = que.front(); que.pop();

        if (ix == 0 || ix == W - 1) return infl;
        if (iy == 0 || iy == H - 1) return infl;

        res += 1LL * (xdic[ix + 1] - xdic[ix]) * (ydic[iy + 1] - ydic[iy]);

        rep(d, 0, 4) {
            int ix2 = ix + dx[d];
            int iy2 = iy + dy[d];
            if (0 <= ix2 && ix2 < W && 0 <= iy2 && iy2 < H && !vis[iy2][ix2]) {
                if (ix == ix2) {
                    // yoko
                    if (tate[max(iy,iy2)][ix2]) continue;
                }
                else {
                    // tate
                    if (yoko[iy][max(ix, ix2)]) continue;
                }

                vis[iy2][ix2] = true;
                que.push({ ix2, iy2 });
            }
        }
    }

    return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    rep(i, 0, N) cin >> A[i] >> B[i] >> C[i];
    rep(i, 0, M) cin >> D[i] >> E[i] >> F[i];

    pre();

    ll ans = calc();
    if (ans == infl) cout << "INF" << endl;
    else cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- 座標圧縮
- [imos法](https://www.hamayanhamayan.com/entry/2017/07/04/020117)
- [BFS](https://www.hamayanhamayan.com/entry/2018/06/16/093035)
///////////////////////// writeup2 start
面積が多角形になる場合がある。
抜本的なアルゴリズム改善ができるような雰囲気を感じない。
なので、全探索の高速化の方針で考えてみる。

全部の盤面をシミュレーションすると2*10^9×2*10^9のサイズが必要なので、これは無理。
無理なのだが、特徴となる点はそれほど多くない。
なので、座標圧縮テクを使って、特徴となる点だけを考えるように変換しよう。

座標圧縮すると盤面が2*1000×2*1000のサイズに圧縮される。
これはメモリに載るサイズである。
なので、この圧縮された状態で解法を考えていく。

基本的には(0,0)からBFSをして到達可能な所の面積を特定していけばいいのだが、色々注意点がある。
BFSする頂点はマスの交点になってしまっているので、少し移動させて、マス自体のBFSにする必要がある。

BFSで移動できるかどうかは、壁があるかどうかの判定になる。
これにはimos法を使って、壁があるなら1以上、ないなら0で判定すればいい。

マスの面積は、(i,j)であれば（iとi+1のx座標の差）×（jとj+1のy座標の差）で計算できる。
これらを足し合わせれば答え。
番兵として、xy座標に-inf,infを入れておけば、座圧後に端に到達すれば面積は∞になる。
///////////////////////// writeup2 end */
