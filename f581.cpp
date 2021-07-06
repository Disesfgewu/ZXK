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
