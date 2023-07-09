//
// Created by Prabal on 29-12-2022.
//


#include "bits/stdc++.h"
#include "Models/RubiksCube3dArray.cpp"
#include "Solvers/IDAstarSolver.h"
//#include "Database/StoredPatternDatabase"
#include "Models/RubiksCubeBits.cpp"
//#include "CornerPatternDB/CornerDBMaker.h"

using namespace std;

int main() {

    RubiksCubeBits cube1;
    RubiksCube3dArray cube2;

    cube1.print();

    if (cube1 == cube2) cout << "Cubes are equal";
    else cout << "Cubes are not equal";

    cube2.l();

    cube2.print();

     Checking hash fn

    unordered_map<RubiksCube3dArray,bool, Hash3d> mp1;

    mp1[cube1]=true;

    if(mp1[cube1]) cout << "Cub1 is present\n";
    else cout<<"Cube1 is not present\n";

    if(mp1[cube2]) cout << "Cub2 is present\n";
    else cout<<"Cube2 is not present\n";


    // Creating corner Database

    CornerDBMaker DBM("StoredPatternDatabase",8);
    DBM.bfsAndStore();

    //  Testing IDAStar Solver Using the Database Created

    vector<Baserubiks::MOVE> moves = cube1.randomShuffleCube(9);

    for (auto move: moves) cout << cube1.getMove(move) << " ";
    cout<<"\n";

    IDAstarSolver<RubiksCubeBits,HashBitboard> IDAsolver(cube1,"D:\\IMP\\RubiksCube\\Database\\StoredPatternDatabase");

    vector<Baserubiks::MOVE> movesToSolve = IDAsolver.solve();

    for (auto move: movesToSolve) cout << cube1.getMove(move) << " ";

    cube1.print();


}