#include <iostream>
#include <string.h>
using namespace std;
class Parse
{
    public:
        void func();
        void output();
        char input[100];
    private:
        char words[101][20];
        int counter;
};
void Parse::func()
{
    int l = strlen(input),i,j;
    int stage =0, mark = 0;
    counter = 0;
    for(i=0;i<l;i++)
    {
        if(stage==0)
        {
            if(input[i]==':' && input[i+1]=='/' && input[i+2]=='/')
            {
                for(j=mark;j<i;j++)words[counter][j-mark]=input[j];
                words[counter][j-mark]='\0';
                mark=i+3;
                i+=2;
                counter++;
                stage++;
            } 
        }
        else if(stage == 1)
        {
            if(input[i]=='.' || input[i]=='/')
            {
                for(j=mark;j<i;j++)words[counter][j-mark]=input[j];
                words[counter][j-mark]='\0';
                mark=i+1;
                counter++;
                if(input[i]=='/')stage++;
            }
        }
        else if(stage == 2)
        {
            if(input[i]=='.' || input[i]=='/')
            {
                for(j=mark;j<i;j++)words[counter][j-mark]=input[j];
                words[counter][j-mark]='\0';
                mark=i+1;
                counter++;
                if(input[i]=='.')stage++;
            }            
        }
        else if(stage == 3)
        {
            for(j=mark;j<l;j++)words[counter][j-mark]=input[j];
            words[counter][j-mark]='\0';
        }
        
    }
}

void Parse::output()
{
    int i;
    for(i=0;i<counter;i++)printf("%s, ",words[i]);
    printf("%s\n",words[i]);
}

int main()
{
    Parse parse;
    char a[100];
    cin>>a;
    strcpy(parse.input,a);
    parse.func();
    parse.output();
    system("pause");
    return 0;
} 
/*
4. �볢���á�C++0x������C++11 & STL�����ֲ�ͬ�Ĵ�����ָ�һ��url�����ϴ����뵽�����ϡ�

For example:

Input: http://msdn.microsoft.com/en-us/library/vstudio/hh279674.aspx

Output: http, msdn, Microsoft, com, en-us, library, vstudio, hh279674, aspx

�����ص㣺

1. ��Ķ����ʹ�ã�������Ա�Ƿ�����

2. ��������ļ�鼰����³���ԵĿ���

3. STL��C++11Ԫ�ص�ʹ��

4. ��http://֮�⣬ �Ƿ��п���ftp:// site:// �����

5. �Ƿ���url�е�����

6. �㷨�Ƿ����Ч

7. ������

*/ 
