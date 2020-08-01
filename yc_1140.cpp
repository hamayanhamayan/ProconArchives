//https://yukicoder.me/problems/no/1140
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
vector<bool> makePrimesBool(int n) { // [2,n]
    vector<bool> pr(n + 1, 1);
    pr[0] = pr[1] = 0;
    rep(p, 2, sqrt(n) + 2) if (pr[p]) for (int x = p * 2; x <= n; x += p) pr[x] = 0;
    return pr;
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














ll A; int P;
vector<bool> primes;
//---------------------------------------------------------------------------------------------------
void solve() {
	cin >> A >> P;

    if (!primes[P]) {
        printf("-1\n");
        return;
    }

    if (A % P == 0) printf("0\n");
    else printf("1\n");
}
//---------------------------------------------------------------------------------------------------
void _main() {
	int T; cin >> T;
    primes = makePrimesBool(5010101);
	rep(t, 0, T) solve();
}





/* ///////////////////////// writeup1 start
# 前提知識
- [素数判定](https://www.hamayanhamayan.com/entry/2017/10/14/125941)
- [フェルマーの小定理](https://www.hamayanhamayan.com/entry/2017/10/14/125941)
///////////////////////// writeup2 start
難しい問題に見える。要求事項として、以下がある。

- Pが素数かを判定
- Pが素数ならmodP上で、AのP!乗を計算せよ

## Pが素数かを判定

素数判定には色々やり方があるが、Pの上限は5×10^6なので、
エラトステネスの篩で前計算しておいて、素数判定はO(1)とするのがいい。
まあ、この辺は頑張ってほしい。

## AのP!乗？

普通に計算するのは無理というのは何となく分かる。
累乗のmod Pは見覚えが無いだろうか？
そう。フェルマーの小定理である。

A^{P!}
= A^{P*(P-1)*(P-2)!}
= (A^{P-1})^{P*(P-2)!}
= 1^{P*(P-2)!}
= 1

このように言い換えることができるので、基本的には答えは1になる。
コーナーケースとしてA mod Pが0の場合がある。
///////////////////////// writeup2 end */
