#include <stdio.h>
typedef struct{
	float TL,GT,DG;
	char Ten[30];
    int PA; 
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
void inDsdv(DoVat dsdv[], int n){
	int i;
	float TTL=0, TGT=0;
	for(i=0; i<n; i++){
		printf("%-25s %-10.2f %-10.2f %-10.2f %d (phuong an)\n",dsdv[i].Ten,dsdv[i].TL,dsdv[i].GT,dsdv[i].DG,dsdv[i].PA);
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
		if(dsdv[i].PA> 1) dsdv[i].PA=1;
		w1=w1-dsdv[i].TL*dsdv[i].PA;
	}
}
int main(){
	FILE *file = fopen("Caibalo3.txt","r");
	int w,i=0,n; DoVat dsdv[30];
	//
	fscanf(file,"%d",&w);
	printf("%d\n",w);
	while(!feof(file)){
		fscanf(file,"%f%f%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].Ten);
		dsdv[i].DG=dsdv[i].GT/dsdv[i].TL;
		dsdv[i].PA=0;
		i++;
	}
	n=i;
	//
	printf("\n");
	sortByDG(dsdv,n);
	Greedy(dsdv, n, w);
	inDsdv(dsdv,n);
	fclose(file);
}
