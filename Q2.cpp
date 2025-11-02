#include <stdio.h>
#include <string.h>

char name[50];
char cnic[20];
int stock1 = 50, price1 = 100;
int stock2 = 10, price2 = 200;
int stock3 = 20, price3 = 300;
int stock4 = 8,  price4 = 150;
int totalBill = 0;

void customerinformation() {
	printf("Enter the name of customer : ");
	scanf("%s", name); 
	printf("Enter the CNIC number : ");
	scanf("%s", cnic);
}

void displayinventory() {
	int codes[] = {1,2,3,4};
	int stock[] = {50,10,20,8};
	int price[] = {100,200,300,150};
	int i;
	printf("\n   Product Code |  Quantity in Stock | Price per Product\n");
	printf("   -----------------------------------------------\n");
	for(i=0;i<4;i++) {
		printf("      %03d       |         %d         |        %d\n",codes[i], stock[i] ,price[i]);
	}
}

void updateinventory() {
	int n,i,code;
	printf("How many items you purchased : ");
	scanf("%d",&n);

	for(i=0;i<n;i++) {
		printf("Enter the product code you purchased : ");
		scanf("%d",&code);

		if(code == 1) {
			stock1--;
		} else if(code == 2) {
			stock2--;
		} else if(code == 3) {
			stock3--;
		} else if(code == 4) {
			stock4--;
		} else {
			printf("Invalid Code\n");
		}
	}

	printf("\nUpdated Stock:\n");
	printf("001 item stock is : %d\n",stock1);
	printf("002 item stock is : %d\n",stock2);
	printf("003 item stock is : %d\n",stock3);
	printf("004 item stock is : %d\n",stock4);
}

void additemtocart() {
	int total=0;
	int code,price=0,quantity;  
	printf("Enter Product Code : ");
	scanf("%d",&code);
	printf("Enter Quantity : ");
	scanf("%d",&quantity);

	if(code == 1) {
		price = 100;
	} else if(code == 2) {
		price = 200;
	} else if(code == 3) {
		price = 300;
	} else if(code == 4) {
		price = 150;
	} else { 
		printf("Invalid Code\n"); 
		return;
	}

	total = price * quantity; 
	totalBill += total;
	printf("Product code %d Quantity is %d Price is : %d Rupees\n",code,quantity,total);
}

void displaytotalbill() {
	char promo[20];
	printf("\nYour Total Bill is : %d Rupees\n",totalBill);
	printf("Do you have a Promo Code? (Enter code or 'no'): ");
	scanf("%s",promo);

	if(strcmp(promo,"Eid2025")==0) { // sting variable to store user input
		int discounted = totalBill - (totalBill * 0.25);
		printf("Promo Applied! You got 25%% off.\n");
		printf("Your Discounted Bill is : %d Rupees\n",discounted);
	} else {
		printf("No Promo Applied. Final Bill : %d Rupees\n",totalBill);
	}
}

void showinvoice() {
	printf("\n----------- INVOICE -----------\n");
	printf("Customer Name : %s\n",name);
	printf("Customer CNIC : %s\n",cnic);
	printf("Total Bill    : %d\n",totalBill);
	printf("-------------------------------\n");
}

int main() {
	int want;
	printf("--- Welcome TO The Pakistan Biggest Super Market ----\n");
	printf("Sir What You Want :\n");

	do { 
		printf("\n1. Customer Information\n2. Display Inventory\n3. Update Inventory\n4. Add Item To Cart\n5. Display Total Bill\n6. Show Invoice\n7. Exit\n"); 
		printf("\nEnter Choice : ");
		scanf("%d",&want);

		switch(want) {
			case 1: customerinformation(); break;
			case 2: displayinventory(); break;
			case 3: updateinventory(); break;
			case 4: additemtocart(); break;
			case 5: displaytotalbill(); break;
			case 6: showinvoice(); break;
			case 7: printf("Thank You:\nGood Bye\n"); break;
			default : printf("Invalid Choice\n"); break;
		}
	} while(want!=7);

	return 0;
}

