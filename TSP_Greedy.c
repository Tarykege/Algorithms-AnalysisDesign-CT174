#include<stdio.h>
#define size 50
typedef struct{
	int dau,cuoi;
	float w; //trong so canh
	int PA;
}Edge;
//readfile 
void readFile(Edge dsCanh[], int *n, int *m){
	FILE *f = fopen("inp_TSP.txt","r");
	int i,j,t,k=0;
	float temp;
	fscanf(f,"%d",n);
	
	for(i=0; i<*n; i++){
		for(j=i; j<*n; j++){
			if(i==j) for(t=0; t<=j; t++) fscanf(f,"%f",&temp);
			else{
				fscanf(f,"%f",&dsCanh[k].w);
				dsCanh[k].dau=i;
				dsCanh[k].cuoi=j;
				dsCanh[k].PA;
				k++;
			}
		}
	}
	*m=k;
	fclose(f);
}
//in DS Edges
void inDS(Edge dsCanh[], int n, int m){
	int i;
	for(i=0; i<m; i++){
		printf("%-9.2f %-3c %-3c\n",dsCanh[i].w,dsCanh[i].dau+65,dsCanh[i].cuoi+65);
	}
	printf("\n");
}
//in DS phuong an
void inPA(Edge dsCanh[], int n, int m){
	int i; float TGT=0;
	for(i=0; i<m; i++){
		if(dsCanh[i].PA==1){
			printf("%-6.2f %-6c %-6c\n",dsCanh[i].w,dsCanh[i].dau+65,dsCanh[i].cuoi+65);
			TGT+= dsCanh[i].w;	
		} 
	}
	printf("Tong gia tri: %.2f\n",TGT);
	printf("\n");
}
//sap xep theo trong so tang dan
void insertSort(Edge dsCanh[], int n, int m){
	int i,j;
	for(i=1; i<m; i++){
		j=i;
		while( j>0 && (dsCanh[j-1].w>dsCanh[j].w) ){
			Edge t = dsCanh[j-1];
			dsCanh[j-1] = dsCanh[j];
			dsCanh[j] = t;
			j--;
		}
	}
}
//
int cycle(int parent[], int dau, int cuoi){
	while(dau != parent[dau]){
		dau=parent[dau];
	}
	while(cuoi != parent[cuoi]){
		cuoi=parent[cuoi];
	}
	return dau==cuoi;
}
//
void greedy(Edge dsCanh[], int n, int m, int parent[], int d[]){
	int i,j;
	for(i=0; i<n; i++){
		parent[i]=i;
		d[i]=0;
	}
	for(i=0; i<m; i++){
		int dau = dsCanh[i].dau;
		int cuoi = dsCanh[i].cuoi;
		if( d[dau]<2 && d[cuoi]<2 && !cycle(parent,dau,cuoi) ){
			d[dau]++;
			d[cuoi]++;
			parent[cuoi]=dau;
			dsCanh[i].PA=1;
		}
	}
	for(i=0; i<m; i++){
		int dau = dsCanh[i].dau;
		int cuoi = dsCanh[i].cuoi;
		if( d[dau]<2 && d[cuoi]<2 && cycle(parent,dau,cuoi) ){
			d[dau]++;
			d[cuoi]++;
			parent[cuoi]=dau;
			dsCanh[i].PA=1;
		}
	}
	
}
int main(){
	//Buoc 1
	Edge dsCanh[size];
	int n,m;
	readFile(dsCanh,&n,&m);
	printf("Danh sach canh\n");
	inDS(dsCanh,n,m);
	
	insertSort(dsCanh,n,m);
	printf("Danh sach canh sau khi sap xep\n");
	inDS(dsCanh,n,m);
	
	//Buoc 2
	int parent[n]; //luu cha cua tung dinh
	int d[n]; 	   //luu so bac cua moi dinh
	greedy(dsCanh,n,m,parent,d);
	printf("Danh sach canh sau khi thuc hien tham an\n");
	inPA(dsCanh,n,m);
	
	return 0;
}
