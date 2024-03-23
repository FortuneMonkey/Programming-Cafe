#include "Header.h"


int main()
{
	menu();
	return 0;
}

void menu()
{
	system("cls");
	int option;

	printf("User Menu\n");
	printf("------------------\n");
	printf("1.Admin\n");
	printf("2.Tutor\n");
	printf("3.Student\n");
	printf("4.Exit\n");
	printf("------------------\n");

	printf("Enter your option = ");
	scanf("%d", &option);

	switch (option) {
	case 1:
		login_admin();
		break;
	case 2:
		tutor();
		break;
	case 3:
		student();
		break;
	case 4:
		printf("Exiting.....");
		exit(1);
	default:
		printf("Invalid Option !\n");
	}
}


void login_admin()
{
	system("cls");

	//Using admin key to access the menu
	char input[20];

	printf("Enter the admin key = ");
	scanf("%s", &input);

	//Admin key define in header file
	if (strcmp(input, ADMIN_KEY) == 0)
	{
		admin();
	}
	else
	{
		char input[10];

		printf("Invalid admin key. Access denied.\n");
		printf("Continue (Yes/No) ?");
		scanf("%s", &input);

		if (strcmp(input, "yes") == 0)
		{
			menu();
		}
		else
		{
			printf("Thank You");
			exit(1);
		}
	}
}



void admin()
{
	int option;
	system("cls");


	printf("Admin Menu\n");
	printf("------------------------------------------------------------------------------\n");
	printf("1.Registration of Tutor\n");
	printf("2.Adding New Programming Cafe Session\n");
	printf("3.Registration of Student\n");
	printf("4.Enrol Student in Session\n");
	printf("5.Listing of Programming Café Sessions and Participating Students\n");
	printf("6.Viewing Tutor or Student or Program Session Data\n");
	printf("7.Delete Data\n");
	printf("8.Back to Previous Page\n");
	printf("------------------------------------------------------------------------------\n");

	printf("Enter your option = ");
	scanf("%d", &option);



	//admin option
	switch (option) {
	case 1:
		registration_of_tutor();
		break;
	case 2:
		adding_new_programming_session();
		break;
	case 3:
		registration_of_student();
		break;
	case 4:
		enrol_student_session();
		break;
	case 5:
		listing_of_pc();
		break;
	case 6:
		viewing();
		break;
	case 7:
		delete_data();
		break;
	case 8:
		menu();
		break;
	default:
		printf("Invalid Option !\n");
	}
}


void registration_of_tutor()
{
	system("cls");
	FILE* fptr1;
	fptr1 = fopen("tutor_details.txt", "a+");

	if (fptr1 != NULL)
	{
		char loop[5] = "yes";
		while (strcmp(loop, "yes") == 0)
		{
			struct tutor td;

			printf("Enter TutorID = ");
			scanf("%s", td.tutorid);

			printf("Enter Tutor Name = ");
			scanf("%s", td.name);

			printf("Enter Tutor Title = ");
			scanf("%s", td.title);

			printf("Enter Password (8 characters) = ");
			scanf("%s", td.password);

			if (strlen(td.password) == 8)
			{

				fwrite(&td, sizeof(td), 1, fptr1);

				printf("\n----------------------------------------\n");
				printf("Continue(Yes/No) ? ");
				printf("\n----------------------------------------\n");
				scanf("%s", &loop);
				printf("----------------------------------------\n");

				if ((strcmp(loop, "yes") != 0))
				{
					fclose(fptr1);
					admin();
				}

			}
			else
			{
				printf("\n----------------------------------------\n");
				printf("Password is not valid");
				printf("\n----------------------------------------\n");
				printf("Continue(Yes/No) ? ");
				scanf("%s", &loop);
				printf("\n----------------------------------------\n");


				if ((strcmp(loop, "yes") != 0))
				{
					fclose(fptr1);
					admin();
				}

			}
		}

	}
	else
	{
		printf("File Open Unsuccessful");
	}
}



