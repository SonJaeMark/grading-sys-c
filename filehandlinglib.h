#pragma once

#include "userStruct.h"

int idGenerator();

int saveUser(char *userDetails, int userType);
int saveStudent(char *studentDetailsCsvForm);
int saveTeacher(char *teacherDetailsCsvForm);
int saveAllStudent(char studentDetailsCsvForm[STR_MAX_LEN][STR_MAX_LEN]);
int saveAllTeacher(char studentDetailsCsvForm[STR_MAX_LEN][STR_MAX_LEN]);
int saveLog(char *log);
int saveCurrentUser(char *details);
Student getStudentById(char *id);
Teacher getTeacherById(char *id);
Student getStudentByUsername(char *username);
Teacher getTeacherByUsername(char *username);
void getAllTeacherByField(Teacher *teacherList, char *field, char *target);
void getAllStudentByField(Student *studentList, char *field, char *target);
void getCurrentUser(char *currentUserDetails);
void updateStudentDetails(char *id, char *updtedStudentDetailsCsvForm);
void updateTeacherDetails(char *id, char *updtedTeacherDetailsCsvForm);
