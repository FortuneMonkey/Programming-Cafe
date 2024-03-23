#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define ADMIN_KEY "admin123" // Define the admin key

struct tutor
{
	char name[20];
	char tutorid[20];
	char title[20];
	char password[20];
};

struct program
{
	char session_code[20];
	char title[20];
	char day[20];
	char start_time[20];
	char location[20];
	char tutor_code[20];
};

struct student
{
	char tpnumber[20];
	char student_name[20];
	char password[20];
};

//structure to enroll student in a session
struct enroll
{
	char tpnumber[20];
	char name[20];
	char session_code[20];
	char tutor_code[20];
	char location[20];

};


void menu();
void admin();
void student();
void tutor();


//viewing
void view_tutor();
void view_program();
void view_student();


//admin functions
void login_admin();
void registration_of_tutor();
void adding_new_programming_session();
void registration_of_student();
void enrol_student_session();
void listing_of_pc();
void viewing();
void delete_data();
void delete_enrolledstudent();
void delete_program();


//student functions
void enrol_yourself();
int login_student();
void delete_student();
void student_listing();

//tutor functions
int login_tutor();
void delete_tutor();
void tutor_listing();

