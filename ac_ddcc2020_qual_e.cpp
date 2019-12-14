//https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_e
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
int getrandmax() {
	static uint32_t y = time(NULL);
	y ^= (y << 13); y ^= (y >> 17);
	y ^= (y << 5);
	return abs((int)y);
}
int getrand(int l, int r) { // [l, r]
	return getrandmax() % (r - l + 1) + l;
}
vector<int> makePermutation(int n) {
	vector<int> v(n);
	rep(i, 0, n) v[i] = i + 1;
	rep(i, 0, n) {
		int j = getrand(0, n - 1);
		swap(v[i], v[j]);
	}
	return v;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N;
char ans[201];
//---------------------------------------------------------------------------------------------------
string ask(vector<int> d) {
	printf("?");
	fore(i, d) printf(" %d", i+1);
	printf("\n");
	fflush(stdout);

	string res; cin >> res;
	return res;
}
string ask2(int st) {
	vector<int> v;
	rep(i, 0, N) v.push_back((st + i) % (2 * N));
	return ask(v);
}
void answer() {
	printf("! ");
	rep(i, 0, N * 2) printf("%c", ans[i]);
	printf("\n");
}
//---------------------------------------------------------------------------------------------------
#define blue 'B'
#define red 'R'
void _main() {
	cin >> N;
	rep(i, 0, 2 * N) ans[i] = '#';

	int a = 0, b = N;
	string as = ask2(a), bs = ask2(b);
	while (a + 1 != b) {
		int md = (a + b) / 2;
		if (ask2(md) == as) a = md;
		else b = md;
	}

	if (as == "Red") {
		ans[a] = 'R';
		ans[(a + N) % (2 * N)] = 'B';
	}
	else {
		ans[a] = 'B';
		ans[(a + N) % (2 * N)] = 'R';
	}

	rep(st, 0, N - 1) {
		vector<int> v;
		rep(i, 0, N - 1) v.push_back((a + 1 + i) % (2 * N));
		v.push_back((a + N + 1 + st) % (2 * N));
		auto res = ask(v);
		if (res == "Red") ans[(a + N + 1 + st) % (2 * N)] = 'R';
		else ans[(a + N + 1 + st) % (2 * N)] = 'B';
	}

	rep(st, 0, N - 1) {
		vector<int> v;
		rep(i, 0, N - 1) v.push_back((a + 1 + N + i) % (2 * N));
		v.push_back((a + 1 + st) % (2 * N));
		auto res = ask(v);
		if (res == "Red") ans[(a + 1 + st) % (2 * N)] = 'R';
		else ans[(a + 1 + st) % (2 * N)] = 'B';
	}

	answer();
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
N個ならんで質問をしよう。
1つずつずらしながら質問をしたときに答えの色が変わるポイントがある。
例えばiからN個で赤、i+1からN個で青になった場合は、i番目が赤でi+N番目が青に確定する。
ここで重要なのが、i+1～i+N-1は赤と青の個数が等しくなっているということである。
よって、このN-1個とどこか別の1つを指定すると別の1つの色が分かるという寸法。
i+1～i+N-1が同数であるということは、iとi+Nが異なる色なので、i+N+1～i+2*N-1も同数となる。
よって、分からない部分が全て分かる。

赤青の境目が分かった所で2N回必要。
よって、20回くらいで赤青の境目を見つけたいが、これは二分法でできる。
（二分探索とは呼ばないらしい）
赤と青の傾向には単調性が無いが、実は境目を見つけることができる。
これは[a,b)としたときにaとbでの色が常に異なるように更新をしていく。
すると、いつかa+1=bとなりa,bの色が異なる状況を作ることができる。
///////////////////////// writeup2 end */
