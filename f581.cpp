// APCS 2020 / 7 第三題
/* 
題目說明： （來源：https://zerojudge.tw/ShowProblem?problemid=f581）
有 n 個房間排成一個環，編號分別是 0 到 n−1。

房間之間有單向的路徑，編號 i 的房間可以走到編號 (i+1)modn的房間。

每次進入編號 i 的房間可以獲得 pi 個點數（最一開始待的房間也可以獲得點數）。

現在依序有 m 個任務，第 i 個任務需要蒐集到 qi 個點數。對於每次的任務，若一開始在編號 s 的房間，且走到編號 t 的房間時候可以蒐集到需要的點數，則完成這次任務後會停在編號 (t+1)modn 的房間。

一開始在編號 0 的房間，依據接收到 m 個任務，請求出完成第 m 個任務後會停在哪個編號的房間？ 
input：
第一行包含兩個正整數 n,m(1≤n≤200000,1≤m≤20000)。

第二行包含 n 個正整數 p0,p1,p2,…,pn−1，p 的總和不超過 109。

第三行包含 m 個正整數 q0,q1,q2,…,qm−1，qi 不會超過 p 的總和。
output：
輸出一個非負整數表示最後停在哪個編號的房間
*/

#include <iostream>
#include <algorithm>

using namespace std;
int n , m ;
const int nmax = 200000 , mmax = 20000 ;
int p[nmax] , q[mmax] , p2[nmax];
int main ()
{
	cin.tie(0) ;
	cout.tie(0) ;
	cin >> n >> m >> p2[0] ;
	p[0] = p2[0] ;
	for ( int i = 1 ; i < n ; i++ )
	{
		cin >> p2[i] ;
		p[i] = p2[i] + p[i - 1] ;  // 前綴和累加 
	}
	for ( int i = 0 ; i < m ; i++ )
		cin >> q[i] ;
	int A = 0 , B = 0 ; // A 控制解答，也就是現在的位子 B 控制二分搜 
	for ( int i = 0 ; i < m ; i++ )
	{
		int ti = lower_bound( p , p + n , q[i] + B ) - p ; // 找到任務完成的下一點 
		if ( ti != n ) // ti != n 表示 一圈內有完成 
		{
			A = ti ;    // 紀錄位置 
			B = p[ti] ; // 二分搜 更新下一個位子的累積分數 由於已開始 所以直接記錄此點 
		}
		else
		{              // ti == n 表示 一圈未完成 
			B = p[ n - 1 ] - p[ A ] ; // 更新二分搜 用總前綴和最後一項扣除前一輪的任務完成點之前之前綴和 
			A = 0 ;                   // 剩下的以所需分數-B 即為下次搜尋的搜尋值
									  // B = p[n-1] - p[A]
									  // q[i] - B = q[i] - (  p[n-1] - p[A] ) = q[i] - p[n-1] + p[A]     
			int ti2 = lower_bound( p , p + n , q[i] - B ) - p ;
			A = ti2 ;
			B = p[ ti2 ] ;
		}
	}
	A++ ;
	cout << A%n << endl;
}
