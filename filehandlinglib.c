#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "userStruct.h"
#include "strflib.h"


#define ID_VAL_FILE "id_value.txt"
#define STUDENT_CSV_FILE "student_csv_file.txt"
#define TEACHER_CSV_FILE "teacher_csv_file.txt"
#define SECRETE_PASSWORD_FILE "secrete_password_file.txt"
#define LOGS_FILE "logs_file.txt"
#define CURRENT_USER_LOGS "current_user_login.txt"


int idGenerator()
{
    FILE *idFile;
    int id = 0;

    idFile = fopen(ID_VAL_FILE, "r");

    if(idFile==NULL)
    {
        id = 240000;
        idFile = fopen(ID_VAL_FILE, "w");
        fprintf(idFile,"%d", id);
        fclose(idFile);
    }
    else
    {
        fscanf(idFile, "%d", &id);
        id++;

        idFile = fopen(ID_VAL_FILE, "w");
        fprintf(idFile,"%d", id);
        fclose(idFile);
    }
    return id;
}

int saveUser(char *userDetails, int userType)
{
    int succesFlag = 0;
    FILE *filePtr;

    if(userType == 0)
    {
        filePtr = fopen(STUDENT_CSV_FILE, "r");
    }
    else 
    {
        filePtr = fopen(TEACHER_CSV_FILE, "r");
    }

    if(userType == 0 && filePtr == NULL)
    {
        filePtr = fopen(STUDENT_CSV_FILE, "w");
        fprintf(filePtr,"id,user_name,first_name,last_name,date_of_birt,section,grades\n");
        fprintf(filePtr,"%s\n", userDetails);
        succesFlag = 1;
    }
    else if(userType == 1 && filePtr == NULL)
    {
        filePtr = fopen(TEACHER_CSV_FILE, "w");
        fprintf(filePtr,"id,user_name,first_name,last_name,date_of_birt,students\n");
        fprintf(filePtr,"%s\n", userDetails);
        succesFlag = 1;
    }
    else if(userType == 0)
    {
        filePtr = fopen(STUDENT_CSV_FILE, "a");
        fprintf(filePtr,"%s\n", userDetails);
        succesFlag = 1;
    }
    else if(userType == 1)
    {
        filePtr = fopen(TEACHER_CSV_FILE, "a");
        fprintf(filePtr,"%s\n", userDetails);
        succesFlag = 1;
    }

    fclose(filePtr);
    return succesFlag;
}

int saveStudent(char *studentDetailsCsvForm)
{
    return saveUser(studentDetailsCsvForm, 0);
}

int saveTeacher(char *teacherDetailsCsvForm)
{
    return saveUser(teacherDetailsCsvForm, 1);
}

int saveAllStudent(char studentDetailsCsvForm[STR_MIN_LEN][STR_MIN_LEN], int size)
{
    char studentDetailsCsvFormBuff[STR_MIN_LEN];
    int successFlag = 0;

    for (int i = 0; i < size; i++)
    {
        strcpy(studentDetailsCsvFormBuff, studentDetailsCsvForm[i]);
        successFlag+=saveStudent(studentDetailsCsvFormBuff);
    }
    return successFlag;
}
int saveAllTeacher(char teacherDetailsCsvForm[STR_MIN_LEN][STR_MIN_LEN], int size)
{
    char teacherDetailsCsvFormBuff[STR_MIN_LEN];
    int successFlag = 0;

    for (int i = 0; i < size; i++)
    {
        strcpy(teacherDetailsCsvFormBuff, teacherDetailsCsvForm[i]);
        successFlag+=saveTeacher(teacherDetailsCsvFormBuff);
    }
    return successFlag;
}

int saveLog(char *log)
{
    FILE *logFile;

    logFile = fopen(LOGS_FILE, "r");
    int successFlag = 0;

    if(logFile == NULL)
    {
        logFile = fopen(LOGS_FILE, "w");
        fprintf(logFile, "logs\n");
        fprintf(logFile, "%s\n", log);
        fclose(logFile);
        successFlag = 1;
    }
    else
    {
        logFile = fopen(LOGS_FILE, "a");
        fprintf(logFile, "%s\n", log);
        fclose(logFile);
        successFlag = 1;
    }
    return successFlag;
}

int saveCurrentUser(char *details)
{
    FILE *currUserLoggedInFile;
    int successFlag = 0;

    currUserLoggedInFile = fopen(LOGS_FILE, "w");
    fprintf(currUserLoggedInFile, "%s", details);
    fclose(currUserLoggedInFile);
    if(currUserLoggedInFile != NULL)successFlag = 1;
 
    return successFlag;
}

int saveUserPassword(char *userDetails)
{
    FILE *psswrdFile;

    psswrdFile = fopen(SECRETE_PASSWORD_FILE, "r");
    int successFlag = 0;

    if(psswrdFile == NULL)
    {
        psswrdFile = fopen(SECRETE_PASSWORD_FILE, "w");
        fprintf(psswrdFile, "id,password\n");
        fprintf(psswrdFile, "%s\n", userDetails);
        fclose(psswrdFile);
        successFlag = 1;
    }
    else
    {
        psswrdFile = fopen(SECRETE_PASSWORD_FILE, "a");
        fprintf(psswrdFile, "%s\n", userDetails);
        fclose(psswrdFile);
        successFlag = 1;
    }
    return successFlag;
}

Student getStudentById(char *id)
{
    
}

Teacher getTeacherById(char *id)
{}
Student getStudentByUsername(char *username)
{}
Teacher getTeacherByUsername(char *username)
{}
void getAllTeacherByField(Teacher *teacherList, char *field, char *target)
{}
void getAllStudentByField(Student *studentList, char *field, char *target)
{}
void getCurrentUser(char *currentUserDetails)
{}
void updateStudentDetails(char *id, char *updtedStudentDetailsCsvForm)
{}
void updateTeacherDetails(char *id, char *updtedTeacherDetailsCsvForm)
{}