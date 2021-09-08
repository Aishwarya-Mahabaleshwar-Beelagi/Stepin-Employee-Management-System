#include "emp.h"
void Add_record()
{
	system("cls");
	fseek(fp, 0, SEEK_END);
	char another = 'y';

	while (another == 'y') {
		printf("\nEnter Name : ");
		scanf("%s", e1.name);

		printf("\nEnter Age : ");
		scanf("%d", &e1.age);

		printf("\nEnter Salary : ");
		scanf("%f", &e1.salary);

		printf("\nEnter EMP-ID : ");
		scanf("%d", &e1.id);

		fwrite(&e, size, 1, fp);

		printf("\nWant to add another"
			" record (Y/N) : ");
		fflush(stdin);

		scanf("%c", &another);
	}
}

// Function to delete the records
void Delete_record()
{
	system("cls");
	char empname[50];
	char another = 'y';

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
}

// Function to display the record
void Display_record()
{
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

	while (fread(&e, size, 1, fp) == 1)
		printf("\n%s\t\t%d\t\t%.2f\t%10d",
			e1.name, e1.age, e1.salary, e1.id);

	printf("\n\n\n\t");
	system("pause");
}

// Function to modify the record
void Modify_record()
{
	system("cls");
	char empname[50];
	char another = 'y';

	while (another == 'y') {
		printf("\nEnter employee name"
			" to modify : ");
		scanf("%s", empname);

		rewind(fp);

		// While File is open
		while (fread(&e, size, 1, fp) == 1) {
			// Compare the employee name
			// with ename
			if (strcmp(e.name, empname) == 0) {
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
}
