//https://yukicoder.me/problems/no/905
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
#define def 1
template<class V, int NV> struct SegTree { //[l,r)
	V comp(V& l, V& r) { return l * r; };

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
	void add(int i, V v) { update(i, val[i + NV] + v); }
	V operator[](int x) { return get(x, x + 1); }
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














int N; ll A[101010];
SegTree<int, 1 << 17> stup, stdwn;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	rep(i, 0, N - 1) {
		if (A[i] <= A[i + 1]) stup.update(i, 1);
		else stup.update(i, 0);

		if (A[i] >= A[i + 1]) stdwn.update(i, 1);
		else stdwn.update(i, 0);
	}

	int Q; cin >> Q;
	rep(q, 0, Q) {
		int l, r; cin >> l >> r;
		
		int f = stup.get(l, r);
		int g = stdwn.get(l, r);

		printf("%d %d\n", f, g);
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
ある列が広義単調増加列であるというのは、各要素間でA[i]≦A[i+1]であればいい。
A[i]≦A[i+1]であるなら1、そうでないなら0であるとすると、すべての要素間が1であればいい。
これはこの区間についての総積が1であればいいことに言い換えられる。
よって、事前に隣接する要素についてA[i]≦A[i+1]であるかを見て、区間積をとるセグメントツリーを作ればいい。
あとは、これを使って、答えていく。

広義単調減少であるかの判定も全く同じように行う。

///////////////////////// writeup2 end */
