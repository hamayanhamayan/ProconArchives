//https://www.hackerrank.com/contests/tsg-live-4-programming-contest/challenges/tsg-live-4-procon-constructable
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
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
//---------------------------------------------------------------------------------------------------
//        Welcome to My Coding Space!       @hamayanhamayan
//---------------------------------------------------------------------------------------------------












int A, B, X;
//---------------------------------------------------------------------------------------------------
#define yes "Yes"
#define no "No"
string solve() {
	int g = gcd(A, B);
	if (X % g != 0) return no;

	A /= g;
	B /= g;
	X /= g;

	rep(s, 0, max(1010101, X / B + 10)) {
		int y = s;
		ll x = X - 1LL * B * y;
		if (x % A == 0 and 0 < x / A) return yes;
	}

	return no;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> A >> B >> X;
	cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
数学的な問題っぽい。
とりあえずググるか「二元一次方程式 整数解」とやると、[いつものサイト](https://mathtrain.jp/axbyc)が出てくる。
これによると、Xがgcd(A,B)の倍数であれば、整数解になるっぽい。
とりあえず、これは判定しておき、そうじゃないならNo

あとは、整数解の中に自然数ペアがあるかどうか。
[適当に出てきたこれのhir******さんのやつ](https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q14112073229)を参考に一般解を考える。
g = gcd(A,B)して、A,B,Xをgで割ったものを以降は考える。
Ax+By=X
By=X-Ax
By=A(X/A-x)
A,Bは互いに素なので、
X/A-x=Bk より x=X/A-Bk
y=Ak
となる。yは整数となる必要があるので、k=s/Aと考えて変形しよう。
x=X/A-Bs/A
y=s
で、x,yは0以上なので、
0≦X/A-Bs/A より Bs/A≦X/A より s≦X/B
0≦s
これでsの範囲が分かる。
あとは、この範囲において、x=X/A-Bs/Aが整数となればいい。
これは(X-Bs)が0以上のAの倍数になればいいことになる。

x,y に関する二元一次不定方程式 ax+by=c が整数解を持つ
⟺ c はgcd(a,b) の倍数

///////////////////////// writeup2 end */
