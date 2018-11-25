#include <vector>

void merge(std::vector<int> &v, int l, int m, int r){
	std::vector<int> v2;
	v2.reserve(r-l+1);
	int i = l, j = m+1; 

	while(i <= m && j <= r){
		if(v[i]<v[j]){
			v2.push_back(v[i]);
			i++;
		} else {
			v2.push_back(v[j]);
			j++;
		}
	}
	while(i<=m){
		v2.push_back(v[i]);
		i++;
	}
	while(j<=r){
		v2.push_back(v[j]);
		j++;
	}

	for(int k = l; k<=r; k++){
		v[k] = v2[k-l];
	}
}

void mergeSort(std::vector<int> &v, int l, int r){
	if(l<r){
		int m = l+(r-l)/2;
		mergeSort(v, l, m);
		mergeSort(v, m+1, r);
		merge(v, l, m, r);
	}
}