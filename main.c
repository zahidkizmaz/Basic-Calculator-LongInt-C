/* 
 * File:   main.c
 * Author: zahid
 *
 * Created on April 13, 2017, 11:09 AM
 * 
 * // https://defuse.ca/big-number-calculator.htm   online calculator for correction
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct LongInt
{
    char num[50];
};


struct LongInt AssignValue(char *v)
{
    struct LongInt res;
    strcpy(res.num,v);
    return res ;
}

void printLI(struct LongInt L)
{
    printf("%s", L.num);
}

struct LongInt AddLI(struct LongInt A, struct LongInt B)
{
    int len1, len2;
    int r,c;
    struct LongInt Z;
    len1 = strlen(A.num)-1;
    len2 = strlen(B.num)-1;
    int resindex = 49;
    c = 0;
    while (len1 >= 0 && len2 >= 0)
    {
        r = c + A.num[len1] - '0' + B.num[len2] - '0';
        if (r > 9)
        {
            r = r - 10;
            c = 1;
        }
        else
        {
            c = 0;
        }
        Z.num[resindex] = r + '0';
        resindex--;
        len1--;
        len2--;
    }

    while (len1 >= 0 )
    {
        r = c + A.num[len1] - '0';
        if (r > 9)
        {
            r = r - 10;
            c = 1;
        }
        else
        {
            c = 0;
        }
        Z.num[resindex] = r + '0';
        resindex--;
        len1--;
    }

    while (len2 >= 0)
    {
        r = c + B.num[len2] - '0';
        if (r > 9)
        {
            r = r - 10;
            c = 1;
        }
        else
        {
            c = 0;
        }
        Z.num[resindex] = r + '0';
        resindex--;
        len2--;
    }
    if (c > 0)
    {
        Z.num[resindex] = c + '0';
        resindex--;
    }

    len1 = 0;
    resindex++;
    while (resindex < 50)
    {
        Z.num[len1] = Z.num[resindex];
        len1++;
        resindex++;
    }
    Z.num[len1] = 0;
    return Z;

}


int main(int argc, char** argv) {    
    
    struct LongInt A,B,C;
    A = AssignValue("12345678987654321");
    B = AssignValue("777777777777777777");
    C = AddLI(A, B);
    printLI(C);
    printf("\n");


    return (EXIT_SUCCESS);
}