void adding_new_programming_session()
{
	system("cls");

	FILE* fptr2;
	fptr2 = fopen("program_details.txt", "a+");

	if (fptr2 != NULL)
	{
		char loop[5] = "yes";
		while (strcmp(loop, "yes") == 0)
		{
			struct program pd;

			printf("Enter Session Code = ");
			scanf("%s", pd.session_code);

			printf("Enter Title = ");
			scanf("%s", pd.title);

			printf("Enter Day = ");
			scanf("%s", pd.day);

			printf("Enter Start Time = ");
			scanf("%s", pd.start_time);

			printf("Enter Location = ");
			scanf("%s", pd.location);

			printf("Enter Tutor Code = ");
			scanf("%s", pd.tutor_code);


			fwrite(&pd, sizeof(pd), 1, fptr2);


			printf("\n--------------------------------\n");
			printf("Continue(Yes/No) ? ");
			scanf("%s", &loop);
			printf("\n--------------------------------\n");


			if ((strcmp(loop, "yes") != 0))
			{
				fclose(fptr2);
				admin();
			}
		}

	}
	else
	{
		printf("File Open Unsuccessful");
	}
}



void registration_of_student()
{
	system("cls");

	FILE* file;
	file = fopen("file.txt", "a+");

	if (file != NULL)
	{
		char loop[5] = "yes";
		while (strcmp(loop, "yes") == 0)
		{
			struct student s;

			printf("Enter TP Number = ");
			scanf("%s", s.tpnumber);

			printf("Enter Name = ");
			scanf("%s", s.student_name);

			printf("Enter Password (8 characters) = ");
			scanf("%s", s.password);

			if (strlen(s.password) == 8)
			{
				fwrite(&s, sizeof(s), 1, file);

				printf("\n-----------------------------\n");
				printf("Continue(Yes/No) ? ");
				printf("\n-----------------------------\n");
				scanf("%s", &loop);
				printf("-----------------------------\n");


				if ((strcmp(loop, "yes") != 0))
				{
					fclose(file);
					admin();
				}
			}
			else
			{
				printf("\n-----------------------------\n");
				printf("Password is not valid");
				printf("\n-----------------------------\n");
				printf("Continue(Yes/No) ? ");
				scanf("%s", &loop);
				printf("-----------------------------\n");

				if ((strcmp(loop, "yes") != 0))
				{
					fclose(file);
					admin();
				}
			}
		}
	}
	else
	{
		printf("Failed to open file !\n");
	}
}

void enrol_student_session()
{
	system("cls");

	FILE* file;
	FILE* file1;
	FILE* file2;

	int found = 0;
	int found1 = 0;


	char loop[5] = "yes";
	while (strcmp(loop, "yes") == 0)
	{
		file = fopen("enroll_session.txt", "a+");
		file1 = fopen("program_details.txt", "r");
		file2 = fopen("file.txt", "r");
		if (file == NULL || file1 == NULL)
		{
			printf("Failed to open file !\n");
		}
		else
		{
			struct enroll e;
			struct program p;
			struct student s;

			printf("TP Number : ");
			scanf("%s", e.tpnumber);

			while (fread(&s, sizeof(s), 1, file2)) {
				if (strcmp(s.tpnumber, e.tpnumber) == 0)
				{
					strcpy(e.name, s.student_name);
					found1 = 1;
				}

			}
			if (found1 != 1)
			{
				char choose[20];
				printf("\nInvalid TP Number ");
				printf("\n--------------------------------------");
				printf("\nGo to Delete Menu (yes or no) ? ");
				scanf("%s", &choose);

				if (strcmp(choose, "yes") == 0)
				{
					admin();
				}
				else
				{
					printf("Exiting.....");
				}

			}

			printf("Session Code : ");
			scanf("%s", e.session_code);


			while (fread(&p, sizeof(p), 1, file1)) {
				if (strcmp(p.session_code, e.session_code) == 0)
				{
					strcpy(e.tutor_code, p.tutor_code);
					strcpy(e.location, p.location);
					found = 1;
				}
			}
			if (found != 1)
			{
				admin();
			}
			fwrite(&e, sizeof(e), 1, file);

			printf("\n--------------------------\n");
			printf("Continue (Yes/No) ?");
			scanf("%s", &loop);
			printf("\n--------------------------\n");

			fclose(file);
			fclose(file1);

			if (strcmp(loop, "yes") != 0)
			{
				admin();
			}
		}
	}
}


