#include <iostream>
#include <vector>
//#include <string>
#include <time.h>

using namespace std;

int main() { //Assumes that there is only one solution
    int contents[9][9] = {{5, 3, -1, -1, 7, -1, -1, -1, -1},
                          {6, -1, -1, 1, 9, 5, -1, -1, -1},
                          {-1, 9, 8, -1, -1, -1, -1, 6, -1},
                          {8, -1, -1, -1, 6, -1, -1, -1, 3},
                          {4, -1, -1, 8, -1, 3, -1, -1, 1},
                          {7, -1, -1, -1, 2, -1, -1, -1, 6},
                          {-1, 6, -1, -1, -1, -1, 2, 8, -1},
                          {-1, -1, -1, 4, 1, 9, -1, -1, 5},
                          {-1, -1, -1, -1, 8, -1, -1, 7, 9}};


    bool found[9]; //whether each number has been found
    bool cont = true;
    int iSquare, xSquare, currentVal; //coordinates of top left corner of 3x3 square

    while(cont == true) {
        cont = false;
        for(int i = 0; i < 9; i++) { //for every space
            for (int x = 0; x < 9; x++) {

                if (contents[i][x] == -1) { //if blank space
                    for (int a = 0; a < 9; a++) { //resets found array
                        found[a] = false;
                    }

                    for (int a = 0; a < 9; a++) {
                        if (contents[i][a] != -1) { //check rows
                            found[contents[i][a] - 1] = true;
                        }
                        if (contents[a][x] != -1) { //check columns
                            found[contents[a][x] - 1] = true;
                        }
                    }

                    iSquare = ((int)((int)i / 3)) * 3;
                    xSquare = ((int)((int)x / 3)) * 3;
                    for (int a = iSquare; a < iSquare + 3; a++) { //checks the 3x3 square surrounding the piece
                        for (int b = xSquare; b < xSquare + 3; b++) {
                            if (contents[a][b] != -1) {
                                found[contents[a][b] - 1] = true;
                            }
                        }
                    }

                    currentVal = -1; //undefined
                    for (int a = 0; a < 9; a++) { //check the found array and only use a not found value if it's unqiuely not found
                        if (found[a] == false) {

                            if (currentVal == -1) { //if 1 solution
                                currentVal = a + 1;
                            }
                            else { //if more than 1 solution
                                currentVal = -1;
                                break;
                            }
                        }
                    }
                    if (currentVal != -1) {
                        contents[i][x] = currentVal;
                        cont = true;
                    }
                }
            }
        }
    }


    for (int a = 0; a < 9; a++) { //outputs solution
        for (int b = 0; b < 9; b++) {
            cout << contents[a][b] << "   ";
            if (contents[a][b] != -1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}





    


