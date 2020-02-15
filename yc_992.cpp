//https://yukicoder.me/problems/no/992
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
template<int MOD> struct ModInt {
    static const int Mod = MOD; unsigned x; ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt& operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt& operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt& operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt& operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u);
    }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ostream& operator<<(ostream& st, const ModInt<MOD> a) { st << a.get(); return st; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r;
}
typedef ModInt<1000000007> mint;
vector<int> compress1(int* v, int n) {
    vector<int> dic;
    rep(i, 0, n) dic.push_back(v[i]);
    sort(all(dic));
    dic.erase(unique(all(dic)), dic.end());
    rep(i, 0, n) v[i] = lower_bound(all(dic), v[i]) - dic.begin();
    return dic;
}
#define def make_pair(0,mint(1))
using V = pair<int, mint>;
template<int NV> struct SegTree { //[l,r)
    V comp(V& l, V& r) { 
        if (l.first == 0) return r;
        if (r.first == 0) return l;
        if (l.first < r.first) return r;
        else if (l.first > r.first) return l;
        return make_pair(l.first, l.second + r.second);
    };

    vector<V> val; SegTree() { val = vector<V>(NV * 2, def); }
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














int N, A[201010];
SegTree<1 << 18> st;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    compress1(A, N);

    rep(i, 0, N) {
        auto p = st.get(0, A[i]);
        p.first++;

        auto cu = st[A[i]];
        st.update(A[i], st.comp(cu, p));
    }
    cout << st.get(0, N).second << endl;

}





/* ///////////////////////// writeup1 start
# 前提知識
- 座標圧縮
- [LIS](https://www.hamayanhamayan.com/?page=1493538812)
- [セグメントツリー](https://www.hamayanhamayan.com/entry/2017/07/08/173120)
///////////////////////// writeup2 start
Aに負の数が入っているのは、ちょっと面倒な気がする。
かつ、配列Aは実際の値は特に重要ではなく、数の大小だけが問題なので、座標圧縮して、[0,N)におさめておこう。

LISの解法の、セグメントツリー解法をベースに考えていこう。
先頭から順番に数を見ていきながら、セグメントツリーを更新していく。
具体的には、以下のようにセグメントツリーを作成する。
`i番目の要素は、今まで見てきた要素の最後がi=A[j]であるLISの(最長の長さ, その組み合わせ)`
これを特殊なマージをしていく。
最長の長さ同士のマージであれば、組み合わせを足してマージする。
そうでないなら、長さが異なるなら、長いほうを利用する。
単位元は(0,1)とすればよい。

これで、更新していき、最終的に全体をgetして、組み合わせ部分を答えると答え。
単位元のマージの仕方と、自身を更新するときにしっかりマージするのに注意。
///////////////////////// writeup2 end */
