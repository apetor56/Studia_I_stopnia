#include <stdio.h>
#include <unistd.h>

int main(int argc, const char* argv[])
{
    printf("Pierwszy komunikat\n");
    execl("potomny.x", "potomny.x", NULL);
    printf("Drugi komunikat\n");            // ta i poniższe linie kodu nie zostaną wykonane, ponieważ
                                            // funkcja execl() zakończy działanie bieżącego procesu
    return 0;
}