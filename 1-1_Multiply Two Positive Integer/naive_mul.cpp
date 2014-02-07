#include "naive_mul.h"
namespace naive_mul{
	void str2vec(string s, vector<char> &v){
		static const char asciiShift = -48 ;
		for(int i=0; i<s.length(); i++){
			v.push_back(s[i]+asciiShift) ;
		}
	}

	void showVec(vector<char> &v){
		for(int i=0; i<v.size(); i++)
			cout << (int)v[i] ;
		cout << endl ;
	}

	vector<char> add(vector<char> v1, vector<char> v2){
		vector<char> result ;
		vector<char>::reverse_iterator it1, it2 ;
		char sum, carry=0 ;
		for(it1=v1.rbegin(), it2=v2.rbegin(); it1!=v1.rend() || it2!=v2.rend(); ++it1, ++it2){
			if(it1==v1.rend()){
				sum = (*it2)+carry ;
				--it1 ;
			}
			else if(it2==v2.rend()){
				sum = (*it1)+carry ;
				--it2 ;
			}
			else
				sum = (*it1) + (*it2) + carry ; ;
			if(sum >= 10){
				sum -= 10 ;
				carry = 1 ;
			}
			else
				carry = 0 ;
			result.push_back(sum) ;
		}
		if(carry != 0)
			result.push_back(carry) ;
		reverse(result.begin(), result.end()) ;
		return result ;
	}

	vector<char> mul_digit(vector<char> &v, char d){
		vector<char> result ;
		vector<char>::reverse_iterator it ;
		char mul, carry=0 ;
		for(it=v.rbegin(); it!=v.rend(); ++it){
			mul = (*it)*d + carry ;
			if(mul >= 10){
				carry = (int)mul/10 ;
				mul = (int)mul%10 ;
			}
			else
				carry = 0 ;
			result.push_back(mul) ;
		}
		if(carry != 0)
			result.push_back(carry) ;
		reverse(result.begin(), result.end()) ;
		return result ;
	}

	vector<char> mul(vector<char> &v1, vector<char> &v2){
		vector<char> result ;
		vector<char>::iterator it ;
		result.push_back(0) ;
		for(it=v2.begin(); it!=v2.end(); ++it){
			result.push_back(0) ;
			result = add(result, mul_digit(v1, (*it))) ;
		}
		return result ;
	}

	vector<char> mul_table(vector<char> &v1, vector<char> &v2){
		vector<char> result ;
		vector<char>::iterator it ;
		vector<vector<char>> table(10) ;
		result.push_back(0) ;
		for(it=v2.begin(); it!=v2.end(); ++it){
			result.push_back(0) ;
			if(table[*it].empty())
				table[*it] = mul_digit(v1, *it) ;
			result = add(result, table[*it]) ;
		}
		return result ;
	}
}