void listing_of_pc()
{
	system("cls");
	FILE* file;
	file = fopen("enroll_session.txt", "r");

	if (file != NULL)
	{
		struct enroll e;

		printf("TP Number \t Student Name \t Session Code \t Tutor Code \t Location");
		printf("\n-----------------------------------------------------------------------------------------\n");

		while (fread(&e, sizeof(e), 1, file))
		{

			printf("%s \t %s \t    %s \t   %s \t          %s\n", e.tpnumber, e.name, e.session_code, e.tutor_code, e.location);

		}
		printf("\n-----------------------------------------------------------------------------------------\n");
		fclose(file);


		char loop[20];

		printf("\nGo to admin page (yes or no) ? ");
		scanf("%s", &loop);

		if (strcmp(loop, "yes") == 0)
		{
			admin();
		}
		else
		{
			printf("Exiting.....");
		}
	}
	else
	{
		printf("File Open Unsuccessful");
	}
}


void delete_data()
{
	system("cls");
	int option;

	printf("Delete Menu");
	printf("\n------------------------------\n");
	printf("1.Delete Tutor\n");
	printf("2.Delete Student\n");
	printf("3.Delete Program\n");
	printf("4.Delete Enrolled Student\n");
	printf("5.Back to Admin");
	printf("\n------------------------------\n");

	printf("Choose your option : ");
	scanf("%d", &option);

	switch (option)
	{
	case 1:
		delete_tutor();
		break;
	case 2:
		delete_student();
		break;
	case 3:
		delete_program();
		break;
	case 4:
		delete_enrolledstudent();
		break;
	case 5:
		admin();
		break;
	default:
		printf("Invalid Option !\n");

	}
}


void delete_tutor()
{
	system("cls");

	FILE* fp4;
	FILE* fp4temp;

	fp4 = fopen("tutor_details.txt", "a+");
	fp4temp = fopen("temp.txt", "w");

	struct tutor details;
	int choice, found = 0;
	char tutorID[5];
	char loop[20];

	//error handling
	if (fp4 == NULL || fp4temp == NULL) {
		printf("\n------------------------------------------------------------------------\n");
		printf("Sorry, but file can not be opened! Please restart the program.");
		printf("\n------------------------------------------------------------------------");
		exit(1);
	}
	printf("\n------------------------------------------------------------------------\n");
	printf("Delete Options");
	printf("\n------------------------------------------------------------------------\n");
	printf("1. Delete a specific tutor\n");
	printf("2. Delete everything\n");
	printf("3. Back to Delete Menu");
	printf("\n------------------------------------------------------------------------\n");
	printf("Enter a choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		printf("-------------------------------------------");
		printf("\nEnter tutorID: ");
		scanf("%s", &tutorID);
		printf("-------------------------------------------");
		while (fread(&details, sizeof(details), 1, fp4)) {
			if (strcmp(details.tutorid, tutorID) == 0) {
				found = 1;
				printf("\nThe tutor has been deleted!");
				printf("\n-------------------------------------------\n");

			}
			else {
				fwrite(&details, sizeof(details), 1, fp4temp);

			}
		}
		if (found != 1)
		{
			printf("\nThe tutor does not exist in the system");
			printf("\n-------------------------------------------\n");



			printf("\nGo to Delete Menu (yes or no) ? ");
			scanf("%s", &loop);

			if (strcmp(loop, "yes") == 0)
			{
				delete_data();
			}
			else
			{
				printf("Exiting.....");
			}
		}
		else
		{
			fclose(fp4);
			fclose(fp4temp);
			remove("tutor_details.txt");
			rename("temp.txt", "tutor_details.txt");

			printf("\nGo to Delete Menu (yes or no) ? ");
			scanf("%s", &loop);

			if (strcmp(loop, "yes") == 0)
			{
				delete_data();
			}
			else
			{
				printf("Exiting.....");
			}
		}


	case 2:
		printf("-------------------------------------------\n");
		printf("Successfully deleted all tutors!");
		printf("\n-------------------------------------------\n");
		fclose(fp4);
		fclose(fp4temp);
		remove("tutor_details.txt");
		rename("temp.txt", "tutor_details.txt");

		printf("\nGo to Delete Menu (yes or no) ? ");
		scanf("%s", &loop);

		if (strcmp(loop, "yes") == 0)
		{
			delete_data();
		}
		else
		{
			printf("Exiting.....");
		}

		break;

	case 3:
		delete_data();
		break;
	default:
		break;
	}
}


