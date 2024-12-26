typedef struct Grades
{
    float MATH;
    float SCI;
    float ENG;
    float AVE;
} Grades;

typedef struct Date
{
    int MM;
    int DD;
    int YYYY;
} Date;

typedef struct Student
{
    int id;
    char *fname;
    char *lname;
    char *userName;
    char *password;
    char *section;
    struct Date *dateOfBirth;
    struct Grades *grades;
} Student;

typedef struct Teacher
{
    int id;
    char *fname;
    char *lname;
    char *userName;
    char *password;
    struct Date *dateOfBirth;
    struct Student *studentsList;
} Teacher;