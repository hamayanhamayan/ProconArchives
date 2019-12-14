//https://atcoder.jp/contests/kupc2019/tasks/kupc2019_e
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/













int N;
//---------------------------------------------------------------------------------------------------
enum State{
	I_CAN_SELECT, 
	YOU_CAN_SELECT,
	I_GO_TO_RETURN,
	YOU_GO_TO_RETURN,
};
vector<int> E[101010];
State dfs(int cu) {
	int cnt[4] = { 0, 0, 0, 0 };

	fore(to, E[cu]) {
		auto s = dfs(to);

		cnt[s]++;

		if (0 < cnt[I_GO_TO_RETURN] and 0 < cnt[YOU_GO_TO_RETURN]) return I_CAN_SELECT;
		if (s == YOU_CAN_SELECT) return I_CAN_SELECT;
	}

	if (cnt[I_GO_TO_RETURN] == 0 and cnt[YOU_GO_TO_RETURN] == 0 and 0 < cnt[I_CAN_SELECT]) return YOU_CAN_SELECT;
	if (cnt[I_GO_TO_RETURN] > 0) return YOU_GO_TO_RETURN;
	if (cnt[YOU_GO_TO_RETURN] > 0) return I_GO_TO_RETURN;

	// leaf
	return YOU_GO_TO_RETURN;
}
//---------------------------------------------------------------------------------------------------
bool dp[21][21];
#define wi true
#define lo false
void labo() {
	dp[0][0] = lo;
	rep(youcan, 0, 21) rep(yougo, 0, 21) {
		if (youcan) dp[youcan][yougo] = lo;
		if (yougo) if (!dp[youcan][yougo - 1]) dp[youcan][yougo] = wi;
	}

	rep(youcan, 0, 21) rep(yougo, 0, 21) printf("dp[%d][%d] = %d\n", youcan, yougo, (int)dp[youcan][yougo]);
}
//---------------------------------------------------------------------------------------------------
int cnt[4];
#define win "Alice"
#define lose "Bob"
string solve() {
	cin >> N;
	rep(n, 0, N) {
		int M;
		cin >> M;
		rep(i, 1, M + 1) E[i].clear();
		rep(i, 2, M + 1) {
			int p; cin >> p;
			E[p].push_back(i);
		}

		State st = dfs(1);

		switch (st)
		{
		case I_CAN_SELECT:
			cnt[YOU_CAN_SELECT]++;
			break;
		case YOU_CAN_SELECT:
			cnt[I_CAN_SELECT]++;
			break;
		case I_GO_TO_RETURN:
			cnt[YOU_GO_TO_RETURN]++;
			break;
		case YOU_GO_TO_RETURN:
			cnt[I_GO_TO_RETURN]++;
			break;
		default:
			break;
		}
	}

	if (0 < cnt[I_CAN_SELECT]) return win;

	if (cnt[YOU_GO_TO_RETURN] % 2 == 1) return win;
	return lose;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
最後に相手ターンでスタート地点に戻せば、こちらの勝ちになる。
各木に一旦入ったら抜け出すまでは他の木は関係無くなるので、木についてはある程度独立に考えられる。
木については、入ってから出るまでに以下の可能性が考えられる。
スタート地点に駒があって、ある木の根に駒を入れた人を先手と考える。

- A: 先手の意思でスタート地点に先手で帰るか後手で帰るか選択できる
- B: 後手の意思でスタート地点に先手で帰るか後手に帰るか選択できる
- C: どんな場合でもスタート地点に先手で帰る
- D: どんな場合でもスタート地点に後手で帰る

これ以外のパターンはない。
それぞれのパターン数が分かれば、どちらが勝てるか分かる。
Cは状況が変わらないので、無視できる。

Aが1つでもあれば勝てる。
そうでないなら、Dの偶奇で勝敗が決定する。
Dが偶数なら負け、奇数なら勝ち。
Dが偶数なら相手に真似っこ戦略されて最終的に負ける。
Dが偶数だと、先手がDをとれば後手もDをとるし、Bをとったら、後手が先手で帰るように選択すればいい。
最終的にDが0で、先手で動けなくなる。
奇数時で必勝は先手がDを最初にとって、あとは、逆の立場で真似っこ戦略すればいい。

あとは、このパターン分けであるが、それぞれの木について木DPすればいい。
バックトラックで求めることができる。
状況はA～Dで考えればいい。
///////////////////////// writeup2 end */