void delete_student()
{
	system("cls");

	FILE* file;
	FILE* filetemp;

	file = fopen("file.txt", "a+");
	filetemp = fopen("filetemp.txt", "w");

	struct student details;
	int choice, found = 0;
	char tpnumber[20];
	char loop[20];

	//error handling
	if (file == NULL || filetemp == NULL) {
		printf("\n------------------------------------------------------------------------\n");
		printf("Sorry, but file can not be opened! Please restart the program.");
		printf("\n------------------------------------------------------------------------");
		exit(1);
	}
	printf("\n------------------------------------------------------------------------\n");
	printf("Delete Options");
	printf("\n------------------------------------------------------------------------\n");
	printf("1. Delete a specific student\n");
	printf("2. Delete everything\n");
	printf("3. Back to Delete Menu");
	printf("\n------------------------------------------------------------------------\n");
	printf("Enter a choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		printf("-------------------------------------------");
		printf("\nEnter Student TP Number : ");
		scanf("%s", &tpnumber);
		printf("-------------------------------------------");
		while (fread(&details, sizeof(details), 1, file)) {
			if (strcmp(details.tpnumber, tpnumber) == 0) {
				found = 1;
				printf("\nThe tutor has been deleted!");
				printf("\n-------------------------------------------");
			}
			else {
				fwrite(&details, sizeof(details), 1, filetemp);
			}
		}
		if (found != 1) {
			printf("\nThe tutor does not exist in the system");
			printf("\n-------------------------------------------\n");
		}
		fclose(file);
		fclose(filetemp);
		remove("file.txt");
		rename("filetemp.txt", "file.txt");

		printf("\nGo to Delete Menu (yes or no) ? ");
		scanf("%s", &loop);

		if (strcmp(loop, "yes") == 0)
		{
			delete_data();
		}
		else
		{
			printf("Exiting.....");
		}

		break;

	case 2:
		printf("-------------------------------------------\n");
		printf("Successfully deleted all tutors!");
		printf("\n-------------------------------------------\n");
		fclose(file);
		fclose(filetemp);
		remove("file.txt");
		rename("filetemp.txt", "file.txt");

		printf("\nGo to Delete Menu (yes or no) ? ");
		scanf("%s", &loop);

		if (strcmp(loop, "yes") == 0)
		{
			delete_data();
		}
		else
		{
			printf("Exiting.....");
		}

		break;
	case 3:
		delete_data();
		break;

	default:
		break;
	}
}


