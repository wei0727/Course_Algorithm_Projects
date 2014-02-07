#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>
using namespace std ;

struct point{
	double x ;
	double y ;
} ;

double point_distance(point &a, point &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)) ;
}

int main(){
	int n ;
	cin >> n ;
	for(int i=0; i<n; i++){
		int num ;
		cin >> num ;
		vector<point> polygon(num) ;
		vector<vector<double>> lenTable(num, vector<double>(num, 0)) ;
		for(int j=0; j<num; j++)
			cin >> polygon[j].x >> polygon[j].y ;
		for(int j=0; j<num; j++){
			for(int k=j+2; k<num; k++){
				if(j==0 && k==num-1)
					continue ;
				lenTable[j][k] = point_distance(polygon[j], polygon[k]) ;
				lenTable[k][j] = lenTable[j][k] ;
			}
		}
		vector<vector<double>> dp(num, vector<double>(num, 0)) ;
		for(int j=2; j<num; j++){
			for(int m=0; m<num-j; m++){
				int k = m+j ;
				double tmp = DBL_MAX ;
				for(int x=m+1; x<k; x++){
					tmp = min(tmp, dp[m][x]+dp[x][k]+lenTable[m][x]+lenTable[x][k]) ;
				}
				dp[m][k] = tmp ;
			}
		}
		cout << dp[0][num-1] << endl ;
	}
	return 0 ;
}