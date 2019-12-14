//https://yukicoder.me/problems/no/876
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/


int N, Q; ll A[101010];
ll B[101010];
BIT<int> bit(101010);
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> Q;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N - 1) {
        B[i] = A[i + 1] - A[i];
        if(B[i] != 0)
            bit.update(i, 1);
    }

    rep(i, 0, Q)
    {
        int t; cin >> t;
        if(t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            if(l) {
                bit.update(l - 1, 0);
                B[l - 1] += x;
                if(B[l - 1] != 0)
                    bit.update(l - 1, 1);
            }
            bit.update(r, 0);
            B[r] -= x;
            if(B[r] != 0)
            bit.update(r, 1);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int ans = bit.get(l, r) + 1;
            printf("%d\n", ans);
        }
    }
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
問題をよく見ると、隣り合う数が異なる組+1を答える問題になっている。
つまり、数の実際の大小は特に意味がない。
加えて、今回は区間addのクエリもあるため、階差を使う問題だと推測できる。

b[i]=a[i + 1]-a[i]として階差を取る。
すると、クエリ1の区間更新[L,R]はB[L-1]+=x, B[R]-=xと2点を更新するだけでよくなる。
クエリ2の差が0かそうでないかという部分は、階差そのもの。
あとは、クエリ2の高速化であるが、クエリ1の更新は2箇所だけであるため、
更新されたら更新するようにすれば、BITを使った高速化が見込める。
階差bを0ならば0, 0でないなら1として、BITに乗せておこう。
これでクエリ2はBIT[L,R-1]+1が答えになる。
///////////////////////// writeup2 end */
