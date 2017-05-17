#include"graph.h"
int main(){
    AdjMatrix A=   {
             1,1,1,1,0,0,1,0,0 ,
             1,1,1,0,0,0,0,0,0 ,
             1,1,1,0,0,0,0,0,0 ,
             1,0,0,1,1,1,0,0,0 ,
             0,0,0,1,1,1,0,0,0 ,
             0,0,0,1,1,1,0,1,0 ,
             1,0,0,0,0,0,1,1,1 ,
             0,0,0,0,0,1,1,1,1 ,
             0,0,0,0,0,0,1,1,1
    };
    MGraph G;
    CreatGraph(&G, A);
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            if(i!=j)BFSTraverse(G, i, j);
        }
    }
    //BFSTraverse(G, 9, 5);
}