void delete_program()
{
	system("cls");

	FILE* file;
	FILE* filetemp;

	file = fopen("program_details.txt", "a+");
	filetemp = fopen("program_detailstemp.txt", "w");

	struct program details;
	int choice, found = 0;
	char sessioncode[20];
	char loop[20];

	//error handling
	if (file == NULL || filetemp == NULL) {
		printf("\n------------------------------------------------------------------------\n");
		printf("Sorry, but file can not be opened! Please restart the program.");
		printf("\n------------------------------------------------------------------------");
		exit(1);
	}
	printf("\n------------------------------------------------------------------------\n");
	printf("Delete Options");
	printf("\n------------------------------------------------------------------------\n");
	printf("1. Delete a specific student\n");
	printf("2. Delete everything\n");
	printf("3. Back to Delete Menu");
	printf("\n------------------------------------------------------------------------\n");
	printf("Enter a choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		printf("-------------------------------------------");
		printf("\nEnter Session Code : ");
		scanf("%s", &sessioncode);
		printf("-------------------------------------------");
		while (fread(&details, sizeof(details), 1, file)) {
			if (strcmp(details.session_code, sessioncode) == 0) {
				found = 1;
				printf("\nThe tutor has been deleted!");
				printf("\n-------------------------------------------");
			}
			else {
				fwrite(&details, sizeof(details), 1, filetemp);
			}
		}
		if (found != 1) {
			printf("\nThe tutor does not exist in the system");
			printf("\n-------------------------------------------\n");
		}
		fclose(file);
		fclose(filetemp);
		remove("program_details.txt");
		rename("program_detailstemp.txt", "program_details.txt");

		printf("\nGo to Delete Menu (yes or no) ? ");
		scanf("%s", &loop);

		if (strcmp(loop, "yes") == 0)
		{
			delete_data();
		}
		else
		{
			printf("Exiting.....");
		}

		break;

	case 2:
		printf("-------------------------------------------\n");
		printf("Successfully deleted all tutors!");
		printf("\n-------------------------------------------\n");
		fclose(file);
		fclose(filetemp);
		remove("program_details.txt");
		rename("program_detailstemp.txt", "program_details.txt");

		printf("\nGo to Delete Menu (yes or no) ? ");
		scanf("%s", &loop);

		if (strcmp(loop, "yes") == 0)
		{
			delete_data();
		}
		else
		{
			printf("Exiting.....");
		}

		break;
	case 3:
		delete_data();
		break;

	default:
		break;
	}
}


void delete_enrolledstudent()
{
	system("cls");

	FILE* file;
	FILE* filetemp;

	file = fopen("enroll_session.txt", "a+");
	filetemp = fopen("enroll_sessiontemp.txt", "w");

	struct enroll details;
	int choice, found = 0;
	char tpnumber[20];
	char loop[20];

	//error handling
	if (file == NULL || filetemp == NULL) {
		printf("\n------------------------------------------------------------------------\n");
		printf("Sorry, but file can not be opened! Please restart the program.");
		printf("\n------------------------------------------------------------------------");
		exit(1);
	}
	printf("\n------------------------------------------------------------------------\n");
	printf("Delete Options");
	printf("\n------------------------------------------------------------------------\n");
	printf("1. Delete a specific student\n");
	printf("2. Delete everything\n");
	printf("3. Back to Delete Menu");
	printf("\n------------------------------------------------------------------------\n");
	printf("Enter a choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		printf("-------------------------------------------");
		printf("\nEnter Student TP Number : ");
		scanf("%s", &tpnumber);
		printf("-------------------------------------------");
		while (fread(&details, sizeof(details), 1, file)) {
			if (strcmp(details.tpnumber, tpnumber) == 0) {
				found = 1;
				printf("\nThe tutor has been deleted!");
				printf("\n-------------------------------------------");
			}
			else {
				fwrite(&details, sizeof(details), 1, filetemp);
			}
		}
		if (found != 1) {
			printf("\nThe tutor does not exist in the system");
			printf("\n-------------------------------------------\n");
		}
		fclose(file);
		fclose(filetemp);
		remove("enroll_session.txt");
		rename("enroll_sessiontemp.txt", "enroll_session.txt");

		printf("\nGo to Delete Menu (yes or no) ? ");
		scanf("%s", &loop);

		if (strcmp(loop, "yes") == 0)
		{
			delete_data();
		}
		else
		{
			printf("Exiting.....");
		}

		break;

	case 2:
		printf("-------------------------------------------\n");
		printf("Successfully deleted all tutors!");
		printf("\n-------------------------------------------\n");
		fclose(file);
		fclose(filetemp);
		remove("enroll_session.txt");
		rename("enroll_sessiontemp.txt", "enroll_session.txt");

		printf("\nGo to Delete Menu (yes or no) ? ");
		scanf("%s", &loop);

		if (strcmp(loop, "yes") == 0)
		{
			delete_data();
		}
		else
		{
			printf("Exiting.....");
		}

		break;
	case 3:
		delete_data();
		break;

	default:
		break;
	}
}



