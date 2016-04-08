#include "game_of_life.h"
typedef std::vector<std::vector<bool> > matrix;
Game_Of_Life::Game_Of_Life()
{

}

matrix *Game_Of_Life::getBlankField(int rows, int cols) {
  matrix *field = new matrix();
  for (int i = 0; i < rows; i++) {
    field->push_back(std::vector<bool>());
    for (int j = 0; j < cols; j++) {(field->at(i)).push_back(false);}
  }
  return field;
}

void Game_Of_Life::copy(matrix &field, matrix &oldField) {
    oldField = field;
    int count = 0;
    for (int i = 0; i < getRows(field); i++)
      for (int j = 0; j < getCols(field); j++){//перебор всех
        for (int tori = i - 1; tori <= i + 1; tori++){
          for (int torj = j - 1; torj <= j + 1; torj++){
            if (tori != i || torj != j){//учтем то что мы считаем без средней ячейки
              if ((tori == -1) && (torj == -1)) {if (field[getRows(field) - 1][getCols(field) - 1])count++;}// левый угол верх
              else
                if ((tori == getRows(field)) && (torj == -1)){if (oldField[0][getCols(field) - 1])count++;}//левый УГОЛ НИЗ
                else
                  if ((tori == -1) && (torj == getCols(field))){if (oldField[getRows(field) - 1][0])count++;}// правый УГОЛ ВЕРХ
                  else
                    if ((tori == getRows(field)) && (torj == getCols(field))){if (oldField[0][0])count++;}// правый УГОЛ НИЗ
                    else
                      if (torj == -1){if (oldField[tori][getCols(field) - 1])count++;} //левый
                      else
                        if (torj == getCols(field)){if (oldField[tori][0])count++;}//правый
                        else
                          if (tori == -1){if (oldField[getRows(field) - 1][torj])count++;} //верхний
                          else
                            if (tori == getRows(field)){if (oldField[0][torj])count++;}//нижний
                            else if (oldField[tori][torj])count++;}
          }
        }
      if (oldField[i][j]) {if (count < 2 || count > 3)field[i][j] = false;}
      else
        if (count == 3)field[i][j] = true;
    count = 0;
    }
  }
void Game_Of_Life::drawField(matrix &field) {
//    // For each row...
//    for (uint i = 0; i < field.size(); i++) {
//        // ...draw first '|'...
//         ui<< '|';
//        // ...then for each value in row...
//        for (uint j = 0; j < field[0].size(); j++) {
//            // ...draw '*' if the cell is alive, ' ' otherwise...
//            ui->textEdit << (field[i][j] ? '*' : ' ') << ' ';
//        }
//        // ...close row with '|'
//        ui->textEdit << "|\n";
//    }
}
