//https://atcoder.jp/contests/ttpc2019/tasks/ttpc2019_h
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
struct DynamicSegTree {
    // ----------------------- modidy!! -------------------------------
    using T = pair<ll,ll>;
    inline T comp(T a, T b) {
        return {a.first + b.first, a.second + b.second};
    }
    // ----------------------------------------------------------------

    struct Node { int lft, rht; T val; Node(int _lft, int _rht, T _val) : lft(_lft), rht(_rht), val(_val) {} };
    deque<Node> deq;
    int root, width, sz;

    DynamicSegTree() {
        deq.push_back(Node(-1,-1,make_pair(0LL, 0LL)));
        root = 0;
        width = 1;
        sz = 1;
    }

    int create(int parent, bool is_right) {
        int i = deq.size();
        deq.push_back(Node(-1,-1,make_pair(0LL, 0LL)));
        if (is_right) deq[parent].rht = i;
        else deq[parent].lft = i;
        return i;
    }
    void update(int i, T v) {
        assert(0 <= i);
        while (width <= i) {
            Node node(root, -1, deq[root].val);
            root = deq.size();
            deq.push_back(node);
            width *= 2;
        }
        update(root, -1, false, 0, width, i, v);
    }
    void update(int i, int parent, bool is_right, int il, int ir, int j, T v) {
        if (il == j and ir == j + 1) {
            if (i == -1) { i = create(parent, is_right); sz += 1; }
            deq[i].val = v;
        } else if (ir <= j or j + 1 <= il) {
        } else {
            if (i == -1) i = create(parent, is_right);
            update(deq[i].lft, i, false, il, (il + ir) / 2, j, v);
            update(deq[i].rht, i, true, (il + ir) / 2, ir, j, v);

            T lft = make_pair(0LL, 0LL);
            if (0 <= deq[i].lft) lft = deq[deq[i].lft].val;
            T rht = make_pair(0LL, 0LL);
            if (0 <= deq[i].rht) rht = deq[deq[i].rht].val;

            deq[i].val = comp(lft, rht);
        }
    }
    T get(int l, int r) {
        assert(0 <= l and l <= r);
        if (width <= l) return make_pair(0LL, 0LL);
        return get(root, 0, width, l, min(width, r));
    }
    T get(int i, int il, int ir, int l, int r) {
        if (i == -1) return make_pair(0LL, 0LL);
        if (l <= il and ir <= r) {
            return deq[i].val;
        } else if (ir <= l or r <= il) {
            return make_pair(0LL, 0LL);
        } else {
            return comp(get(deq[i].lft, il, (il + ir) / 2, l, r),get(deq[i].rht, (il + ir) / 2, ir, l, r));
        }
    }
    T get(int i) { return get(i, i + 1); }

    void add(int i, T v) { update(i, comp(get(i), v)); }
};
struct UnionFind {
    vector<int> par; // uf(x,y)->y
    UnionFind() {}
    UnionFind(int NV) { init(NV); }
    void init(int NV) { par.clear(); rep(i, 0, NV) par.push_back(i); }
    void reset() { rep(i, 0, par.size()) par[i] = i; }
    int operator[](int x) { return par[x] == x ? x : par[x] = operator[](par[x]); }
    void operator()(int x, int y) { x = operator[](x); y = operator[](y); if (x != y) par[x] = y; }
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
int X[101010], P[101010];
DynamicSegTree st[101010];
ll memo[101010];
vector<pair<ll, ll>> buf[101010];
ll tot[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> X[i] >> P[i];

    rep(i, 0, N) {
        if(0 <= X[i])
            tot[i] = X[i];
        else {
            buf[i].push_back({-X[i], P[i]});
            st[i].add(P[i], {-X[i], -1LL * X[i] * P[i]});
        }
    }

    ll ans = 0;
    int Q;
    cin >> Q;
    UnionFind uf(N);
    rep(q, 0, Q)
    {
        int a, b; cin >> a >> b;
        a--;
        b--;

        int aa = uf[a];
        int bb = uf[b];

        if(aa != bb) {
            ans -= memo[aa];
            ans -= memo[bb];

            if(buf[aa].size() > buf[bb].size())
                swap(aa, bb);

            // aaをbbにくっつける
            tot[bb] += tot[aa];
            fore(p, buf[aa]) {
                buf[bb].push_back(p);
                st[bb].add(p.second, {p.first, p.first * p.second});
            }

            uf(aa, bb);

            int ng = 0, ok = inf;
            while(ng + 1 != ok) {
                int md = (ng + ok) / 2;
                auto p = st[bb].get(md, inf);
                if(p.first < tot[bb])
                    ok = md;
                else
                    ng = md;
            }

            auto p = st[bb].get(ok, inf);
            memo[bb] = p.second;

            ll rest = tot[bb] - p.first;
            auto pp = st[bb].get(ng, ok);
            memo[bb] += min(rest, pp.first) * ng;
            ans += memo[bb];
        }

        printf("%lld\n", ans);
    }
}

/* ///////////////////////// writeup1 start
# 前提知識
- [動的構築セグメントツリー](https://www.hamayanhamayan.com/entry/2017/07/08/173120)
- [マージテク](https://www.hamayanhamayan.com/entry/2017/02/10/132728)
///////////////////////// writeup2 start
まずは簡単なことから考えていく。
条件を見ると支援関係は連結成分ごとに考えられていく。
ある連結成分で支援を行える額は総和をとっても問題ない。
支援を受ける額は、Pが大きい順に貪欲に割り当てれば最適っぽい。
クエリを見ていくと、全体の支援で救える人数の最大値は2つの連結成分を連結させる時に、
両方の連結成分での救える人数の最大値を引いて、新しくできた連結成分での救える人数の最大値を足せば、
インクリメンタルに答えを構築できる。
ここまではよくある方針。

両方の連結成分の最大値を引くのもメモっておけばいいいし、連結についてはUnionfindでいい。
問題が、新しく連結成分を作ったときの最適解をいかに求めるかという部分である。
何が簡単に求めるかという観点で探してみると、支援額の総額は簡単に求められる。
ここからがブレイクスルー。
支援を受ける国のPをindexとしたセグメントツリーを考える。
Pをindexとして、頂点には(Xの合計, X*Pの合計)を乗せる。
このセグメントツリーでXの合計＜支援額の総和をとなるPを二分探索で求める。
これでPを大きい淳に貪欲に割り当てるときの支援される上限まで支援されるPが特定できる。
あとは、境界になっている部分で残りの割り当てを行えばいい。

最後に連結成分ごとにセグメントツリーを管理する必要があり、連結させるときにマージする必要がある。
これは、マージテクを使おう。
マージテクを使えば、ならしで全体O(logN)が達成できる。
///////////////////////// writeup2 end */
