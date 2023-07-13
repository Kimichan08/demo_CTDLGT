#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct sinhvien{
	char id[5], name[100], gender[5], address[200], className[20];
}SinhVien;

//stack chua duoc bao nhieu phan tu
int capacity = 2;  
//index<dau tien> cua stack
int top = -1;

int isFull(int capacity){
	if(top >= capacity - 1){
		return 1; // khi stack day
	}
	return 0;
}

int isEmpty(){
	if(top == -1){
		return 1; // khi stack rong
	}
	return 0;
}

SinhVien insertData(){
	SinhVien sv; // tao doi tuong sv co kieu du lieu struct SinhVien
	printf("Nhap ma sinh vien:");
	fflush(stdin);
	gets(sv.id);
	printf("Nhap ten sinh vien: ");
	gets(sv.name);
	printf("Nhap gioi tinh: ");
	gets(sv.gender);
	printf("Nhap dia chi: ");
	gets(sv.address);
	printf("Nhap lop: ");
	gets(sv.className);
	return sv;
}

void showOneStudent(SinhVien sv){
	printf("\n\tMa SV: %s",sv.id);
	printf("\n\tTen SV: %s",sv.name);
	printf("\n\tGioi tinh: %s",sv.gender);
	printf("\n\tDia chi: %s",sv.address);
	printf("\n\tLop: %s",sv.className);
}

void showListData(int top,SinhVien listStack[] ){
	for(int i = top; i>= 0; i--){
		showOneStudent(listStack[i]);
	}
}

SinhVien getTopStudent(SinhVien listStack[]){ // pop nua mua
	return listStack[top];
}

SinhVien popStudent(SinhVien listStack[]){
	SinhVien sv;
	sv = listStack[top];
	--top;
	return sv;
}

void push(SinhVien sv,SinhVien listStack[]){ // nhan 3 tham so 
	++top; // tang phan tu trong stack
	listStack[top] = sv;
}

int main(){
	SinhVien listStack[100], sv;
	int choose;
	
	do{
		printf("\n----------- MENU -----------\n");
        printf("1. Them 1 phan tu vao stack \n");
        printf("2. Hien thi cac phan tu trong stack \n");
        printf("3. Goi phuong thuc getTopStudent() \n");
        printf("4. Goi phuong thuc pop() \n");
        printf("0. Thoat chuong trinh \n");
        printf("Your Choose: ");
        scanf("%d", &choose);
        fflush(stdin);
        switch(choose){
        	case 0:
        		exit(0);
        		break;
        	case 1:
        		if(isFull(capacity) == 1){
        			printf("\n\tStack is full, overflow condition!\n");
        			break;
				}
				sv = insertData();
				push(sv, listStack);
				printf("\n\t Successfully!\n");
        		break;
        	case 2:
        		if(isEmpty()== 1){
        			printf("\n\tStack is empty, underflow condition!\n");
        			break;
				}
				showListData(top, listStack);
        		break;
        	case 3:
        		if(isEmpty()== 1){
        			printf("\n\tStack is empty, underflow condition!\n");
        			break;
				}
				showOneStudent(getTopStudent(listStack));
        		break;
        	case 4:
        		if(isEmpty()== 1){
        			printf("\n\tStack is empty, underflow condition!\n");
        			break;
				}
				showOneStudent(popStudent(listStack));
        		break;
		}
	}while(0==0);
	return 0;
}

