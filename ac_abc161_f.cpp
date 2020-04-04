//https://atcoder.jp/contests/abc161/tasks/abc161_f
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
vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for (ll i = 1; i*i <= n; i++) if (n%i == 0) { S.push_back(i); if (i*i != n) S.push_back(n / i); }
	sort(S.begin(), S.end());
	return S;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














ll N;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	set<ll> ans;

	auto ed1 = enumdiv(N);
	fore(d, ed1) if (2 <= d) {
		ll K = d;
		ll n = N;
		while (n % K == 0) n /= K;
		if ((n - 1) % K == 0) ans.insert(K);
	}

	auto ed2 = enumdiv(N - 1);
	fore(d, ed2) if (2 <= d) ans.insert(d);

	cout << ans.size() << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [O(sqrt(N))による約数列挙](https://www.hamayanhamayan.com/entry/2017/10/14/125941)
///////////////////////// writeup2 start
Kを固定して、操作を逆に考えてみよう。
操作を見てみると、1から初めて+Kをするか、×Kをするかという操作になっている。

図

逆操作の×Kはいつでもできる。
これは遷移先は必ずKの倍数となるので、÷Kが選択されるためである。
だが、+Kはいつでもはできない。
+Kした結果がKの倍数であれば/Kされてしまうためである。
これは元々がKの倍数であれば+KしたときにKの倍数となってしまう。
よって、1からスタートするが、×Kを1回でも行った場合はそれ以降は×Kをするしかなくなる。
まとめると、操作は、「(1)+Kを任意回する (2)×Kを任意回する」に限定される。
この遷移先の中にNが含まれていれば、Kは条件を満たすKとなる。

図

こうして見てみると、1,K+1,2K+1,3K+1がNであるようなKというのは、N-1の約数になっている。
K-1の約数を全列挙して2よりも大きいものが答えのKとなる。

後は、K倍されているものが考慮すべきものとして残るが、このKはNの約数が候補として上がる。
よって、KをNの約数として固定して、そのKで割れるだけ割ったときの残りが、nK+1の形になっていればいい。
これも残り-1をしてKの倍数かを判定すればいい。

自分は両方のパターンで出したKをsetに入れて、重複チェックを念のためしているが、
たぶん被らないと思う。
///////////////////////// writeup2 end */