//tutor option

void tutor()
{
	system("cls");

	char tutorid[20];
	char password[9];
	int verified = 0;

	printf("\nEnter Tutor Code : ");
	scanf("%s", &tutorid);
	printf("\nEnter Password : ");
	scanf("%s", &password);

	verified = login_tutor(tutorid, password);

	int option;

	if (verified == 0)
	{
		printf("Tutor Menu\n");
		printf("----------------------------\n");
		printf("1.View Listing of Session\n");
		printf("2.Back to menu\n");
		printf("----------------------------\n");

		printf("Enter your option = ");
		scanf("%d", &option);

		switch (option) {
		case 1:
			tutor_listing(tutorid);
			break;
		case 2:
			menu();
			break;
		default:
			printf("Invalid Option !\n");
		}
	}
	else {
		printf("Invalid TP Number or Password");

		char loop[20];
		printf("\n-----------------------------------\n");
		printf("Back to Menu (Yes/No) ?");
		scanf("%s", &loop);
		printf("\n-----------------------------------\n");
		if (strcmp(loop, "yes") == 0)
		{
			menu();
		}
		else {
			printf("Exiting......");
			exit(1);
		}
	}
}


int login_tutor(char tutorid[20], char password[9])
{
	system("cls");

	if (strlen(password) == 8)
	{
		struct tutor t;

		FILE* file = fopen("tutor_details.txt", "r");
		if (file == NULL) {
			printf("Failed to open the file.\n");
		}


		int found = 0;

		while (fread(&t, sizeof(t), 1, file))
		{
			if (strcmp(t.tutorid, tutorid) == 0 && strcmp(t.password, password) == 0) {
				found = 1;
				break;
			}
		}

		fclose(file);

		if (found == 1) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else
	{
		printf("Password is not valid");
		return 1;
	}
}


void tutor_listing(char tutorid[20])
{
	system("cls");

	FILE* file;
	file = fopen("enroll_session.txt", "r");

	if (file == NULL)
	{
		printf("Failed to open the file \n");
	}
	else
	{
		struct enroll e;
		struct tutor t;

		printf("TP Number \t Student Name \t Session Code \t Tutor Code \t Location");
		printf("\n-----------------------------------------------------------------------------------------\n");

		while (fread(&e, sizeof(e), 1, file))
		{
			if (strcmp(e.tutor_code, tutorid) == 0)
			{
				printf("%s \t %s \t    %s \t   %s \t          %s\n", e.tpnumber, e.name, e.session_code, e.tutor_code, e.location);
			}

		}
		printf("\n-----------------------------------------------------------------------------------------\n");
		fclose(file);

		char loop[20];

		printf("\nGo Back to Menu (yes or no) ? ");
		scanf("%s", &loop);

		if (strcmp(loop, "yes") == 0)
		{
			menu();
		}
		else
		{
			printf("Exiting.....");
		}
	}
}


//student option

void student()
{
	system("cls");

	char tpnumber[20];
	char password[9];
	int verified = 0;

	printf("\nEnter TP Number: ");
	scanf("%s", &tpnumber);
	printf("\nEnter Password: ");
	scanf("%s", &password);

	verified = login_student(tpnumber, password);


	int option;

	if (verified == 0)
	{
		printf("Student Menu\n");
		printf("--------------------------------------------------\n");
		printf("1.View Listing of Session\n");
		printf("2.Enrol yourself in any available session\n");
		printf("3.Back to Menu\n");
		printf("--------------------------------------------------\n");

		printf("Enter your option = ");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			student_listing(tpnumber);
			break;
		case 2:
			enrol_yourself(tpnumber);
			break;
		case 3:
			menu();
			break;
		default:
			printf("Invalid Option !\n");
		}
	}
	else
	{
		printf("Invalid TP Number or Password");

		char loop[20];
		printf("\n-----------------------------------\n");
		printf("Back to Menu (Yes/No) ?");
		scanf("%s", &loop);
		printf("\n-----------------------------------\n");
		if (strcmp(loop, "yes") == 0)
		{
			menu();
		}
		else {
			printf("Exiting......");
			exit(1);
		}
	}
}



