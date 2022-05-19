#include<stdio.h>
void readFile(int a[], int *n){
	int i=0;
	FILE *f=fopen("Sort.txt","r");
	while(!feof(f)){
		fscanf(f,"%d ",&a[i]);
		i++;
	}
	*n=i;
}
void swap(int a[], int x, int y){
	int t = a[x];
	a[x]=a[y];
	a[y]=t;
}
//------------------------------------------------//
int findPivot(int a[], int i, int j){
	int k=i+1;
	while(k<=j && a[k] == a[i]){
		k++;
	}
	if(k>j) return -1;
	if(a[k]>a[i]) return k; else return i;
}
int partition(int a[], int i, int j, int pivot){
	int l=i, r=j;
	while(l<=r){
		while(a[l]<pivot) l++;
		while(a[r]>=pivot) r--;
		if(l<r){
			swap(a,l,r);
		}
	}
	if(l>r) return l;
}
void QuickSort(int a[], int i, int j){
	int pivot = findPivot(a,i,j);
	if(pivot!=-1){
		int k=partition(a,i,j,a[pivot]); // int k=partition(a,i,j,pivot); sai vi pivot la vi tri khong phai gia tri cho de phan hoach
		QuickSort(a,i,k-1);
		QuickSort(a,k,j);
	}
}
//------------------------------------------------//
void SelectionSort(int a[], int n){
	int i,j,lowIdx,lowVal;
	for(i=0; i<=n-1; i++){
		lowIdx=i;
		lowVal=a[i];
		for(j=i+1; j<=n-1; j++){
			if(a[j]<lowVal){
				lowVal=a[j];
				lowIdx=j;
			}
		}
		swap(a,i,lowIdx);
	}
}
//------------------------------------------------//
void InsertionSort(int a[], int n){
	int i,j;
	for(i=1; i<=n-1; i++){
		j=i;
		while(j>0 && a[j-1]>a[j]){
			swap(a,j-1,j);
			j--;
		}
	}
}
//------------------------------------------------//
void BubbleSort(int a[], int n){
	int i,j;
	for(i=0; i<=n-2; i++){
		for(j=n-1; j>=i+1; j--){
			if(a[j-1]>a[j]) swap(a,j-1,j);
		}
	}
}
//------------------------------------------------//
void printData(int a[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ",a[i]);
	}
}
int main(){
	int a[100], a1[100];
	int n,i;
	readFile(a,&n);
	for(i=0; i<n; i++){
		a1[i]=a[i];
	}
//	QuickSort(a1,0,n-1);
//	SelectionSort(a1,n);
//	InsertionSort(a1,n);
//	BubbleSort(a1,n);
	printData(a1,n);
	return 0;
}
