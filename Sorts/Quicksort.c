#include <stdio.h>
#include <stdlib.h>
// return pivot value
int partition(int a[], int l, int r, int key){
	int iL = l;
	int iR = r;
	while(iL<=iR){
		// voi iL, di tim phan tu >= key de swap
		while(a[iL]<key) iL++;
		while(a[iR]>key) iR--;
		// doi cho 2 phan tu dung khong dung vi tri
		if(iL<=iR){
			int t = a[iL];
			a[iL]=a[iR];
			a[iR]=t;
			iL++; iR--;
		}
	}
	return iL;	
}
void quick_sort(int a[], int l, int r){
	// Dieu kien dung
	if(l>=r) return;
	// B1 chon khoa
	int key = a[(l+r)/2];
	// B2 Phan bo lai mang theo khoa
	int k_idx = partition(a,l,r,key);
	// B3 Chia doi mang => lap lai
	quick_sort(a,l,k_idx-1);
	quick_sort(a,k_idx,r);
}
int main(){
	int a[] = {3,5,4,1,8,6,7,2};
	int n = sizeof(a)/sizeof(a[0]);
	quick_sort(a,0,n-1);
	int i;
	for(i=0; i<n; i++){
		printf("%d ",a[i]);
	}
	return 0;
}
