//
// Created by Prabal on 30-12-2022.
//

#ifndef RUBIKSCUBE_CORNERDBMAKER_H
#define RUBIKSCUBE_CORNERDBMAKER_H
#include "CornerPatternDB.h"
#include "../Models/RubiksCubeBits.cpp"

using namespace std;

class CornerDBMaker {
private:
    string fileName;
    CornerPatternDB cornerDB;

public:
    CornerDBMaker(string _fileName) {
        fileName = _fileName;
    }

    CornerDBMaker(string _fileName, uint8_t init_val) {
        fileName = _fileName;
        cornerDB = CornerPatternDB(init_val);
    }

    bool bfsAndStore(){
        RubiksCubeBits cube;
        queue<RubiksCubeBits> q;
        q.push(cube);
        cornerDB.setNumMoves(cube, 0);
        int curr_depth = 0;
        while (!q.empty()) {
            int n = q.size();
            curr_depth++;
            if (curr_depth == 9) break;
            for (int counter = 0; counter < n; counter++) {
                RubiksCubeBits node = q.front();
                q.pop();
                for (int i = 0; i < 18; i++) {
                    auto curr_move = RubiksCubeBits::MOVE(i);
                    node.move(curr_move);
                    if ((int) cornerDB.getNumMoves(node) > curr_depth) {
                        cornerDB.setNumMoves(node, curr_depth);
                        q.push(node);
                    }
                    node.invert(curr_move);
                }
            }
        }

        cornerDB.toFile(fileName);
        return true;
    }
};


#endif //RUBIKSCUBE_CORNERDBMAKER_H
