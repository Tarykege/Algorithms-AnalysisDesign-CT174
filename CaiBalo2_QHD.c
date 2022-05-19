#include<stdio.h>
typedef struct{
	int TL,GT,SL,PA;
	char Ten[20];
}DoVat;
typedef int bang[50][100];
//doc file
void readFile(DoVat dsdv[], int *n, int *w){
	FILE *f = fopen("inp_CaiBalo2.txt","r");
	fscanf(f,"%d",w);
	int i=0;
	while(!feof(f)){
		fscanf(f,"%d%d%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].SL,&dsdv[i].Ten);
		dsdv[i].PA=0;
		i++;
	}
	*n=i;
	fclose(f);
}
// in dsdv
void inDSDV(DoVat dsdv[], int n, int w){
	printf("\n");
	printf("Bai toan cai balo2 bang thuat toan quy hoach dong:\n\n");
	int i,TTL=0,TGT=0;
	for(i=0; i<n; i++){
		printf("%-20s %-9d %-9d %d(SL) %9d(PA)\n",dsdv[i].Ten,dsdv[i].TL,dsdv[i].GT,dsdv[i].SL,dsdv[i].PA);
		TTL+=dsdv[i].PA*dsdv[i].TL;
		TGT+=dsdv[i].PA*dsdv[i].GT;
	}
	printf("\n");
	printf("Trong luong balo: %d\n",w);
	printf("Tong trong luong: %d\n",TTL);
	printf("Tong gia tri: %d\n",TGT);
}
int min(int a, int b){
	return a>b? b:a;
}
//tao bang
void taoBang(DoVat dsdv[], bang F, bang X, int n, int w){
	int V,k,xk,yk;
	for(V=0; V<=w; V++){
		X[0][V] = V/dsdv[0].TL;
		F[0][V] = X[0][V]*dsdv[0].GT;
	}
	
	for(k=1; k<n; k++){
		for(V=0; V<=w; V++){
			int FMAX = F[k-1][V];
			int XMAX = 0;
			yk = min(V/dsdv[k].TL,dsdv[k].SL);
			for(xk=1; xk<=yk; xk++){
				if(FMAX<F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT){
					FMAX= F[k-1][V-xk*dsdv[k].TL]+xk*dsdv[k].GT;
					XMAX=xk;
				}
			}
			F[k][V]=FMAX;
			X[k][V]=XMAX;
		}
	}
}
// inBang
void inBang(bang F, bang X, int n, int w){
	int V,k;
	for(k=0; k<n; k++){
		for(V=0; V<=w; V++){
			printf("%-2d %-2d | ",F[k][V],X[k][V]);
		}
		printf("\n");
	}
}
//tra bang
void traBang(DoVat dsdv[], bang F, bang X, int n, int w){
	int V=w, k;
	for(k=n-1; k>=0; k--){
		if(X[k][V]!=0){
			dsdv[k].PA=X[k][V];
			V-=X[k][V]*dsdv[k].TL;
		}
	}	
}
int main(){
	//buoc 1
	DoVat dsdv[100];
	int n,w;
	readFile(dsdv,&n,&w);
	//buoc 2
	bang F,X;
	taoBang(dsdv,F,X,n,w);
	inBang(F,X,n,w);
	//buoc 3
	traBang(dsdv,F,X,n,w);
	inDSDV(dsdv,n,w);
	return 0;
}
