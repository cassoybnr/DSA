#ifndef studtype_H
#define studtype_H

typedef struct{
    char LName[30];
    char FName[30];
    char MI;
}Name;

typedef stuct{
    Name name;
    char course[8];
    int id;
    int age;
}Studtype, *StudPtr;

#endif