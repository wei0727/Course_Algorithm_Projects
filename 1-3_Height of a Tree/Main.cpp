#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std ;

int treeHeight(vector<int>::iterator root, vector<int>::iterator end){
	if(root == (end-1))
		return 1 ;
	int lt, rt ;
	vector<int>::iterator right = lower_bound(root+1, end, *(root)) ;
	if(right == end)
		rt = 0 ;
	else
		rt = treeHeight(right, end) ;
	if(right == (root+1))
		lt = 0 ;
	else
		lt = treeHeight(root+1, right) ;
	return max(lt, rt)+1 ;
}

int main(){
	int n ;
	cin >> n ;
	for(int i=0; i<n; i++){
		int nodes ;
		cin >> nodes ;
		vector<int> tree(nodes) ;
		for(int j=0; j<nodes; j++)
			cin >> tree[j] ;
		cout << "height: " ;
		cout << treeHeight(tree.begin(), tree.end())-1 << endl ;
	}
	return 0 ;
}