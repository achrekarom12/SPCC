// Pass 1 of two pass macro processor

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    // f1 is the input file, f2 is the ntab file and f3 is the dtab file
    FILE *f1, *f2, *f3;
    // la is the label, mne is the mnemonic and opnd is the operand
    char mne[20], opnd[20], la[20];
    /*
    Create three files: input.txt, ntab.txt and dtab.txt beforehand.
    Input file will contain this: 

    EX1	MACRO   &A,&B
    -	LDA	&A
    -	STA	&B
    -	MEND	-
    SAMPLE	START	1000
    -	EX1	N1,N2
    N1  RESW	1
    N2	RESW	1
    -	END	-

    Note: There is tab after each word in the input file. The macro which is defined is named as 'EX1' and it takes two parameters
    which are &A and &B. The macro is called 'EX1' and it takes two arguments which are N1 and N2. The macro is called in the
    input file and the arguments are passed to the macro. The macro is expanded and the output is stored in the file 'dtab.txt'.
    The macro name and the arguments are stored in the file 'ntab.txt'.

    */

    f1 = fopen("input.txt", "r");
    f2 = fopen("ntab.txt", "w+");
    f3 = fopen("dtab.txt", "w+");
    if (f1 == NULL || f2 == NULL || f3 == NULL)
    {
        printf("Error in opening files");
        exit(0);
    }
    // Read the first line from the input file
    fscanf(f1, "%s%s%s", la, mne, opnd);
    //  Read the complete file
    while (strcmp(mne, "MEND") != 0)
    {
        // If the mnemonic is 'MACRO' then store the macro name and the arguments in the ntab file
        if (strcmp(mne, "MACRO") == 0)
        {
            fprintf(f2, "%s\n", la);
            fprintf(f3, "%s\t%s\n", la, opnd);
        }
        // If the mnemonic is not 'MACRO' then store the mnemonic and the operand in the dtab file
        else
            fprintf(f3, "%s\t%s\n", mne, opnd);
        fscanf(f1, "%s%s%s", la, mne, opnd);
    }
    // Store the 'MEND' in the dtab file
    fprintf(f3, "%s", mne);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    printf("Pass 1 of two-pass macro processor is completed");
    return 0;
}

/*
Output:
ntab.txt will contain this:
EX1

dtab.txt will contain this:
EX1	&A,&B
LDA	&A
STA	&B
MEND

*/