#include <iostream>
#include <vector>
//#include <string>
#include <time.h>

using namespace std;

//THIS WAS A GOOD IDEA HOWEVER DOESN'T WORK AS BOTH RULES MAY NOT ALWAYS BE SATISFIED, HENCE THERE ARE BLANK SPACES (HENCE IMPROPER PLACEMENT) IN THE SUDOKU BOARD

void generate() {
    srand(time(0));

    vector<int> suitable;
    bool chosen[9]; //whether a given column has been used
    int contents[9][9], nextIndex, suitableCount = 0;
    for (int i = 0; i < 9; i++) { //initialises variables
        for (int x = 0; x < 9; x++) {
            contents[i][x] = -1;
        }
    }

    for (int a = 1; a < 10; a++) { //finds suitable grid
       // for (int b = 0; b < 9; b++) {
        //    if (contents[a][b] == -1) { //determines available columns for the current row
         //       suitable.push_back(b);
          //      suitableCount += 1;
           // }
        //}
        for (int k = 0; k < 9; k++) {
            chosen[k] = false;
        }


        for (int b = 0; b < 9; b++) { //b is used for rows here
            for (int c = 0; c < 9; c++) {
                if (contents[b][c] == -1 && chosen[c] == false) {
                    suitable.push_back(c);
                    suitableCount += 1;
                }
            }
            //cout << suitableCount << endl;

            if (suitableCount != 0) {
                nextIndex = suitable[suitableCount * ((float)rand() / RAND_MAX)];
                contents[b][nextIndex] = a;
                //suitable.erase(suitable.begin() + nextIndex);
                chosen[nextIndex] = true;

                suitable.clear();
                suitableCount = 0;
            }
        }
    }
    for (int a = 0; a < 9; a++) { //outputs solution
        for (int b = 0; b < 9; b++) {
            cout << contents[a][b] << "   ";
        }
        cout << endl;
    }
}





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
        //cout << "YTES" << endl;
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

                            if (i == 7 && x == 5 && contents[i][a] == 6) { //WHAT THE HELL IS HAPPENING HERE???
                                cout << "WRONG1 " << a << " " << i << endl;
                            }
                        }
                        if (contents[a][x] != -1) { //check columns
                            found[contents[a][x] - 1] = true;

                            if (i == 7 && x == 5 && contents[a][x] == 6) { //WHAT THE HELL IS HAPPENING HERE???
                                cout << "WRONG2 " << a << " " << x << endl;
                            }
                        }
                    }

                    iSquare = ((int)((int)i / 3)) * 3;
                    xSquare = ((int)((int)x / 3)) * 3;
                    for (int a = iSquare; a < iSquare + 3; a++) { //checks the 3x3 square surrounding the piece
                        for (int b = xSquare; b < xSquare + 3; b++) {
                            if (contents[a][b] != -1) {
                                found[contents[a][b] - 1] = true;

                                if (i == 7 && x == 5 && contents[a][b] == 6) { //WHAT THE HELL IS HAPPENING HERE???
                                    cout << "WRONG3" << endl;
                                }
                            }
                        }
                    }

                    //if (i == 7 && x == 5) { //WHAT THE HELL IS HAPPENING HERE???
                     //    cout << "GAY" << endl;
                    //}

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
                        else {
                            if (i == 7 && x == 5) { //WHAT THE HELL IS HAPPENING HERE???
                                cout << a << endl;
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





    


