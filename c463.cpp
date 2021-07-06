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
