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
void selectionSort(recordtype a[], int n){
	int i,j,lowindex,lowkey;
	for(i=0; i<=n-2; i++){
		lowindex = i;
		lowkey = a[i].key;
		for(j=i+1; j<=n-1; j++){
			if(lowkey>a[j].key){
				lowkey=a[j].key;
				lowindex=j;
			}
		}
		swap(&a[i].key,&a[lowindex].key);
	
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
	printf("----SELECTION SORT----\n");
	readData(a, &n);
	printf("Mang truoc khi sap xep\n");
	printData(a,n);
	selectionSort(a,n);
	printf("\nMang sau khi sap xep\n");
	printData(a,n);

}
