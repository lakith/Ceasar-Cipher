/**
 * caesar.c
 * 
 * S. Lakith Muthugala
 * lakith1995@gmail.com
 * 
 * Encrypt the text using caesa ciphar
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

void lowercaseEncrypt(char letter,int shiftingNumber);
void uppercaseEncrypt(char letter,int shiftingNumber);

int main (int argc, string argv[])
{
    
    if (argc == 1 || argc > 2)
    {
        printf("Usage:%s<key>\n",argv[0]);
        return 1;
    }
    // create some amount of memory location in heap segment of memory
    char*originalText=(char*)malloc(100*sizeof(char));
    
    originalText=GetString();
    
    // convert strings to numbers(intigers)
    int shift=atoi(argv[1]);
    
    for(int i = 0, n = strlen(originalText) ; i < n; i++)
    {
        // store string elements in character variable
        char character = originalText[i];
        
        if (isalpha(character))
        {
            // check uppercase letters
            if (isupper(character))
            {
                uppercaseEncrypt(character,shift);
            }
            // check lowercase letters
            if (islower(originalText[i]))
            {
                lowercaseEncrypt(character,shift);
            } 
        }
        else
        {
            printf("%c",character);
        }
    }
    // relese that memory crated in heap segment
    free(originalText);
    
    printf("\n");
    
    return 0;
}

/**
 * Encrypt lowercase letters using original text n shifting key
 * And print it 
 */ 
void lowercaseEncrypt(char letter,int shiftingNumber){
    
    int alpha=(int)letter;
    shiftingNumber=shiftingNumber%26;
  
    if (alpha > 122-shiftingNumber)
    {
        alpha=((alpha+shiftingNumber)%122)+96;
    }
    else
    {
        alpha=alpha+shiftingNumber;
    }
    printf("%c",(char)alpha);

}
/**
 * Encrypt uppercasecase letters using original text n shifting key
 * And print it 
 */ 
void uppercaseEncrypt(char letter,int shiftingNumber){
int alpha=(int)letter;
shiftingNumber=shiftingNumber%26;

if (alpha > 90-shiftingNumber)
{
    // check the encrypt letter using shifting ket,if it is exceed the the alphabatical limit ,this will reset the encrypt letter
    alpha=((alpha+shiftingNumber)%90)+64;
}
else
{
    // check the encrypt letter using shifting ket, if it is not exceed the limit, this will add the shifting key to original letter
    alpha=alpha+shiftingNumber;
}

printf("%c",(char)alpha);

}
