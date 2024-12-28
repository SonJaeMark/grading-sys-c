#pragma once

#include "userStruct.h"

int idGenerator();

int saveUser(char *userDetails, int userType);
int saveStudent(char *studentDetailsCsvForm);
int saveTeacher(char *teacherDetailsCsvForm);
int saveAllStudent(char studentDetailsCsvForm[STR_MIN_LEN][STR_MIN_LEN], int size);
int saveAllTeacher(char teacherDetailsCsvForm[STR_MIN_LEN][STR_MIN_LEN], int size);
int saveLog(char *log);
int saveCurrentUser(char *details);
int saveUserPassword(char *userDetails);
Student getStudentById(char *id);
Teacher getTeacherById(char *id);
Student getStudentByUsername(char *username);
Teacher getTeacherByUsername(char *username);
void getAllTeacherByField(Teacher *teacherList, char *field, char *target);
void getAllStudentByField(Student *studentList, char *field, char *target);
void getCurrentUser(char *currentUserDetails);
void updateStudentDetails(char *id, char *updtedStudentDetailsCsvForm);
void updateTeacherDetails(char *id, char *updtedTeacherDetailsCsvForm);
