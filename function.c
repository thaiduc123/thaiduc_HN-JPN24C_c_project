#include "function.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//logic ham

	//BOOK

//kiem tra thong tin
int information(char info[]){
    return strlen(info)>0;
}

//kiem tra do dai
int length(char info[], int len){
    return strlen(info)<=len;
}

//kiem tra ten 
int titleDuped(struct Book book[], int n, char title[]){
	int i;
    for (i=0; i<n; i++){
        if (strlen(title)>0 && strcmp(book[i].title, title)==0){
            return 1;
        }
    }
    return 0;
}

int titleLocationDuped(struct Book book[], int n, char title[], int location){
	int i;
    for (i=0; i<n; i++){
        if (i!=location && strlen(title)>0 && strcmp(book[i].title, title)==0){
            return 1;
        }
    }
    return 0;
}

//kiem tra tien
int price(char number[]){
    if (strlen(number)==0){
        return 0;
    }
    int i;
    for (i=0; number[i] != '\0'; i++){
        if (!isdigit(number[i])){
            return 0;
        }
    }
    int price;
    sscanf(number, "%d", &price);
    if (price<0){
        return 0;
    }
    return 1;
}

//mini choice
int miniChoice(int mini){
	loop:
	printf("\nGo back (1) or Exit (0): ");
	scanf("%d", &mini);
	if (mini==1){
		system("cls");
		return;
	} else if (mini==0){
		printf("\n\t\t----Good Bye----");
		exit(0);
	} else {
		printf("\n\tYour input can not be processed, please try again!\n");
		goto loop;
	}
}

//in sach
void printBook(struct Book book[], int size){
	int i;
	printf("\t\t\t\t\t\t*****Book List:*****\n");
	printf("\n|========|=========================|=====================|====================|==================|==================|");
	printf("\n|   ID   |           NAME          |        PRICE        |       AUTHOR       |      GENRE       | Date Publication |");
	printf("\n|========|=========================|=====================|====================|==================|==================|");
	for(i=0; i<size; i++){
		printf("\n| %-6d | %-23s | %-19s | %-18s | %-16s | ", book[i].bookId,book[i].title,book[i].price, book[i].author, book[i].category);
		printf("%-3d/%-3d/%-8d |\n", book[i].publication.month, book[i].publication.day, book[i].publication.year);
		printf("|========|=========================|=====================|====================|==================|==================|");
	}
	printf("\n");
}

//luu du lieu
void saveBooks(struct Book book[], int *n){
	FILE *ptr=fopen("bookData.dat","wb");
	if(ptr==NULL){
		printf("\n\t\t\t$%^&*(*&) ERORR %%#^&$*(@)\n");
	}
	fwrite(book, sizeof(struct Book), *n, ptr);
	printf("\n\t\t--------Saving Complete--------\n");
	fclose(ptr);
}

//doc du lieu
void loadBooks(struct Book book[], int *n){
	FILE *ptr = fopen("bookData.dat", "rb");
	if(ptr==NULL){
		printf("\n\t\t\t$%^&*(*&) ERORR %%#^&$*(@)\n");
	}
	struct Book readBook[100];
	*n=fread(readBook,sizeof(struct Book),100,ptr);
	int i;
	for(i=0;i<*n;i++){
		book[i]=readBook[i];
	}
	fclose(ptr);
}

//them sach
void addBook(struct Book book[], int *n){
	getchar();
	book[*n].bookId= *n+1;
	do{
		printf("\n\t-Please enter book's name: ");
		fgets(book[*n].title, 50, stdin);
		book[*n].title[strcspn(book[*n].title, "\n")] = '\0';
		if (!information(book[*n].title)){
			printf("\n\tThis section is empty!\n");
		} else if(!length(book[*n].title, 50)){
			printf("\n\tThe name is too long!\n");
		} else if(titleDuped(book, *n, book[*n].title)){
			printf("\n\tBook already existed!\n");
		} else {
			break;
		}
	}while(1);
	do{
		printf("\n\t-Please enter price: ");
		scanf("%s", &book[*n].price);
		getchar();
		if (!price(book[*n].price)){
			printf("\n\tPrice invalid!\n");
		} else {
			break;
		}
	}while(1);
	do{
		printf("\n\t-Please enter author's name:");
		fgets(book[*n].author, 50, stdin);
		book[*n].author[strcspn(book[*n].author, "\n")] = '\0';
		if (!information(book[*n].author)){
			printf("\n\tThis section is empty!\n");
		} else if (!length(book[*n].author, 50)){
			printf("\n\tThe name is too long!\n");	
		} else {
			break;
		}
	}while(1);
	do{
		printf("\n\t-Please enter category: ");
		fgets(book[*n].category, 50, stdin);
		book[*n].category[strcspn(book[*n].category, "\n")] = '\0';
		if (!information(book[*n].category)){
			printf("\n\tThis section is empty!\n");
		} else if (!length(book[*n].category, 50)){
			printf("\n\tThe name is too long!\n");	
		} else {
			break;
		}
	}while(1);
	printf("\n\t\t* Date * \n");
	do{
		printf("\n\t-Month: ");
		scanf("%d", &book[*n].publication.month);
		if (book[*n].publication.month<0 || book[*n].publication.month>12){
			printf("\n\tDate invalid!\n");
		} else {
			break;
		}
	}while(1);
	do{
		printf("\n\t-Day: ");
		scanf("%d", &book[*n].publication.day);
		if (book[*n].publication.day<0 || book[*n].publication.day>31){
			printf("\n\tDate invalid!\n");
		} else {
			break;
		}
	}while(1);
	do{
		printf("\n\t-Year: ");
		scanf("%d", &book[*n].publication.year);
		if (book[*n].publication.year<0){
			printf("\n\tDate invalid!\n");
		} else {
			break;
		}
	}while(1);
	printf("\n\t\t--NEW BOOK HAS BEEN ADDED!!--");
	(*n)++;
}

