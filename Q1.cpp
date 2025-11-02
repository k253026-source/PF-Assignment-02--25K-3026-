#include <stdio.h>
int i;
    void addnewbook(int isbns[100], char title[100][50], float prices[100],int quantities[100]); 
	void processSale(int isbns[100], char title[100][50],float prices[100],int quantities[100]);
    void lowStockReport(int isbns[100], char title[100][50], float prices[100],int quantities[100]);
    
	int Total_Books=0;	
	
   		int main() {
   			int menu;
   			int isbns[100];
   			char title[100][50];
   			float prices[100];                
   			int quantities[100];
   			
   			printf("---------Librery Inertes System---------\n");
   			
   			do{
   				printf("\n1.Add New Book:\n2.Process For Sale:\n3.Low Stock Report:\n4.Exit:\n");
   				printf("Choose Option :");
   				scanf("%d",&menu);
   				switch(menu) {
   					case 1: addnewbook(isbns, title, prices, quantities); break;
   					case 2: processSale(isbns, title, prices, quantities); break;
   					case 3: lowStockReport(isbns, title, prices, quantities); break;
					case 4: printf("Thank You ,Good Bye:"); break;
					default: printf("Invalid Choice"); break; 
			    } 
   	    	} while(menu!=4);
   		}
   		
     	     void addnewbook(int isbns[100], char title[100][50], float prices[100], int quantities[100]) {
     	     	int index=Total_Books,j;
     	     	
     	     	printf("Enter ISBNS of Book :");
     	     	scanf("%d",&isbns[index]);
     	     	for(j=0;j<Total_Books;j++) {
     	     		if(isbns[j]==isbns[index]) {
     	     			printf("Book with this ISBN is already exist\n");
     	     			return;
					  }
     	     		
				  }
     	     	getchar();
     	     	printf("Enter Title of Book :");
     	     	scanf("%[^\n]",title[index]);
     	     	printf("Enter the Price of Book :");
     	     	scanf("%f",&prices[index]);
     	     	printf("Enter the Quantity of Book :");
     	     	scanf("%d",&quantities[index]);
     	     	
     	     	Total_Books++;
     	     	printf("Book Added Successfully\n");
     	     	printf("Total Books :%d\n", Total_Books);
			  }
     	    
     	    void processSale(int isbns[100], char title[100][50], float prices[100], int quantities[100]) {
     	    	int isbn,qty,i,found=0;
				 printf("Enter ISBN to sell :");
				 scanf("%d",&isbn);
				 
				 for(i=0;i<Total_Books;i++)	{
				 	if(isbns[i]==isbn) {
				 		found = 1;
				 		printf("Enter the Quantity to sell");
				 		scanf("%d",&qty);
				 		
				 	if(qty<=quantities[i]) {
				 		quantities[i] = quantities[i] - qty;
				 	printf("Successfully Sale Remaining Stock is :%d",quantities[i]);	
					 } else {
					 	printf("NOt Enough Stock");
					 } break;
					 }
					 
				 } if(!found) printf("Book is Not Found");
			 }
     	    void lowStockReport(int isbns[100], char title[100][50], float prices[100], int quantities[100]) {
     	    	int i,found=0;
     	    	printf("\nLow Stock Report\n");
     	    	
     	    for(i=0;i<Total_Books;i++) {
     	    	if(quantities[i]<5) {
     	    	printf("ISBN :%d | Title :%s | Quantity :%d\n",isbns[i],title[i],quantities[i]);
     	            found = 1;
				 }
			 
			 }	if(!found) printf("No LOw Stock Books.\n");
			 }
			 
			 
