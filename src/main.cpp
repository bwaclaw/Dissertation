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
#include <ctime>

using namespace std;





//methods for determining whether a point is on the lattice or not
class Cell{
public:
    int Inf;
    int IsAble;
    
    
};



//Grid class
class Grid{

    
    
    //attributes
    public:
        int L; //length of lattice
    //intialising a grid 2-d array with Cell attibutes
    Cell ** grid;
    //initialising initilaising 1D array
    int *Iteration();
    // initalising Grid attribute
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

//grid constructor
 Grid::Grid(int p){
     //argument of Grid becomes length and height of grid
     L = p;
     //defining a grid as a 1-d Cell array
     grid = new Cell*[L];
     for (int i =0; i<L; i ++) {
         // making every 1-d cell [i] have another dimension - of lenth L - making 2-d grid
         grid [i] = new Cell [L];
         
         
         for (int j =0; j<L; j ++) {
         
             //giving every cell in grid 8 open neighbours
             
             grid[i][j].IsAble = 8;
             
             //making all cells uninfected
             grid[i][j].Inf = 0;
             //infecting middle cell
             if (i == (L/2 -1) && j ==(L/2 -1)){
                 grid[i][j].Inf = 1;
                 
             }
             
         }
    
         
         
         //spreading loops
         
         for (int i =0; i<10; i++) {
             for (int j = 0; j<10; j++) {
                 i = rand()%10 +1;
                 j = rand()%10 +1;
                 
                 //right neighbour will become infected with 1/6 probability
                 if ((grid[i][j].Inf = 1) && (grid[i+1][j].Inf = 0) && (rand()%6 +1 == 2)) {
                     grid[i+1][j].Inf = 1;
                 }
             }
         }
         
         
     }
     //g = & grid;
 }
//method for the spreading of cells
//int **Grid::Spread(){
    
    //getting a checker that will randomly choose from grid and replicate infections to neighbours
    

//}

//method for checking where infected cell is
// pulling array with Grid attributes and initialising the function Iteration
int *Grid::Iteration(){
    
    //initialising array
    
    int *index;
    // {0 = i pos, 1= j pos, 2 = inf (1 or 0)}
    index = new int[3];
    
    //intialising an infected cell at {0,0}
    index [2] = 0;
    index[0] = 0;
    //already intialised above
    //index[1] = 1;

    
    //printing here to stop loop printing once cancer has spread
    
    cout << "Infected cells are present here" << endl;
    
    for (int i=0; i<L; i++){
        for (int j=0; j<L; j++){
           
            // printing position of infected cell
            if (grid[i][j].Inf == 1) {
                
                index [2] = 1;
                index [0] = i;
                index [1] = j;
               // cout << index[0] << ',' << index[1] << endl;
            }
        }
            
    }
    
    return index;
}


int main() {
    
    // seeding the random number
    srand(time(NULL));
    
    
    //testing the random number
    // cout << rand() % 100 + 1 << endl;

    //testing with grid of size length and height 100
    Grid G(10);
    
   // G = new Grid (10);
    

    //printing the grid
    cout << G;
 
    //initalising array d
    int* d ;
    
    //printing d which shows where the infected cell is
    d = G.Iteration();
    for(int i =0; i < 2; i++){
        cout << d[i] << ',';
    }
    cout << endl;

    return 0;
}