int login_student(char tpnumber[20], char password[9])
{
	system("cls");

	if (strlen(password) == 8)
	{

		struct student s;

		FILE* file = fopen("file.txt", "r");
		if (file == NULL) {
			printf("Failed to open the file.\n");
		}


		int found = 0;

		while (fread(&s, sizeof(s), 1, file))
		{
			if (strcmp(s.tpnumber, tpnumber) == 0 && strcmp(s.password, password) == 0) {
				found = 1;
				break;
			}
		}

		fclose(file);

		if (found == 1) {
			return 0;

		}
		else {
			return 1;
		}
	}
	else
	{
		printf("Password is not valid\n");
		return 1;
	}
}



void student_listing(char tpnumber[20])
{
	system("cls");

	FILE* file;
	file = fopen("enroll_session.txt", "r");

	if (file == NULL)
	{
		printf("Failed to open the file \n");
	}
	else
	{
		struct enroll e;


		printf("TP Number \t Student Name \t Session Code \t Tutor Code \t Location");
		printf("\n-----------------------------------------------------------------------------------------\n");

		while (fread(&e, sizeof(e), 1, file))
		{
			if (strcmp(e.tpnumber, tpnumber) == 0)
			{
				printf("%s \t %s \t    %s \t   %s \t          %s\n", e.tpnumber, e.name, e.session_code, e.tutor_code, e.location);
			}

		}
		printf("\n-----------------------------------------------------------------------------------------\n");
		fclose(file);

		char loop[20];

		printf("\nGo Back to Menu (yes or no) ? ");
		scanf("%s", &loop);

		if (strcmp(loop, "yes") == 0)
		{
			menu();
		}
		else
		{
			printf("Exiting.....");
		}
	}
}


void enrol_yourself(char tpnumber[20])
{
	system("cls");

	FILE* file;
	FILE* file1;
	FILE* file2;

	char loop[5] = "yes";
	while (strcmp(loop, "yes") == 0)
	{
		file = fopen("enroll_session.txt", "a+");
		file1 = fopen("program_details.txt", "r");
		file2 = fopen("file.txt", "r");

		if (file == NULL || file1 == NULL || file2 == NULL)
		{
			printf("Failed to open file !\n");
		}
		else
		{
			struct enroll e;
			struct program p;
			struct student s;
			int found = 0;



			printf("Session Code : ");
			scanf("%s", e.session_code);

			while (fread(&s, sizeof(s), 1, file2))
			{
				if (strcmp(s.tpnumber, tpnumber) == 0)
				{
					strcpy(e.name, s.student_name);
				}
			}


			while (fread(&p, sizeof(p), 1, file1)) {
				if (strcmp(p.session_code, e.session_code) == 0)
				{
					strcpy(e.tpnumber, tpnumber);
					strcpy(e.tutor_code, p.tutor_code);
					strcpy(e.location, p.location);
					found = 1;
				}
			}

			if (found != 1)
			{
				menu();
			}

			fwrite(&e, sizeof(e), 1, file);
			printf("\n--------------------------\n");
			printf("Continue (Yes/No) ?");
			scanf("%s", &loop);
			printf("\n--------------------------\n");

			fclose(file);
			fclose(file1);

			if (strcmp(loop, "yes") != 0)
			{
				menu();
			}
		}
	}
}