//sua sach
void editBook(struct Book book[], int n){
	int position;
	printf("\n\t-Please enter a position to edit:");
	scanf("%d", &position);
	int i;
	int findIndex=-1;
	for(i=0;i<n;i++){
		if(book[i].bookId==position){
			findIndex=i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("\n\t   #### NO BOOKS AVAILABLE ####\n");
	}else{
		getchar();
		printf("\n\t\t--[Current book's information]--");
		printf("\n\t------------------------------------");
		printf("\n\tTitle: %s", book[position-1].title);
		printf("\n\tPrice: %s", book[position-1].price);
		printf("\n\tAuthor: %s", book[position-1].author);
		printf("\n\tGenre: %s", book[position-1].category);
		printf("\n");
		printf("\t\tDate publication: \n");
		printf("\n\tMonth: %d", book[position-1].publication.month);
		printf("\n\tDay: %d", book[position-1].publication.day);
		printf("\n\tYear: %d", book[position-1].publication.year);
		printf("\n\t\t----[New book's information]----");
		do{
			printf("\n\t-Please enter book's name: ");
			fgets(book[findIndex].title, 50, stdin);
			book[findIndex].title[strcspn(book[findIndex].title, "\n")] = '\0';
			if (!information(book[findIndex].title)){
				printf("\n\tThis section is empty!\n");
			} else if(!length(book[findIndex].title, 50)){
				printf("\n\tThe name is too long!\n");
			} else if(titleLocationDuped(book, n, book[findIndex].title, findIndex)){
				printf("\n\tBook already existed!\n");
			} else {
				break;
			} 
		}while(1);
		do{
			printf("\n\t-Please enter price: ");
			scanf("%s", &book[findIndex].price);
			getchar();
			if (!price(book[findIndex].price)){
			printf("\n\tPrice invalid!\n");
			} else {
				break;
			}
		}while(1);
		do{
			printf("\n\t-Please enter author's name:");
			fgets(book[findIndex].author, 50, stdin);
			book[findIndex].author[strcspn(book[findIndex].author, "\n")] = '\0';
			if (!information(book[findIndex].author)){
			printf("\n\tThis section is empty!\n");
			} else if (!length(book[findIndex].author, 50)){
				printf("\n\tThe name is too long!\n");	
			} else {
				break;
			}
		}while(1);
		do{
			printf("\n\t-Please enter category: ");
			fgets(book[findIndex].category, 50, stdin);
			book[findIndex].category[strcspn(book[findIndex].category, "\n")] = '\0';
			if (!information(book[findIndex].category)){
				printf("\n\tThis section is empty!\n");
			} else if (!length(book[findIndex].category, 50)){
				printf("\n\tThe name is too long!\n");	
			} else {
				break;
			}
		}while(1);
		printf("\n\t\t* Date * \n");
		do{
			printf("\n\t-Month: ");
			scanf("%d", &book[findIndex].publication.month);
			if (book[findIndex].publication.month<0 || book[findIndex].publication.month>12){
				printf("\n\tDate invalid!\n");
			} else {
				break;
			}
		}while(1);
		do{
			printf("\n\t-Day: ");
			scanf("%d", &book[findIndex].publication.day);
			if (book[findIndex].publication.day<0 || book[findIndex].publication.day>31){
				printf("\n\tDate invalid!\n");
			} else {
				break;
			}
		}while(1);
		do{
			printf("\n\t-Year: ");
			scanf("%d", &book[findIndex].publication.year);
			if (book[findIndex].publication.year<0){
				printf("\n\tDate invalid!\n");
			} else {
				break;
			}
		}while(1);
		printf("\n\t\t*****Completed Editing*****\n");
	}
}

//xoa sach
void deleteBook(struct Book book[], int *n){
	int position;
	printf("\n\t-Please enter id to delete: ");
	scanf("%d", &position);
	int i;
	int findIndex=-1;
	for (i=0; i<*n; i++){
		if (book[i].bookId==position){
			findIndex=i;
			break;
		}
	}
	if (findIndex==-1){
		printf("\n\t   #### NO BOOKS AVAILABLE ####\n");
	} else {
		for (i=findIndex; i<*n; i++){
			book[i]=book[i+1];
			book[i].bookId--;
		}
		(*n)--;
		printf("\n\t\t*****Completed Deleting*****\n");
	}
}

//sap xep tang dan
void sortBookAsc(struct Book book[], int n){
	int i,j;
	for (i=0; i<n-1; i++){
		for( j=0; j<n-i-1; j++){
			if (book[j].price>book[j+1].price){
				struct Book temp = book[j];
				book[j] = book[j+1];
				book[j+1] = temp;
			}
		}
	}
	system("cls");
	printf("\n\t\t*****Completed Sorting*****\n");
	printBook(book, n);
}

//sap xep giam dan
void sortBookDesc(struct Book book[], int n){
	int i,j;
    for (i=0; i<n-1; i++){
        for (j=0; j<n-i-1; j++){
            if (book[j].price < book[j+1].price){
                struct Book temp = book[j];
                book[j] = book[j+1];
                book[j+1] = temp;
            }
        }
    }
    system("cls");
	printf("\n\t\t*****Completed Sorting*****\n");
	printBook(book, n);
}

//tim sach
void searchBookName(struct Book book[], int *n){
	char search[50];
	int found=0;
	int i;
	getchar();
	printf("\n\t-Please enter a book's name: ");
	fgets(search,50,stdin);
	search[strcspn(search, "\n")]='\0';
		for (i=0; i<*n; i++){
		if (strstr(book[i].title, search)!= NULL){
			printf("\n|========|=========================|=====================|====================|==================|==================|");
			printf("\n|   ID   |           NAME          |        PRICE        |       AUTHOR       |      GENRE       | Date Publication |");
			printf("\n|========|=========================|=====================|====================|==================|==================|");
			break;
		}
	}
	for (i=0; i<*n; i++){
		if (strstr(book[i].title, search)!= NULL){
			printf("\n| %-6d | %-23s | %-19s | %-18s | %-16s | ", book[i].bookId,book[i].title,book[i].price, book[i].author, book[i].category);
			printf("%-3d/%-3d/%-8d |\n", book[i].publication.month, book[i].publication.day, book[i].publication.year);
			printf("|========|=========================|=====================|====================|==================|==================|");
			found++;
		}
	}
	if (found==0){
		printf("\n\t\t\tNO BOOK AVAILABLE!\n");
	}	
}


	//MEMBER

//kiem tra so dien thoai
int phone(char number[]){
    if (strlen(number)<10){
        return 1;
    }
    int i;
    for (i=0; number[i] != '\0'; i++){
        if (!isdigit(number[i])){
            return 0;
        }
    }
    long long  phone;
    sscanf(number, "%lld", &phone);
    if (phone<0){
        return 0;
    }
    return 1;
}

//luu du lieu
void saveMembers(struct Customer member[], int *m){
	FILE *ptr=fopen("memberData.dat","wb");
	if(ptr==NULL){
		printf("\n\t\t\t$%^&*(*&) ERORR %%#^&$*(@)\n");
	}
	fwrite(member, sizeof(struct Customer), *m, ptr);
	printf("\n\t\t--------Saving Complete--------\n");
	fclose(ptr);
}

//doc du lieu
void loadMembers(struct Customer member[], int *m){
	FILE *ptr = fopen("memberData.dat", "rb");
	if(ptr==NULL){
		printf("\n\t\t\t$%^&*(*&) ERORR %%#^&$*(@)\n");
	}
	struct Customer readMember[100];
	*m=fread(readMember,sizeof(struct Customer),100,ptr);
	int i;
	for(i=0;i<*m;i++){
		member[i]=readMember[i];
	}
	fclose(ptr);
}

//in khach hang
void printMember(struct Customer member[], int size){
	int i;
	printf("\t\t\t\t\t\t*****Member List:*****\n");
	printf("\n|========|=========================|=====================|===============================|");
	printf("\n|   ID   |           NAME          |        PHONE        |  STATUS (1=locked,0=unlocked) |");
	printf("\n|========|=========================|=====================|===============================|");
	for(i=0; i<size; i++){
		printf("\n| %-6d | %-23s | %-19s | %-29d |", member[i].memberId,member[i].name,member[i].phone, member[i].status);
		printf("\n|========|=========================|=====================|===============================|");
	}
	printf("\n");
}

//them khach hang
void addMember(struct Customer member[], int *m){
	getchar();
	member[*m].memberId= *m+1;
	do{
		printf("\n\t-Please enter member's name: ");
		fgets(member[*m].name, 50, stdin);
		member[*m].name[strcspn(member[*m].name, "\n")] = '\0';
		if (!information(member[*m].name)){
			printf("\n\tThis section is empty!\n");
		} else if(!length(member[*m].name, 50)){
			printf("\n\tThe name is too long!\n");
		} else {
			break;
		}
	}while(1);
	do{
		printf("\n\t-Please enter phone: ");
		scanf("%s", &member[*m].phone);
		getchar();
		if (!phone(member[*m].phone)){
			printf("\n\tPhone invalid!\n");
		} else {
			break;
		}
	}while(1);
	printf("\n\t\t--NEW MEMBER HAS BEEN ADDED!!--");
	(*m)++;
}

//sua khach hang
void editMember(struct Customer member[], int m){
	int position;
	printf("\n\t-Please enter a position to edit:");
	scanf("%d", &position);
	int i;
	int findIndex=-1;
	for(i=0;i<m;i++){
		if(member[i].memberId==position){
			findIndex=i;
			break;
		}
	}
	if(findIndex==-1){
		printf("\n\t   #### NO MEMBERS AVAILABLE ####\n");
	} else if (member[position-1].status==1){
		printf("\n\tThis member has been looked!");
	} else {
		getchar();
		printf("\n\t\t--[Current member's information]--");
		printf("\n\t------------------------------------");
		printf("\n\tName: %s", member[position-1].name);
		printf("\n\tPhone: %s", member[position-1].phone);
		printf("\n");
		printf("\n\t\t----[New member's information]----");
		do{
			printf("\n\t-Please enter member's name: ");
			fgets(member[findIndex].name, 50, stdin);
			member[findIndex].name[strcspn(member[findIndex].name, "\n")] = '\0';
			if (!information(member[findIndex].name)){
				printf("\n\tThis section is empty!\n");
			} else if(!length(member[findIndex].name, 50)){
				printf("\n\tThe name is too long!\n");
			} else {
				break;
			} 
		}while(1);
		do{
			printf("\n\t-Please enter phone: ");
			scanf("%s", &member[findIndex].phone);
			getchar();
			if (!phone(member[findIndex].phone)){
				printf("\n\tPhone invalid!\n");
			} else {
				break;
			}
		}while(1);
		printf("\n\t\t*****Completed Editing*****\n");
	}
}

//khoa hoac mo khoa
int lockOrUnlock(struct Customer member[], int m){
	int position;
	printf("\n\t-Please enter a position to lock/unlock:");
	scanf("%d", &position);
	int i;
	int findIndex=-1;
	for(i=0;i<m;i++){
		if(member[i].memberId==position){
			findIndex=i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("\n\t   #### NO MEMBERS AVAILABLE ####\n");
	}else if (member[position-1].status==0){
		member[position-1].status=1;
		printf("\n\t\tMember has been locked!\n");
    } else {
        member[position-1].status=0;
        printf("\n\t\tMember has been unlocked!\n");
    }
}

//tim kiem khach hang
void searchMemberName(struct Customer member[], int *m){
	char search[50];
	int found=0;
	int i;
	getchar();
	printf("\n\t-Please enter member's name: ");
	fgets(search,50,stdin);
	search[strcspn(search, "\n")]='\0';
	for (i=0; i<*m; i++){
		if (strstr(member[i].name, search)!= NULL){
			printf("\n|========|=========================|=====================|===============================|");
			printf("\n|   ID   |           NAME          |        PHONE        |  STATUS (1=locked,0=unlocked) |");
			printf("\n|========|=========================|=====================|===============================|");
			break;
		}
	}
	for (i=0; i<*m; i++){
		if (strstr(member[i].name, search)!= NULL){
			printf("\n| %-6d | %-23s | %-19s | %-29d |", member[i].memberId,member[i].name,member[i].phone, member[i].status);
			printf("\n|========|=========================|=====================|===============================|");
			found++;
		}
	}
	if (found==0){
		printf("\n\t\t\tNO MEMBER AVAILABLE!\n");
	}	
}
