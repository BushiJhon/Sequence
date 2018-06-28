#include <iostream>
#include "Sequence.h"
#include <time.h>
using namespace std;

int main(){
    clock_t start_1, start_2, end_1, end_2;
    Sequence a("dna.txt");
    cout<<a.length()<<endl;
    cout<<a.numberOf('T')<<endl;
    cout<<a.numberOf('A')<<endl;
    cout<<a.numberOf('C')<<endl;
    cout<<a.numberOf('G')<<endl;
    start_1=clock();
    cout<<a.longestConsecutive()<<endl;
    end_1=clock();
    cout<<(double)(end_1-start_1)/CLOCKS_PER_SEC<<endl;
    start_2=clock();
    cout<<a.longestRepeated()<<endl;
    end_2=clock();
    cout<<(double)(end_2-start_2)/CLOCKS_PER_SEC<<endl;
    return 0;
}
