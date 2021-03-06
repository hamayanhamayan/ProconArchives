//https://yukicoder.me/problems/no/1005
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
inline unsigned int __builtin_clz(unsigned int x) { unsigned long r; _BitScanReverse(&r, x); return 31 - r; }
#endif // _MSC_VER
template<class V> struct SparseTable { // [L,R)
    const V def = 0;
    inline V comp(V a, V b) { return min(a, b); }

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

    V get(int L, int R) {
        assert(0 <= L && L <= R); if (L == R)return def; R--; if (L == R)return a[L]; int h = __lg(L ^ R);
        return comp(b[h][L], b[h][R]);
    }
};
struct SuffixArraySAIS {
    vector<int> sa, lcp, rank;
    SparseTable<int> rmq;
    SuffixArraySAIS() {}
    SuffixArraySAIS(string str_) : str(str_) {
        init(str_);
    }
    SuffixArraySAIS(const vector<int>& S_, int A_SIZE_, bool lcp_flag = true) : S(S_), A_SIZE(A_SIZE_) {
        buildSA();
        if (lcp_flag) {
            buildLCP();
            buildRMQ();
        }
    }
    void init(string str_) {
        str = str_;
        N = str.size() + 1;
        S = vector<int>(N, 0);
        for (int i = 0; i < N; i++) S[i] = str[i];
        A_SIZE = 256;

        buildSA();
        buildLCP();
        buildRMQ();
    }
    string str;
    vector<int> S;
    int A_SIZE;
    int N;
    vector<int> t, B;
    enum { STYPE, LTYPE };

    inline bool is_lms(int i) {
        return i > 0 && t[i] == STYPE && t[i - 1] == LTYPE;
    }
    void bucket() {
        B = vector<int>(A_SIZE);
        for (int i = 0; i < N; i++) B[S[i]]++;
        for (int i = 0; i < A_SIZE - 1; i++) B[i + 1] += B[i];
    }
    void induced_sort() {
        bucket();
        for (int i = 0; i < N; i++) {
            int j = sa[i] - 1;
            if (j >= 0 && S[j] >= S[j + 1]) sa[B[S[j] - 1]++] = j;
        }
        bucket();
        for (int i = N; i--; ) {
            int j = sa[i] - 1;
            if (j >= 0 && S[j] <= S[j + 1]) sa[--B[S[j]]] = j;
        }
    }
    void buildSA() {
        N = S.size();
        sa.assign(N, -1);
        if (N == 1) {
            sa[0] = 0;
            return;
        }
        t.assign(N, STYPE);
        for (int i = N - 1; i--;)
            if (S[i] > S[i + 1] || (S[i] == S[i + 1] && t[i + 1] == LTYPE))
                t[i] = LTYPE;
        bucket();
        for (int i = N; i--;)
            if (is_lms(i)) sa[--B[S[i]]] = i;
        induced_sort();

        int N1 = 0;
        for (int i = 0; i < N; i++) if (is_lms(sa[i])) sa[N1++] = sa[i];

        fill(sa.begin() + N1, sa.end(), -1);
        int name = 0, prev = -1;
        for (int i = 0; i < N1; i++) {
            int cur = sa[i];
            bool diff = (prev == -1);
            for (int j = 0; !diff; j++) {
                if (j > 0 && is_lms(cur + j)) break;
                if (S[cur + j] != S[prev + j]) diff = true;
            }
            if (diff) name++;
            sa[N1 + cur / 2] = name - 1;
            prev = cur;
        }
        vector<int> S1, sa1(N1);
        for (int i = N1; i < N; i++) if (sa[i] >= 0) S1.push_back(sa[i]);
        if (name == N1) for (int i = 0; i < N1; i++) sa1[S1[i]] = i;
        else sa1 = SuffixArraySAIS(S1, name, false).sa;

        N1 = 0;
        for (int i = 0; i < N; i++) if (is_lms(i)) S1[N1++] = i;
        for (int i = 0; i < N1; i++) sa1[i] = S1[sa1[i]];

        fill(sa.begin(), sa.end(), -1);
        bucket();
        for (int i = N1; i--;) {
            int j = sa1[i];
            sa[--B[S[j]]] = j;
        }
        induced_sort();
    }
    void buildLCP() {
        rank.resize(N);
        lcp.resize(N - 1);
        for (int i = 0; i < N; i++) rank[sa[i]] = i;
        int h = 0;
        for (int i = 0; i < N - 1; i++) {
            int j = sa[rank[i] - 1];
            if (h > 0) h--;
            for (; j + h < N && i + h < N && S[j + h] == S[i + h]; h++);
            lcp[rank[i] - 1] = h;
        }
    }

    void buildRMQ() {
        rmq.init(lcp);
    }
    int common_prefix(int x, int y) {
        if (x == y) return N - 1 - x;
        if (y >= N - 1) return 0;
        if (rank[x] > rank[y]) swap(x, y);
        return rmq.get(rank[x], rank[y]);
    }
    int compare(int x, int xn, int y, int yn) {
        int l = common_prefix(x, y);
        if (l >= xn || l >= yn) return xn < yn ? -1 : xn == yn ? 0 : 1;
        return rank[x] < rank[y] ? -1 : x == y ? 0 : 1;
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














string S, T;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> S >> T;
    int N = S.length();
    int M = T.length();

    if (M == 1) {
        int cnt = 0;
        fore(c, S) if (c == T[0]) cnt++;
        if (cnt == 0) cout << 0 << endl;
        else cout << -1 << endl;
        return;
    }

    if (N < M) {
        cout << 0 << endl;
        return;
    }

    SuffixArraySAIS sais;
    sais.init(S + "#" + T);

    int ans = 0;
    int top = 0;
    while (top + M <= N) {
        if (sais.common_prefix(top, N + 1) == M) {
            ans++;
            top += M - 1;
        }
        else top++;
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
