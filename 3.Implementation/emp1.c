// C program for the above approach
/**
 * @file emp1.c
 * @author your name (Aishwarya Beelagi)
 * @brief 
 * @version 0.1
 * @date 2021-09-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

// Structure of the employee
struct emp {
	char name[50];
	float salary;
	int age;
	int id;
};
struct emp e1;

// size of the structure
long int size = sizeof(e1);

// In the start coordinates
// will be 0, 0
COORD cord = { 0, 0 };
void gotoxy(int x, int y)
{
	cord.X = x;
	cord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		cord);
}

// function to set the
// coordinates


FILE *fp, *ft;

// Function to add the records


// Function to delete the records
void deleterecord()
{
	
}


// Function to display the record
void displayrecord()
{
	
}

// Function to modify the record
void modifyrecord()
{
	
}


int main()
{
	int choice;
	char empname[50];
	char another = 'y';

	// opening the file
	fp = fopen("data.txt", "rb+");

	// showing error if file is
	// unable to open.
	if (fp == NULL) {
		fp = fopen("data.txt", "wb+");
		if (fp == NULL) {
			printf("\nCannot open file...");
			exit(1);
		}
	}

	
	
	printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~"
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
		"~~~~~");
	printf("\n\t\t\t\t==================="
		"============================="
		"=====");
	printf("\n\t\t\t\t[|:::>:::>:::>::> "
		"EMPLOYEE RECORD <::<:::<:::"
		"<:::|]\t");
	printf("\n\t\t\t\t==================="
		"============================="
		"=====");
	
	

	while (1) {
		// Clearing console and asking the
		// user for input
		system("cls");
		gotoxy(30, 10);
		printf("\n1. ADD RECORD\n");
		gotoxy(30, 12);
		printf("\n2. DELETE RECORD\n");
		gotoxy(30, 14);
		printf("\n3. DISPLAY RECORDS\n");
		gotoxy(30, 16);
		printf("\n4. MODIFY RECORD\n");
		gotoxy(30, 18);
		printf("\n5. EXIT\n");
		gotoxy(30, 20);
		printf("\nENTER YOUR CHOICE...\n");
		fflush(stdin);
		scanf("%d", &choice);

		// Switch Case
		switch (choice) {
		case 1:

			// Add the records
			system("cls");
	fseek(fp, 0, SEEK_END);
	//char another = 'y';

	while (another == 'y') {
		printf("\nEnter Name : ");
		scanf("%s", e1.name);

		printf("\nEnter Age : ");
		scanf("%d", &e1.age);

		printf("\nEnter Salary : ");
		scanf("%f", &e1.salary);

		printf("\nEnter EMP-ID : ");
		scanf("%d", &e1.id);

		fwrite(&e1, size, 1, fp);

		printf("\nWant to add another"
			" record (Y/N) : ");
		fflush(stdin);

		scanf("%c", &another);
	}
			break;

		case 2:// Delete the records
		    system("cls");
	//char empname[50];
	//char another = 'y';

	while (another == 'y') {
		printf("\nEnter employee "
			"name to delete : ");
		scanf("%s", empname);

		ft = fopen("temp.txt", "wb");
		rewind(fp);

		while (fread(&e1, size,
					1, fp)
			== 1) {
			if (strcmp(e1.name,
					empname)
				!= 0)
				fwrite(&e1, size, 1, ft);
		}

		fclose(fp);
		fclose(ft);
		remove("data.txt");
		rename("temp.txt", "data.txt");
		fp = fopen("data.txt", "rb+");

		printf("\nWant to delete another"
			" record (Y/N) :");
		fflush(stdin);
		another = getchar();
	}
			break;

		case 3:

			// Display the records
			system("cls");

	// sets pointer to start
	// of the file
	rewind(fp);

	printf("\n========================="
		"==========================="
		"======");
	printf("\nNAME\t\tAGE\t\tSALARY\t\t"
		"\tID\n",
		e1.name, e1.age,
		e1.salary, e1.id);
	printf("==========================="
		"==========================="
		"====\n");

	while (fread(&e1, size, 1, fp) == 1)
		printf("\n%s\t\t%d\t\t%.2f\t%10d",
			e1.name, e1.age, e1.salary, e1.id);

	printf("\n\n\n\t");
	system("pause");
			break;

		case 4:

			// Modify the records
			system("cls");
	//char empname[50];
	//char another = 'y';

	while (another == 'y') {
		printf("\nEnter employee name"
			" to modify : ");
		scanf("%s", empname);

		rewind(fp);

		// While File is open
		while (fread(&e1, size, 1, fp) == 1) {
			// Compare the employee name
			// with ename
			if (strcmp(e1.name, empname) == 0) {
				printf("\nEnter new name:");
				scanf("%s", e1.name);
				printf("\nEnter new age :");
				scanf("%d", &e1.age);
				printf("\nEnter new salary :");
				scanf("%f", &e1.salary);
				printf("\nEnter new EMP-ID :");
				scanf("%d", &e1.id);

				fseek(fp, -size, SEEK_CUR);
				fwrite(&e1, size, 1, fp);
				break;
			}
		}

		// Ask for modifying another record
		printf("\nWant to modify another"
			" record (Y/N) :");
		fflush(stdin);
		scanf("%c", &another);
	}
			break;

		case 5:
			fclose(fp);
			exit(0);
			break;

		default:
			printf("\nINVALID CHOICE...\n");
		}
	}

	return 0;
}
