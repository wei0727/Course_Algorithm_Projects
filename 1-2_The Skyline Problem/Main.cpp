#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std ;

struct point{
	long x ;
	long h ;
} ;

point createPoint(long x, long h){
	point p ;
	p.x = x ;
	p.h = h ;
	return p ;
}

bool cmpPoint(point &a, long x){
	return a.x < x ;
}

void showSkyline(vector<point> &s){
	for(int i=0; i<s.size(); i++){
		cout << "(" << s[i].x << ", " << s[i].h << ")" ;
	}
	cout << endl ;
}

//v1 wrong answer
/****************
	while(cin >> l >> h >> r){
		if(skyline.empty()){
			skyline.push_back(createPoint(l, h)) ;
			skyline.push_back(createPoint(r, 0)) ;
			//showSkyline(skyline) ;
			continue ;
		}
		vector<point>::iterator start_it = lower_bound(skyline.begin(), skyline.end(), l, cmpPoint);
		long h_record = 0 ;
		if(start_it == skyline.end()){
			skyline.push_back(createPoint(l, h)) ;
			skyline.push_back(createPoint(r, 0)) ;
			//showSkyline(skyline) ;
			continue ;
		}
		if(start_it == skyline.begin()){
			//never happen if input is sorted
			if(start_it->x > l){
				skyline.insert(start_it, createPoint(l, h)) ;
				start_it = lower_bound(skyline.begin(), skyline.end(), l, cmpPoint);
			}
			else{
				h_record = start_it->h ;
				start_it->h = max(h, start_it->h) ;
			}
			start_it++ ;
		}
		else{
			if(start_it->x == l){
				h_record = start_it->h ;
				start_it->h = max(h, start_it->h) ;
				start_it++ ;
			}
			else{
				vector<point>::iterator pre_it = start_it-1 ;
				h_record = pre_it->h ;
				if(pre_it->h < h){
					skyline.insert(start_it, createPoint(l, h)) ;
					start_it = lower_bound(skyline.begin(), skyline.end(), l, cmpPoint);
					start_it++ ;
				}
			}
		}
		vector<point>::iterator it ;
		bool insert_r = false ;
		for(it=start_it; it!=skyline.end(); ++it){
			if(it->x > r){
				skyline.insert(it, createPoint(r, h_record)) ;
				insert_r = true ;
				break ;
			}
			else if(it->x == r){
				insert_r = true ;
				break ;
			}
			h_record = it->h ;
			if(it->h < h){
				it->h = h ;
			}
		}
		if(!insert_r){
			skyline.push_back(createPoint(r, h_record)) ;
		}
		//showSkyline(skyline) ;
	}
****************/

//v2 ac on uva 105
/*****************
	vector<point> skyline ;
	skyline.reserve(20000) ;
	long l, r, h ;
	while(cin >> l >> h >> r){
		if(skyline.empty()){
			skyline.push_back(createPoint(l, h)) ;
			skyline.push_back(createPoint(r, 0)) ;
			//showSkyline(skyline) ;
			continue ;
		}
		vector<point>::iterator end = lower_bound(skyline.begin(), skyline.end(), r, cmpPoint) ;
		if(end == skyline.end()){
			skyline.push_back(createPoint(r, 0)) ;
		}
		else if(end->x > r){
			skyline.insert(end, createPoint(r, (end-1)->h)) ;	
		}
		vector<point>::iterator start = lower_bound(skyline.begin(), skyline.end(), l, cmpPoint) ;
		if(start->x == l){
			start->h = max(start->h, h) ;
		}
		else{
			if((start-1)->h < h){
				skyline.insert(start, createPoint(l, h)) ;
				start = lower_bound(skyline.begin(), skyline.end(), l, cmpPoint) ;
				start += 1 ;
			}
		}
		for(vector<point>::iterator it=start; it->x < r; ++it){
			if(it->h < h)
				it->h = h ;
		}
	}
	if(skyline.empty())
		skyline.push_back(createPoint(0, 0)) ;
	cout << skyline[0].x << " " << skyline[0].h ;
	for(int i=1; i<skyline.size(); i++){
		if(skyline[i].h!=skyline[i-1].h)
			cout << " " << skyline[i].x << " " << skyline[i].h ;
	}
	cout << endl ;
	return 0 ;
*****************/


int main(){
	int n, b ;
	cin >> n ;
	for(int in=0; in<n; in++){
		cin >> b ;
		vector<point> skyline ;
		skyline.reserve(20000) ;
		long l, r, h ;
		for(int ib=0; ib<b; ib++){
			cin >> l >> h >> r ;
			if(skyline.empty()){
				skyline.push_back(createPoint(l, h)) ;
				skyline.push_back(createPoint(r, 0)) ;
				//showSkyline(skyline) ;
				continue ;
			}
			vector<point>::iterator end = lower_bound(skyline.begin(), skyline.end(), r, cmpPoint) ;
			if(end == skyline.end()){
				skyline.push_back(createPoint(r, 0)) ;
			}
			else if(end->x > r){
				skyline.insert(end, createPoint(r, (end-1)->h)) ;	
			}
			vector<point>::iterator start = lower_bound(skyline.begin(), skyline.end(), l, cmpPoint) ;
			if(start->x == l){
				start->h = max(start->h, h) ;
			}
			else{
				if((start-1)->h < h){
					skyline.insert(start, createPoint(l, h)) ;
					start = lower_bound(skyline.begin(), skyline.end(), l, cmpPoint) ;
					start += 1 ;
				}
			}
			for(vector<point>::iterator it=start; it->x < r; ++it){
				if(it->h < h)
					it->h = h ;
			}
		}
		if(skyline.empty())
			skyline.push_back(createPoint(0, 0)) ;
		cout << skyline[0].x << " " << skyline[0].h ;
		for(int i=1; i<skyline.size(); i++){
			if(skyline[i].h!=skyline[i-1].h)
				cout << " " << skyline[i].x << " " << skyline[i].h ;
		}
		cout << endl ;
	}
	return 0 ;
}
