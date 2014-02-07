#include "naive_mul.h"
#include "improve_mul.h"
using namespace std ;
//using namespace naive_mul ;
using namespace improve_mul ;

//Random number generator
void rng(){
	srand(time(NULL)) ;
	static const int n = 5 ;
	//number of case
	cout << n << endl ;
	//cases
	int digits = 10 ;
	for(int i=0; i<n; i++, digits*=10){
		string a, b ;
		for(int j=1; j<digits; j++){
			int r1, r2 ;
			r1 = ceil(9*rand()/(double)RAND_MAX) ;
			r2 = ceil(9*rand()/(double)RAND_MAX) ;
			a.push_back(r1+48) ;
			b.push_back(r2+48) ;
		}
		int i = ceil(100000*rand()/(double)RAND_MAX) ;
		cout << a << "\n" << b << "\n" << 1 << "\n" << 10 << endl ;
	}
}
/////////////////////////

int main(){
	//rng() ;
	clock_t t1, t2 ;
	int n ;
	cin >> n ;
	for(; n>0; n--){
		//vector<char> n1, n2 ;
		vector<unsigned long long> n1, n2 ;
		int i, j ;
		//input type
		//n1 n2 i j
		string s1, s2 ;
		cin >> s1 >> s2 >> i >> j ;
		str2vec(s1, n1) ;
		str2vec(s2, n2) ;
		//cout << n1.size() << "\t" << n2.size() << endl ;
		t1 = clock() ;
		//n1 = mul_table(n1, n2) ;
		//showVec(n1) ;
		//showVec(n2) ;
		n1 = mul(n1, n2) ;
		showVec(n1, i, j) ;
		t2 = clock() ;
		cout << (t2-t1)/(double)CLOCKS_PER_SEC << " seconds" << endl ;
	}
	system("pause") ;
	return 0 ;
}