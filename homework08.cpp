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
4. 请尝试用“C++0x”，“C++11 & STL”两种不同的代码风格分割一个url，并上传代码到博客上。

For example:

Input: http://msdn.microsoft.com/en-us/library/vstudio/hh279674.aspx

Output: http, msdn, Microsoft, com, en-us, library, vstudio, hh279674, aspx

考察重点：

1. 类的定义和使用，基本成员是否完整

2. 输入参数的检查及其他鲁棒性的考虑

3. STL和C++11元素的使用

4. 除http://之外， 是否有考虑ftp:// site:// 等情况

5. 是否考虑url中的中文

6. 算法是否简洁高效

7. 代码风格

*/ 
