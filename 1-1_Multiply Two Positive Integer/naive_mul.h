#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std ;


namespace naive_mul{
	void str2vec(string s, vector<char> &v) ;
	void showVec(vector<char> &v) ;
	vector<char> add(vector<char> v1, vector<char> v2) ;
	vector<char> mul_digit(vector<char> &v, char d) ;
	vector<char> mul(vector<char> &v1, vector<char> &v2) ;
	vector<char> mul_table(vector<char> &v1, vector<char> &v2) ;
}