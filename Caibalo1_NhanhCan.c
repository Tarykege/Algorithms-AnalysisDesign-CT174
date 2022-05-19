#include <stdio.h>
typedef struct {
	float TL,GT,DG;
	char Ten[20];
	int PA;
}DoVat;
//Doc file
void readFile(DoVat dsdv[], int *n, float *w){
	FILE *f = fopen("CaiBalo1.txt","r");
	fscanf(f,"%f",w);
	int i=0;
	while(!feof(f)){
		fscanf(f,"%f%f%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].Ten);
		dsdv[i].PA=0;
		dsdv[i].DG=dsdv[i].GT/dsdv[i].TL;
		i++;
	}
	*n=i;
	close(f);
}
//In do vat
void inDSDV(DoVat dsdv[], int n, float w){
	int i;
	float TGT=0, TTL=0;
	printf("%.2f\n",w);
	for(i=0; i<n; i++){
		printf("%-20s %-9.2f %-9.2f %.2f %9d (PA)\n",dsdv[i].Ten,dsdv[i].TL,dsdv[i].GT,dsdv[i].DG,dsdv[i].PA);
		TGT+=dsdv[i].PA*dsdv[i].GT;
		TTL+=dsdv[i].PA*dsdv[i].TL;
	}
	printf("\n");
	printf("Tong gia tri = %.2f\n",TGT);
	printf("Tong trong luong = %.2f\n",TTL);
}
//Sap xep theo don gia
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
//Tao goc
void createRoot(float *TGT, float *Wi, float *CT, float *GLNTT, float W, float DG_Max){
	*TGT=0;
	*Wi=W;
	*CT=*TGT+*Wi*DG_Max;
	*GLNTT=0;
}
//Cap nhat goc
updateRoot(float TGT, int x[], DoVat dsdv[], int n, float *GLNTT){
	if(TGT>*GLNTT){
		*GLNTT=TGT;
		int i;
		for(i=0; i<n; i++){
			dsdv[i].PA=x[i];
		}
	}
}
// Branch
void Branch(int n, DoVat dsdv[], int i, float *TGT, float *Wi, float *CT, int x[], float *GLNTT){
	int sl;
	int sldvcl = *Wi/dsdv[i].TL;
	
	for(sl=sldvcl; sl>=0; sl--){
		*TGT=*TGT+dsdv[i].GT*sl;
		*Wi-=dsdv[i].TL*sl;
		*CT+=*TGT+*Wi*dsdv[i+1].DG;
		
		if(*CT>*GLNTT){
			x[i]=sl;
			if((i==n-1) || (*Wi==0)){
				updateRoot(*TGT,x,dsdv,n,GLNTT);
			}
			else
				Branch(n,dsdv,i+1,TGT,Wi,CT,x,GLNTT);
		}
		x[i]=0;
		*TGT=*TGT-dsdv[i].GT*sl;
		*Wi+=dsdv[i].TL*sl;
	}
	 
}
int main(){
	DoVat dsdv[100];
	int n; float w;
	//Buoc 1
	readFile(dsdv,&n,&w);
	sortByDG(dsdv,n);
	
	//Buoc 2
	float TGT, GLNTT, CT, Wi;
	createRoot(&TGT,&Wi,&CT,&GLNTT,w,dsdv[0].DG);
	
	//Buoc 3
	int x[n];
	Branch(n,dsdv,0,&TGT,&Wi,&CT,x,&GLNTT);
	inDSDV(dsdv,n,w);
}
