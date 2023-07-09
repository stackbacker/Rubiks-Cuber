cmake_minimum_required(VERSION 3.24)
project(RubiksCube)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubiksCube Models/Baserubiks.h Models/RubiksCube.cpp Models/RubiksCube3dArray.cpp Models/RubiksCube1dArray.cpp Models/RubiksCubeBits.cpp main.cpp Solvers/BFSSolver.h Solvers/DFSSolver.h Solvers/IDAstarSolver.h Solvers/IDDFSSolver.h CornerPatternDB/CornerPatternDB.h CornerPatternDB/CornerDBMaker.h CornerPatternDB/NibbleArray.cpp CornerPatternDB/NibbleArray.h CornerPatternDB/PatternDatabase.cpp CornerPatternDB/PatternDatabase.h CornerPatternDB/Maths.cpp CornerPatternDB/Maths.h CornerPatternDB/CornerPatternDB.cpp CornerPatternDB/PermutationIdx.h Models/PatternDatabase/PatternDatabase.h)
