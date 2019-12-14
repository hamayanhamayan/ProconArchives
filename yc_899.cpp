//https://yukicoder.me/problems/no/899
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
template<class V, int NV> struct LazySegTree { // [L,R)
    vector<V> dat, lazy; LazySegTree() { dat.resize(NV * 2, def); lazy.resize(NV * 2, ldef); }
    void update(int a, int b, V v, int k, int l, int r) { push(k, l, r); if (r <= a || b <= l) return;
        if (a <= l && r <= b) { setLazy(k, v); push(k, l, r); } else {
        update(a, b, v, k * 2 + 1, l, (l + r) / 2); update(a, b, v, k * 2 + 2, (l + r) / 2, r);
        dat[k] = comp(dat[k * 2 + 1], dat[k * 2 + 2]);}}
    V get(int a, int b, int k, int l, int r) { push(k, l, r); if (r <= a || b <= l) return def;
        if (a <= l && r <= b) return dat[k]; auto x = get(a, b, k * 2 + 1, l, (l + r) / 2);
        auto y = get(a, b, k * 2 + 2, (l + r) / 2, r); return comp(x, y);}
    void update(int a, int b, V v) { update(a, b, v, 0, 0, NV); }
    V get(int a, int b) { return get(a, b, 0, 0, NV); }
    // ---- Template ---------------------------------------------------------------------------------
    
    // 区間代入,区間和
    const V def = 0, ldef = -1;
    V comp(V l, V r) { return l + r; }
    void setLazy(int i, V v) { lazy[i] = v; }
    void push(int k, int l, int r) {
        if (lazy[k] != ldef) {
            // modify------------------------------
            dat[k] = lazy[k] * (r - l);
            // ------------------------------------
            if (r - l > 1) { setLazy(k * 2 + 1, lazy[k]); setLazy(k * 2 + 2, lazy[k]); }
            lazy[k] = ldef;
        }
    }
};
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N;
vector<int> E[101010];
LazySegTree<ll, 1 << 17> st;
//---------------------------------------------------------------------------------------------------
int P[101010];
int L1[101010], R1[101010], L2[101010], R2[101010];
int toVID[101010];
void bfs_eulertour()
{
    rep(i, 0, N) {
        P[i] = -1;
        L1[i] = L2[i] = inf;
        R1[i] = R2[i] = -1;
    }

    queue<int> que;
    que.push(0);
    toVID[0] = 0;
    int vid = 1;

    while(!que.empty()) {
        int cu = que.front();
        que.pop();

        fore(to, E[cu]) if(P[cu] != to) {
            que.push(to);
            P[to] = cu;
            toVID[to] = vid;
            vid++;

            int vcu = toVID[cu];

            chmin(L1[vcu], toVID[to]);
            chmax(R1[vcu], toVID[to]);

            if (0 <= P[cu]) {
                int vp = toVID[P[cu]];
                chmin(L2[vp], toVID[to]);
                chmax(R2[vp], toVID[to]);
            }
        }
    }
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N - 1) {
        int a, b; cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    bfs_eulertour();

    rep(i, 0, N) {
        int a;
        cin >> a;
        st.update(toVID[i], toVID[i] + 1, a);
    }

    int Q; cin >> Q;
    rep(q, 0, Q) {
        int x;
        cin >> x;

        int vx = toVID[x];

        ll sm = 0;

        // 自分の1つ下の子供
        if (0 <= L1[vx]) {
            sm += st.get(L1[vx], R1[vx] + 1);
            st.update(L1[vx], R1[vx] + 1, 0);
        }
        // 自分の2つ下の子供
        if (0 <= L2[vx]) {
            sm += st.get(L2[vx], R2[vx] + 1);
            st.update(L2[vx], R2[vx] + 1, 0);
        }
        // 自分
        sm += st.get(vx, vx + 1);
        st.update(vx, vx + 1, 0);
        
        if (0 <= P[x]) {
            int p = P[x];
            int vp = toVID[p];

            // 親
            sm += st.get(vp, vp + 1);
            st.update(vp, vp + 1, 0);

            // 親の1つ下の子
            if (0 <= L1[vp]) {
                sm += st.get(L1[vp], R1[vp] + 1);
                st.update(L1[vp], R1[vp] + 1, 0);
            }

            if (0 <= P[p]) {
                int pp = P[p];
                int vpp = toVID[pp];
                
                // 親の親
                sm += st.get(vpp, vpp + 1);
                st.update(vpp, vpp + 1, 0);
            }
        }

        printf("%lld\n", sm);
        st.update(vx, vx + 1, sm);
    }
}



/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
操作を見ると、妖精がいる頂点数がどんどん減っている。
頂点を削減しながら、順番に見ていく的なことをしていくのかな…
わからんとなったが…

[BFS Euler Tour](https://niuez.hatenablog.com/entry/2019/10/05/002503)

これは初めて見た。なるほど。
Euler Tourでは通常DFSでやる。
が、BFSでやることである深さについての頂点群が区間に収まる。

区間に帰着させることができたら、あとは区間について総和取得と代入操作ができればいい。
これは遅延評価セグメントツリーにて解決できる。

各クエリについて、以下の要素の総和を取ってくる。

- 自分
- 自分の1つ下の子供
- 自分の2つ下の子供
- 親
- 親の1つ下の子
- 親の親

要素がかぶる場合があるので、消しながら取ってこよう。
///////////////////////// writeup2 end */
