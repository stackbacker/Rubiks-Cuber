//
// Created by Prabal on 28-12-2022.
//

#ifndef RUBIKSCUBE_BASERUBIKS_H
#define RUBIKSCUBE_BASERUBIKS_H

#include "bits/stdc++.h"

using namespace std;

/* * A base class for all the Rubik's Cube Models. There are various representations for Rubik's cube.
   * Each one has its own special definitions. This class provides a shared functionality between
   * all models.
   * We'll benchmark all models and finalize which one is the most optimized.
   */

class Baserubiks {
    public:
        enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
        };

        enum class COLOR {
            WHITE,
            GREEN,
            RED,
            BLUE,
            ORANGE,
            YELLOW
        };

        enum class MOVE {
            L, LPRIME, L2,
            R, RPRIME, R2,
            U, UPRIME, U2,
            D, DPRIME, D2,
            F, FPRIME, F2,
            B, BPRIME, B2
        };

        /*
         * This function returns the color of the cell at (row, col) in face.
         * The row and columns are 0-indexed.
         * If the cube is facing you, then the row numbering starts from the
         * top to bottom, and column numbering starts form the left to right.
        */
        virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

        /*
         * This function returns the first letter of the given COLOR
         * For Ex: COLOR :: RED, it returns character 'R'
         */
        static char getColorLetter(COLOR color);

        /*
         * Returns true if the Rubik's Cube is solved, otherwise returns false.
         */
        virtual bool isSolved() const = 0;

        /*
         * Returns the move in the string format.
         */
        static string getMove(MOVE ind);

        /*
        * Print the Rubik Cube in Planar format.
        *
        * The cube is laid out as follows.
        *
        * The sides:
        *    U
        *  L F R B
        *    D
        *
        * Color wise:
        *
        *          W W W
        *          W W W
        *          W W W
        *
        *  G G G   R R R   B B B   O O O
        *  G G G   R R R   B B B   O O O
        *  G G G   R R R   B B B   O O O
        *
        *          Y Y Y
        *          Y Y Y
        *          Y Y Y
        *
        * Row and Column Numberings:
        * rx -> row numbering
        * cx -> column numbering
        * bx -> both row and column numbering
        *
        *             b0 c1 c2
        *             r1  .  .
        *             r2  .  .
        *
        *  b0 c1 c2   b0 c1 c2   b0 c1 c2   b0 c1 c2
        *  r1  .  .   r1  .  .   r1  .  .   r1  .  .
        *  r2  .  .   r2  .  .   r2  .  .   r2  .  .
        *
        *             b0 c1 c2
        *             r1  .  .
        *             r2  .  .
        *
        */
        void print() const;

        /*
         * This function shuffles the cube randomly with 'times' moves and returns the moves performed.
         */
        vector<MOVE> randomShuffleCube(unsigned int times);

        /*
         * This function perform moves on the Rubik's cube.
         */
        Baserubiks &move(MOVE ind);

        /*
         * Invert a move
         */
        Baserubiks &invert(MOVE ind);

        /*
         * Rotational Moves on the Rubik's Cubes
         *
         * F, F’, F2,
         * U, U’, U2,
         * L, L’, L2,
         * D, D’, D2,
         * R, R’, R2,
         * B, B’, B2
         */

        virtual Baserubiks &f() = 0;

        virtual Baserubiks &fPrime() = 0;

        virtual Baserubiks &f2() = 0;

        virtual Baserubiks &u() = 0;

        virtual Baserubiks &uPrime() = 0;

        virtual Baserubiks &u2() = 0;

        virtual Baserubiks &l() = 0;

        virtual Baserubiks &lPrime() = 0;

        virtual Baserubiks &l2() = 0;

        virtual Baserubiks &r() = 0;

        virtual Baserubiks &d() = 0;

        virtual Baserubiks &dPrime() = 0;

        virtual Baserubiks &d2() = 0;

        virtual Baserubiks &rPrime() = 0;

        virtual Baserubiks &r2() = 0;

        virtual Baserubiks &b() = 0;

        virtual Baserubiks &bPrime() = 0;

        virtual Baserubiks &b2() = 0;

        string getCornerColorString(uint8_t ind) const;

        uint8_t getCornerIndex(uint8_t ind) const;

        uint8_t getCornerOrientation(uint8_t ind) const;

};



#endif //RUBIKSCUBE_BASERUBIKS_H
