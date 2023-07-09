//
// Created by Prabal on 30-12-2022.
//

#include<bits/stdc++.h>
#include "../Models/Baserubiks.h"

#ifndef RUBIKSCUBE_DFSSOLVER_H
#define RUBIKSCUBE_DFSSOLVER_H


// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function

template<typename T, typename H>
class DFSSolver {
private:

    vector<Baserubiks::MOVE> moves;
    int max_search_depth;

//    DFS code to find the solution (helper function)
    bool dfs(int dep) {
        if (rubiksCube.isSolved()) return true;
        if (dep > max_search_depth) return false;
        for (int i = 0; i < 18; i++) {
            rubiksCube.move(Baserubiks::MOVE(i));
            moves.push_back(Baserubiks::MOVE(i));
            if (dfs(dep + 1)) return true;
            moves.pop_back();
            rubiksCube.invert(Baserubiks::MOVE(i));
        }
        return false;
    }

public:
    T rubiksCube;

    DFSSolver(T _rubiksCube, int _max_search_depth = 8) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<Baserubiks::MOVE> solve() {
        dfs(1);
        return moves;
    }

};


#endif //RUBIKSCUBE_DFSSOLVER_H
