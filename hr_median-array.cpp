//https://www.hackerrank.com/contests/eeic-programming-contest-0/challenges/median-array
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
/*---------------------------------------------------------------------------------------------------
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/












ll X, Y; int Q;
//---------------------------------------------------------------------------------------------------
ll solve(ll k) {
	if (k == 1) return X;

	ll mi = 2, ma = 4;
	while (ma <= k) {
		mi *= 2;
		ma *= 2;
	}

	ll xcnt, ycnt;
	if (k <= mi + mi / 2) {
		// first half
		xcnt = mi / 2 - (mi + mi / 2 - k);
		ycnt = mi / 2;
	}
	else {
		// second half
		xcnt = mi / 2 - (k - (mi + mi / 2));
		ycnt = mi / 2 + (k - (mi + mi / 2));
	}

	return X * xcnt + Y * ycnt;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> X >> Y >> Q;
	rep(i, 0, Q) {
		ll K; cin >> K;
		printf("%lld\n", solve(K));
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
色々な方針が見える。
ガチャに失敗すると解くのが難しくなるかもしれない。
実験してみて、規則性を導くのが正しい解法である。

むっちゃ実験すると、
A[2^k]のときは、Y^(2^(k-1))になることが分かる。
このときは、X側は0であるが、1つ進めるとX, 2つ進めると2X, 3つ進めると3Xとなっていく。
これが2^(k-1)Xになるまで続く。
つまり、2^(k-1)+1個分この領域が続く。
次に、1つずつ進めると、Xが1つ減り、Yが1つ増えるようになっていく。
つまり、A[24]=8X+8Yであるので、
A[25]=7X+9Y
A[26]=6X+10Y
といった感じである。
これが、1Xになるまで続く。
なので、2^(k-1)-1個分この領域が続く。

この法則に従って答える。
まず、どの領域に入るかと言うのを探して、前半か後半かを探して、
その何番目というので計算して答える。
///////////////////////// writeup2 end */
