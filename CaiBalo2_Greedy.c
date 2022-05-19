#include <stdio.h>
typedef struct{
	float TL,GT,DG;
	char Ten[30];
    int PA,SL; 
}DoVat;

void sortByDG(DoVat dsdv[], int n){
	int i,j;
	for(i=0; i<n-1; i++){
		for(j=n-1; j>=i+1; j--){
			if(dsdv[j].DG>dsdv[j-1].DG){
				DoVat t = dsdv[j];
				dsdv[j]=dsdv[j-1];
				dsdv[j-1]=t;
			}
		}
	}
}
void ReadFile(DoVat dsdv[], int* n, int* w){
	int i=0;
	FILE *file = fopen("CaiBalo2.txt","r");
	fscanf(file,"%d",w);
	printf("Trong luong toi da: %d\n\n",*w);
	while(!feof(file)){
		fscanf(file,"%f%f%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].SL,&dsdv[i].Ten);
		dsdv[i].DG=dsdv[i].GT/dsdv[i].TL;
		dsdv[i].PA=0;
		i++;
	}
	*n=i;
	fclose(file);
}
void inDsdv(DoVat dsdv[], int n){
	int i;
	float TTL=0, TGT=0;
	for(i=0; i<n; i++){
		printf("%-25s %-10.2f %-10.2f %-10.2f %-10d %d (phuong an)\n",dsdv[i].Ten,dsdv[i].TL,dsdv[i].GT,dsdv[i].DG,dsdv[i].SL,dsdv[i].PA);
	}
	printf("\n");
	for(i=0; i<n; i++){
		TGT+=dsdv[i].GT*dsdv[i].PA;
		TTL+=dsdv[i].TL*dsdv[i].PA;
	}
	printf("Tong gia tri: %.2f\n",TGT);
	printf("Tong trong luong: %.2f\n",TTL);
	printf("Phuong an (don gia giam dan): X(%d",dsdv[0].PA);
	for(i=1; i<n; i++){
		printf(",%d",dsdv[i].PA);
	}
	printf(")\n");
}
void Greedy(DoVat dsdv[], int n, int w){
	int w1=w, i;
	for(i=0; i<n; i++){
		dsdv[i].PA=w1/dsdv[i].TL;
		if(dsdv[i].PA>dsdv[i].SL) dsdv[i].PA=dsdv[i].SL;
		w1=w1-dsdv[i].TL*dsdv[i].PA;
	}
}
int main(){
	int w,n,i=0; DoVat dsdv[30];
	ReadFile(dsdv,&n,&w);
	sortByDG(dsdv,n);
	Greedy(dsdv, n, w);
	inDsdv(dsdv,n);
}
