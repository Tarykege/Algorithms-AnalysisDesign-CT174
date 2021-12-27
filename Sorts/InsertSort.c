#include<stdio.h>
void insert_sort(int a[], int n){
	int i,j,key;
	// chay tu phan tu thu 2 vi phan tu thu 1 coi nhu da duoc sap xep
	for(int i=1; i<n; i++){
		key=a[i];
		j=i-1;
		// xet gia tri phia truoc cua key co lon hon key khong, neu co thi lui, den khi gap gia tri nho hon vao gan gia tri vao phia sau
		while(a[j]>key && j>=0){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
int main(){
	int a[] = {6,4,5,1,67,6};
	insert_sort(a,6);
	return 0;
}
