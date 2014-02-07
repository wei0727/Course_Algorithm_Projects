#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

int lis(vector<int> &s){
	if(s.empty())
		return 0 ;
	vector<int> v ;
	v.push_back(s[0]) ;
	for(int i=1; i<s.size(); i++){
		if(s[i] > v.back())
			v.push_back(s[i]) ;
		else
			*lower_bound(v.begin(), v.end(), s[i]) = s[i] ;
	}
	return v.size() ;
}

int main(){
	int n ;
	cin >> n ;
	for(int i=0; i<n; i++){
		int len ;
		cin >> len ;
		vector<int> s(len) ;
		for(int j=0; j<len; j++)
			cin >> s[j] ;
		cout << lis(s) << endl ;
	}
	return 0 ;
}