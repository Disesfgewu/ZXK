#include <bits/stdc++.h>
using namespace std ;
vector <string> d ;
stack <int> w ;
int F( int x )      // 定義三種指定函數 
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
		d.push_back( o ) ;    // 切割母字串變為子字串放進vector中 
	int i = d.size() - 1  ;
	while ( i >= 0 ) //利用stack性質，先進後出 
	{
		if ( d[i] != "f" && d[i] != "g" && d[i] != "h" ) // 假設遇到的資料是數字 
		{
			w.push( atoi(d[i].c_str() ) ) ;				// 丟入stack中 
		}
		else if ( d[i] == "f" )   // 如果遇到 f ，則取stack最上方之元素進入函式運算 
		{
			int k = F( w.top() );
			w.pop() ;                  
			w.push( k ) ;		 // 再放進stack中 
		 } 
		else if ( d[i] == "g" ) // 如果遇到 g ，則取stack最上方之兩個元素進入函式運算 
		{
			int k2 = w.top() ;
			w.pop() ;
			int k1 = w.top() ;
			w.pop() ;
			int k = G( k2 , k1 ) ;
			w.push( k ) ;		// 再放進stack中 
		}
		else if ( d[i] == "h" ) // 如果遇到 g ，則取stack最上方之三個元素進入函式運算  
		{
			int k1 = w.top() ;
			w.pop() ;
			int k2 = w.top() ;
			w.pop() ;
			int k3 = w.top() ;
			w.pop() ;
			int k = H( k1 , k2 , k3 ) ;
			w.push( k ) ;		// 再放進stack中 
		}
		i-- ;
	}
	cout << w.top() << endl ;   // 最後存留於stack之資料必唯一，且即為解 
 } 
