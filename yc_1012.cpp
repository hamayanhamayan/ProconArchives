//https://yukicoder.me/problems/no/1012
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
template<class V> struct BIT {
    BIT() {}  // [L, R)
    int NV;vector<V> bit;
    BIT(int n){ init(n); }
    void init(int n) { NV = 1; while (NV < n)NV *= 2; bit.resize(NV); clear(); }
    V operator[](int e) { V s = 0; e++; while (e) s += bit[e - 1], e -= e&-e; return s; }
    void add(int e, V v) { e++; while (e <= NV) bit[e - 1] += v, e += e&-e; }
    int lower_bound(V val) { 
        V tv = 0; int i, ent = 0; for (i = NV - 1; i >= 0; i--)
        if(tv+bit[ent+(1<<i)-1]<=val)tv+=bit[ent+(1<<i)-1],ent += (1 << i);return ent;
    }
    V get(int L, int R) {
        assert(0 <= L); assert(R <= NV); assert(L <= R);
        V res = 0; if(R) res += operator[](R - 1); if (L) res -= operator[](L - 1);return res;
    }
    void clear() { rep(i, 0, NV) bit[i] = 0; }
	void update(int e, V v) { add(e, v - get(e, e + 1)); }
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
BIT<ll> totw(101010), totxw(101010);
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> Q;
    vector<pair<int, int>> xw;
    rep(i, 0, N) {
        int x, w; cin >> x >> w;
        xw.push_back({ x, w });
    }
    sort(all(xw));

    rep(i, 0, N) totw.add(i, xw[i].second);
    rep(i, 0, N) totxw.add(i, 1LL * xw[i].first * xw[i].second);

    rep(_, 0, Q) {
        int X; cin >> X;
        int idx = lower_bound(all(xw), make_pair(X, -1)) - xw.begin();

        ll ans = 0;
        ans += 1LL * X * totw.get(0, idx) - totxw.get(0, idx);
        ans += totxw.get(idx, 101010) - 1LL * X * totw.get(idx, 101010);
        printf("%lld\n", ans);
    }
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
クエリ問題であるが、今回は各クエリを高速に計算していく方針で考える。
O(1)かO(logN)くらいを目指そう。

まず、絶対値を含む問題でよくある方針として、絶対値を外して効率よく計算できないかを考える。
絶対値そのままでは効率よくやれないことが多いので、場合分けをして外していく。
今回で言うと、Xiよりも小さい場所にある荷物と大きい場所にある荷物について分けて計算する。
それぞれについて、コストを計算して、最後に足し合わせれば答えが得られる。
どちらも同じようなアルゴリズムになるので、とりあえず、Xよりも小さい場所にある荷物のコストを
最適に計算する方法を考えよう。

荷物の位置はXよりも小さいので、コストは以下のように書き直すことができる。
(X - x[i]) * w[i]
今回は、x[i]<Xを満たすものについて以上のコストの総和が求まればいい。
例としてi,j,kにおける総和を考えよう。
(X - x[i]) * w[i] + (X - x[j]) * w[j] + (X - x[k]) * w[k]
= X * (w[i] + w[j] + w[k]) - (x[i] * w[i] + x[j] * w[j] + x[k] * w[k])
式変形をするといかにも高速に計算できそうな要素が出てくる。
これを見ると、wの総和とx*wの総和が高速に得られれば計算が可能。

いい感じの小さい課題が出てきた。
x[i]<Xを満たすものについて、wの総和とx*wの総和を高速に求めたい。
今のままだと場所がバラバラなのでやりにくい。
荷物をxの値でソートしておくと、x[i]<Xを満たす荷物はとある区間になる。
区間に対する総和と言えば、累積和やBITである。
自分はBITで実装した。
BITにxでソートした、wの総和とx*wの総和を入れておく。

x[i]<Xを満たす区間の場所についてはlower_boundで取得すればいい。
Xよりも大きい場所について同様の計算を行って和をとれば答え。
///////////////////////// writeup2 end */
