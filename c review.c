#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // Simple Input Output
    /*  int roll;
      char grade;
      float gpa;

      printf("Please enter roll, grade, gpa: \n");
      // scanf("%d %c %f", &roll, &grade, &gpa);
      scanf("%d", &roll);
      fflush(stdin);
      scanf("%c", &grade);
      scanf("%f", &gpa);
      printf("Roll: %d, Grade: %c, GPA: %f", roll, grade, gpa);
    */
    /*
    char x;
    x=getchar();
    putchar(x);*/

    /*
    char a;
    while( (a=getchar()) != '\0')
        putchar(a);
    */

    /*   char firstName[100]="hello world";
       char copyName[100];

       for(int i=0; (copyName[i]= firstName[i])!= '\0'; i++);
       puts(copyName); */

    /* char first[100]="My name is Hadiuzzaman";
     char copyName[100];
     strcpy(copyName, first);
     puts(copyName);*/

    // C Pointer
    /*   int a=10, *b, c;

       b= &a;
       c= *b;

       printf("%d", c); */

    /*    char name[100]="Bangladesh Is My Motherland";
        char *bd;
        bd= (char *) malloc( strlen( name));

        char *bd2;
        bd2= strdup(name);

        strcpy(bd,name);
        puts(bd2); */

 /*   char str[100]="hello world";
    char substr[100]="world";

    int loc= strstr(str,substr);
    int x= &str[0];
    printf("%d", loc -x);  */

    // Number conversion

    char *num= "1234";
    int num2= atoi(num);
    printf("%d", num2);


    return 0;
}
/*
  int inputInteger;
    char inputCharacter;
    float inputFloat;


    printf("Enter an Integer, Character and Floating point number\n");
    scanf("%d %c %f", &inputInteger, &inputCharacter,
        &inputFloat);


    printf("\nInteger you entered is : %d", inputInteger);
    printf("\nCharacter you entered is : %c", inputCharacter);
    printf("\nFloating point number you entered is : %f",
        inputFloat);

    getch();
    return 0;
    */
