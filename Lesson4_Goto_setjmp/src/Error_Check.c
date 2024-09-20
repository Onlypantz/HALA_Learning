#include<stdio.h>
#include"Error_Check.h"



void ReadFile()
{
    printf (".... \n");
    THROW (FILE_ERROR, "File is not available");
}

void NetworkOperation()
{
    printf ("Network checking...\n");
    THROW (NETWORK_ERROR, "Network is not available");
}

void CaculateData()
{
    printf ("Caculating...\n");
    THROW (CACULATION_ERROR, "Unexpected Error");
}