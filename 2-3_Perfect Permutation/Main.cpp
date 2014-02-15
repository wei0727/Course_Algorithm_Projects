#include <iostream>
#include <vector>
#include <bitset>
#include <ctime>
using namespace std ;

//random number generator
void rng(){
	srand(time(NULL)) ;
	for(int i=0; i<20; i++){
		for(int j=0; j<20; j++)
			cout << rand()%1000000 << " " ;
		cout << endl ;
	}
}
//

int main(){
	//rng() ;
	clock_t t1, t2 ;
	int n ;
	cin >> n ;
	for(int i=0; i<n; i++){
		int len ;
		cin >> len ;
		int size = 1 << len ;
		vector<vector<int>> w(len, vector<int>(len)) ;
		for(int j=0; j<len; j++){
			for(int k=0; k<len; k++)
				cin >> w[j][k] ;
		}
		t1 = clock() ;
		vector<long> dp(size, 0) ;
		vector<int> dp_from(size, 0) ;
		for(int j=0; j<size-1; j++){
			bitset<20> bj(j) ;
			//cout << endl << "cur " << bj << endl ;
			for(int k=0; k<len; k++){
				if(!bj[k]){
					bitset<20> tmp(bj) ;
					tmp.set(k) ;
					int update = tmp.to_ulong() ;
					int weight = dp[j] ;
					for(int m=0; m<len; m++){
						if(bj[m]){
							//cout << k << "\t" << m << "\t" << w[k][m] << endl ;
							weight += w[k][m] ;
						}
					}
					//cout << "weight " << weight << endl ;
					if(weight >= dp[update]){
						//cout << "old weight " << dp[update] << endl ;
						dp[update] = weight ;
						dp_from[update] = j ;
					}
				}
			}
		}
		//cout << dp[size-1] << endl ;
		int cur = size-1 ;
		while(cur>0){
			bitset<20> b(cur-dp_from[cur]) ;
			for(int j=0; j<len; j++){
				if(b[j]){
					cout << j+1 << " " ;
					break ;
				}
			}
			cur = dp_from[cur] ;
		}
		t2 = clock() ;
		cout << "time: " << (t2-t1)/(double)CLOCKS_PER_SEC << endl ;
	}
	return 0 ;
}