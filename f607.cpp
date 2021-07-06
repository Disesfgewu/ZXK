// APCS 2021 / 1 第三題
/*
題目說明：（來源：https://zerojudge.tw/ShowProblem?problemid=f607） 
有一根長度為 L 的棍子，你會把這個棍子切割 n 次。

假設一開始棍子左端放在數線上 0 的位置，棍子的右端放在數線上 L 的位置，每次的切割會給定一個介於 0 到 L 的數字表示要切個的位置，你要把穿過個這位置的棍子切成兩段，而所需的花費就等於所切割的棍子的長度。
input：
第一行有兩個整數 n,L。

接下來 n 行每行有兩個整數 x,i，表示 x 位置被切過一刀，而這刀是全部的切割中的第 i 刀，保證 i 是介於 [1,n] 的整數且不會重複。

配分

20分: 1≤n≤1000,1≤L≤107
30分: 1≤n≤50000,1≤L≤107
50分: 1≤n≤200000,1≤L≤107
output：
輸出一個整數表示總共的切割費用，答案可能超過 2^31 但不會超過 2^60。
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
