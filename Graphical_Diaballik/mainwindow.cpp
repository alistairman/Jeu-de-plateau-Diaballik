#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include "Game.h"
#include <QInputDialog>

using namespace std;
using namespace GameSpace;

MainWindow::MainWindow(QWidget *parent,Game * game):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    game_(game)
{
    ui->setupUi(this);
    setWindowTitle(" DIABALLIK");
    ui->tableWidget->setRowCount(7);
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setVisible(true);
    //ui->Player1->setText("");
    //ui->Player2->setText("");

}


MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::isPossibleToAdd(){
    return game_->isPossibleToAdd();
}

void MainWindow::addPlayers(){

    QString title = title.fromStdString("entrez nom");
    list<Players> players;
    while(players.size()<2){
        QString player1 = QInputDialog::getText(this,title,"Player ");
        string name = player1.toStdString();
        Players * p = new Players(name,Color::NO);
        players.push_back(*p);
    }
    game_->addPlayers(players);
}

void MainWindow::quit(){
    this->close();
}

void MainWindow::setGame(Game * game){
    game_ = game;
    game_->registerObserver(this);
}


void MainWindow::update() const{

    QString player1 = QString::fromStdString(game_->getPlayer(1).getName());
    ui->Player1->setText(player1);

    QString player2 = QString::fromStdString(game_->getPlayer(2).getName());
    ui->Player2->setText(player2);
}

void MainWindow::initGame(){

    for(int i=0;i < 7;i++){
        for(int j =0;j<7;j++){
            QString test = QString::fromStdString("hello");
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(test));
        }
    }
}




