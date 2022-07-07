#include<bits/stdc++.h>
using namespace std;

map<char,char> mp;
void printEncoding(string s, string asf){
    // write your code here
    if(s[0] == '0'){
        return ;
    }
    if(s.size() == 0){
        cout << asf << endl;
        return;
    }
    else if(s.size() == 1){
        char ch = s[0];
        if(ch == '0'){
            return ;
        }
        int chv = ch - '0';
        char code = (char)(chv+'a'-1) ;//1->a , 2->b and so on
        cout << asf+code << endl;
        return;
    }
    
    // i have 2 choices either 1char or 2chars
    
    char ch1 = s[0];
    string ros1 = s.substr(1);
    if(ch1 == '0'){
        return;
    }
    else{
        int ch1v = ch1-'0';
        char code = (char)(ch1v+'a'-1);
        printEncoding(ros1,asf+code);
    }
    
    string ch12 = s.substr(0,2);
    string ros2 = s.substr(2);
    int ch12v = stoi(ch12);
    if(ch12v >= 27){
        return;
    }
    else{
        char code = (char)(ch12v+'a'-1) ;
        printEncoding(ros2,asf+code);
    }
}

int main(){
    string str;
    cin>>str;
    
    printEncoding(str,"");
    
}
