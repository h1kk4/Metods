
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <map>

using namespace std;

int main() {
    multimap<int, string> myFirstMap;
    multimap<int, string> mySecondMap;
    char *buff = new char[256];
    ifstream f1, f2;
    f1.open("/Users/alex/ClionProjects/CLASSWORK/File1.txt");
    f2.open("/Users/alex/ClionProjects/CLASSWORK/File2.txt");
    int x(0);
    while (!f1.eof()) {
        x++;
        f1.getline(buff, 256, '\n');
        static_cast<string>(buff);
        myFirstMap.insert(pair<int, string>(x, buff));
    }

    int y(0);
    while (!f2.eof()) {
        f2.getline(buff, 256, '\n');
        static_cast<string>(buff);
        bool flag= false;
        y++;
        for (auto it=myFirstMap.begin(); it!=myFirstMap.end();it++){
            if (it->second==buff){
                flag=true;
                break;
            }
        }
        if (flag){
            mySecondMap.insert(pair<int,string>(y,buff));
        }
        else{
            cout<<"File2 "<<y<<" "<<buff<<'\n';
        }

    }

    for (auto it1=myFirstMap.begin(); it1!=myFirstMap.end();it1++){
        bool flag= true;
        for (auto it2=mySecondMap.begin(); it2!=mySecondMap.end();it2++){
            if (it1->second==it2->second){
                flag= false;
                break;
            }
        }
        if (flag){
            cout<<"File1 "<<it1->first<<" "<<it1->second<<'\n';
        }
    }
    f2.close();
    f1.close();
    //wow, changes
    delete[] buff;
    return 0;
}