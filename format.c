#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

int toInt(char *input)
{
    //this function takes input string of 1s and 0s and makes it into an int using two's complement
    int i = 1;
    int toret = 0;
    
    if (input[0] == '1')
        {toret = (-1) * pow(2,31);}
   
    while (i < 32)
    {
        if (input[i] == '1')
                {toret = toret + pow(2, (31 - i));}
        if (input[i] != '0' && input[i] != '1')
        {
            fprintf(stderr, "Invalid binary input for two's complement\n");
            exit(0);
        }
        i++;
    }
    
    //to print my new int as chars
     
    if (toret < 0)
    {
        printf("-");
        toret = toret * (-1);
    }

    int printpwer = 0;

    while (toret > pow(10, printpwer))
    {
        printpwer++;
    }
    int toprint[printpwer];
    int j = 0;
    printpwer--;

    while(toret != 0)
    {
        toprint[j] = toret % 10;
        j++;
        toret = toret / 10;
    }

    int k;
    for (k = j - 1; k>=0; k--)
    {
        char printing = toprint[k] + 48;
        printf("%c", printing);
    }
    printf("\n");
    return 0;
}

float toFloat(char *input)
{
    //takes input and turns it into float using ieee 754 format
    int i = 1;
    float toret = 1;
    int power = 0;
    char sign = input[0];
    char convert;
    int intconv;
    
    while(i<9)
    {
        convert = input[i];
        intconv = convert - 48;
        if (intconv < 0 || intconv > 1)
            {fprintf(stderr, "Invalid binary input in exponent\n"); exit(0);}

        power = power + (intconv * pow(2,(8-i)));
        i++;
    }
    power = power - 127;
    
    while (i < 32)
    {
        convert = input[i];
        intconv = convert - 48;
        if (intconv < 0 || intconv > 1)
            {fprintf(stderr, "Invalid binary input in Mantissa\n"); exit(0);}
    
        toret = toret + (intconv * pow(2,(((-1) * (i-9)) - 1)));
        i++;
    }

    float finalpow = pow(2, power);
    
    //checks if pinf, ninf, and NaN
    if (power == 128)
    {
        if (toret == 0)
        {
            if (sign == '1')
            {
                printf("ninf\n");
                return 0;
            }

            if (sign == '0')
            {
                printf("pinf\n");
                return 0;
            }
        }

        printf("NaN\n");
        return 0;
    }

    toret = toret * finalpow;
    if (sign == '1')
        {toret = toret * (-1);}

    //prints float as ASCII
    int floatpower = 0;
    int num;
    float lt1 = toret;
    
    if (toret < 0)
    {
        printf("-");
        toret = toret * (-1);
    }

    if (toret > 10)
    {
        while(toret >= 10)
        {
           toret = toret / 10; 
           floatpower++;
        }
    }

    if (toret < 1)
    {
        while(toret < 1)
        {
            toret = toret * 10;
            floatpower--;
        }
    }
    
    num = toret;
    lt1 = toret - num;

    char pfirst = num + 48;
    printf("%c", pfirst);

    char pdec;
    if (lt1 != 0)
    {
        printf(".");
        int numprint;
        int loopnum = 0;
        for (loopnum = 0; loopnum < 6; loopnum++)
        {
            lt1 = lt1 * 10;
            numprint = lt1;
            numprint = numprint % 10;
            pdec = numprint + 48;
            printf("%c", pdec);
        }
    }

    
    if (floatpower != 0)
    {
        printf("e");
        if (floatpower < 0)
        {
            printf("-"); floatpower = floatpower * (-1);
        }
        char expprint;
        int t;
        while(floatpower != 0)
        {
            t = floatpower % 10;
            expprint = t + 48;
            floatpower = floatpower / 10;
            printf("%c", expprint);
        }

    }
    printf("\n");
    return toret;
}

int main(int argc, char **argv)
{
 // checks for correct arguments and input length
    if (argc != 3)
        {fprintf(stderr, "invalid number of arguments. Please try again\n"); return 0;}
    
    int arg1_len = strlen(argv[1]);

    if (arg1_len != 32)
        {fprintf(stderr, "invalid argument. Please try again\n"); return 0;}
    
    char *input;
    input = argv[1];

    char *iof;
    iof = argv[2];

    switch(iof[0])
    {
        case 'i':
            toInt(input); break;
        case 'f':
            toFloat(input); break;
        case 'I':
            toInt(input); break;
        case 'F':
            toFloat(input); break;
    }
    return 0;
}
