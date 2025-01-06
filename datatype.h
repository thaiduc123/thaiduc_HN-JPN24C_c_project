#include <stdbool.h>
//kieu du lieu

struct Date{
	int month, day, year;
};

struct Book{
	int bookId;
	char title[50];
	char price[20];
	char author[50];
	char category[50];
	struct Date publication;
};

struct Customer{
	int memberId;
	char name[50];
	char phone[20];
	int status;
	//struct Book borrowedBooks[];
};

