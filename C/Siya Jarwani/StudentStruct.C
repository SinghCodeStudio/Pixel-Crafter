/*
    Team Name: Pixel Crafters
    Author: Siya Jarwani
    DOC : 9/2/2025
    Objective : To create a student form
*/

#include <stdio.h>
#include <conio.h>  
#include <stdlib.h>

#define SIZE 10

struct Student {
    int rollno;
    char name[30], grade;
    float fees, eng, maths, comp, sci, hin, guj, ss, per, total;
} s[SIZE]; //end of struct

void create();
void display();
int search(int rollno);
void calculateGrade(int i);

void main() { //main start
    int i, choice, rollno;
    clrscr();

    while (1) { //while loop start
        printf("\n\n1. Create\n2. Display\n3. Search\n4. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {  // switch case start
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Enter the Roll Number to be searched: ");
                scanf("%d", &rollno);
                i = search(rollno);

                if (i == -1) {
                    printf("\nNo Data Found\n");
                } else {
                    printf("\nId\tName\tFees\tEng\tMaths\tSci\tComp\tSS\tHin\tGuj\tGr\n");
                    printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%c\n",
                           s[i].rollno, s[i].name, s[i].fees, s[i].eng, s[i].maths,
                           s[i].sci, s[i].comp, s[i].ss, s[i].hin, s[i].guj, s[i].grade);
                }
                break;

            case 4:
                getch();
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
} //end of struct

void create() { 
    int r, i;
    float temp;
    for (i = 0; i < SIZE; i++) {
        printf("\nEnter the Roll Number: ");
        scanf("%d", &r);
        s[i].rollno = r;

        printf("Enter the Name: ");
        scanf("%s", s[i].name); 
        printf("Enter the Fees: ");
        scanf("%f", &temp);
        s[i].fees = temp;

        printf("Enter the Marks:\nEnglish: ");
        scanf("%f", &s[i].eng);
        printf("Maths: ");
        scanf("%f", &s[i].maths);
        printf("Science: ");
        scanf("%f", &s[i].sci);
        printf("Computer: ");
        scanf("%f", &s[i].comp);
        printf("Social Studies: ");
        scanf("%f", &s[i].ss);
        printf("Hindi: ");
        scanf("%f", &s[i].hin);
        printf("Gujarati: ");
        scanf("%f", &s[i].guj);

        calculateGrade(i);
    }
} //end of function

void calculateGrade(int i) {
    s[i].total = s[i].eng + s[i].maths + s[i].hin + s[i].guj + s[i].comp + s[i].ss + s[i].sci;
    s[i].per = s[i].total / 8; 

    if (s[i].per > 90) {
        s[i].grade = 'A';
    } else if (s[i].per > 80) {
        s[i].grade = 'B';
    } else {
        s[i].grade = 'C';
    }
}//end of function

void display() {
    int i;
    printf("\nId\tName\tFees\tEng\tMaths\tSci\tComp\tSS\tHin\tGuj\tGr\n");
    for (i = 0; i < SIZE; i++) { 
        printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%c\n",
               s[i].rollno, s[i].name, s[i].fees, s[i].eng, s[i].maths,
               s[i].sci, s[i].comp, s[i].ss, s[i].hin, s[i].guj, s[i].grade);
    }
}//end of function

int search(int rollno) {
    int i;
    for (i = 0; i < SIZE; i++) { 
        if (s[i].rollno == rollno) {
            return i;
        }
    }
    return -1; 
} //end of function
