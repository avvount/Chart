#include <iostream>
#include <map>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>


struct mystruct
{
    double a;
    int x;
};


void print_pid()
{
    printf("pid=%d\n", getpid());
}

void print_pmap(int LINE)
{
    std::cout << LINE << "\t" ;
    std::fflush(stdout);
    char szCmd[64];
    snprintf(szCmd, sizeof(szCmd), "pmap -d %d | tail -n 1", getpid());
    system(szCmd);
}

void test_map(int n, int LINE)
{
	
    std::unordered_map<size_t, std::vector<mystruct> > m;
    
    for (size_t i = 0; i < 10000; i++)
    {
        m[i] = std::vector<mystruct>(n);
    }
    print_pmap(LINE);
}
int main(int, char**) {
    print_pid();
    print_pmap(__LINE__);

    for (size_t i = 0; i < 10; i++)
    {
        test_map(100*i, __LINE__);
        print_pmap(__LINE__);
    }
    
}
