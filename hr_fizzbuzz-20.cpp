//https://www.hackerrank.com/contests/oyamac/challenges/fizzbuzz-20
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
                      Welcome to My Coding Space!       @hamayanhamayan0
---------------------------------------------------------------------------------------------------*/












int N;
//---------------------------------------------------------------------------------------------------
void _main(){
    cin >> N;
    if (N % 15 == 0) cout << "fizzbuzz" << endl;
    else if (N % 3 == 0) cout << "fizz" << endl;
    else if (N % 5 == 0) cout << "buzz" << endl;
    else cout << N << endl;
 }





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
有名なFizzBuzz問題。
なんとも愚直に解いてしまった。
yukicoderのFizzBuzz問題を見ると面白い回答が見られると思います。

まず15の倍数かを判定し、そうならfizzbuzzと答えよう。
あとは、3の倍数、5の倍数判定をして、そうでないならそのまま答える。
15の倍数を先に判定しないと、3の倍数で先に引っかかったりすると答えが変わる。
///////////////////////// writeup2 end */
//　