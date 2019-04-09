#include <stdio.h>
#include <stdlib.h>

const char * prog_name = "run_per";

static void
print_usage_and_die(void)
{
    fprintf(stderr, "usage:\n%s [integer]\n", prog_name);
    exit(1);
}



static void
per(uint64_t n)
{
    size_t step = 1;

    while (n > 10) {
        char         str[32];
        const char * i = &str[0];
        uint64_t     prod = 1;

        sprintf(str, "%llu", n);

        while(*i) {
            prod *= (*i - '0');
            ++i;
        }

        n = prod;
        printf("step: %zu: %s -> %llu\n", step, str, n);
        ++step;
    }

    return;
}


     
int
main(int    argc,
     char * argv[])
{
    if (argc != 2) {
        print_usage_and_die();
    }

    uint64_t n = atoll(argv[1]);

    if (!n) {
        print_usage_and_die();
    }

    per((uint64_t) n);
}
