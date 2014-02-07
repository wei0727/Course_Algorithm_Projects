#include "improve_mul.h"

namespace improve_mul{
#define base 1000000000 
#define maxdigits 9 

	void str2vec(string s, vector<unsigned long long> &v){
		static const char asciiShift = -48 ;
		int r = s.length()%maxdigits  ;
		if(r!=0)
			s.insert(0, maxdigits-(s.length()%maxdigits), '0') ;
		for(int i=0; i<s.length(); i+=maxdigits){
			unsigned long long tmp=0 ;
			for(int j=0; j<maxdigits; j++){
				tmp *= 10 ;
				tmp += s[i+j]+asciiShift ;
			}
			v.push_back(tmp) ;
		}
	}

	void showVec(vector<unsigned long long> &v){
		cout << v[0] ;
		for(int i=1; i<v.size(); i++){
			cout << setfill('0') << setw(maxdigits) << v[i] ;
		}
		cout << endl ;
	}

	void showVec(vector<unsigned long long> &v, int i, int j){
		string str_v ;
		for(int x=0; x<v.size(); x++){
			str_v.append(to_string(v[x])) ;
			if(str_v.length() > j) 
				break ;
		}
		for(int x=i-1; x<j; x++)
			cout << str_v[x] ;
		cout << endl ;
	}

	vector<unsigned long long> add(vector<unsigned long long> &v1, vector<unsigned long long>&v2){
		vector<unsigned long long> result ;
		vector<unsigned long long>::reverse_iterator it1, it2 ;
		unsigned long long sum, carry=0 ;
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
			if(sum >= base){
				sum -= base ;
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

	vector<unsigned long long> mul_base(vector<unsigned long long> &v, unsigned long long d){
		vector<unsigned long long> result ;
		vector<unsigned long long>::reverse_iterator it ;
		unsigned long long mul, carry=0 ;
		for(it=v.rbegin(); it!=v.rend(); ++it){
			mul = (*it)*d + carry ;
			if(mul >= base){
				carry = mul/base ;
				mul = mul%base ;
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

	vector<unsigned long long> mul(vector<unsigned long long> &v1, vector<unsigned long long>&v2){
		vector<unsigned long long> result, tmp ;
		vector<unsigned long long>::iterator it ;
		vector<unsigned long long>::reverse_iterator rit1, rit2 ;
		//result.push_back(0) ;
		for(it=v2.begin(); it!=v2.end(); ++it){
			result.push_back(0) ;
			//result = add(result, mul_base(v1, (*it))) ;
			tmp = mul_base(v1, *it) ;
			if(it==v2.begin())
				result = tmp ;
			else{
				for(rit1=result.rbegin(), rit2=tmp.rbegin(); rit1!=result.rend()&&rit2!=tmp.rend(); ++rit1, ++rit2){
					*rit1 += *rit2 ;
				}
			}
		}
		unsigned long long carry=0 ;
		for(rit1=result.rbegin(); rit1!=result.rend(); ++rit1){
			*rit1 += carry ;
			if(*rit1>=base){
				carry = *rit1/base ;
				*rit1 = *rit1%base ;
			}
			else
				carry = 0 ;
		}
		if(carry > 0)
			result.insert(result.begin(), carry) ;
		return result ;
	}
}