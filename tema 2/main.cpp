#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
ifstream f("date.in");
int fstari,stari,inp;
int matrice[10][10];
int m_nfa[10][10],q[10],m_dfa[10][10],n,q0;
void creare(int v[])
{
    for(int i=0;i<sizeof(v)-1;i++)
        for(int j=i+1;j<sizeof(v);j++)
         if(v[i]>v[j])
            swap(v[i],v[j]);
    for(int i=1;i<sizeof(v);i++)
        if(v[i]==v[i-1])
    {
        v[i]=v[i-1];
        i--;
    }
}
void crdfa()
{   int aux[10];
    int l=0;
    matrice[0][0]=q0;
    int viz[10][10];
    //viz[0][0]=q0;
    int ok=0;
    while(ok==0)
    {for(int i=1;i<=stari;i++)
        for(int j=1;j<=inp;j++)
                {   int poz=matrice[i][j];
                    if(matrice[poz][j-1]==1)
                    {
                        l++;
                        aux[l-1]=1;
                    }
                }
                creare(aux);
//                m_dfa[i][j]=aux[i];
        for(int x=0;x<stari;x++)
            if(viz[x]==aux)
                ok=1;
        if(ok==0)
          {
              int mat[10][10];
              mat[0][0]=aux[0];
          }
    }}

void afisareDfa()
{ cout<<"m";
  for (int i=0;i<stari;i++)
  {for (int j=1;j<=inp;j++)
      {cout<<"starea: ";
      for(int j=0;j<sizeof(m_dfa);j++)
       {cout<<m_dfa[i][j];
        cout<<" "<<char (65+j)<<" " ;}
          for(int k=0;k<sizeof(m_dfa);k++)
            {cout<<m_dfa[i][k];
            cout<<endl;}
      }
  }
  //cout<<endl<<"stare initiala = ";
  for(int i=0;i<sizeof(m_dfa);i++)
    cout<<m_dfa[0][i];
  cout<<endl;
}
int main()
{
    int n,v[10],q0,q[10],lbj[10],p[10],i,bla;
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
    for(int i=0;i<stari;i++)
        for(int j=0;j<inp;j++)
    {
        matrice[i][j]=-1;
    }
    for(i=1;i<=stari;i++)
        for(int j=1;j<=inp;j++)
            f>>matrice[i][j];
    crdfa();
    afisareDfa();
    //verificare(v,cuv);

}
