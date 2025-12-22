#include "Credentials.h"

static void Cesar(char chaine[], int length, int decalage)
{
    for (int i = 0; i < length; i++)
    {
        if(chaine[i] == '\0') break;

        int code = (int)chaine[i];
        code = code + decalage;
        
        if(code > 255) code = code - 255;
        if(code < 0) code = code + 255;

        chaine[i] = (char)code;
    }
}

void Credentials::crypt()
{
    Cesar(login, 20, 9);
    Cesar(password, 20, 5);
}

void Credentials::decrypt()
{
    Cesar(login, 20, -9);
    Cesar(password, 20, -5);
}