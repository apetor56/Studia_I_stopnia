#define _POSIX_C_SOURCE 1
#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>

#define ITERATIONS 3

int main(int argc, const char* argv[])
{
    int fork_value = fork();

    switch(fork_value)                                      // pierwszy switch + fork wykonywane sa dla
    {                                                       // pierwszego glownego procesu
        case -1:
        perror("fork error");
        exit(EXIT_FAILURE);

        case 0:
        if(setpgid(getpid(), 0) == -1){                     // proces potomny staje sie liderem nowej grupy,
            perror("setpgid error");                        // + obsluga bledu
            exit(EXIT_FAILURE);
        }

        if(signal(atoi(argv[2]), SIG_IGN) == SIG_ERR){      // ten proces potomny ma ignorowac przychodzacy do
            perror("signal error");                         // niego sygnal (ktory jest podawany w linii komend)
            exit(EXIT_FAILURE);                             // + obsluga bledu
        }
        break;

        default:
        break;
    }

    if(fork_value == 0){                                    // "jesli jest to proces potomny, utworzony powyzej"
        for(int i = 0; i < ITERATIONS; i++)
        {
            switch (fork())                                 // 3 razy wywolana funkcja fork dla p. potomnego,
            {                                               // ktory jest liderem swojej grupy
                case -1:
                perror("fork error");
                exit(EXIT_FAILURE);

                case 0:
                execl("./obsluga.x", "obsluga.x", argv[1], argv[2], NULL);  // nowo powstale procesy uruchomiaja
                perror("execl error");                                      // program obsluga.x wraz z argumentami
                _exit(EXIT_FAILURE);                                        // podanymi wczesniej w linii komend
                                                                            // + obsluga bledu
                default:
                break;
            }
        }

        for(int j = 0; j < ITERATIONS; j++)         // jesli proces utworzyl juz swoje wszystkie p.potomne
        {                                           // (tutaj 3) to wywoluje odpowiednia liczbe razy funkcje
            int f1;                                 // wait + obsluga bledu
            int status = wait(&f1);                 // p. potomne tak dlugo beda "zawieszone", dopoki
                                                    // nie dostana sygnalu od glownego procesu
            if(status == -1){
                perror("wait error");
                exit(EXIT_FAILURE);
            }
            printf("wait status: %d\n", status);
        }
    }

    else{                                           // "jesli jest to glowny proces"
        sleep(1);                                   // proces glowny jest uspiony, by procesy potomne
                                                    // jego procesu potomnego mogly wykonac program obsluga.x
        
        
        int m_pgid = (-1) * getpgid(fork_value);    // uzyskanie ujemnego PGID p.potomnego glownego procesu
        if(kill(m_pgid, 0) == -1){                  // sprawdzenie czy taka grupa istnieje
            perror("kill && PGID error");
            exit(EXIT_FAILURE);
        }
        kill(m_pgid, atoi(argv[2]));                // jesli istnieje, to do calej grupy wysylany jest sygnal

        int f2;
        if(wait(&f2) == -1){                        // nastepnie glowny proces czeka na zakonczenie swojego
            perror("wait father error");            // p.potomnego
            exit(EXIT_FAILURE);
        }
    }
}