//https://atcoder.jp/contests/abc150/tasks/abc150_f
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
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r;
}
int getrandmax() {
	static uint32_t y = time(NULL);
	y ^= (y << 13); y ^= (y >> 17);
	y ^= (y << 5);
	return abs((int)y);
}
int getrand(int l, int r) { // [l, r]
	return getrandmax() % (r - l + 1) + l;
}
typedef ModInt<1000000007> mint1;
typedef ModInt<1000000009> mint2;
int primes[10] = { 10007, 10009, 10037, 10039, 10061, 10067, 10069, 10079, 10091, 10093 };
bool isShuffle = false;
struct RollingHash {
	mint1 p1; mint2 p2;
	int n;
	vector<mint1> m1; vector<mint2> m2;
	vector<mint1> v1; vector<mint2> v2;

	RollingHash() {
		if (!isShuffle) {
			rep(i, 0, 101) { int a = getrand(0, 9); int b = getrand(0, 9); swap(primes[a], primes[b]); }
			isShuffle = true;
		}
		p1 = primes[0], p2 = primes[1];
	}

	void init(string s, char o = 'a') {
		vector<int> v;
		fore(c, s) v.push_back(c - o);
		init(v);
	}

	void init(vector<int> s) {
		n = s.size();
		m1.resize(n); m2.resize(n); v1.resize(n); v2.resize(n);

		m1[0] = 1; m2[0] = 1;
		v1[0] = s[0]; v2[0] = s[0];

		rep(i, 1, n) {
			m1[i] = m1[i - 1] * p1;
			m2[i] = m2[i - 1] * p2;
			v1[i] = v1[i - 1] + m1[i] * s[i];
			v2[i] = v2[i - 1] + m2[i] * s[i];
		}
	}
	inline pair<mint1, mint2> hash(int l, int r) { // s[l..r]
		assert(l <= r); assert(r < n);
		mint1 a = v1[r];
		if (l) a -= v1[l - 1];
		a *= m1[n - 1 - r];

		mint2 b = v2[r];
		if (l) b -= v2[l - 1];
		b *= m2[n - 1 - r];

		return { a, b };
	}
	inline ll llhash(int l, int r) { // s[l..r]
		auto h = hash(l, r);
		return 1LL * h.first.get() * h.second.Mod + h.second.get();
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














int N, A[201010], B[201010], A2[201010], B2[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	rep(i, 0, N) cin >> B[i];

	rep(i, 0, N) A2[i] = A[i] ^ A[(i + 1) % N];
	rep(i, 0, N) B2[i] = B[i] ^ B[(i + 1) % N];

	vector<int> v;
	rep(i, 0, N) v.push_back(A2[i]);
	rep(i, 0, N) v.push_back(A2[i]);
	rep(i, 0, N) v.push_back(B2[i]);

	RollingHash rh;
	rh.init(v);

	rep(k, 0, N) if (rh.hash(k, k + N - 2) == rh.hash(N * 2, N * 2 + N - 2)) {
		int x = A[k] ^ B[0];
		printf("%d %d\n", k, x);
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
自明な所から考えると、kを固定すると、a[i] = b[i+k] XOR xということは、
a[i] XOR b[i+k] = xなので、xは一意に定まる。
なので、kを固定すると、最初の1要素でxがわかり、他の要素にてそれが成り立つか確認できればいい。

操作をまとめると、K要素分shiftさせて、全体にXOR xした結果がBと一致するかを判定したい。
これを判定するにはいくつかの知見を持っている必要がある。
段階的に考えていこう。

XOR xがない場合、つまり、AをK要素分shiftさせた結果とBが等しくなるかを判定する方法を考えよう。
これは、選択肢が色々ある。A+A+[inf]+Bのように配列を結合させて、KMPをやってもいいし、
A+AとBに対してローリングハッシュを作って比較してもいい。
どちらにしろ、何が言いたいかというと、A+Aのように2個分くっつけることで、
shiftを考えるのではなく、ある区間がBと一致するかという問題で考えることができるということである。
これはshift問題に取り組むときに実装量を減らすため、よく使われるテクである。

今回の問題はこれに区間XORが追加される。
区間に一定の操作を行うことへの対処法はいくつかテクがあるが、その中でも階差を用いる方法を使おう。
これは和で考えると分かりやすいが、
1 2 3 4
に対する階差は
 1 1 1
であるが、2から4に+2するとすると、階差の最初の1を+2するだけで実現できる。
 3 1 1
とすると、最初が1であることから、
1 4 5 6
の状態を表していることが分かる。
これをXORでも行う。

A2[i] = A[i] xor A[i + 1]
B2[i] = B[i] xor B[i + 1]
として階差を取っておこう。
すると、
A[i]以降にXOR xをするには、A2[i-1]にXOR xをするだけでよくなる。
しかも、この階差を取っておくことで、区間が等しいかというのも判定することが、できる。
A[i..i+K-1] = B[j..j+K-1] が成り立つことと A[i]=B[j] かつ A2[i..i+K-2]=B2[j..j+K-2]が成り立つことは同義である。
しかもA[i]=B[j]となるようにXOR xを考えているため、実際はA2[i..i+K-2]=B2[j..j+K-2]が成り立つことだけ考えればいい。
もう既にxの値は関係なく、階差を取ったときにA2[i..i+K-2]=B2[j..j+K-2]が成り立つことを判定すればよくなる。
これは、同様にKMPでもローリングハッシュでもよい。
これで答えが求まる。
///////////////////////// writeup2 end */
