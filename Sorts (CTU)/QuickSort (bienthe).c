#include<stdio.h>
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;
void swap(recordtype *x, recordtype *y){
	recordtype temp;
	temp=*x;
	*x=*y;
	*y=temp;
};
//chon chot
int findPivot(recordtype a[], int i, int j){
	int k,firstkey;
	k=i+1;
	firstkey = a[i].key;
	while(k<=j && a[k].key==firstkey){
		k++;
	}
	if(k>j) return -1;
	if(a[k].key>firstkey) return i; else return k;
}
//phan hoach
int partition(recordtype a[], int i, int j, int pivot){
	int L=i, R=j;
	while(L<=R){
		while(a[L].key<=pivot) L++;
		while(a[R].key>pivot) R--;
		if(L<R) swap(&a[L],&a[R]);
	}
	return L;
}
void QuickSort(recordtype a[], int i, int j){
	int pivotIndx=findPivot(a,i,j), k;
	keytype pivot;
	if(pivotIndx != -1){
		pivot = a[pivotIndx].key;
		k = partition(a,i,j,pivot);
		QuickSort(a,i,k-1);
		QuickSort(a,k,j);
	}
}
void readData(recordtype a[], int *n){
	FILE *file = fopen("data.txt","r");
	int i=0;
	if(file!=NULL){
		while(!feof(file)){
			fscanf(file,"%d%f",&a[i].key, &a[i].otherfields);
			i++;
		}
	} else printf("loi khong doc duoc file\n");
	fclose(file);
	*n=i;
}
void printData(recordtype a[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%3d %5d %8.2f \n",i , a[i].key, a[i].otherfields);
	}
}
int main(){
	recordtype a[100];
	int n;
	FILE *file = fopen("data.txt","r");
	printf("----QUICK SORT----\n");
	readData(a, &n);
	printf("Mang truoc khi sap xep\n");
	printData(a,n);
	QuickSort(a, 0, n-1);
	printf("\nMang sau khi sap xep\n");
	printData(a,n);

}
