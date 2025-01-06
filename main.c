#include <stdio.h>
#include <stdlib.h>
#include "function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Book books[100];
struct Customer members[100];
int n=0;
int m=0;
int main(int argc, char *argv[]) {
	int pick = 0;
	int choice=0;
	int subChoice=0;
	int sortChoice=0;
	do{
		main:
		printf("\n\t    LIBRARY MANAGEMENT SYSTEM\n");
		printf("\n\t==================================\n");
		printf("\n\t\tCHOOSE YOUR OPTION\n");
		printf("\t----------------------------------\n");
		printf("\t[-1-]: Book list\n");
		printf("\t[-2-]: Customer list\n");
		printf("\t[-0-]: Exit\n");
		printf("\tENTER YOUR CHOICE: ");
		scanf("%d", &pick);
		switch(pick){
			case 0: {
				system("cls");
				printf("\n\t\t----Come back soon----");
				break;
			}
			case 1: {
				system("cls");				
				do{
					menuBook:
					printf("\n\t\t****Books Management****");
					printf("\n\t==================================\n");
					printf("\n\t\tCHOOSE YOUR OPTION\n");
					printf("\t----------------------------------\n");
					printf("\t[*1*]: View book list\n");
					printf("\t[*2*]: Add book\n");
					printf("\t[*3*]: Edit book\n");
					printf("\t[*4*]: Remove book\n");
					printf("\t[*5*]: Sort books\n");
					printf("\t[*6*]: Search books\n");
					printf("\t[*0*]: Exit\n");
					printf("\t----------------------------------\n");
					printf("\tENTER YOUR CHOICE: ");
					scanf("%d", &choice);
					switch(choice){
						case 0: {
							system("cls");
							break;
						}
						case 1: {
							system("cls");
							printf("\n");
							loadBooks(books, &n);
							printBook(books, n);
							miniChoice(subChoice);
							break;
							}
						case 2: {
							system("cls");
							addBook(books, &n);
							saveBooks(books, &n);
							miniChoice(subChoice);
							break;
						}
						case 3: {
							system("cls");
							editBook(books, n);
							saveBooks(books, &n);
							miniChoice(subChoice);
							break;
						}
						case 4: {
							system("cls");
							deleteBook(books, &n);
							saveBooks(books, &n);
							miniChoice(subChoice);
							break;
						}
						case 5: {
							system("cls");
							int mini;
							do{
								printf("\n\t\tCHOOSE YOUR OPTION\n");
								printf("\n\t------------------------------");
								printf("\n\t(-1-): Ascending by price");
								printf("\n\t(-2-): Descending by price");
								printf("\n\t(-0-): Exit");
								printf("\n\t==============================");
								printf("\n\tENTER YOUR CHOICE: ");
								scanf("%d", &sortChoice);
								switch(sortChoice){
									case 1:{
										sortBookAsc(books, n);
										loop1:
										printf("\nGo back (1) or Exit (0): ");
										scanf("%d", &mini);
										if (mini==1){
											system("cls");
											goto menuBook;
										} else if (mini==0){
											printf("\n\t\t----Good Bye----");
											exit(0);
										} else {
											printf("\n\tYour input can not be processed, please try again!\n");
											goto loop1;
										}
										break;
									}
									case 2:{
										sortBookDesc(books, n);
										loop2:
										printf("\nGo back (1) or Exit (0): ");
										scanf("%d", &mini);
										if (mini==1){
											system("cls");
											goto menuBook;
										} else if (mini==0){
											printf("\n\t\t----Good Bye----");
											exit(0);
										} else {
											printf("\n\tYour input can not be processed, please try again!\n");
											goto loop2;
										}
										break;
									}
									case 0:{
										system("cls");
										break;
									}
								}
							}while(sortChoice!=0);
							break;
						}
						case 6:{
							system("cls");
							loadBooks(books, &n);
							searchBookName(books, &n);
							miniChoice(subChoice);
							break;
						}
					}
				}while(choice!=0);
				break;
			}
			case 2:{
				system("cls");
				do{
					printf("\n\t\t****Members Management****");
					printf("\n\t==================================\n");
					printf("\n\t\tCHOOSE YOUR OPTION\n");
					printf("\t----------------------------------\n");
					printf("\t[*1*]: View members list\n");
					printf("\t[*2*]: Add member\n");
					printf("\t[*3*]: Edit member's information\n");
					printf("\t[*4*]: Lock/Unlock member \n");
					printf("\t[*5*]: Search member\n");
					printf("\t[*0*]: Exit\n");
					printf("\t----------------------------------\n");
					printf("\tENTER YOUR CHOICE: ");
					scanf("%d", &choice);
					switch(choice){
						case 0: {
							system("cls");
							break;
						}
						case 1: {
							system("cls");
							loadMembers(members, &m);
							printMember(members, m);
							miniChoice(subChoice);
							break;
						}
						case 2: {
							system("cls");
							addMember(members, &m);
							saveMembers(members, &m);
							miniChoice(subChoice);
							break;
						}
						case 3: {
							system("cls");
							editMember(members, m);
							saveMembers(members, &m);
							miniChoice(subChoice);
							break;
						}
						case 4: {
							system("cls");
							lockOrUnlock(members, m);
							saveMembers(members, &m);
							miniChoice(subChoice);
							break;
						}
						case 5: {
							system("cls");
							loadMembers(members, &m);
							searchMemberName(members, &m);
							miniChoice(subChoice);
							break;
						}
					}
				}while(choice!=0);
				break;
			}
		}
	}while(pick!=0);
	return 0;
}

