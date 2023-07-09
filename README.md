# Rubiks-Cuber
Created a Rubiks Cube Solver using Graph algorithms such as :
* DFS (Depth First Search)
* BFS (Breadth First Search) 
* IDDFS (Iterative Deepening Depth First Search).

## Optimization using the Korf's IDA Star Algorithm

* According to the research paper published by Richard E. Korf in July 1997, we can optimize the search time
for the algorithm by a large extent through the use of Sequentially indexed Permutation databases of 
Rubik's cubes' edges and corners.
Link to the paper : https://www.cs.princeton.edu/courses/archive/fall06/cos402/papers/korfrubik.pdf

* After creating the corner databases upto depth-8, on its use,we'll observe drastic optimization, implemented as the IDA Star algorithm.

### Would you like to race againt it ?!
![](rubiks-cube.gif)
