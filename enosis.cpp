#include <bits/stdc++.h>
using namespace std;


int main()
{
    string str="The day is sunny";

    stack<string> stk;
    int l=str.size();
    string word="";
    for(int i=0; i<l; i++ ){
        if(str[i]!=32){
            word+= str[i];
        }
        else if(str[i]==32){
            stk.push(word);
            word="";
        }
    }
    stk.push(word);

    while(!stk.empty()){
        string top= stk.top();
        cout<< top<< " ";
        stk.pop();
    }

    return 0;
}
