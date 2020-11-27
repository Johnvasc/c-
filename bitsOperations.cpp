#include <iostream>
using namespace std;

int main()
{
    int bin[8]; int bit;
    for(int i=7; i>=0; i--){
        cin>>bin[i];
    }
    int escolha;
    do{
        cout<<"1 - bit read\n2 - setbit\n3 - resetbit\n0 - sair\n";
        cin>>escolha;
        if(escolha!=0){
            cout<<"escolha o bit a operar\n";
            cin>>bit;
        }
        if(escolha==1){
            int bin2[]={0,0,0,0,0,0,0,0};
            bin2[bit-1]=1;
            for(int i=7; i>=0; i--){
                cout<<bin[i]*bin2[i]<<" ";
            }
        }
        else if(escolha==2){
            int bin2[]={0,0,0,0,0,0,0,0};
            bin2[bit-1]=1;
            for(int i=7; i>=0; i--){
                cout<<bin[i]+bin2[i]<<" ";
            }
        }
        else if(escolha==3){
            int bin2[]={1,1,1,1,1,1,1,1};
            bin2[bit-1]=0;
            for(int i=7; i>=0; i--){
                cout<<bin[i]*bin2[i]<<" ";
            }
        }
        cout<<"\n";
    }while(escolha!=0);
    return 0;
}
