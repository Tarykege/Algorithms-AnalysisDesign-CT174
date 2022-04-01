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
void bubbleSort(recordtype a[], int n){
	int i,j;
	for(i=0; i<=n-2; i++){
		for(j=n-1; j>=i+1; j--){
			if(a[j].key<a[j-1].key){
				swap(&a[j],&a[j-1]);
			}
		}
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
	printf("----BUBBLE SORT----\n");
	readData(a, &n);
	printf("Mang truoc khi sap xep\n");
	printData(a,n);
	bubbleSort(a,n);
	printf("\nMang sau khi sap xep\n");
	printData(a,n);

}
