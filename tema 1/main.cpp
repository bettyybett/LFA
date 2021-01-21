#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{   fstream f("date.in");
    char cuv[20],lambda[1],lbj[20];
    int a,b,c,n,i,j,na=0,nb=0,dfa[10][10],p[10],q0,q[10],stari,fstari,inp,k,blabla=0,qf=0;

    f>>stari;
    for(i=1;i<=stari;i++)
        f>>q[i];
    f>>fstari;
    for(i=1;i<=fstari;i++)
        f>>p[i];
    f>>inp;
    for(i=1;i<=inp;i++)
        f>>lbj[i];
    f>>q0;
    blabla=q0;
    lambda[0]='r';
    for(i=1;i<=stari;i++)
        for(j=1;j<=inp;j++)
            dfa[i][j]=-1;
    for(i=1;i<=stari;i++)
        for(j=1;j<=inp;j++)
            f>>dfa[i][j];
    f>>cuv;
    n=strlen(cuv);


i=0;
if(cuv[i]==lambda[i])
    {cout<<"cuvantul apartine limbajului";
    nb=1;}
int found = 0;
if(nb==0)
{
  while(i<n)
        { found = 0;
        for(a=1;a<=inp;a++)
            if(cuv[i]==lbj[a])
                found=1;
            if(found == 1){
                for(j=1;j<=inp;j++)
                    if(lbj[j]==cuv[i])
                        k=j;
            } else {
              cout<<"cuvantul nu apartine limbajului";
                break;
            }

            blabla=dfa[blabla][k];

            i++;}
int foundFinalState=0;

if(found==1)
    for(i=1;i<=fstari;i++)
            if(blabla==p[i])
                foundFinalState=1;

if(foundFinalState==1)
cout<<"cuvantul apartine limbajului";
else
    cout<<"cuvantul nu apartine limbajului";



}

    return 0;
}
