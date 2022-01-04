#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "csr.h"
int main(int argc, char* argv[])
{
    char* prg = argv[0];
    char* opt = argv[1];
    char* msg = argv[2];
    if (argc == 1)
    {
        fprintf(stderr, "%s: no option and massage\n", prg);
        exit(3);
    }
    if (argc == 2)
    {
        if ((strcmp(opt, "-E") == 0) || (strcmp(opt, "-D") ==
                                         0))
        {
            fprintf(stderr, "%s: no message\n", prg);
            exit(9);
        }
        else
        {
            fprintf(stderr, "%s: no option\n", prg);
            exit(8);
        }
    }
    if (argc == 3)
    {
        if (strcmp(opt, "-E") == 0)
            CSR_encrypt(msg);
        else if (strcmp(opt, "-D") == 0)
            CSR_decrypt(msg);
        else if (strcmp(opt, "-EM") == 0)
            CSR_enc_math(msg);
        else if (strcmp(opt, "-DM") == 0)
            CSR_dec_math(msg);
        else
        {
            fprintf(stderr, "%s: illegal option: %s\n", prg,
                    opt);
            exit(1);
        }
    }
    if (argc >= 4)
    {
        fprintf(stderr, "Too many strings...");
        exit(7);
    }
    exit(0);
}
