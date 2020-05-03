//https://atcoder.jp/contests/abc166/tasks/abc166_f
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














int N, A, B, C;
string S[101010];
//---------------------------------------------------------------------------------------------------
vector<char> ans;
bool dfs(int cu, int a, int b, int c) {
	if (cu == N) return true;

	if (S[cu] == "AB") {
		if (a == 0 && b == 0) return false;
		if (0 < a && dfs(cu + 1, a - 1, b + 1, c)) {
			ans.push_back('B');
			return true;
		}
		if (0 < b && dfs(cu + 1, a + 1, b - 1, c)) {
			ans.push_back('A');
			return true;
		}
		return false;
	}

	if (S[cu] == "AC") {
		if (a == 0 && c == 0) return false;
		if (0 < a && dfs(cu + 1, a - 1, b, c + 1)) {
			ans.push_back('C');
			return true;
		}
		if (0 < c && dfs(cu + 1, a + 1, b, c - 1)) {
			ans.push_back('A');
			return true;
		}
		return false;
	}

	if (S[cu] == "BC") {
		if (b == 0 && c == 0) return false;
		if (0 < b && dfs(cu + 1, a, b - 1, c + 1)) {
			ans.push_back('C');
			return true;
		}
		if (0 < c && dfs(cu + 1, a, b + 1, c - 1)) {
			ans.push_back('B');
			return true;
		}
		return false;
	}
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> A >> B >> C;
	rep(i, 0, N) cin >> S[i];

	dfs(0, A, B, C);

	if (ans.size() == 0) cout << "No" << endl;
	else {
		printf("Yes\n");
		reverse(all(ans));
		fore(c, ans) printf("%c\n", c);
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
珍しい系統の問題。

以下のように考察を進める

- 場面を色々考えてみると、大体うまくいきそうな感じがする
- うまくいかない場合を考えてみると、その手をやるしかないという一本線
	- これの構築はなかなか厳しいんじゃないか？という気持ちに
- （あとは絶対にオススメはしないが、順位表を参考にする）
	- 先頭が爆速で通しているし複雑な構築方法は要求しないだろうという仮説
	- 通しているレートに割とばらつきがあるため、何か性質を見つけ出す問題だろう
- (1,0,0)でAB,BC,AC,AB,BC,AC,...のような一本道を構築で作るのはなかなか難しいのでは？
	- 貪欲に選ぶ方法がある？
	- もしかして全探索できる？
- 手元でいろいろやってみると、全探索してダメなパターンは割とすぐにダメと分かる

以上の考察から、
「全探索でダメな状態になったら、それ以上は遷移できないので枝刈りしていく」方針で解く。
やや博打な感じもするが、順位表からのメタ読みにも合う解法だし、
これ以外の回答だと貪欲解しかなさそうで、その場合に全探索解法は役に立つのでとりあえず書いてみる。

dfsでクエリ毎の2択でどちらを選ぶかで全探索する。
ここで、選んだ先でABCのどれかが負になったら、既にダメ状態なので、それ以降の遷移はしないようにするのが大事。
このようにダメ状態であると分かった段階で枝刈りをすることで、高速に全探索ができる。
///////////////////////// writeup2 end */
