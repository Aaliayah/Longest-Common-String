//
//  main.cpp
//  LCS_improvement
//
//  Created by Yi Hui Lai on 2021/4/29.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>
using namespace::std;
int main(int argc, const char * argv[]) {
    string x,y;
    cin>>x;
    cin>>y;
    clock_t start,end;
    start = clock();
    int x_length = (int)x.size();
    int y_length = (int)y.size();
    map<char,vector<int>> m;
    map<char,vector<int>> ::iterator iter;
    vector<int> lis;
    for(int i=0;i<x_length;i++){
        iter = m.find(x[i]);
        if(iter == m.end()){
            vector<int> v;
            v.push_back(i);
            m[x[i]] = v;
        }
        
        else{
            vector<int> temp;
            temp = iter->second;
            temp.push_back(i);
            //char c = iter->first;
            m[iter->first] = temp;
        }
        
    }
    
    for(int i=0;i<y_length;i++){
        iter = m.find(y[i]); //search in map = O(logn)
        if(iter == m.end()){
            continue;
        }
        else{
            for(int j=(int)iter->second.size();j>0;j--){
                lis.push_back(iter->second[j-1]);
            }
            
        }
    }
    
    // do lis lis to lisOutcome
    
    vector<int> lisOutcome [lis.size()+1];
    lisOutcome[1].push_back(lis[0]);
    int maxLength = 1;
    for(int i=1;i<lis.size();i++){
        if(lisOutcome[maxLength][maxLength-1]<lis[i]){

            vector<int> temp;
            temp = lisOutcome[maxLength];
            temp.push_back(lis[i]);
            maxLength++;
            lisOutcome[maxLength] = temp;

        }
        else{
            vector<int> temp;

            int index = lower_bound(lisOutcome[maxLength].begin(), lisOutcome[maxLength].end(),lis[i])- lisOutcome[maxLength].begin();
            
            for(int k=0;k<index;k++){
                temp.push_back(lisOutcome[maxLength][k]);
            }
            temp.push_back(lis[i]);
            lisOutcome[index+1] = temp;
            
        }
    }
   
    for(int i=0;i<lisOutcome[maxLength].size();i++){
        
        cout<<x[lisOutcome[maxLength][i]];
    }
    cout<<endl;
    end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<"Time:"<< cpu_time_used;
    cout<<endl;
    return 0;
}



/*
hhheihisojfie
heihsi

uhusieoeie
hueei
 
abcabc
abbcad
 */



