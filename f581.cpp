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
		p[i] = p2[i] + p[i - 1] ;  // �e��M�֥[ 
	}
	for ( int i = 0 ; i < m ; i++ )
		cin >> q[i] ;
	int A = 0 , B = 0 ; // A ����ѵ��A�]�N�O�{�b����l B ����G���j 
	for ( int i = 0 ; i < m ; i++ )
	{
		int ti = lower_bound( p , p + n , q[i] + B ) - p ; // �����ȧ������U�@�I 
		if ( ti != n ) // ti != n ��� �@�餺������ 
		{
			A = ti ;    // ������m 
			B = p[ti] ; // �G���j ��s�U�@�Ӧ�l���ֿn���� �ѩ�w�}�l �ҥH�����O�����I 
		}
		else
		{              // ti == n ��� �@�饼���� 
			B = p[ n - 1 ] - p[ A ] ; // ��s�G���j ���`�e��M�̫�@�������e�@�������ȧ����I���e���e��M 
			A = 0 ;                   // �ѤU���H�һݤ���-B �Y���U���j�M���j�M��
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
