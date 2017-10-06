#include<iostream>
#include<cmath>
#include<string>
using namespace std;
char hard[8]= {'b','c', 'd', 'g', 'k', 'n', 'p', 't'};
char endd[3] = {'a','o','u'};
bool notIn(char c){
    c = tolower(c);
    for(int i=0;i<8;i++){
        if(hard[i]==c)
            return false;
    }
return true;
}
char ending(char c){
    c = tolower(c);
    char cc;
    int x=99;

    for(int i=0;i<3;i++){
        int v = int(c)- int(endd[i]);
        if(v<0)
            v*=-1;
        if(v<x){
            cc= endd[i];
            x = v;
        }else if(v==x){
            if(int(cc)>int(endd[i])){
                cc= endd[i];
                x = v;
            }
        }
    }
return cc;
}
char nearest(char c,bool b){
    c = tolower(c);
    char cc;
    int x=99;

    for(int i=0;i<8;i++){
        int v = int(c)- int(hard[i]);
        if(v<0)
            v*=-1;
        if(v<x){
            cc= hard[i];
            x = v;
        }else if(v==x){
            if(int(cc)>int(hard[i])){
                cc= hard[i];
                x = v;
            }
        }
    }
    if(b){
        cc= toupper(cc);
    }
return cc;
}
int main(){
//while(true){

    string m;
    getline(cin, m);
    string x=" "+m+" ";

    char start;
    char last;
    int gg =0;
    for(int i=1;i<x.size()-1;i++){
        char a = x[i-1];
        char b = x[i];
        char c = x[i+1];

        bool t = true;
        if(a=='-'){
            if(!notIn(b)){
                 b = start;
            }
        }
        else if(a==' '){
            gg = 0;
            if(notIn(b)){
                if(isupper(b))
                b =nearest(b,true);
                else
                    b =nearest(b,false);
            }
            start = tolower(b);
        }
        else if(!notIn(b) && !notIn(c)){
                if(gg!=0)
            b = start;
        }
        else if(!notIn(b) && !notIn(b)){
            if(gg!=0)
            b = start;
        }

        if(b!='-'){
            cout<<b;
        }else{
            gg++;
        }
        if(c==' '){
            if(!notIn(b)){
                cout<<ending(b)<<"h";
            }
        }
    }
cout<<endl;
//}
return 0;
}
