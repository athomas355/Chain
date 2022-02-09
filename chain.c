#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

struct cli_struct {
    bool p, c, s, i;
    int nprocs, nchars, sleeptime, niters;
    char* textfile;
};

struct cli_struct parse_args(int argc, char* argv[]) {
    struct cli_struct cli_args;
    int option;
    cli_args.p = false;
    cli_args.c = false;
    cli_args.s = false;
    cli_args.i = false;
    cli_args.nprocs = 4;
    cli_args.nchars = 80;
    cli_args.sleeptime = 3;
    cli_args.niters = 1;

    while((option = getopt(argc, argv, "hp:c:s:i:")) != -1) {
        switch(option) {
            case 'h':
                printf("chain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile\n\t"
                    "-h: help (usage) message\n\t"
                    "-p: Number of processes\n\t"
                    "-c: Number of characters read into the buffer\n\t"
                    "-s: Time to sleep in each iteration\n\t"
                    "-i: Numbner of iterations in the loop\n\t"
                    "textfile: File containing text to be read through stdin\n"
                );
                exit(0);
            case 'p':
                cli_args.p = true;
                cli_args.nprocs = atoi(optarg);
                break;
            case 'c':
                cli_args.c = true;
                cli_args.nchars = atoi(optarg);
                break;
            case 's':
                cli_args.s = true;
                cli_args.sleeptime = atoi(optarg);
                break;
            case 'i':
                cli_args.i = true;
                cli_args.niters = atoi(optarg);
                break;
            case '?':
                printf("Unknown option: %s\n", optarg);
                exit(1);    
        }
    }

    for(; optind < argc; optind++) {
        cli_args.textfile = argv[optind];
    }

    return cli_args;
}

int main (int argc, char *argv[]) {
    struct cli_struct args = parse_args(argc, argv);
    pid_t childpid = 0;
    int i, n, c;
    char mybuf[args.nchars];
    //printf("%d\n", args.nchars);

    // if (argc != 2){ /* check for valid number of command-line arguments */
    //     fprintf(stderr, "Usage: %s processes\n", argv[0]);
    //     return 1;
    // }

    // n = atoi(argv[1]);
    for (i = 1; i < args.nprocs; i++)
        if (childpid = fork())
            break;

    for(int i = 0; i < args.niters; i++) {
        // sleep(args.sleeptime);
        // wait(NULL);
        
        //default
        // fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
        //     i, (long)getpid(), (long)getppid(), (long)childpid);

        //step 7:    
        // fprintf(stderr, "i:%d", args.niters);
        // fprintf(stderr, " process ID:%ld", (long)getpid());
        // fprintf(stderr, " parent ID:%ld", (long)getppid());
        // fprintf(stderr, " child ID:%ld\n", (long)childpid);

        //step 8:
        for(int j = 0; j < args.nchars; j++) {
            if(c != EOF ) {
                c = getchar();
                mybuf[j] = c;
                
            }
        }
        mybuf[args.nchars] = '\0';
         fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld mybuf:%s\n",
             i, (long)getpid(), (long)getppid(), (long)childpid, mybuf);
    }

    
    //printf("%s", mybuf);
    return 0;
}