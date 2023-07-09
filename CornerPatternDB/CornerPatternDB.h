//
// Created by Prabal on 30-12-2022.
//

#ifndef RUBIKSCUBE_CORNERPATTERNDB_H
#define RUBIKSCUBE_CORNERPATTERNDB_H

#include "../Models/Baserubiks.h"
#include "PatternDatabase.h"
#include "PermutationIdx.h"
using namespace std;

class CornerPatternDB : public PatternDatabase {

    typedef Baserubiks::FACE F;

    PermutationIdx<8> permIndexer;

public:
    CornerPatternDB();
    CornerPatternDB(uint8_t init_val);
    uint32_t getDatabaseIndex(const Baserubiks& cube) const;

};

#endif //RUBIKSCUBE_CORNERPATTERNDB_H
