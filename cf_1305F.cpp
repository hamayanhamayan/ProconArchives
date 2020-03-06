//https://codeforces.com/contest/1305/problem/F
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
int getrandmax() {
    static uint32_t y = time(NULL);
    y ^= (y << 13); y ^= (y >> 17);
    y ^= (y << 5);
    return abs((int)y);
}
// [l, r]
int getrand(int l, int r) {
    return getrandmax() % (r - l + 1) + l;
}
vector<ll> enumPrimeOnly(ll n) {
    ll x = n;
    vector<ll> res;
    for (int i = 2; 1LL * i * i <= n; i++) if (x % i == 0) {
        res.push_back(i);
        while (x % i == 0) x /= i;
    }
    if (x > 1) res.push_back(x);
    return res;
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














int N; ll A[201010];
//---------------------------------------------------------------------------------------------------
ll calc(ll gcd) {
    ll res = 0;
    rep(i, 0, N) {
        if (A[i] < gcd) res += gcd - A[i];
        else res += min(A[i] % gcd, gcd - (A[i] % gcd));
    }
    return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> A[i];

    ll ans = infl;
    rep(_, 0, 20) {
        int target = getrand(0, N - 1);
        rep(d, -1, 2) if(2 <= A[target] + d) {
            auto vp = enumPrimeOnly(A[target] + d);
            fore(p, vp) chmin(ans, calc(p));
        }
    }
    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [乱択アルゴリズム](https://www.hamayanhamayan.com/entry/2017/08/25/110421)
///////////////////////// writeup2 start
手の付け所の1つとして最適方針を考えるというのがある。
この仮定で重要なものを得ることができる。
全部のgcdを取った結果を2にしたいと考えると、奇数の要素を+1すれば達成できるので、
答えがNを超えることはない。

ここから得られるものが何かというと、ある最適解が存在して、各要素に必要な操作回数が割り当たっているとする。
その要素のうち1つをランダムで選んだ時に、必要な操作回数が1以下である要素を選ぶ確率は少なくとも1/2である。
これを得られるかが最も重要。
一番意地悪な最適解は、「0 2 0 2 0 2 0 2 0 2... 」というやつで、これが1/2。

よって、乱択アルゴリズムを使う。
回数はお好みだが、googleで計算してみると10回でも99.9%成功と出ているので、10でも行けそうな雰囲気。
自分は20にしました。
必要な操作回数が1以下であろう要素を乱択で取り出してくる。
操作回数が1以下ということは、A[i]かA[i]-1かA[i]+1の3択になる。
全部に対して、計算してみて、操作回数が最小のものを選ぼう。

これからはA[i]のみで考える。（±1のやつは置き換えて読むだけ）
A[i]はもうこれ以上操作せず、ほかのやつを操作することで、gcdを2以上にしたい。
と考えると、gcdはA[i]の約数になることが分かる。
だが、10^12だと約数は10^3個くらいあるものもある。ちょっと数が多い。
実際は約数ではなく、素因数だけを考えるだけでよい。
gcdを固定したときの必要な操作回数の総和は、それぞれの要素についてA[j] mod gcdが0となるようにA[j]を
操作する最小回数の総和となる。
具体的にはmin(A[j] % gcd, A[j] - (A[j] % gcd))
gcdに合成数abを使うとき、その因数aを使うときで、それぞれの要素での最小回数を考えると、
どのような場合でも因数aの方が同じか小さくなる。
雰囲気をいかに書いておく。

```
ab  |  x      |
a   |  x |    |
細かく割ってある方がmodで0の距離が近くなる！
```

実装はそれほど難しくない。
解説を難しく感じたらコードを見たほうが簡潔かもしれない。
///////////////////////// writeup2 end */
