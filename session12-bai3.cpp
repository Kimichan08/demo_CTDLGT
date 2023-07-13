#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct product
{
    char id[6], name[100], nhasx[100], ngayhethan[50];
    int yearsx, quantity;
    float price;
} Product;

void addElement(Product *pro){
	fflush(stdin);
	
	printf("\nNhap ID: ");
	gets(pro->id);
	
	printf("Nhap ten: ");
	gets(pro->name);
	
	printf("Nhap nha san xuat: ");
	gets(pro->nhasx);
	
	printf("Nhap nam san xuat: ");
	fflush(stdin);
	scanf("%d", &pro->yearsx);
	
	fflush(stdin);
	printf("Nhap ngay het han: ");
	gets(pro->ngayhethan);
	
	fflush(stdin);
	printf("Nhap vao so luong: ");
	scanf("%d",&pro->quantity);
	
	printf("Nhap vao gia ban: ");
	scanf("%f",&pro->price);
	
}

void insertToArray(Product arrProd[], int n){
	for(int i=0; i<n; i++){
		addElement(&arrProd[i]);
	}
}

void showOneElement(Product pro){
	printf("\nID: %s",pro.id);
	printf("\nName: %s",pro.name);
	printf("\nNha san xuat: %s",pro.nhasx);
	printf("\nNam san xuat: %d", pro.yearsx);
	printf("\nNgay het han: %s", pro.ngayhethan);
	printf("\nSo luong: %d", pro.quantity);
	printf("\nGia ban: $%.2f", pro.price);
}

void showListElement(Product arrProd[], int n){
	for(int i=0; i<n; i++){
		printf("\n");
		showOneElement(arrProd[i]);
	}
}

void Swap(Product *p1, Product *p2)
{
    Product temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sortAcesdingByProName(Product arrProd[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - 1 - i; j++)
        {
            if (strcmp(arrProd[j].name, arrProd[j + 1].name) > 0)
            {
                Swap(&arrProd[j], &arrProd[j + 1]);
            }
        }
    }
}

void sortDescendingByPrice(Product arrProd[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - 1 - i; j++)
        {
            if (arrProd[j].price < arrProd[j + 1].price)
            {
                Swap(&arrProd[j], &arrProd[j + 1]);
            }
        }
    }
}

void searchByPriceRange(Product arrProd[], int n, float minPrice, float maxPrice)
{
    int count = 0;
    printf("\n\tDanh sach san pham nam trong khoang %.2f den %.2f: ", minPrice, maxPrice);
    for (int i = 0; i < n; i++)
    {
        if (arrProd[i].price >= minPrice && arrProd[i].price <= maxPrice)
        {
            printf("\n");
            showOneElement(arrProd[i]);
            count++;
        }
    }
    if (count == 0)
    {
        printf("Khong co san pham nao nam trong khoang %.2f den %.2f", minPrice, maxPrice);
    }
}

void ShowMenus()
{
    printf("\n ================ MENU ================ \n");
    printf("1. Them 1 san pham vao danh sach(danh sach dang mang) \n");
    printf("2. Hien thi tat ca cac san pham dang co trong danh sach \n");
    printf("3. Sap xep va hien thi danh sach tang dan theo ten san pham \n");
    printf("4. Sap xep va hien thi danh sach giam dan theo gia ban \n");
    printf("5. Tim kiem cac san pham theo khoang gia tu minPrice den maxPrice \n");
}


int main(){
	Product listProd[100];
	int choice,n;
	 float minPrice, maxPrice;
	do{
		fflush(stdin);
		ShowMenus();
		printf("\nYour Choice is: ");
		scanf("%d",&choice);
		fflush(stdin);
		
		switch(choice){
			case 1:
				printf("\n\tThem 1 san pham vao danh sach");
				printf("\n\tNhap so phan tu cua mang: ");
				scanf("%d",&n);
				insertToArray(listProd,n);
				break;
			case 2:
				printf("\n\t2. Hien thi tat ca cac san pham dang co trong danh sach \n");
	            printf("\n\tDanh sach du lieu: \n");
	            showListElement(listProd, n);
				break;
			case 3:
	            printf("\n\t3. Sap xep va hien thi danh sach tang dan theo ten san pham  \n");
	            printf("\n\tDanh sach du lieu sau khi sap xep theo ten: \n");
	            sortAcesdingByProName(listProd, n);
	            showListElement(listProd, n);
	            break;
	        case 4:
	            printf("\n\t4. Sap xep va hien thi danh sach giam dan theo gia ban \n");
	            printf("\n\tDanh sach du lieu sau khi sap xep theo gia ban: \n");
	            sortDescendingByPrice(listProd, n);
	            showListElement(listProd, n);
	            break;

	        case 5:
	            printf("\n\t5. Tim kiem cac san pham theo khoang gia tu minPrice den maxPrice \n");
	            printf("\n\tNhap khoang gia dau: ");
	
	            fflush(stdin);
	            scanf("%f", &minPrice);
	            printf("\n\tNhap khoang gia cuoi: ");
	            scanf("%f", &maxPrice);
	            searchByPriceRange(listProd, n, minPrice, maxPrice);
	            break;
			
			default:
				printf("\n\tInvalid choice");
				break;
		}
	}while(1==1);
	return 0;
}

