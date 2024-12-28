#include <stdlib.h>
#include <stdio.h>

#include "userStruct.h"
#include "strflib.h"


#define ID_VAL_FILE "id_value.txt"
#define STUDENT_CSV_FILE "student_csv_file.txt"
#define TEACHER_CSV_FILE "teacher_csv_file.txt"


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

    if(userType == 0 && filePtr ==NULL)
    {
        filePtr = fopen(STUDENT_CSV_FILE, "w");
        fprintf(filePtr,"id,user_name,first_name,last_name,date_of_birt,section,grades\n");
        fprintf(filePtr,"%s\n", userDetails);
    }
    else if(userType == 1 && filePtr ==NULL)
    {
        filePtr = fopen(TEACHER_CSV_FILE, "w");
        fprintf(filePtr,"id,user_name,first_name,last_name,date_of_birt,students\n");
        fprintf(filePtr,"%s\n", userDetails);
    }
    else if(userType == 0)
    {
        filePtr = fopen(STUDENT_CSV_FILE, "a");
        fprintf(filePtr,"%s\n", userDetails);
    }
    else if(userType == 1)
    {
        filePtr = fopen(TEACHER_CSV_FILE, "a");
        fprintf(filePtr,"%s\n", userDetails);
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

int saveAllStudent(char studentDetailsCsvForm[STR_MAX_LEN][STR_MAX_LEN])
{}
int saveAllTeacher(char studentDetailsCsvForm[STR_MAX_LEN][STR_MAX_LEN])
{}
int saveLog(char *log)
{}
int saveCurrentUser(char *details)
{}
Student getStudentById(char *id)
{}
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