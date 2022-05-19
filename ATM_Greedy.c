#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct{
	 int value;   // tien so
	 char vs[30]; // value string = tien chu
	 int soluong; // so luong to phai tra
	 int stt; // so thu tu dau vao input
}tien;
void sortByValue(tien t[], int n){ // Sap xep theo gia tri
	int i,j;
	for(i=0; i<=n-2; i++){
		for(j=n-1; j>=i+1; j--){
			if(t[j].value>t[j-1].value){
				tien tam = t[j];
				t[j]=t[j-1];
				t[j-1]=tam; 
			}
		}
	}
};
void sortByInput(tien t[], int n){ // Sap xep theo thu tu dau vao
	int i,j;
	for(i=0; i<=n-2; i++){
		for(j=n-1; j>=i+1; j--){
			if(t[j].stt<t[j-1].stt){
				tien tam = t[j];
				t[j]=t[j-1];
				t[j-1]=tam; 
			}
		}
	}
};
int thanhtien=0,tienthieu=0;
void greedy(tien t[], int request, int n){
	int i=0, div;
	int request_tam=request;
	while(request_tam>0){
		
		div=request_tam/t[i].value;      //xet loai tien i co tra duoc hay khong
		if(div>0){                       // neu tra duoc
			t[i].soluong=div;            // cap nhat lai so luong tien i
			request_tam-=t[i].value*div; // cap nhat so tien con lai
			thanhtien+=t[i].value*div;   // cap nhat tong so tien da tra duoc
		}
		
		i++;
		if(i==n){                  // truong hop tien du qua nho nen khong tra duoc
			tienthieu=request_tam; //cap nhat so tien thieu va thoat khoi vong lap
			break;
		}
	}
}
void in_tien(tien t[], int n, int request){
	printf("\n");
	int i=0;
	for(i=0; i<n; i++){
		if(t[i].soluong!=0)
			printf("|%-25s|%-9d|%-9d(so to)|%-10d (thanh tien)\n",t[i].vs,t[i].value,t[i].soluong,t[i].soluong*t[i].value);
	}
	printf("\n");
	printf("So tien can rut: %d\nSo tien da tra: %d\nTien thieu: %d\n",request,thanhtien,tienthieu);
	printf("\n");
	sortByInput(t,n);
	printf("Phuong an (theo gia tri tang dan): X(%d",t[0].soluong);
	for(i=1; i<n; i++){
		printf(", %d",t[i].soluong);
	}
	printf(")\n");
}
int main(){
	FILE *file = fopen("ATM.txt","r");
	tien t[MAX];
	int i=0, n, request; //n = so loai tien, request = yeu cau phai tra
	while(!feof(file)){
		fscanf(file,"%d",&t[i].value);       // doc tien so (int)
		fgets(t[i].vs,30,file);              // doc tien chu (string)
		
		if(t[i].vs[strlen(t[i].vs)-1]=='\n')
			t[i].vs[strlen(t[i].vs)-1]='\0'; //xoa ki tu \n cuoi chuoi

		t[i].soluong=0;                      // khoi tao so luong tien lay tra = 0
		t[i].stt=i+1;
		i++;
	}
	n=i;
	printf("Nhap so tien can rut: ");scanf("%d", &request);
	sortByValue(t,n);    // sap xep tien theo thu tu giam
	greedy(t,request,n); // thuc hien tinh tien
	in_tien(t,n,request);// in ket qua 
	fclose(file);
}
