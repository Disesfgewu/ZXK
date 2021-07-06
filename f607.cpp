// APCS 2021 / 1 �ĤT�D
/*
�D�ػ����G�]�ӷ��Ghttps://zerojudge.tw/ShowProblem?problemid=f607�^ 
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
		scanf( "%d %d" , &x , &p ) ;  // ��J�C���I�P�ĴX�M���J 
		X[p-1] = x ;
	 } 
	 long long count = 0 ;
	 set <int> s { 0 , l } ;          // �إ�set��ƫ��A����C �]�_�l�Ȭ� 0 �P���� l �^ 
	for ( int i = 0 ; i < n; i++ )
	{
		auto it = s.insert( X[i] ).first ; // �Q��set�۰ʱƧǥ\��A�̷Ӥ��Ϊ����ǥh�� 
		count += *( next( it ) ) - *( prev( it ) ) ; // �Ӥ��Ϊ��O�ΧY�����J�ᦹ�ƪ��ᶵ��h�e�� 
	}
	printf( "%lld\n" , count ) ;
    return 0; 
}
