#ifndef SEQUENCE_H
#define SEQUENCE_H

using namespace std;

class Sequence{
    public:   
    Sequence(string filename);
    int length();
    int numberOf(char base);
    string longestConsecutive();
    string longestRepeated();
    private:
    int count_all;
    int count_A;
    int count_T;
    int count_C;
    int count_G;
    char all[1500000];
};

#endif
