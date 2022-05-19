#include <stdio.h>
typedef struct{
	char Ten[20];
	int TL,GT,PA;
}DoVat;
typedef int bang[50][100];
//readfile
void readFile(DoVat dsdv[], int *n, int *w){
	FILE *f = fopen("inp_CaiBalo1.txt","r");
	fscanf(f,"%d",w);
	int i=0;
	while(!feof(f)){
		fscanf(f,"%d%d%[^\n],",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].Ten);
		dsdv[i].PA=0;
		i++;
	}
	*n=i;
	fclose(f);
}
//indsdv
void inDSDV(DoVat dsdv[], int n, int w){
	printf("Phuong an cai balo 1 thuat toan quy hoach dong:\n");
	printf("\n");
	int i,TTL=0,TGT=0;
	for(i=0; i<n; i++){
		printf("%-20s %-9d %-d %9d (PA)\n",dsdv[i].Ten, dsdv[i].TL, dsdv[i].GT, dsdv[i].PA);
		TTL+=dsdv[i].PA*dsdv[i].TL;
		TGT+=dsdv[i].PA*dsdv[i].GT;
	}
	printf("\n");
	printf("Trong luong cua balo: %d\n",w);
	printf("Tong trong luong: %d\n",TTL);
	printf("Tong gia tri: %d\n",TGT);
	
}
//in bang
void inBang(bang F, bang X, int n, int w){
	int V,k;
	for(k=0; k<n; k++){
		for(V=0; V<=w; V++){
			printf("%-2d%2d | ",F[k][V],X[k][V]);
		}
		printf("\n");
	}
	printf("\n");
}
//tao bang
void taoBang(DoVat dsdv[], bang F, bang X, int n, int w){
	int V,k,xk,yk;
	for(V=0; V<=w; V++){
		X[0][V] =V/dsdv[0].TL;
		F[0][V] = X[0][V]*dsdv[0].GT;
	}
	for(k=1; k<n; k++){
		for(V=0; V<=w; V++){
			int FMAX=F[k-1][V];
			int XMAX=0;
			yk=V/dsdv[k].TL;
			for(xk=1; xk<=yk; xk++){
				if(FMAX<F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT){
					FMAX=F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT;
					XMAX=xk;
				}
			}
			F[k][V]=FMAX;
			X[k][V]=XMAX;
		}
	}
}
//tra bang
void traBang(bang F, bang X, DoVat dsdv[], int w, int n){
	int V=w,k;
	for(k=n-1; k>=0; k--){
		if(X[k][V]!=0){
			dsdv[k].PA=X[k][V];
			V-=dsdv[k].TL*X[k][V];
		}
	}
}
int main(){
	//Buoc 1
	DoVat dsdv[100];
	int n,w;	
	readFile(dsdv,&n,&w);
	//Buoc 2
	bang F;
	bang X;
	taoBang(dsdv,F,X,n,w);
	inBang(F,X,n,w);
	//Buoc 3
	traBang(F,X,dsdv,w,n);
	inDSDV(dsdv,n,w);
}
