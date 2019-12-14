//https://yukicoder.me/problems/no/884
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

string N;
int M;
int dp[201010][2];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    M = N.length();
    reverse(all(N));

    rep(i, 0, M + 1) rep(hasKuri, 0, 2) dp[i][hasKuri] = inf;
    dp[0][0] = 0;

    rep(i, 0, M) rep(hasKuri, 0, 2) {
        int x = N[i] - '0' + hasKuri;

        if(x == 0) {
            chmin(dp[i + 1][0], dp[i][hasKuri]);
        }
        else if(x == 1) {
            chmin(dp[i + 1][0], dp[i][hasKuri] + 1);
            chmin(dp[i + 1][1], dp[i][hasKuri] + 1);
        }
        else {
            chmin(dp[i + 1][1], dp[i][hasKuri]);
        }
    }

    int ans = min(dp[M][0], dp[M][1] + 1);
    cout << ans << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
操作について考えてみると、2^kを足すか引くかということができる。
各位について、「2^kを1度足すか、2^kを1度引くか、なにもしない」の3択を選択すればいい。
2^kを足して2^kを引く操作があれば、それは操作を1つずつ引けば同様の動作を実現できるし、
2^kを2度足す操作は2^(k+1)を1度足す操作に置き換えるべきだからである。
あとは、小さい数から引いていくことを考えると下の位はすべて0にしておかないと、その後の操作で
下の位を小さくすることはできないので、下から0を埋めていくのが良さそう。
ここまで来れば、あとはDPである。

dp[i][hasKuri] := 下i桁目まで0になっていて、繰り上がりがあるかどうかのフラグがhasKuriであるときの最小操作回数
///////////////////////// writeup2 end */
