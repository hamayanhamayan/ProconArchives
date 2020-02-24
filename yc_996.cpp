//https://yukicoder.me/problems/no/996
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
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














string S;
//---------------------------------------------------------------------------------------------------
pair<string, int> ope1(string s) {
	int cnt = 0;
	string res = "";
	int n = s.length();
	rep(i, 0, n) {
		if (i + 5 <= n && s.substr(i, 5) == "phnom") {
			cnt++;
			res += "penh";
			i += 4;
		}
		else res += s[i];
	}
	return { res, cnt };
}
pair<string,int> ope2(string s) {
	int cnt = 0;
	string res = "";
	fore(c, s) {
		if (c == 'h') cnt = 1;
		else res += c;
	}
	fore(c, res) if (c == 'e') {
		c = 'h';
		cnt = 1;
	}
	return { res, cnt };
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> S;

	int ans = 0;
	rep(i, 0, 2) {
		int tot = 0, res;
		string s = S;
		if (i == 0) tie(s, tot) = ope2(s);

		rep(_, 0, 5) {
			int res;
			tie(s, res) = ope1(s);
			tot += res;
			tie(s, res) = ope2(s);
			tot += res;
		}

		int n = s.length();
		int ma = 0;
		rep(i, 0, n - 4) if (s.substr(i, 5) == "phnom") {
			int cnt = 0;
			int j = i + 3;
			while (j < n - 1) {
				if (s.substr(j, 2) != "om") break;
				cnt++;
				j += 2;
			}
			chmax(ma, cnt);
			tot += cnt;
		}

		if (ma == 0) {
			tie(s, res) = ope2(s);
			tot += res;
		} else tot += ma + 1;
		
		chmax(ans, tot);
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
雰囲気で解こうとして、解ききれなかったので、解説AC。
何となく眺めると、
phnom→penh→phn
となるので、操作1→操作2とやるとomが消える感じがする。
例をみると、omが続いていると連続で使われる見たいなので、phnの末尾にomがたくさんあったら、それだけ分操作1ができそう。
なので、omの個数が大切っぽい。
操作1→操作2というのを見ると、操作2では全体で行われてしまうため、操作1はomの個数分、操作2は連続するomの個数の最大値っぽい。
いいところまで来た。
全体的に操作がなかなかややこしいので、若干の最適ムーブがないと星3にはならなそう。
気持ちとしては、操作1の方がきつい操作なので、なるべくこっちをやっておきたい。
phnomで操作2をやってpnomとなってしまうと悲しい。
なので、操作1をなるべくやって操作2がよさそう。

これで解法の原型ができる。
操作1をなるべくやって、操作2をやるというのを繰り返す。
ただ、だんだんphnomomom...のグループ操作になっていくので、最初の数回は愚直にシミュレートしておく。
（たぶん2回くらい回せばよさそうだけど、5回回してる）
あと、最初に操作2をやっておかないと操作1ができないパターンとかもあるので、やっとく。

[kmjpさんの記事](http://kmjp.hatenablog.jp/entry/2020/02/22/0900)では、なんとなくをちゃんと説明している。
なるほどです。
///////////////////////// writeup2 end */
