#include "datatype.h"
//nguyen mau ham

int miniChoice(int mini);
int information(char info[]);
int length(char info[], int len);

//book
void printBook(struct Book book[], int size);
int price(char number[]);
int titleDuped(struct Book book[], int n, char title[]);
void saveBooks(struct Book book[], int *n);
void loadBooks(struct Book book[], int *n);
void addBook(struct Book book[], int *n);
void editBook(struct Book book[], int n);
void deleteBook(struct Book book[], int *n);
void sortBookDesc(struct Book book[], int n);
void sortBookAsc(struct Book book[], int n);
void searchBookName(struct Book book[], int *n);

//member
int phone(char number[]);
int lockOrUnlock(struct Customer member[], int m);
void saveMembers(struct Customer member[], int *m);
void loadMembers(struct Customer member[], int *m);
void printMember(struct Customer member[], int size);
void addMember(struct Customer member[], int *m);
void editMember(struct Customer member[], int m);
void searchMemberName(struct Customer member[], int *m);
