#include <stdio.h>
#include <setjmp.h>
#include <Error_Check.h>

jmp_buf buf;
char error_message [50];
int exception_code;

int main ()
{
    TRY{
        ReadFile();
        NetworkOperation();
        CaculateData();
    }
    CATCH(FILE_ERROR){
        printf ("%s\n",error_message);
    }
    CATCH(NETWORK_ERROR){
        printf ("%s\n",error_message);
    }
    CATCH (CACULATION_ERROR){
        printf ("%s\n",error_message);
    }

    return 0;
}