void viewing()
{
	system("cls");
	int option;

	printf("Viewing Menu\n");
	printf("-------------------------\n");
	printf("1.View Tutor Data\n");
	printf("2.View Program Session Data\n");
	printf("3.View Student Data\n");
	printf("4.Back to Admin Menu\n");
	printf("-------------------------\n");

	printf("Enter your option = ");
	scanf("%d", &option);

	switch (option) {
	case 1:
		view_tutor();
		break;
	case 2:
		view_program();
		break;
	case 3:
		view_student();
		break;
	case 4:
		admin();
		break;
	default:
		printf("Invalid Option !\n");
	}
}


void view_tutor()
{
	system("cls");

	FILE* fptr1;
	fptr1 = fopen("tutor_details.txt", "r");

	if (fptr1 != NULL)
	{
		struct tutor td;

		while (fread(&td, sizeof(td), 1, fptr1)) {
			printf("\nTutorID: %s", td.tutorid);
			printf("\nTutor's name: %s ", td.name);
			printf("\nTutor's title: %s", td.title);
			printf("\nTutor's password: %s", td.password);
			printf("\n-------------------------------------------\n");


		}
		fclose(fptr1);

		char loop[20];

		printf("Go to admin page (yes or no) ? ");
		scanf("%s", &loop);

		if (strcmp(loop, "yes") == 0)
		{
			viewing();
		}
		else
		{
			printf("Exiting.....");
		}
	}
	else
	{
		printf("File Open Unsuccessful");
	}

}


void view_program()
{
	system("cls");
	FILE* fptr2;
	fptr2 = fopen("program_details.txt", "r");

	if (fptr2 != NULL)
	{
		struct program pd;

		while (fread(&pd, sizeof(pd), 1, fptr2)) {
			printf("\nSession Code: %s", pd.session_code);
			printf("\nTitle: %s ", pd.title);
			printf("\nDay: %s", pd.day);
			printf("\nStart Time: %s", pd.start_time);
			printf("\nLocation: %s", pd.location);
			printf("\nTutor Code: %s", pd.tutor_code);
			printf("\n-------------------------------------------\n");
		}
		fclose(fptr2);


		char loop[20];

		printf("Go to admin page (yes or no) ? ");
		scanf("%s", &loop);

		if (strcmp(loop, "yes") == 0)
		{
			viewing();
		}
		else
		{
			printf("Exiting.....");
		}

	}
	else
	{
		printf("File Open Unsuccessful");
	}
}


void view_student()
{
	system("cls");
	FILE* fptr3;
	fptr3 = fopen("file.txt", "r");

	if (fptr3 != NULL)
	{
		struct student sd;

		while (fread(&sd, sizeof(sd), 1, fptr3)) {
			printf("\nTP Number: %s", sd.tpnumber);
			printf("\nStudent Name: %s ", sd.student_name);
			printf("\nPassword: %s ", sd.password);
			printf("\n-------------------------------------------\n");
		}
		fclose(fptr3);


		char loop[20];

		printf("Go to admin page (yes or no) ? ");
		scanf("%s", &loop);

		if (strcmp(loop, "yes") == 0)
		{
			viewing();
		}
		else
		{
			printf("Exiting.....");
		}

	}
	else
	{
		printf("File Open Unsuccessful");
	}
}