//
//  main.cpp
//  LCS-improve
//
//  Created by Yi Hui Lai on 2021/4/27.
//

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>
using namespace:: std;
int max(int,int);

int array1[20000][20000];


int main(int argc, const char * argv[]) {
    
    int randomStringSize=10;
    cout<<"start";
    for(int repeat = 0 ;repeat<100;repeat++,randomStringSize+=30){
        string x,y;
        
        srand( time(NULL) );
        for(int i=0;i<randomStringSize;i++){
            int r = rand();
            r = r%26 +97;
            x = x+(char)r;
        }
        for(int i=0;i<randomStringSize;i++){
            int r = rand();
            r = r%26 +97;
            y = y+(char)r;
        }

        
        clock_t start,end;
        start = clock();
        int x_length = (int)x.size();
        int y_length = (int)y.size();
                
                
        
        for(int j=0;j<y_length;j++){
            for(int i=0;i<x_length;i++){
                if (i == 0 && j == 0) {
                    array1[i][j] = (x[i] == y[j]);
                    //arr[i][j] =(x[i] == y[j]);
                }
                else if (i == 0) {
                    if(x[i]==y[j]){
                        array1[i][j]=1;
                    }
                    else{
                        array1[i][j] = array1[0][j-1];
                    }
                    //arr[i][j] =(x[i] == y[j]);
                }
                else if (j == 0) {
                    if(x[i]==y[j]){
                        array1[i][j]=1;
                    }
                    else{
                        array1[i][j] = array1[i-1][0];
                    }
                   // arr[i][j] =(x[i] == y[j]);
                }
                
                else {
                    if(x[i]==y[j]){
                            //cout<<"enter";
                            array1[i][j] = array1[i-1][j-1]+1;
                    }
                    else if(x[i]!=y[j]){
                        array1[i][j] = max(array1[i-1][j],array1[i][j-1]);
                       
                    }
                }
            }
        }
        //cout<<array1[x_length-1][y_length-1];
       // cout<<endl;
        end = clock();
        double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        cout<<cpu_time_used;
        cout<<endl;
        


    }
    return 0;
}
 
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
//abcabc
//abbcad
