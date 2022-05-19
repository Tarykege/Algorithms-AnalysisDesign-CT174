#include<stdio.h>
//Struct do vat
typedef struct{
	float TL,GT,DG;
	char Ten[20];
	int PA;
}DoVat;
//readfile
void readFile(DoVat dsdv[], int *n, float *w){
	FILE *f = fopen("inp_CaiBalo3.txt","r");
	fscanf(f,"%f",w);
	int i=0;
	while(!feof(f)){
		fscanf(f,"%f%f%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].Ten);
		dsdv[i].DG=dsdv[i].GT/dsdv[i].TL;
		dsdv[i].PA=0;
		i++;
	}
	*n=i;
	fclose(f);
}
//inds
void inDSDV(DoVat dsdv[], int n, float w){
	int i;
	float TTL=0, TGT=0;
	printf("%.2f\n\n",w);
	for(i=0; i<n; i++){
		printf("%-20s %-9.2f %-9.2f %.2f %9d(PA)\n",dsdv[i].Ten,dsdv[i].TL,dsdv[i].GT,dsdv[i].DG,dsdv[i].PA);
		TGT+=dsdv[i].GT*dsdv[i].PA;
		TTL+=dsdv[i].TL*dsdv[i].PA;
	}
	printf("\n");
	printf("Tong gia tri: %.2f\n",TGT);
	printf("Tong trong luong: %.2f\n",TTL);
}
//sap xep theo don gia
void sortByDG(DoVat dsdv[], int n){
	int i,j;
	for(i=0; i<n-1; i++){
		for(j=n-1; j>=i+1; j--){
			if(dsdv[j].DG>dsdv[j-1].DG){
				DoVat t = dsdv[j];
				dsdv[j] = dsdv[j-1];
				dsdv[j-1] = t;
			}
		}
	}
}
// tao goc
void createRoot(float *TGT, float *Wi, float *CT, float w, float DG_Max, float *GLNTT){
	*TGT=0;
	*Wi=w;
	*CT=*TGT+*Wi*DG_Max;
	*GLNTT=0;
}
// cap nhat GLNTT
void updateRoot(float TGT, float *GLNTT, DoVat dsdv[], int x[], int n){
	if(TGT>*GLNTT){
		*GLNTT=TGT;
		int i;
		for(i=0; i<n; i++){
			dsdv[i].PA=x[i];
		}
	}
}
//min
int min(int a, int b){
	return a<b? a:b;
}
//Branch
void Branch(int n, DoVat dsdv[], int i, float *TGT, float *Wi, float *CT, float *GLNTT, int x[]){
	int sl;
	int sldvcl = min(1,*Wi/dsdv[i].TL); //sldvcl = so luong do vat con lai
	for(sl=sldvcl; sl>=0; sl--){
		*TGT+=sl*dsdv[i].GT;
		*Wi-=sl*dsdv[i].TL;
		*CT=*TGT+*Wi*dsdv[i+1].DG;
		if(*CT>*GLNTT){
			x[i]=sl;
			if((i==n-1) || (*Wi==0)){
				updateRoot(*TGT,GLNTT,dsdv,x,n);
			}
			else
				Branch(n,dsdv,i+1,TGT,Wi,CT,GLNTT,x);
		}
		x[i]=0;
		*TGT-=sl*dsdv[i].GT;
		*Wi+=sl*dsdv[i].TL;
	}
}
int main(){
	DoVat dsdv[100];
	int n; float w;
	//Buoc 1
	readFile(dsdv,&n,&w);
	sortByDG(dsdv,n);
	
	//Buoc 2
	float TGT,Wi,CT,GLNTT;
	createRoot(&TGT,&Wi,&CT,w,dsdv[0].DG,&GLNTT);
	
	//Buoc 3
	int x[n];
	Branch(n,dsdv,0,&TGT,&Wi,&CT,&GLNTT,x);
	inDSDV(dsdv,n,w);
	return 0;
}
