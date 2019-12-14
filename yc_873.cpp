//https://yukicoder.me/problems/no/873
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
int dp[301010];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;

    rep(i, 0, 301010) dp[i] = inf;
    dp[0] = 0;

    rep(i, 1, N + 1) rep(x, 1, 10101) {
        if(i - x * x < 0) break;
        chmin(dp[i], dp[i - x * x] + x);
    }

    vector<int> odd;
    rep(x, 1, 10101) if(x * x <= N and x % 2 == 1) odd.push_back(x);
    vector<int> even;
    rep(x, 1, 10101) if(x * x <= N and x % 2 == 0) even.push_back(x);
    int even_num = even.size();

    string ans = "";
    int cu = N;
    int lst = 0;
    while(1 <= cu) {
        int use = -1;
        fore(x, odd) if(0 <= cu - x * x) if(dp[cu - x * x] + x == dp[cu]) {
            use = x;
            break;
        }

        if(use < 0) {
            if(lst == 0) {
                rrep(i, even_num - 1, 0) {
                    int x = even[i];
                    if(0 <= cu - x * x) if(dp[cu - x * x] + x == dp[cu]) {
                        use = x;
                        break;
                    }
                }
            } else {
                fore(x, even) {
                    if(0 <= cu - x * x) if(dp[cu - x * x] + x == dp[cu]) {
                        use = x;
                        break;
                    }
                }
            }
        }

        rep(i, 0, use) {
            if(0 < i) lst = 1 - lst;
            ans += char('0' + lst);
        }
        cu -= use * use;
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
4^2+3^2+2^2+1^1+1^1というのが決まれば、ここからバイナリを作るのは難しくないので、
二乗の和がNであって、底の総和が最小であるようなものを探せばいい。
まずは、実験する。

```
N = 1 = 1^2
N = 2 = 1^1 + 1^1
N = 3 = 1^1 + 1^1 + 1^1
N = 4 = 2^2
N = 5 = 2^2 + 1^1
N = 32 = 4^2 + 4^2
```

うーん。ぱっと使えそうな規則性がない。
ここで制約を見ると10^5くらいになっている。
これは規則性ではなくて、DPか？
DPでした。

dp[i] := ヤバさがiのバイナリでの最短長
状態O(N)で遷移は1^2,2^2,3^2,...なのでO(sqrt(N))
よって、O(Nsqrt(N))でできる。

あとは、dpを見ながら復元していこう。
010101と基本していけばいい。
だが、3^2+4^2の場合は、
0101 101
とするより、
010 0101
のようにするほうが辞書順最小になる。
つまり、奇数でなるべく小さいものを先に持ってこよう。
偶数は後で使って、なるべく大きいものから使おう。

…でやるとコンテスト後のチャレンジケースで落ちる。
「偶数は後で使って、なるべく大きいものから使おう。」
という条件であるが、偶数を1つ使うと、11ではなく00が作れるので、
偶数を最初に大きい方から使ったら、次は小さい方から使うほうがいい、
そしたら次は大きい方から…を繰り返す。
///////////////////////// writeup2 end */
