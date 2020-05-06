//https://atcoder.jp/contests/past202004-open/tasks/past202004_n
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
// StaticHealthy2DSegtree
#define def 0
using V = ll;
V comp(V& l, V& r) { return l + r; };
struct SegTree { //[l,r)
    int NV;
    vector<V> val;
    void init(int n) {
        NV = 1;
        while (NV < n) NV *= 2;
        val = vector<V>(NV * 2, def);
    }
    V get(int x, int y, int l, int r, int k) {
        if (r <= x || y <= l) return def; if (x <= l&&r <= y)return val[k];
        auto a = get(x, y, l, (l + r) / 2, k * 2); auto b = get(x, y, (l + r) / 2, r, k * 2 + 1); return comp(a, b);
    }
    V get(int x, int y) { return get(x, y, 0, NV, 1); }
    void update(int i, V v) { i += NV; val[i] = v; while (i>1)i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]); }
    void compupdate(int i, V v) { update(i, comp(v, val[i + NV])); }
    void add(int i, V v) { update(i, val[i + NV] + v); }
    V operator[](int x) { return get(x, x + 1); }
};

struct StaticHealthy2DSegTree {
    int NV;
    vector<SegTree> st;
    vector<vector<int>> index;
    
    void init(vector<vector<pair<int,V>>> &v) {
        int n = v.size();
        NV = 1; while (NV < n) NV *= 2;
        index.resize(2 * NV);
        rep(i, 0, n) fore(p, v[i]) index[i + NV].push_back(p.first);
        rrep(i, NV * 2 - 1, 1) {
            sort(index[i].begin(), index[i].end());
            index[i].erase(unique(index[i].begin(), index[i].end()), index[i].end());
            fore(j, index[i]) index[i / 2].push_back(j);
        }
        st.resize(2 * NV);
        rep(i, 1, NV * 2) st[i].init(index[i].size());
        
        rep(i, 0, n) fore(p, v[i]) {
            int j = lower_bound(index[i + NV].begin(), index[i + NV].end(), p.first) - index[i + NV].begin();
            st[i + NV].update(j, p.second);
        }

        rrep(i, NV * 2 - 1, 2) {
            rep(j, 0, index[i].size()) {
                V v = st[i][j];
                
                int k = lower_bound(index[i / 2].begin(), index[i / 2].end(), index[i][j]) - index[i / 2].begin();
                st[i / 2].compupdate(k, v);
            }
        }
    }
    V get(int sx, int tx, int sy, int ty, int k, int l, int r) {
        assert(k < NV * 2);
        assert(l < r);
        if (r <= sx or tx <= l) return def;
        if (sx <= l and r <= tx) {
            int syy = lower_bound(index[k].begin(), index[k].end(), sy) - index[k].begin();
            int tyy = lower_bound(index[k].begin(), index[k].end(), ty) - index[k].begin();
            return st[k].get(syy, tyy);
        }
        int md = (l + r) / 2;
        V le = get(sx, tx, sy, ty, k * 2, l, md);
        V ri = get(sx, tx, sy, ty, k * 2 + 1, md, r);
        return comp(le, ri);
    }
    V get(int sx, int tx, int sy, int ty) {
        return get(sx, tx, sy, ty, 1, 0, NV);
    }
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, Q;
int xmin[50101], ymin[50101], D[50101], C[50101];
int A[101010], B[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> Q;
    rep(i, 0, N) cin >> xmin[i] >> ymin[i] >> D[i] >> C[i];
    rep(i, 0, Q) cin >> A[i] >> B[i];

    vector<int> xs, ys;
    rep(i, 0, N) {
        xs.push_back(xmin[i]);
        xs.push_back(xmin[i] + D[i] + 1);
        ys.push_back(ymin[i]);
        ys.push_back(ymin[i] + D[i] + 1);
    }
    rep(i, 0, Q) {
        xs.push_back(A[i]);
        ys.push_back(B[i]);
    }

    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    sort(all(ys));
    ys.erase(unique(all(ys)), ys.end());

    int NY = ys.size();
    vector<vector<pair<int, ll>>> v(NY);
    vector<map<int, ll>> v2(NY);
    rep(i, 0, N) {
        int xm = lower_bound(all(xs), xmin[i]) - xs.begin();
        int xmd = lower_bound(all(xs), xmin[i] + D[i] + 1) - xs.begin();
        int ym = lower_bound(all(ys), ymin[i]) - ys.begin();
        int ymd = lower_bound(all(ys), ymin[i] + D[i] + 1) - ys.begin();

        v2[ym][xm] += C[i];
        v2[ymd][xm] -= C[i];
        v2[ym][xmd] -= C[i];
        v2[ymd][xmd] += C[i];
    }
    rep(y, 0, NY) fore(p, v2[y]) v[y].push_back(p);

    StaticHealthy2DSegTree st;
    st.init(v);

    rep(i, 0, Q) {
        int x = lower_bound(all(xs), A[i]) - xs.begin();
        int y = lower_bound(all(ys), B[i]) - ys.begin();

        ll ans = st.get(0, y + 1, 0, x + 1);
        printf("%lld\n", ans);
        
    }
}





/* ///////////////////////// writeup1 start
# 前提知識
- [二次元imos](https://www.hamayanhamayan.com/entry/2017/07/04/020117)
- 座標圧縮
- [2Dセグメントツリー](https://www.hamayanhamayan.com/entry/2017/07/08/173120)か平面走査
///////////////////////// writeup2 start
二次元imosを拡張させて解く。
二次元imosが分からない場合はそちらを先に勉強した方が、こちらに取り組みやすいだろう。
さて、二次元imos的には、各領域に対して、
(xmin, ymin) +C
(xmin+D+1, ymin) -C
(xmin, ymin+D+1) -C
(xmin+D+1, ymin+D+1) +C
として、縦に累積和、横に累積和をしたときの(A[j],B[j])がそのまま答えになる。
だが、横と縦に累積和は盤面が大きすぎてできないので、何とかする必要がある。
二次元imosを行うと、すべてのマスについてコストが分かるが、今回はそこまでは必要ない。
指定したマスについてコストが分かればいい。
この時、指定したマス(A[j],B[j])のコストは、
二次元imosの前処理をした状態で(0,0)と(A[j],B[j])を対角点とする長方形に含まれる
コストの総和と等しくなる。
なので、二次元に対する矩形和が取れれば今回の問題は解けることになる。

ここから解法が2択あって、「2Dセグメントツリー」か「平面走査」のどちらかである。
まず、どちらであっても使用する座標をすべて洗い出して座標圧縮しておこう。

平面走査は割と古典的（なイメージ）だが強力である。
BITを持って、y座標を小さい方を順番に見ていって、縦の累積和をやりながら、
実際に求めるときは横の累積和の代わりにBITを使うことで、(0,0)からの矩形和を求めるという戦略。

2Dセグメントツリーを仮に持っていれば、今回要求されている操作と行える操作が等しいので、分かりやすい。
計算量がやや心配だが、ちょっとだけ実行時間制限も大きいので、使ってもいいよというメッセージだろう。
///////////////////////// writeup2 end */
