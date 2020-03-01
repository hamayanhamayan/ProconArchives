//https://www.hackerrank.com/contests/yfkpo3-1/challenges/sweets-distribution-hard
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
struct func {
    ll a, b, c, d, ab, bc, cd, abc, bcd, abcd;
    func(ll a = -1, ll b = -1, ll c = -1, ll d = -1, ll ab = -1,
        ll bc = -1, ll cd = -1, ll abc = -1, ll bcd = -1, ll abcd = -1) :
        a(a), b(b), c(c), d(d), ab(ab), bc(bc), cd(cd), abc(abc), bcd(bcd), abcd(abcd) {}
};
func operator*(func x, func y) {
    func res;

    if (x.a < 0) return y;
    if (y.a < 0) return x;

    res.a = x.a + y.a;
    res.b = x.b + y.b;
    res.c = x.c + y.c;
    res.d = x.d + y.d;

    if (0 <= y.ab) chmax(res.ab, x.a + y.ab);
    chmax(res.ab, x.a + y.b);
    if (0 <= x.ab) chmax(res.ab, x.ab + y.b);

    if (0 <= y.bc) chmax(res.bc, x.b + y.bc);
    chmax(res.bc, x.b + y.c);
    if (0 <= x.bc) chmax(res.bc, x.bc + y.c);

    if (0 <= y.cd) chmax(res.cd, x.c + y.cd);
    chmax(res.cd, x.c + y.d);
    if (0 <= x.cd) chmax(res.cd, x.cd + y.d);

    if (0 <= y.abc) chmax(res.abc, x.a + y.abc);
    if (0 <= y.bc) chmax(res.abc, x.a + y.bc);
    if (0 <= x.ab && 0 <= y.bc) chmax(res.abc, x.ab + y.bc);
    if (0 <= x.ab) chmax(res.abc, x.ab + y.c);
    if (0 <= x.abc) chmax(res.abc, x.abc + y.c);

    if (0 <= y.bcd) chmax(res.bcd, x.b + y.bcd);
    if (0 <= y.cd) chmax(res.bcd, x.b + y.cd);
    if (0 <= x.bc && 0 <= y.cd) chmax(res.bcd, x.bc + y.cd);
    if (0 <= x.bc) chmax(res.bcd, x.bc + y.d);
    if (0 <= x.bcd) chmax(res.bcd, x.bcd + y.d);

    if (0 <= y.abcd) chmax(res.abcd, x.a + y.abcd);
    if (0 <= y.bcd) chmax(res.abcd, x.a + y.bcd);
    if (0 <= x.ab && 0 <= y.bcd) chmax(res.abcd, x.ab + y.bcd);
    if (0 <= x.ab && 0 <= y.cd) chmax(res.abcd, x.ab + y.cd);
    if (0 <= x.abc && 0 <= y.cd) chmax(res.abcd, x.abc + y.cd);
    if (0 <= x.abc) chmax(res.abcd, x.abc + y.d);
    if (0 <= x.abcd) chmax(res.abcd, x.abcd + y.d);

    return res;
}
//---------------------------------------------------------------------------------------------------
template<class V, int NV> struct SegTree { // [L,R)
    V comp(V l, V r) { return l * r; };
    vector<V> val; SegTree() { val = vector<V>(NV * 2); }
    V get(int x, int y, int l = 0, int r = NV, int k = 1) {
        if (r <= x || y <= l)return V();
        if (x <= l && r <= y)return val[k];
        auto A = get(x, y, l, (l + r) / 2, k * 2);
        auto B = get(x, y, (l + r) / 2, r, k * 2 + 1);
        return comp(A, B);
    }
    void update(int i, V v) { i += NV; val[i] = v; while (i > 1)i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]); }
};
/*---------------------------------------------------------------------------------------------------
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/












int N, Q, A[201010], B[201010], C[201010], D[201010];
SegTree<func, 1 << 18> st;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> Q;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    rep(i, 0, N) cin >> C[i];
    rep(i, 0, N) cin >> D[i];

    rep(i, 0, N) st.update(i, func(A[i], B[i], C[i], D[i]));

    rep(_, 0, Q) {
        int l, r; cin >> l >> r; l--; r--;

        auto tmp = st.get(l, l + 1);
        st.update(l, st.get(r, r + 1));
        st.update(r, tmp);

        auto f = st.get(0, N);
        printf("%lld\n", f.abcd);
    }
}





/* ///////////////////////// writeup1 start
# Om
- [ȃ}[WZOgc[](https://www.hamayanhamayan.com/entry/2017/07/08/173120)
///////////////////////// writeup2 start
Easy͒SŐ؂āAAB̍őlCD̍őlOvZĂASSTmaxƂĂ΂B
HardȉɎB

2_ē߂B
ɂZOgc[ōŝzۂCB
e_ɁA(a, b, c, d, ab, bc, cd, abc, bcd, abcd)Ƃ̍őlێĂB
}[W͍Bȉ̂悤ȊB

```cpp
struct func {
    ll a, b, c, d, ab, bc, cd, abc, bcd, abcd;
    func(ll a = -1, ll b = -1, ll c = -1, ll d = -1, ll ab = -1,
        ll bc = -1, ll cd = -1, ll abc = -1, ll bcd = -1, ll abcd = -1) :
        a(a), b(b), c(c), d(d), ab(ab), bc(bc), cd(cd), abc(abc), bcd(bcd), abcd(abcd) {}
};
func operator*(func x, func y) {
    func res;

    if (x.a < 0) return y;
    if (y.a < 0) return x;

    res.a = x.a + y.a;
    res.b = x.b + y.b;
    res.c = x.c + y.c;
    res.d = x.d + y.d;

    if (0 <= y.ab) chmax(res.ab, x.a + y.ab);
    chmax(res.ab, x.a + y.b);
    if (0 <= x.ab) chmax(res.ab, x.ab + y.b);

    if (0 <= y.bc) chmax(res.bc, x.b + y.bc);
    chmax(res.bc, x.b + y.c);
    if (0 <= x.bc) chmax(res.bc, x.bc + y.c);

    if (0 <= y.cd) chmax(res.cd, x.c + y.cd);
    chmax(res.cd, x.c + y.d);
    if (0 <= x.cd) chmax(res.cd, x.cd + y.d);

    if (0 <= y.abc) chmax(res.abc, x.a + y.abc);
    if (0 <= y.bc) chmax(res.abc, x.a + y.bc);
    if (0 <= x.ab && 0 <= y.bc) chmax(res.abc, x.ab + y.bc);
    if (0 <= x.ab) chmax(res.abc, x.ab + y.c);
    if (0 <= x.abc) chmax(res.abc, x.abc + y.c);

    if (0 <= y.bcd) chmax(res.bcd, x.b + y.bcd);
    if (0 <= y.cd) chmax(res.bcd, x.b + y.cd);
    if (0 <= x.bc && 0 <= y.cd) chmax(res.bcd, x.bc + y.cd);
    if (0 <= x.bc) chmax(res.bcd, x.bc + y.d);
    if (0 <= x.bcd) chmax(res.bcd, x.bcd + y.d);

    if (0 <= y.abcd) chmax(res.abcd, x.a + y.abcd);
    if (0 <= y.bcd) chmax(res.abcd, x.a + y.bcd);
    if (0 <= x.ab && 0 <= y.bcd) chmax(res.abcd, x.ab + y.bcd);
    if (0 <= x.ab && 0 <= y.cd) chmax(res.abcd, x.ab + y.cd);
    if (0 <= x.abc && 0 <= y.cd) chmax(res.abcd, x.abc + y.cd);
    if (0 <= x.abc) chmax(res.abcd, x.abc + y.d);
    if (0 <= x.abcd) chmax(res.abcd, x.abcd + y.d);

    return res;
}
```

ŁAƂ́AŜłƂĂabcdB
}[WƂɁAabcdɂꂼ1͕KvfԂۂȂ}[Ŵӓ_B
///////////////////////// writeup2 end */
