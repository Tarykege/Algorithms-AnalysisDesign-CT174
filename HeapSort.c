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
void pushDown(recordtype a[], int first, int last){
	int r=first;
	while(r<=(last-1)/2){ // node can xet <= last parent node
		if(last==2*r+1){ // last node == node trai
			if(a[r].key > a[last].key) swap(&a[r],&a[last]); // neu node parent > last node thi swap
			r=last;
		}
		else if(a[r].key>a[r*2+1].key && (a[r*2+1].key<=a[r*2+2].key)){ // if node parent > left node and left node <= right node then swap r & l n
			swap(&a[r],&a[r*2+1]);
			r=r*2+1;
		}
		else if(a[r].key>a[r*2+2].key && (a[r*2+2].key < a[r*2+1].key)){ // if node parent > right node and right node < left node then swap r & r n
			swap(&a[r],&a[r*2+2]);
			r=r*2+2;
		}
		else r=last; // if node parent < right node and left node
	}
}
void heapSort(recordtype a[], int n){
	int i;
	// from last parent node to root
	for(i=(n-2)/2; i>=0; i--){
		pushDown(a,i,n-1);
	}
	// from last node to 2th node
	for(i=n-1; i>=2; i--){
		swap(&a[0],&a[i]);
		pushDown(a,0,i-1);
	}
	swap(&a[0],&a[1]);
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
void printData2(recordtype a[], int n){
	int i;
	for(i=n-1; i>=0; i--){
		printf("%3d %5d %8.2f \n",n-i-1, a[i].key, a[i].otherfields);
	}
}
int main(){
	recordtype a[100];
	int n;
	FILE *file = fopen("data.txt","r");
	printf("----HEAP SORT----\n");
	readData(a, &n);
	printf("Mang truoc khi sap xep\n");
	printData(a,n);
	heapSort(a,n);
	printf("\nMang sau khi sap xep\n");
	printData2(a,n);
}
