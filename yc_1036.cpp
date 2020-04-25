//https://yukicoder.me/problems/no/1036
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
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
#ifdef _MSC_VER
inline unsigned int __builtin_clz(unsigned int x){unsigned long r;_BitScanReverse(&r,x);return 31-r;}
#endif // _MSC_VER
template<class V> struct SparseTable { // [L,R)
    const V def = 0;
    inline V comp(V a, V b) { return gcd(a,b); }

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
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N; ll A[501010];
SparseTable<ll> st;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    vector<ll> v;
    rep(i, 0, N) v.push_back(A[i]);
    st.init(v);

    ll ans = 1LL * N * (N - 1) / 2 + N;
    int R = 0;
    rep(L, 0, N) {
        chmax(R, L);
        while (R < N && 1 < st.get(L, R + 1)) R++;
        ans -= R - L;
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
