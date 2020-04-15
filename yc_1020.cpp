//https://yukicoder.me/problems/no/1020
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














int N, K; string S;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> K >> S;
	
    string pre = S.substr(0, K - 1);
    string post = S.substr(K - 1);

    if (N % 2 == K % 2) reverse(all(pre));

    string ans = post + pre;
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
難易度に反して問題が難しい印象がある。
何か性質を見抜くのが本質の問題であろう。
とりあえず、実験コードを書く。

```cpp
cin >> N >> K >> S;
string s = S;

rep(k, 2, N + 1) {
	K = k;
	S = s;
	rep(i, 0, N - K + 1) {
		rep(j, 0, K / 2) swap(S[i + j], S[i + K - 1 - j]);
	}
	printf("%2d : %s\n", k, S.c_str());
}
```


N=10,S="0123456789"として、Kを変えながら愚直解法で答えを出してみる。

```
 2 : 123456789 0
 3 : 23456789 01
 4 : 3456789 210
 5 : 456789 0123
 6 : 56789 43210
 7 : 6789 012345
 8 : 789 6543210
 9 : 89 01234567
10 : 9 876543210
```

分かりやすさのために空白を入れているが、規則性はわかりやすい。
先頭K個を取ってきて、偶数なら反転、奇数ならそのまま入れ込むみたいだ。
偶奇が重要なようだが、Nの偶奇で何か変わったりしないだろうか。
念のため、N=9,S="012345678"で改めて見ておく。

```
 2 : 12345678 0
 3 : 2345678 10
 4 : 345678 012
 5 : 45678 3210
 6 : 5678 01234
 7 : 678 543210
 8 : 78 0123456
 9 : 8 76543210
```

こちらだと、奇数が反転になっている。
NとKの偶奇が一致しているなら反転かな？
とりあえずこれ以上の組み合わせもなさそうなので、これで出してみるとAC。

///////////////////////// writeup2 end */
