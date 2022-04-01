#include <stdio.h>
void merge(int a[], int l, int m, int r){
	int i,i1,i2; // khoi tao 3 con tro
	int n1 = m-l+1; // so luong phan tu mang 1
	int n2 = r-m; // so luong phan tu mang 2
	
	// khoi tao 2 mang dua tren mang a
	int a1[n1],a2[n2];
	for(i=0 ; i<n1; i++){
		a1[i]=a[l+i];
	}
	for(i=0 ; i<n2; i++){
		a2[i] = a[m+1+i];
	}
	
	i1=0;
	i2=0;
	i=l;
	// case a1 && a2 != empty
	while(i1<n1 && i2<n2){
		if(a1[i1]<=a2[i2]){
			a[i]=a1[i1];
			i1++;
		}
		else{
			a[i]=a2[i2];
			i2++;
		}
		i++;
	}
	
	// case a1 empty || a2 empty
	while(i1<n1){
		a[i]=a1[i1];
		i++; 
		i1++;
	}
	while(i2<n2){
		a[i]=a2[i2];
		i++; 
		i2++;
	}
}
void merge_sort(int a[],int l, int r){
	// Dieu kien dung
	if(l<r){
		// Chia ra
		int m=l+(r-l)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,r);
		// Tron vao
		merge(a,l,m,r);
	}
}
int main(){
	int a[] = { 12, 11, 13, 5, 6, 7 };
	int i,n = sizeof(a)/sizeof(a[0]);
	merge_sort(a,0,n-1);
	for(i=0 ; i<n; i++){
		printf("%d ",a[i]);
	}
	return 0;
}
