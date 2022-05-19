#include<stdio.h>
#define size 50
typedef struct{
	int dau,cuoi;
	int da_dung;
	float w;
}Edge;
void readFile(Edge dsCanh[][size], int *n){
	FILE *f= fopen("inp_TSP.txt","r");
	fscanf(f,"%d",n);
	int i,j;
	for(i=0; i<*n; i++){
		for(j=0; j<*n; j++){
			fscanf(f,"%f",&dsCanh[i][j].w);
			dsCanh[i][j].dau=i;
			dsCanh[i][j].cuoi=j;
			dsCanh[i][j].da_dung=0;
		}
	}
	fclose(f);
};
void inDS(Edge dsCanh[][size], int n){
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			printf("%c%c=%5.2f    ",dsCanh[i][j].dau+65,dsCanh[i][j].cuoi+65,dsCanh[i][j].w);
		printf("\n");
	}
}
int cycle(Edge x[], int k, int dinhKeTiep){
	int i=0, check=0;
	while(i<k && !check){
		if(dinhKeTiep == x[i].dau) check=1;
		else i++;
	}
	return check;
}
void updateGNNTT(Edge a[][size],Edge x[], Edge PA[], int n, float TGT, float *GNNTT){
	int i;
	x[n-1]=a[x[n-2].cuoi][x[0].dau];
	TGT+=x[n-1].w;
	if(TGT<*GNNTT){
		*GNNTT=TGT;
		for(i=0; i<n; i++) PA[i]=x[i];
	}
}
int CanhMin(Edge a[][size], int n){
	int i,j;
	float Cmin=3.4e+38;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i!=j && a[i][j].w<Cmin && !a[i][j].da_dung) 
				Cmin=a[i][j].w;
		}
	}
	return Cmin;
}
void NhanhCan(Edge a[][size], int n, int i, int dau, float *TGT, float *CD, float *GNNTT, Edge x[], Edge PA[] ){
	int j; //cac dinh ke tiep
	for(j=0; j<n; j++){
		if(dau!=j && !a[dau][j].da_dung && !cycle(x,i,j)){
			*TGT+=a[dau][j].w;
			*CD = *TGT + (n-(i+1))*CanhMin(a,n);
			
			if(*CD<*GNNTT){
				x[i]=a[dau][j];
				a[dau][j].da_dung=1;
				a[j][dau].da_dung=1;
				if(i==n-2){
					updateGNNTT(a,x,PA,n,*TGT,GNNTT);
				}
				else
					NhanhCan(a,n,i+1,j,TGT,CD,GNNTT,x,PA);
			}
			*TGT-=a[dau][j].w;
			a[dau][j].da_dung=0;
			a[j][dau].da_dung=0;
		}
	}
}
void inPA(int n, Edge PA[]){
	float sum=0;
	int i,j;
	printf("\nPhuong an tim duoc: \n");
	for(i=0; i<n; i++){
		sum+=PA[i].w;
		printf("%c%c=%5.2f    \n",PA[i].dau+65,PA[i].cuoi+65,PA[i].w);
	}
	printf("\n\nChu trinh: \n");
	for(i=0; i<n; i++){
		printf("%c",PA[i].dau+65);
		printf("->");
	}
	printf("%c",PA[0].dau+65);
	printf("\n\nTong do dai cac canh cua chu trinh = %5.2f\n",sum);
}
int main(){
	//Buoc 1
	Edge dsCanh[size][size];
	int n;
	readFile(dsCanh,&n);
	inDS(dsCanh,n);
	//Buoc 2
	Edge PA[n];
	Edge x[n];
	//Tao ham update GNNTT, cycle, CMin
	//Buoc 3
	float TGT=0, GNNTT=3.4e+38, CD=0 ;
	char c;
	printf("Nhap canh xuat phat: ");
	scanf("%c",&c);
	NhanhCan(dsCanh,n,0,c-97,&TGT,&CD,&GNNTT,x,PA);
	inPA(n,PA);
	return 0;
}
