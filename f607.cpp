// APCS 2021 / 1 第三題
/*
題目說明：（來源：https://zerojudge.tw/ShowProblem?problemid=f607） 
*/ 
#include <bits/stdc++.h> 
using namespace std;

const int mmax = 200000 ;
int X[mmax] ; 
int main() 
{ 	
	int n , l , x , p ;
	scanf( "%d %d" , &n , &l ) ;
	for ( int i = 0 ; i < n ; i++ )
	{
		scanf( "%d %d" , &x , &p ) ;  // 輸入每個點與第幾刀切入 
		X[p-1] = x ;
	 } 
	 long long count = 0 ;
	 set <int> s { 0 , l } ;          // 建立set資料型態之串列 （起始值為 0 與長度 l ） 
	for ( int i = 0 ; i < n; i++ )
	{
		auto it = s.insert( X[i] ).first ; // 利用set自動排序功能，依照切割的順序去切 
		count += *( next( it ) ) - *( prev( it ) ) ; // 該切割的費用即為插入後此數的後項減去前項 
	}
	printf( "%lld\n" , count ) ;
    return 0; 
}
