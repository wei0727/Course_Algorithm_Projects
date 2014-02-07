#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <iomanip>
using namespace std ;

namespace improve_mul{
	void str2vec(string s, vector<unsigned long long> &v) ;
	void showVec(vector<unsigned long long> &v) ;
	void showVec(vector<unsigned long long> &v, int i, int j) ;
	vector<unsigned long long> add(vector<unsigned long long> &v1, vector<unsigned long long>&v2) ;
	vector<unsigned long long> mul_base(vector<unsigned long long> &v1, unsigned long long d) ;
	vector<unsigned long long> mul(vector<unsigned long long> &v1, vector<unsigned long long>&v2) ;
}