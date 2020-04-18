//https://yukicoder.me/problems/no/1031
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
#ifdef _MSC_VER
inline unsigned int __builtin_clz(unsigned int x){unsigned long r;_BitScanReverse(&r,x);return 31-r;}
#endif // _MSC_VER
template<class V> struct SparseTable { // [L,R)
    const V def = make_pair(-1,-1);
    inline V comp(V a, V b) { return max(a,b); }

    int n; vector<V> a, b[22]; inline int __lg(int x) { return 32 - 1 - __builtin_clz(x); }
    void init(vector<V> v) {
        int nn = v.size(); n = 1; while (n < nn) n *= 2; a.resize(n);
        rep(i, 0, 22) b[i].resize(n); rep(i, 0, nn) a[i] = v[i];

        int d = 1 << __lg(n - 1), e = d << 1;
        for (int h = 0, f; (f = 1 << h) <= d; ++h) {
            for (int i = f, r = f << 1; i < e; i += r) {
                b[h][i - 1] = a[i - 1];
                for (int j = i - 2; j >= i - f; --j) b[h][j] = comp(b[h][j + 1], a[j]);
                b[h][i] = a[i];
                for (int j = i + 1; j < i + f; ++j) b[h][j] = comp(b[h][j - 1], a[j]);
            }
        }
    }

    V get(int L,int R){assert(0<=L&&L<=R);if(L==R)return def;R--;if(L==R)return a[L];int h=__lg(L^R);
        return comp(b[h][L],b[h][R]);}};
int defmin = inf;
template<class V, int NV> struct SegTreeMin { //[l,r)
    V comp(V& l, V& r) { return min(l, r); };

    vector<V> val; SegTreeMin() { val = vector<V>(NV * 2, defmin); }
    V get(int x, int y, int l = 0, int r = NV, int k = 1) {
        if (r <= x || y <= l)return defmin; if (x <= l && r <= y)return val[k];
        auto a = get(x, y, l, (l + r) / 2, k * 2); 
        auto b = get(x, y, (l + r) / 2, r, k * 2 + 1);
        return comp(a, b);
    }
    void update(int i, V v) {
        i += NV; val[i] = v;
        while (i>1) i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]);
    }
    void add(int i, V v) { update(i, val[i + NV] + v); }
    V operator[](int x) { return get(x, x + 1); }
};
#define def 0
template<class V, int NV> struct SegTreeMax { //[l,r)
    V comp(V& l, V& r) { return max(l, r); };

    vector<V> val; SegTreeMax() { val = vector<V>(NV * 2, def); }
    V get(int x, int y, int l = 0, int r = NV, int k = 1) {
        if (r <= x || y <= l)return def; if (x <= l && r <= y)return val[k];
        auto a = get(x, y, l, (l + r) / 2, k * 2);
        auto b = get(x, y, (l + r) / 2, r, k * 2 + 1);
        return comp(a, b);
    }
    void update(int i, V v) {
        i += NV; val[i] = v;
        while (i > 1) i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]);
    }
    void add(int i, V v) { update(i, val[i + NV] + v); }
    V operator[](int x) { return get(x, x + 1); }
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














int N, A[101010];
SparseTable<pair<int, int>> st;
//---------------------------------------------------------------------------------------------------
int pre[20][101010];
int post[20][101010];
SegTreeMin<int, 1 << 17> stmin;
SegTreeMax<int, 1 << 17> stmax;
void init() {
    rep(p, 0, 20) rep(idx, 0, 101010) pre[p][idx] = 0;
    rep(i, 0, N) {
        pre[0][i + 1] = stmax.get(0, A[i]);
        stmax.update(A[i], i + 1);
    }
    rep(p, 1, 20) rep(idx, 0, N + 1) pre[p][idx] = pre[p - 1][pre[p - 1][idx]];

    defmin = N + 1;
    rep(p, 0, 20) rep(idx, 0, 101010) post[p][idx] = N + 1;
    rrep(i, N - 1, 0) {
        post[0][i + 1] = stmin.get(0, A[i]);
        stmin.update(A[i], i + 1);
    }
    rep(p, 1, 20) rep(idx, 0, N + 1) post[p][idx] = post[p - 1][post[p - 1][idx]];
}
int getpre(int idx, int cnt) {
    int res = idx;
    rep(p, 0, 20) if (cnt & (1 << p)) res = pre[p][res];
    return res;
}
int getpost(int idx, int cnt) {
    int res = idx;
    rep(p, 0, 20) if (cnt & (1 << p)) res = post[p][res];
    return res;
}
//---------------------------------------------------------------------------------------------------
ll ans = 0;
void f(int L, int R) {
    if (L == R) return;
    if (L + 1 == R) return;
    auto ma = st.get(L, R);

    int C = ma.second;

    {
        int ok = 0, ng = N + 1;
        while (ok + 1 != ng) {
            int md = (ok + ng) / 2;
            if (L <= getpre(C, md)) ok = md;
            else ng = md;
        }
        ans += ok;
    }

    {
        int ok = 0, ng = N + 1;
        while (ok + 1 != ng) {
            int md = (ok + ng) / 2;
            if (getpost(C, md) < R) ok = md;
            else ng = md;
        }
        ans += ok;
    }

    f(L, C);
    f(C + 1, R);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

    init();

    vector<pair<int, int>> dic;
    dic.push_back({ -1, -1 });
    rep(i, 0, N) dic.push_back({ A[i], i + 1 });
    st.init(dic);

	f(1, N + 1);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [列の分割統治](https://www.hamayanhamayan.com/entry/2017/05/21/234616)
///////////////////////// writeup2 start
自分の解法はちょっとやりすぎかもしれない。

この問題を解くときに厄介なのは、異なる操作であっても同じ結果になることがあり、
その同じ結果がダブって計算しては行けないということである。
これを解決するために以下のように問題を読み替えて考えよう。
ある区間を選んだ時の(最大の要素,最小の要素)の組み合わせは？
このように言い換えると若干数えやすくなる。

解法の方針であるが、最大の要素を固定する。
そこから、ありえる最小の要素を数え上げることで問題を解く。
例えば`1 7 3 2 5 8 6 4`というサンプル3で考えてみる。
最大の要素を5の場合を考えたいとき、5を含むような区間で、かつ5より大きい部分は含んではいけないので、
`3 2 5`
この区間に対して、操作区間を考えることになる。
5は必ず含むべきなので、区間を5から伸ばしていくように考えていく。
すると、`3 2 5`, `2 5`の2パターンしかないが、どちらも最小値が2なので、(5, 2)しか答えがない。
もう少し一般化して説明すると、ある最大値から区間を伸ばしていき、最小値が更新される回数が答えになる。

これはgetpre(idx, cnt)に任せよう。
A[idx]から最小値が更新されるようにcnt回移動したときの最終的な場所を求める。
この関数の内部ではダブリングを使っている。

この関数が用意できれば、二分探索によって、最小値が何回更新されるかが分かる。
移動後に区間内に入っているような最大回数を求めれば、何回更新されるかを導ける。

最後に、最大値を固定したときに、どこまでの区間で考えることができるかというのをどうやって扱うかであるが、
列の分割統治を利用する。
二分探索で範囲を特定する方が簡単かもしれない。
列の分割統治では、列の最大値をとってきて、それに対して操作を行い、
操作を行った後に、その最大値で列を分割して、再帰によって処理を行う。
///////////////////////// writeup2 end */
