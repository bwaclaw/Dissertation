//
//  main.cpp
//  Simplemodel
//
//  Created by Jason Grealey on 26/09/2016.
//  Copyright © 2016 Jason Grealey. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

using namespace std;





//methods for determining whether a point is on the lattice or not
class Cell{
public:
    int Inf;
    int IsAble;
    
    
};




class Grid{

    
    
    
    public:
        int L; //length of lattice
    Cell ** grid;
    int *Iteration();
    Grid(int p);
    //operator string() const { return "Hi"; }
    
};

ostream & operator<<(ostream & Str, Grid const & v) {
    // print something from v to str, e.g: Str << v.getX();
    for (int i =0; i<v.L; i ++) {
        for (int j =0; j<v.L; j ++) {
            Str << v.grid[i][j].Inf << ' ';
            
        }
    
        Str << endl;
    }
    return Str;
}


 Grid::Grid(int p){
     L = p;
     grid = new Cell*[L];
     for (int i =0; i<L; i ++) {
         grid [i] = new Cell [L];
         for (int j =0; j<L; j ++) {
             grid[i][j].IsAble = 8;
             grid[i][j].Inf = 0;
             if (i == (L/2 -1) && j ==(L/2 -1)){
                 grid[i][j].Inf = 1;
                 
             }
             
         }
    
     }
     //g = & grid;
}

int *Grid::Iteration(){
    int *index;
    index = new int[3];
    index [2] = 0;
    index[0] = 0;
    index[1] = 1;
    for (int i=0; i<L; i++){
        for (int j=0; j<L; j++){
            if (grid[i][j].Inf == 1) {
                cout << "MAXIMUM OVERBORK" << endl;
                index [2] = 1;
                index [0] = i;
                index [1] = j;
                cout << index[0] << ',' << index[1] << endl;
            }
        }
            
    }
    
    return index;
}

int main() {
    // insert code here...

    Grid G(10);
   // G = new Grid (10);
    
    cout << G;
 
    int* d ;
    
    d = G.Iteration();
    for(int i =0; i < 2; i++){
        cout << d[i] << ',';
    }
    cout << endl;

    return 0;
}
