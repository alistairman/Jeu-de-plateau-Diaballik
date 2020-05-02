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
    //ui->tableWidget->setShowGrid(true);
    //ui->tableWidget->setVisible(true);
    //ui->tableWidget->resize(500,500);
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

    //Piece * piece = new Piece(Color::NO);
    /**for(int i=0;i < 7;i++){
        for(int j =0;j<7;j++){
            if(game_->getPiece(i,j).getColor()==Color::BLACK){
                QString test = QString::fromStdString("BLACK");
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(test));
            }
            if(game_->getPiece(i,j).getColor()==Color::WHITE){
                QString test = QString::fromStdString("WHITE");
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(test));
            }
        }
    }*/

    game_->showTable(ui->tableWidget);
    QString name = name.fromStdString("Current Player is : "+game_->getCurrentPlayer().getName());
    ui->currentPlayer->setText(name);
}




