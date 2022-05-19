#include <stdio.h>
#define size 50

void readFile(int a[][size], int *n){
	FILE *f;
	f=fopen("inp_TamGiacSo.txt", "r");
	if(f==NULL){
		printf("Loi mo file!!!\n");
		return;
	}
	int i=0, j;	
	while (!feof(f)){
		for(j=0; j<=i; j++)
			fscanf(f, "%d", &a[i][j]); 
		i++;
		}
	*n=i;
	fclose(f);
}
//in
void PrintData(int a[][size], int n){
	int i,j;
	printf("\nTam giac so da cho\n");
	for(i=0; i<n; i++){
		for(j=0; j<=i; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
}
//tim chi so max
int CS_max(int F[][size], int i, int j){
	if (j==0)
		return (F[i-1][0] > F[i-1][1])? 0:1;
	if (j==i)
		return i-1;
	if (j==i-1)
		return (F[i-1][i-2] > F[i-1][i-1])? i-2:i-1;
	
	if (F[i-1][j-1]>F[i-1][j] && F[i-1][j-1]>F[i-1][j+1])
		return j-1;
	if (F[i-1][j]>F[i-1][j-1] && F[i-1][j]>F[i-1][j+1])
		return j;
	if (F[i-1][j+1]>F[i-1][j] && F[i-1][j+1]>F[i-1][j-1])
		return j+1;
}

// Dung cong thuc truy hoi de tao bang F
void Tao_Bang(int a[][size], int n, int F[][size]){
 	int i, j;
	 // 2 dong dau tien cua bang F xac dinh cu the
 		F[0][0]= a[0][0];
 		F[1][0]= F[0][0] + a[1][0];
 		F[1][1]= F[0][0] + a[1][1];
 	// Tu dong thu 3 (i=2) tro ve sau
	// Moi phan tu cua bang F duoc xac dinh nho vao dong truoc do (truy hoi)
	 for(i=2; i<n; i++)
		 for(j=0; j<=i; j++){
			 int k=CS_max(F,i,j);
			 F[i][j] = F[i-1][k] + a[i][j];
	 }
}
//in bang
void inBang(int n, int F[][size]){
	int i, j;
	printf("\nBang F\n");
	for(i=0; i<n; i++){
		for(j=0; j<=i; j++)
		 	printf("%5d", F[i][j]);
		printf("\n");
	}
}
//Chi so max dong cuoi
int CS_cuoi(int F[], int j){
	int somax=F[0];
	int maxindex=0;
	int k;
	
	for(k=1; k<=j; k++)
		if (F[k]>somax){
			somax=F[k];
			maxindex=k;
		}
	return maxindex;
}
//Tra bang
void Tra_Bang(int a[][size], int n, int F[][size], int PA[]){
	int i,j;
	j=CS_cuoi(F[n-1],n-1);
	PA[n-1]=a[n-1][j];
	
	for(i=n-1; i>=1; i--){
		j=CS_max(F,i,j);
		PA[i-1]=a[i-1][j];
	}
}

int GiaPA(int PA[], int n){
	int i;
	int sum=0;
	for(i=0; i<n; i++)	sum+=PA[i];
	return sum;
}

void PrintPA(int PA[], int n){
	int i;
	printf("\nPhuong an la duong di qua cac so : ");
	printf("\%d", PA[0]);
	for(i=1; i<n; i++)	printf("->%d", PA[i]);
	printf("\n\nTong cac so tren duong di la %d\n", GiaPA(PA,n));
}	

int main(){
	//Buoc 1
	int a[size][size]; //Luu tam giac so
	int n;
	printf("\nBai toan tam giac so dung thuat toan quy hoach dong\n");
	readFile(a,&n);
	PrintData(a,n);
	//Buoc 2
	int PA[n]; 	
	int F[n][size];
	Tao_Bang(a,n,F);
	inBang(n,F);
	//Buoc 3
	Tra_Bang(a,n,F,PA);
	PrintPA(PA,n);
	return 0;
}
