//https://yukicoder.me/problems/no/865
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










int N, A[201010], Q;
BIT<int> bit(201010);
//---------------------------------------------------------------------------------------------------
int ans = -1;
void update(int L) {
	if (0 <= L and L + 24 <= N) {
		int tot = bit.get(L, L + 24);
		chmax(ans, tot);
	}
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, N) bit.update(i, A[i]);

	rep(L, 0, N) update(L);

	cin >> Q;
	rep(q, 0, Q) {
		int T, V; cin >> T >> V;
		T--;
		bit.update(T, V);
		rep(L, T - 23, T + 1) update(L);
		printf("%d\n", ans);
	}
}






/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
クエリ計算を行っていくが、降水量が減ることはないため、
変化する分を計算すればいい。
ある個所が変更されたときに影響を受けるのは24区間である。
なので、その24区間の総和の最大値をつかって、答えを更新すればいい。
///////////////////////// writeup2 end */	