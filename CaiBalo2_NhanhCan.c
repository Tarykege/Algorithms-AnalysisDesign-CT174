#include <stdio.h>
typedef struct{
	float TL,GT,DG; // Tl = trong luong, GT = gia tri, DG = don gia
	int SL,PA; 		//SL = so luong, PA = phuong an
	char Ten[20];	
}DoVat;
void readFile(DoVat dsdv[], int *n, float *W){
	FILE * file = fopen("inp_CaiBalo2.txt","r");
	int i=0;
	fscanf(file,"%f",W);
	while(!feof(file)){
		fscanf(file,"%f%f%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].SL,&dsdv[i].Ten);
		dsdv[i].DG=dsdv[i].GT/dsdv[i].TL;
		dsdv[i].PA=0;
		i++;
	}
	*n=i;
	fclose(file);
}
void sortByDG(DoVat dsdv[], int n){
	int i,j;
	for(i=0; i<=n-2; i++){
		for(j=n-1; j>=i+1; j--){
			if(dsdv[j-1].DG<dsdv[j].DG){
				DoVat t = dsdv[j-1];
				dsdv[j-1]=dsdv[j];
				dsdv[j]=t;
			}
		}
	}
}
void inDSDV(DoVat dsdv[], int n, float W){
	int i;
	float TTL=0, TGT=0;
	printf("%.2f\n\n",W);
	printf("");
	for(i=0; i<n; i++){
		printf("%-20s %-9.2f %-9.2f %-9.2f %d (SL) %6d (PA)\n",dsdv[i].Ten, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].SL, dsdv[i].PA);
		TTL += dsdv[i].PA * dsdv[i].TL;
		TGT += dsdv[i].PA * dsdv[i].GT;
	}
	printf("\n");
	printf("Tong gia tri: %.2f\n",TGT);
	printf("Tong trong luong: %.2f\n",TTL);
	printf("\n");
}
void createRoot(float *TGT, float *CT, float *GLNTT, float *Wi, float W, float DG_Max){
	*TGT=0;
	*Wi=W;
	*CT=*TGT+*Wi*DG_Max;
	*GLNTT=0;
}
void updateGLNTT(DoVat a[], int n, int x[], float TGT, float *GLNTT){
	if(TGT>*GLNTT){
		*GLNTT=TGT;
		int i;
		for(i=0; i<n; i++){
			a[i].PA=x[i];
		}
	}
}
int min(int a, int b){
	return a<b? a:b;	
}
void Branch(int n, DoVat dsdv[], int i, float W, float *TGT, float *CT, float *GLNTT, float *Wi, int x[]){
	int sl;
	int SLDVCTLD = min(dsdv[i].SL,*Wi/dsdv[i].TL); //So luong do vat co the lay duoc
	
	for(sl=SLDVCTLD; sl>=0; sl--){
		*TGT += sl*dsdv[i].GT;
		*Wi -= sl*dsdv[i].TL;
		*CT = *TGT + *Wi * dsdv[i+1].DG;
		if(*CT > *GLNTT){
			
			x[i]=sl; //danh dau da xet so luong nay
			
			if((i==n-1) || (*Wi==0)){
				updateGLNTT(dsdv, n, x, *TGT, GLNTT);
			}
			else 
				Branch(n, dsdv, i+1, W, TGT, CT, GLNTT, Wi, x);
		}
		x[i]=0;
		*TGT -= sl*dsdv[i].GT;
		*Wi += sl*dsdv[i].TL;
	}
	
}
int main(){
	DoVat dsdv[100];
	float W;
	int n;
	//Buoc 1
	readFile(dsdv,&n,&W);
	sortByDG(dsdv,n);
	//inDSDV(dsdv,n,W);
	
	//Buoc 2
	float TGT,Wi,CT,GLNTT;
	createRoot(&TGT,&CT,&GLNTT,&Wi,W,dsdv[0].DG);
	
	//Buoc 3
	int x[n];
	Branch(n, dsdv, 0, W, &TGT, &CT, &GLNTT, &Wi, x);
	inDSDV(dsdv,n,W);
}
