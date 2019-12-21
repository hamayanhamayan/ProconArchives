//https://www.hackerrank.com/contests/eeic-programming-contest-0/challenges/palindromic-factorization
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












ll X;
//---------------------------------------------------------------------------------------------------
set<int> buf;
void pre() {
	// 1 digit
	rep(i, 1, 10) buf.insert(i);

	// more then 1 digit
	rep(dgt, 2, 10) {
		int start = 1;
		rep(i, 0, dgt / 2 - 1) start *= 10;
		int end = 1;
		rep(i, 0, dgt / 2) end *= 10;
		rep(p1, start, end) {
			int p2 = 0;
			int x = p1;
			while (0 < x) {
				p2 = p2 * 10 + (x % 10);
				x /= 10;
			}

			if (dgt % 2 == 1) {
				rep(i, 0, 10) {
					buf.insert((p1 * 10 + i) * end + p2);
				}
			}
			else {
				buf.insert(p1 * end + p2);
			}
		}
	}
}
//---------------------------------------------------------------------------------------------------
void solve() {
	cin >> X;

	int ans = 0;
	fore(x, buf) if(X % x == 0) {
		ll y = X / x;
		if (x > y) break;

		if (buf.count(y)) {
			cout << "Yes" << endl;
			cout << x << endl;
			cout << y << endl;
			return;
		}
	}
	cout << "No" << endl;
	return;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	pre();
	int T; cin >> T;
	rep(t, 0, T) solve();
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
約数列挙して、割って、2つとも回文数であればよさそう。
だが、約数列挙はO(sqrt(N))かかるので、この方針では間に合わない。
約数列挙するけれど、その中で回文数ってかなり少ないのでは？
約数として考えるべき数は最大10^9である。
10^9は回文数ではないため、9桁までの数の回文数を列挙して、それを約数として考えればいい。
だいぶ現実的な感じになってきた。
9桁の回文数の個数は前半が決まれば後半が決まるので、前半4桁のパターン×中心1桁のパターンとなる。
今は組み合わせ数を正確に求めるわけではないので、適当にleading-0も含めて考えると、10^4*10で10^5通りである。
これが1～9桁分なので、雑に計算しても10^6通りとなる。
これが列挙できれば答えられそうだ。

列挙方法としては、前半を列挙して後半を同様にくっつければいい。
奇数桁数の場合は中心もうまくやる。
10^6通りあるので、計算量には気をつけよう。
数値計算だけで頑張ろう。

あとは30テストケースあるので、列挙自体は先に済ませておくといい。
あとは、クエリ毎に確認すれば答え。
///////////////////////// writeup2 end */
