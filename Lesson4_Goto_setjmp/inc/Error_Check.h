#ifndef __ERROR_CHECK_H
#define __ERROR_CHECK_H

#include<setjmp.h>
#include<string.h>



extern jmp_buf buf;
extern char error_message [50];
extern int exception_code;
enum ERROR_CODE
{
    NO_ERROR,
    FILE_ERROR,
    NETWORK_ERROR,
    CACULATION_ERROR
};

#define TRY  if ((exception_code = setjmp(buf)) == NO_ERROR) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x, y) strcpy(error_message, y); longjmp (buf, (x))

void ReadFile();
void NetworkOperation();
void CaculateData();



#endif