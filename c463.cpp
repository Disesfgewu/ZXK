// APCS 2017 / 10 第三題
/*
題目說明：https://apcs.csie.ntnu.edu.tw/index.php/questionstypes/previousexam/ （來源：https://zerojudge.tw/ShowProblem?problemid=c463）
input：
第一行有一個正整數n代表樹狀圖的節點個數，節點的編號為1到n。
接下來有n行，第i行的第一個數字k代表節點i有k個子節點，第i行接下來的k個數字就是這些子節點的編號。
每一行的相鄰數字間以空白隔開。
output：
輸出兩行各含一個整數，第一行是根節點的編號，第二行是H(T)。
*/
#include <bits/stdc++.h>
using namespace std;
const int nmax = 100001 ;
int k[nmax] = {0} ; 
int h[nmax] = {0} ;
int par[nmax] = {0} ;
int n ;
int main ()
{
	cin >> n ;
	int i , j ;
	for ( i = 1 ; i <= n ; i++ )
	{
		cin >> k[i] ;
		for ( j = 0 ; j < k[i] ; j++ )
		{
			int point ;
			cin >> point ;
			par[point] = i ;
		}
	}
	for ( i = 1 ; i <= n ; i++ )
	{
		if ( par[i] == 0 )
		{	 
			cout << i << endl;
			break;
		}
	}
	for ( i = 1 ; i <= n  ; i++ )
	{
		if( k[i] == 0 )
    	{
	        int height = 0 ; 
   		    int tmp = par[i] ;
        	while ( tmp != 0 )
        	{
        	   	height++ ;
        	   	h[tmp] = max ( h[tmp] , height ) ;
            	tmp = par[tmp];
        	}
    	}
    }
    long long count = 0 ;
    for ( int i = 1 ; i <= n ; i++ )
    	count += h[i] ;
	cout << count << endl; 
 } 
