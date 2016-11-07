#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

void toBin(int aos)
{
    //changes int to binary and prints it as chars
    printf("b");
    int pwer = 0;
    while (aos > pow(2, pwer))
    {
        pwer++;
    }
    int toprint[pwer];
    int i = 0;
    pwer--;
    while(aos != 0)
    {
        toprint[i] = aos % 2;
        i++;
        aos = aos / 2;
    }
    int j;
    for (j = i-1; j >= 0; j--)
    {
        char printing = toprint[j] + 48;
        printf("%c", printing);
    }
    printf("\n");
}

void toDec(int aos)
{
    //prints decimal as chars
    printf("d");
    int pwer = 0;
    while (aos > pow(10, pwer))
    {
        pwer++;
    }
    int toprint[pwer];
    int i = 0;
    pwer--;
    while(aos != 0)
    {
        toprint[i] = aos % 10;
        i++;
        aos = aos / 10;
    }
    int j;
    for (j = i-1; j >= 0; j--)
    {
        char printing = toprint[j] + 48;
        printf("%c", printing);
    }
    printf("\n");
}

void toOct(int aos)
{
    //changes decimal to oct and prints it as chars
    printf("o");
    int pwer = 0;
    while (aos > pow(8, pwer))
    {
        pwer++;
    }
    int toprint[pwer];
    int i = 0;
    pwer--;
    while(aos != 0)
    {
        toprint[i] = aos % 8;
        i++;
        aos = aos / 8;
    }
   
    int j;
    for (j = i-1; j >= 0; j--)
    {
        char printing = toprint[j] + 48;
        printf("%c", printing);
    }
    printf("\n");
}

void toHex(int aos)
{
    //changes decimal to Hex and prints it as chars
    printf("x");
    int pwer = 0;
    while (aos > pow(16, pwer))
    {
        pwer++;
    }
    int toprint[pwer];
    int i = 0;
    pwer--;
    while(aos != 0)
    {
        toprint[i] = aos % 16;
    
        i++;
        aos = aos / 16;
    }
    char printing; 
    int j;
    for (j = i-1; j >= 0; j--)
    {
     switch (toprint[j])
        {
            case 10: printf("a"); break;
            case 11: printf("b"); break;
            case 12: printf("c"); break;
            case 13: printf("d"); break;
            case 14: printf("e"); break;
            case 15: printf("f"); break;

            default: 
                printing = toprint[j] + 48;
                printf("%c", printing);
        }
    }
    printf("\n");
}

int HexInt(char *input)
{
    //changes hex string to int
   int len = strlen(input);
   int i = len-1;
   int power = 0;   
    int toret = 0;
    char convert;
    int intconv;
      
    int negs = 0;
    if (input[0] == '-')
    {
        negs = 1;
    }
    while (i>negs)
    {
        convert = input[i];
        intconv = convert - 48;
        if ((intconv < 0 || intconv > 9)&&(intconv < 17 || intconv > 22)&&(intconv < 49 || intconv > 54))
            {fprintf(stderr, "Invalid hexadecimal input\n");return (-1);}

//      fix for numbers > 9
        if (intconv >=17 && intconv <= 22)
            {intconv = intconv - 7;}
        if (intconv >= 49 && intconv <= 54)
            {intconv = intconv - 39;}
        toret = toret + (intconv * pow(16, power));

        power++;
        i--;
    }
  
    return toret;

}

int DecInt(char *input)
{
    //changes decimal string  to int
    int len = strlen(input);
    int i = len -1;
    int power = 0;
    int toret = 0;
    char convert;
    int intconv;
   
    int negs = 0;
    if (input[0] == '-')
    {
        negs = 1;
    }
    while (i>negs)
    {
        convert = input[i];
        intconv = convert - 48;
        if (intconv < 0 || intconv > 9)
            {fprintf(stderr, "Invalid decimal input\n");return (-1);}

        toret = toret + (intconv * pow(10, power));

        power++;
        i--;
    }

    return toret;
}

int OctInt(char *input)
{
  //changes oct string to int
    int len = strlen(input);
    int i = len -1;
    int power = 0;
    int toret = 0;
    char convert;
    int intconv;
   
    int negs = 0;
    if (input[0] == '-')
    {
        negs = 1;
    }
    while (i>negs)
    {
        convert = input[i];
        intconv = convert - 48;
        if (intconv < 0 || intconv > 7)
            {fprintf(stderr, "Invalid octal input\n"); return (-1);}

        toret = toret + (intconv * pow(8, power));

        power++;
        i--;
    }
    return toret;
}

int BinaryInt(char *input)
{
    //changes binary string to int
   int len = strlen(input); 
   int i = len -1;
   int power = 0;
    int toret = 0;
    char convert;
    int intconv;

    int negs = 0;
    if (input[0] == '-')
    {
        negs = 1;
    }

    while (i>negs)
    {
        convert = input[i];
        intconv = convert - 48;
        if (intconv < 0 || intconv > 1)
            {fprintf(stderr, "Invalid binary input\n"); return (-1);}

        toret = toret + (intconv * pow(2, power));

        power++;
        i--;
    }

    return toret;
}

int main(int argc, char **argv)
{
   // checks for correct # of arguments
    if (argc != 5)
        {fprintf(stderr, "invalid number of arguments. Please try again\n"); return 0;}
    
    int arg1_len = strlen(argv[1]);

    if (arg1_len != 1)
         {fprintf(stderr, "second argument invalid. Please try again\n"); return 0;}
    char *pom;
    pom = argv[1];

    char *tobase;
    tobase = argv[4];


    char *firstarg;
    char *secarg;
    firstarg = argv[2];
    secarg = argv[3];
    
    int intret1; 
    int intret2;
    int neg1 = 0;
    int neg2 = 0;

    if (firstarg[0] == '-')
    {
        neg1 = 1;
    }

    if (secarg[0] == '-')
    {
        neg2 = 1;
    }
    
    //enters correct converter
    switch(firstarg[neg1])
    {
         case 'b': 
            intret1 = BinaryInt(firstarg); break;
         case 'o': 
            intret1 = OctInt(firstarg); break;
         case 'd': 
            intret1 = DecInt(firstarg); break;
         case 'x': 
            intret1 = HexInt(firstarg); break;
    }

    //enters correct converter
     switch(secarg[neg2])
    {
         case 'b': 
            intret2 = BinaryInt(secarg); break;
         case 'o': 
            intret2 = OctInt(secarg); break;
         case 'd': 
            intret2 = DecInt(secarg); break;
         case 'x': 
            intret2 = HexInt(secarg); break;
    }
    
    if (intret1 == (-1))
        {return 0;}
    if (intret2 == (-1))
        {return 0;}

    if (neg1 == 1)
        {intret1 = intret1 * (-1);}

    if (neg2 == 1)
        {intret2 = intret2 * (-1);}

    int aos;
    if (pom[0] == '+')
        {aos = intret1 + intret2;}

    if (pom[0] == '-')
        {aos = intret1 - intret2;}

    if (aos < 0)
        {printf("-"); aos = aos * (-1);}

    
    switch(tobase[0])
    {
        case 'b':
            toBin(aos); break;
        case 'd':
            toDec(aos); break;
        case 'o':
            toOct(aos); break;
        case 'x':
            toHex(aos); break;
          
    }
   
    return 0;
}
