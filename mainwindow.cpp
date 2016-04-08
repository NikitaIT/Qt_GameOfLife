#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game_of_life.h"
#include <iostream>
#include "qpaintwidget.h"
#include <QPainter>
Game_Of_Life *Game = new Game_Of_Life();
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(ui->stopButton, SIGNAL(clicked()), ui->textEdit,SLOT(stopGame()));
    // Создаем виджет
        wgt = new QPaintWidget(this);
    // И кладём его в лайаут
        ui->GameLayout->addWidget(wgt);

        for (int i = 0; i < Game->getRows(*Game->field); i++) {
            for (int j = 0; j < Game->getCols(*Game->field); j++) {
//                Game->field->at(i).at(j) = rand() % 2;
                Game->field->at(2).at(3) = 1;
                Game->field->at(3).at(4) = 1;
                Game->field->at(4).at(2) = 1;
                Game->field->at(4).at(3) = 1;
                Game->field->at(4).at(4) = 1;
            }
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_StartButton_clicked()
{
    int q=0;
while(q++!=5 ){wgt->repaint();}

}
QPaintWidget::QPaintWidget(QWidget * parent) : QWidget(parent)
{
}
void QPaintWidget::paintEvent(QPaintEvent *) {
    QPainter p(this); // Создаём новый объект рисовальщика
    int pensize = 10;
    p.setPen(QPen(Qt::red,pensize,Qt::SolidLine)); // Настройки рисования
        for (int i = 0; i < 1; i++) {
            for (int i = 0; i < Game->field->size(); i++) {
        //        // ...draw first '|'...
                //QPointF::QPointF1 ( 2, 2 );
                 //p.drawText(QPointF1,"|");
        //        // ...then for each value in row...
                for (int j = 0; j < Game->field->at(0).size(); j++) {
        //            // ...draw '*' if the cell is alive, ' ' otherwise...
                    if(Game->field->at(i).at(j))
                    {
                        p.drawPoint(i*pensize,j*pensize);
                    }
                }
                // ...close row with '|'
            }
        }
    matrix *oldField = Game->getBlankField(Game->getRows(*Game->field), Game->getRows(*Game->field));
    Game->copy(*Game->field, *oldField);
}

void MainWindow::on_AddNewButton_clicked()
{
    for (int i = 0; i < Game->getRows(*Game->field); i++) {
        for (int j = 0; j < Game->getCols(*Game->field); j++) {
//                Game->field->at(i).at(j) = rand() % 2;
            Game->field->at(2).at(3) = 1;
            Game->field->at(3).at(4) = 1;
            Game->field->at(4).at(2) = 1;
            Game->field->at(4).at(3) = 1;
            Game->field->at(4).at(4) = 1;
        }
    }
}
