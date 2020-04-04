//https://yukicoder.me/problems/no/1017
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














int N, A[151010];
vector<int> msks[4010101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	int M = min(22, N);
	rep(msk, 0, 1 << M) {
		int sm = 0;
		rep(i, 0, M) if (msk & (1 << i)) sm += A[i];
		msks[sm].push_back(msk);
	}

	rep(tot, 1, 4010101) if (1 < msks[tot].size()) {
		int plus = msks[tot][0];
		int minus = msks[tot][1];

		printf("Yes\n");
		rep(i, 0, M) {
			if (i) printf(" ");

			if (plus & (1 << i)) printf("%d", A[i]);
			else if (minus & (1 << i)) printf("-%d", A[i]);
			else printf("0");
		}
		rep(i, M, N) printf(" 0");
		printf("\n");

		return;
	}

	printf("No\n");
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
今までの経験からして、これ系で行けそうというものはあるが、制約がちょっと厳しいのと、構築する必要がある。
なにも思いつかんけど、難易度がREDじゃないというときは、何か性質を見抜くべきと考えよう。
つまり、自明な所から考えてみる。

まず同じ数が1ペアでもあれば、それを+と-にして他を全部0にすれば答えが作れる。
よって、考えるべきは、すべて異なる数が与えられた場合である。
この場合、割と作れそうな感じがするが、ここからの思考が難しい。
んー、分からん！

（解説読み中…）

どんなパターンでも22種類くらいあれば構築可能とのこと。
N=22という基準は鳩ノ巣原理で端的に言える。なるほど。明白だ。
そういう問題どっかで見たな。
ではなく、端的に換言すると、こういうのを早く思い出せ（反省）。

まあ、結論としては配列Aの先頭22個を取り出してN≦22の問題として改めて解くことを考える。
こちらの問題もまあまあ実装に困るのだが、半分全列挙を知っていればO(3^(N/2))がアルゴリズムとしては一番わかりやすい。

とりあえず、O(N2^N)の解法を紹介しておく。
O(N2^N)ですべての部分集合について総和を計算する。
それで以下の配列を構築する。
msks[tot] := 総和がtotとなる部分集合mskの集合
説明がちょっとわかりにくいが、コードを見て補完してほしい。
この時、「totが最も小さくて、個数が2個以上のmsks[tot]の1番目の集合と2番目の集合は必ず共通項を持たない」。
これはなぜかというと、共通項をもし持つのであれば、それをどちらの集合からも削除して、totがより小さいものにできるためである。
なので、totが最小のmsks[tot]の1番目と2番目を取ってくれば、それが+にする集合と-にする集合となるので、
それを+,-にして他を0で答えると答え。
///////////////////////// writeup2 end */
