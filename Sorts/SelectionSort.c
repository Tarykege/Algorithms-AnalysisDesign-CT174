#include <stdio.h>
void selection_sort(int a[], int n){
	int i,j,min_idx;
	for(i=0; i<n; i++){
		min_idx=i;
		for(j =i+1; j<n; j++){
			if(a[min_idx]>a[j]){
				min_idx=j;
			}
		}
		// min_idx == i: Khong tim duoc phan tu nho hon nam phia sau
		if(min_idx!=i){
			int t = a[i];
			a[i]=a[min_idx];
			a[min_idx]=t;
		}
	}
}
int main(){
	int a[] = {6,4,5,1,67,6};
	selection_sort(a,6);
	return 0;
}
