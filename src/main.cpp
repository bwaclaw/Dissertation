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
    
    // don't need this attribute because it can make it too complicated for updating after infections
    //int IsAble;
    
    
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
             
            // grid[i][j].IsAble = 8;
             
             //making all cells uninfected
             grid[i][j].Inf = 0;
             //infecting middle cell
             if (i == (L/2 -1) && j ==(L/2 -1)){
                 grid[i][j].Inf = 1;
                 
             }
             
         }
     
     
     }
       // infecting a few more cells at the initlisation of the grid
       grid [5][4].Inf=1;
       grid [4][5].Inf=1;
       grid [5][5].Inf=1;
     //grid [4][5].Inf=1;
       //grid [5][5].Inf=1;
     
     
 


                //want a timestep method so we can randomly choose cell that is infected and spread to neighbour

            //setting time parameter
            double t = 0;




        while (t <=200000) {
            
            int i = rand()%L;
            int j = rand()%L;
            
        //ensuring x,y lie withing L-1 so that we can spread to edge
            int y = min(i+1,L-2);
            int x = min(j+1,L-2);
            //cout << x << ' ' << i << ' '<< y << ' ' << j << endl;
            //if randomly selecting a infected cell
            if(grid[x][y].Inf == 1){
                
                //rightwards infection
                if(grid[x][y+1].Inf == 0) {
                    grid[x][y+1].Inf = 1;
                    
                }
                //leftwards
                else if(grid[x][y-1].Inf == 0){
                    grid[x][y-1].Inf=1;
                    
                 }
                //upwards
                else if(grid[x+1][y].Inf == 0){
                    grid[x+1][y].Inf=1;
                    
                }
                //downwards
                else if(grid[x-1][y].Inf==0){
                    grid[x-1][y].Inf=1;
                    
                }

                else{
                }
            //cout << x+1 << ' ' << x-1 << ' '<< y+1 << ' ' << y-1 << endl;
            
                
                
                
                
                
            }
            t = t + 1;
        }
     


            
            
 }
            
            
            
            










































            //previous infection method of translating the grid is not being used anymore
            // ---------------------------------------------------------------------------------------


     //}
     //g = & grid;
     
     
     
     //spreading loops a number of times and 1/6 of the time will spread to the right
    /// int b = 0;
     
     //for (int i =0; i<L; i ++) {
         
        // for (int j = 0; j<L; j ++) {
             
             
           //  cout << "is this working" << endl;
             //i = rand()%L;
             //j = rand()%L;
             
             //cout << i << j << endl;
             //cout << *this << endl;
             //Cell g = grid[i][j];
             
             // el ultimo
             //int y = min(j+1,L-1);
              //cout << grid[i][j].Inf << endl;
             //right neighbour will become infected with 1/6 probability
              //if ((grid[i][j].Inf) == 1 && grid[i][y].Inf ==0) {
             //grid[4][5].Inf = 1;
                 // b = 1;
                  //grid[i][y].Inf = 1;
                  //cout << grid[i][y].Inf << endl;
                  //cout << y << " " << j << endl;
             //cout << "success" << endl;
                //  break;
             //cout << "is this working" << endl;
             
             //  }
             //else grid[i+1][j].Inf = 0;
        // }//if(b==1) {break;}
     //}
     
     //}
     
            // --------------------------------------------------------------------------------------------------------
 
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
    Grid G(100);
    
   // G = new Grid (10);
    

    //printing the grid
    cout << G;
 
    //initalising array d
    int* d ;
    
    //printing d which shows where the infected cell is
    //d = G.Iteration();
    //for(int i =0; i < 2; i++){
       // cout << d[i] << ',';
    //}
    //cout << endl;

    return 0;
}
