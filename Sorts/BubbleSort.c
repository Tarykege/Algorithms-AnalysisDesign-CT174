#include <stdio.h>
void bubble_sort(int a[], int n){
	int i,j;
	for(i=0; i<n; i++){
		int isSorted=0;
		for(j=0; j<n-i-1; j++){
			if(a[j]>a[j+1]){
				isSorted=1;
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
		// kiem tra co thay doi khong, neu khong thi ham da sap xep break
		if(isSorted==0) break;
	}
}
int main(){
	int a[] = {9,4,5,1,67,6};
	bubble_sort(a,6);
}
