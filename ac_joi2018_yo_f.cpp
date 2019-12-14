//https://atcoder.jp/contests/joi2018yo/tasks/joi2018_yo_f
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













int N, K; ll L; int A[201010];
//---------------------------------------------------------------------------------------------------
int cnt[201010];
ll check(int x) {
	BIT<ll> bit(N + 1);

	bit.add(0, 1);
	rep(i, 0, min(N, K - 1)) {
		if (i) cnt[i] = cnt[i - 1];
		else cnt[i] = 0;
		if (A[i] <= x) cnt[i]++;
	}

	ll res = 0;
	rep(R, K - 1, N) {
		cnt[R] = cnt[R - 1];
		if (A[R] <= x) cnt[R]++;
		bit.add(cnt[R - K + 1], 1);

		// f(0,L-1,x) ≦ f(0,R,x) - K
		if (0 <= cnt[R] - K + 1) res += bit.get(0, cnt[R] - K + 1);
	}
	return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K >> L;
	rep(i, 0, N) cin >> A[i];

	//rep(i, 2, 10) printf("%d -> %lld\n", i, check(i));

	int ng = 0, ok = N;
	while (ng + 1 != ok) {
		int x = (ng + ok) / 2;
		if (L <= check(x)) ok = x;
		else ng = x;
	}
	cout << ok << endl;
}


/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
