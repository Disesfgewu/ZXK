// APCS 2019 / 2 第三題
/*
題目說明：（來源：https://zerojudge.tw/ShowProblem?problemid=f640）
有三個函數：

f(x) = 2x – 3
g(x, y) = 2x +y – 7
h(x, y, z) = 3x – 2y + z

另有一個由這三個函數所組成的運算式，依序給你其中的函數名稱及參數，請求出這個運算式的值。例如：
h f 5 g 3 4 3
代表
h(f(5), g(3, 4), 3)
=h(7, 3, 3)
=18
input：
輸入只有一行，含有運算式中所有的函數名稱及參數值，兩兩以一個空白隔開。函數名稱為 f、g、h 其中一個字母，參數值則為一個介於 -1000 及 1000 的整數。
output：
輸出運算式的值。運算過程及結果的整數值其絕對值均不大於10^9。
*/
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
