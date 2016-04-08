#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qpaintwidget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
//    void saveGame();
//    void loadGame();
private slots:

    void on_StartButton_clicked();

    void on_AddNewButton_clicked();

private:
    Ui::MainWindow *ui;
    // Указатель на объект нашего класса
    QPaintWidget *wgt;

protected:
    void changeEvent(QEvent *e);
};

#endif // MAINWINDOW_H
