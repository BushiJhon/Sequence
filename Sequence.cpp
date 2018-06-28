#include <iostream>
#include "Sequence.h"
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#pragma GCC diagnostic error "-std=c++11"
using namespace std;

struct temp{
    char* pos;
    int length;
};

int newStrcmp(const void* a, const void* b){ 
    temp A=*((temp*)a);
    temp B=*((temp*)b);
    for(int i=0;i<A.length&&i<B.length;++i)
    {
       if(*(A.pos+i)!=*(B.pos+i))
       {
          return (*(A.pos+i))-(*(B.pos+i));
       }
    }
    return A.length-B.length;
}

Sequence::Sequence(string filename){
    fstream input_stream;
    char chstring[100];
    strcpy(chstring,filename.c_str());
    input_stream.open(chstring);
    int i=0;
    int a=0;
    int t=0;
    int c=0;
    int g=0;
    while(input_stream)
    {
      char ch;
      input_stream>>ch;
      if(input_stream.fail())
      {
        break;
      }
      if(ch!='\n')
      {
         all[i]=ch;
         ++i;
         switch(ch)
         {
           case 'A':++a;break;
           case 'T':++t;break;
           case 'C':++c;break;
           case 'G':++g;break;
         }
      }
     }
     count_all=i;
     count_A=a;
     count_T=t;
     count_C=c;
     count_G=g;
}

int Sequence::length(){
    return count_all;
}

int Sequence::numberOf(char base){
    switch(base)
    {
      case 'A':return count_A;break;
      case 'T':return count_T;break;
      case 'C':return count_C;break;
      case 'G':return count_G;break;
    }
}

string Sequence::longestConsecutive(){
    int countAll=1;
    char base=all[0];
    int count=1;
    for(int i=0;i<count_all;++i)
    {
          for(int j=i+1;j<count_all;++j)
          {
             if(all[i]==all[j])
             {
                ++count;
                if(j==count_all-1)
                {
                   if(count>countAll)
                   {
                      countAll=count;
                      base=all[i];
                   }
                   count=1;
                   break;
                }
              }
             else
             {
                if(count>countAll)
                {
                   countAll=count;
                   base=all[i];
                 }
                 count=1;
                 i=j;
                 break;
              }
            }
        }
     string returnChar;
     for(int i=0;i<countAll;++i)
     {
        returnChar=returnChar+base;
      }
     return returnChar;
}

string Sequence::longestRepeated(){
   temp* t = (temp*) new temp[count_all];
   char* ch= (char*)all;
   for(int i=0;i<count_all;++i)
   {
      t[i].pos=ch+i;
      t[i].length=count_all-i;
   }
   qsort(t,count_all,sizeof(t[0]),newStrcmp);
   int postion=0;
   int longest=0;
   for(int i=0;i<count_all-1;++i)
   {
      int j;
      for( j=0;j<t[i].length&&j<t[i+1].length;++j)
      {
         if(*(t[i].pos+j)!=*(t[i+1].pos+j))
         {
            if(j>longest)
            {
              longest=j;
              postion=i;
            }
            break;
          }
       }
       if(j>longest)
       {
          longest=j;
          postion=i;
       }
    }
    string returnS;
    for(int i=0;i<longest;++i)
    {
       returnS=returnS+*(t[postion].pos+i);
    }
    delete []t;       
    return returnS;
}


         
              
       
