#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H
#include <vector>
typedef std::vector<std::vector<bool> > matrix;

class Game_Of_Life
{

    const static int rows = 40, cols = 40;
public:
    matrix *field = getBlankField(rows, cols);
    Game_Of_Life();
    matrix *getBlankField(int rows, int cols);
    void copy(matrix &field, matrix &oldField);
    bool isEqual(matrix &field, matrix &oldField){return (field == oldField);}
    int getRows(const matrix &field) {return field.size();}
    int getCols(const matrix &field) {if (getRows(field) != 0) return field[0].size(); return -1;}
    void clearWin() {}
    void drawField(matrix &field);
};

#endif // GAME_OF_LIFE_H
