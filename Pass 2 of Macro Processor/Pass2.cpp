#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    // f1 is the input file, f2 is the ntab file, f3 is the dtab file, f4 is the atab file and f5 is the output file
    FILE *f1, *f2, *f3, *f4, *f5;
    int i, len;
    // la is the label, mne is the mnemonic and opnd is the operand
    char mne[20], opnd[20], la[20], name[20], mne1[20], opnd1[20], arg[20];

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

    ntab.txt will contain this:
    EX1

    dtab.txt will contain this:
    EX1	&A,&B
    -	LDA	&A
    -	STA	&B
    -	MEND	-

    Note: ntab.txt and dtab.txt should be already created before running this program with the above contents.
    */

    f1 = fopen("input.txt", "r");
    f2 = fopen("ntab.txt", "r");
    f3 = fopen("dtab.txt", "r");
    f4 = fopen("atab.txt", "w+");
    f5 = fopen("op.txt", "w");
    fscanf(f1, "%s%s%s", la, mne, opnd);
    while (strcmp(mne, "END") != 0)
    {
        if (strcmp(mne, "MACRO") == 0)
        {
            fscanf(f1, "%s%s%s", la, mne, opnd);
            while (strcmp(mne, "MEND") != 0)
                fscanf(f1, "%s%s%s", la, mne, opnd);
        }
        else
        {
            fscanf(f2, "%s", name);
            if (strcmp(mne, name) == 0)
            {
                len = strlen(opnd);
                for (i = 0; i < len; i++)
                {
                    if (opnd[i] != ',')
                        fprintf(f4, "%c", opnd[i]);
                    else
                        fprintf(f4, "\n");
                }
                fseek(f2, SEEK_SET, 0);
                fseek(f4, SEEK_SET, 0);
                fscanf(f3, "%s%s", mne1, opnd1);
                fprintf(f5, ".\t%s\t%s\n", mne1, opnd);
                fscanf(f3, "%s%s", mne1, opnd1);
                while (strcmp(mne1, "MEND") != 0)
                {
                    if (opnd1[0] == '&')
                    {
                        fscanf(f4, "%s", arg);
                        fprintf(f5, "-\t%s\t%s\n", mne1, arg);
                    }
                    else
                        fprintf(f5, "-\t%s\t%s\n", mne1, opnd1);
                    fscanf(f3, "%s%s", mne1, opnd1);
                }
            }
            else
                fprintf(f5, "%s\t%s\t%s\n", la, mne, opnd);
        }
        fscanf(f1, "%s%s%s", la, mne, opnd);
    }
    fprintf(f5, "%s\t%s\t%s\n", la, mne, opnd);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    printf("Pass 2 of two-pass macro processor is completed");
    return 0;

}

/*
Output:
op.txt will contain this:
SAMPLE	START	1000
.	EX1	N1,N2
-	LDA	N1
-	STA	N2
N1	RESW	1
N2	RESW	1
-	END	-

Note: op.txt is the output file.

atab.txt will contain this:
N1
N2

Again, input files are already created before running this program with the above contents.
Input files: input.txt, ntab.txt and dtab.txt
Output files: op.txt and atab.txt

*/