#include <bits/stdc++.h>
using namespace std ;
vector <string> d ;
stack <int> w ;
int F( int x )      // �w�q�T�ث��w��� 
{
	return 2*x - 3 ;
}
int G( int x , int y )
{
	return 2*x + y - 7 ;
}
int H( int x , int y , int z )
{
	return 3*x - 2*y + z ;
}
int main ()
{
	string s  ;
	string o ;
	getline( cin , s ) ;
	stringstream ss( s ) ;
	while ( ss >> o )
		d.push_back( o ) ;    // ���Υ��r���ܬ��l�r���ivector�� 
	int i = d.size() - 1  ;
	while ( i >= 0 ) //�Q��stack�ʽ�A���i��X 
	{
		if ( d[i] != "f" && d[i] != "g" && d[i] != "h" ) // ���]�J�쪺��ƬO�Ʀr 
		{
			w.push( atoi(d[i].c_str() ) ) ;				// ��Jstack�� 
		}
		else if ( d[i] == "f" )   // �p�G�J�� f �A�h��stack�̤W�褧�����i�J�禡�B�� 
		{
			int k = F( w.top() );
			w.pop() ;                  
			w.push( k ) ;		 // �A��istack�� 
		 } 
		else if ( d[i] == "g" ) // �p�G�J�� g �A�h��stack�̤W�褧��Ӥ����i�J�禡�B�� 
		{
			int k2 = w.top() ;
			w.pop() ;
			int k1 = w.top() ;
			w.pop() ;
			int k = G( k2 , k1 ) ;
			w.push( k ) ;		// �A��istack�� 
		}
		else if ( d[i] == "h" ) // �p�G�J�� g �A�h��stack�̤W�褧�T�Ӥ����i�J�禡�B��  
		{
			int k1 = w.top() ;
			w.pop() ;
			int k2 = w.top() ;
			w.pop() ;
			int k3 = w.top() ;
			w.pop() ;
			int k = H( k1 , k2 , k3 ) ;
			w.push( k ) ;		// �A��istack�� 
		}
		i-- ;
	}
	cout << w.top() << endl ;   // �̫�s�d��stack����ƥ��ߤ@�A�B�Y���� 
 } 
