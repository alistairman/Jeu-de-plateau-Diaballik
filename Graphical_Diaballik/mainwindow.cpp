#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include "Game.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QGridLayout>
#include <QEvent>

using namespace std;
using namespace GameSpace;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    setWindowTitle(" DIABALLIK");
    initBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initBoard(){

    ui->tableWidget->setRowCount(7);
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    connect(ui->tableWidget, SIGNAL(clicked(const QModelIndex &)), this, SLOT(getIndice(const QModelIndex &)));
    QHeaderView *verticalHeader = ui->tableWidget->verticalHeader();
    verticalHeader->setSectionResizeMode(QHeaderView::Fixed);
    verticalHeader->setDefaultSectionSize(60);

}

void MainWindow::addPlayers(){

    QString title = title.fromStdString("entrez nom");
    Color color = Color::BLACK;
    list<Players> players;
    while(players.size()<2){
        if(players.size()==1) color = Color::WHITE;
        QString player1 = QInputDialog::getText(this,title,"Player ");
        string name = player1.toStdString();
        Players * p = new Players(name,color);
        players.push_back(*p);
    }
    game_->addPlayers(players);

    QString player1 = QString::fromStdString(game_->getPlayer(1).getName());
    ui->Player1->setText(player1);
    ui->Player1->setStyleSheet("QLabel{color : #e2e200;}");

    QString player2 = QString::fromStdString(game_->getPlayer(2).getName());
    ui->Player2->setText(player2);
    ui->Player2->setStyleSheet("QLabel{color : red;}");
    getCurrentPlayer();
}

void MainWindow::quit(){
    ui->~MainWindow();
    this->close();
}

void MainWindow::setGame(Game & game){
    game_ = &game;
    rowO=-1;
    colO=-1;
    rowD=-1;
    colD=-1;
    countMove = 0;
    countPasse = 0;
    game_->registerObserver(this);
}

void MainWindow::getCurrentPlayer(){
    QString name = name.fromStdString("Current Player is : "+ game_->getCurrentPlayer().getName());
    ui->currentPlayer->setText(name);
}

void MainWindow::update() {
    updateTable();
    getCurrentPlayer();
}



void MainWindow::updateTable(){
    game_->showTable(ui->tableWidget);
}

void MainWindow::getIndice(const QModelIndex & index){

    QString row = row.fromStdString(to_string(index.row()));
    QString col= col.fromStdString(to_string(index.column()));
    ui->label_selected->setText("Selected: "+row +"-"+col);

    if(rowO==-1){
        rowO = index.row();
        colO = index.column();
    }
    else{
        rowD = index.row();
        colD = index.column();
    }
}

void MainWindow::move()
{
    QString rowOO = rowOO.fromStdString(to_string(rowO));
    QString colOO= colOO.fromStdString(to_string(colO));
    QString rowDD = rowDD.fromStdString(to_string(rowD));
    QString colDD= colDD.fromStdString(to_string(colD));
    ui->label_move->setText("move from: "+rowOO +"-"+colOO+" to: "+rowDD+"-"+colDD);


    unsigned row =  static_cast<unsigned>(rowO);
    unsigned col = static_cast<unsigned>(colO);
    unsigned roww = static_cast<unsigned>(rowD);
    unsigned coll = static_cast<unsigned>(colD);

    game_->move(row,col,roww,coll);
    rowO=-1;
    colO = -1;
    rowD = -1;
    colD=-1;
}

void MainWindow::passe()
{
    QString rowOO = rowOO.fromStdString(to_string(rowO));
    QString colOO= colOO.fromStdString(to_string(colO));
    QString rowDD = rowDD.fromStdString(to_string(rowD));
    QString colDD= colDD.fromStdString(to_string(colD));
    ui->label_passe->setText("Throw from: "+rowOO +"-"+colOO+" to: "+rowDD+"-"+colDD);

    unsigned row =  static_cast<unsigned>(rowO);
    unsigned col = static_cast<unsigned>(colO);
    unsigned roww = static_cast<unsigned>(rowD);
    unsigned coll = static_cast<unsigned>(colD);

    game_->passe(row,col,roww,coll);
    rowO=-1;
    colO = -1;
    rowD = -1;
    colD=-1;
}

void MainWindow::on_move_clicked()
{
    try {
        if(countMove<2){
            move();
            countMove++;
        }
        if (countMove==2){
            QString noMove = "You have no more movement available";
            QMessageBox msgNoMove;
            msgNoMove.setIcon(QMessageBox::Information);
            msgNoMove.setText(noMove);
            msgNoMove.exec();
        }
        if(game_->isOver()){
            showWinner();
        }
    } catch (string const & e) {
        QString err = err.fromStdString(e);
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText(err);
        msgBox.exec();
    }
}


void MainWindow::on_passe_clicked()
{
    try {
        if(countPasse<1){
            passe();
            countPasse++;
        }
        if(countPasse==1){
          QString noThrow = "You no longer have a throw available";
          QMessageBox msgNoThrow;
          msgNoThrow.setIcon(QMessageBox::Information);
          msgNoThrow.setText(noThrow);
          msgNoThrow.exec();
        }
        if(game_->isOver()){
            showWinner();
        }
    } catch (string const & e) {
        QString err = err.fromStdString(e);
        QMessageBox msgBox;
        msgBox.setText(err);
        msgBox.exec();
    }
}

void MainWindow::on_cancel_clicked()
{
    rowO=-1;
    colO = -1;
    rowD = -1;
    colD=-1;
    QString rowOO = rowOO.fromStdString(to_string(rowO));
    QString colOO= colOO.fromStdString(to_string(colO));
    QString rowDD = rowDD.fromStdString(to_string(rowD));
    QString colDD= colDD.fromStdString(to_string(colD));
    ui->label_passe->setText("Throw from: "+ rowOO +"-"+colOO +" to: "+ rowDD +"-"+colDD);
    ui->label_move->setText("move from: "+ rowOO +"-"+colOO +" to: "+ rowDD+"-"+colDD);
}

void MainWindow::on_endturn_clicked()
{
    countMove=0; countPasse=0; game_->swapPlayer();
    getCurrentPlayer();
    rowO=-1;
    colO = -1;
    rowD = -1;
    colD=-1;
    QString rowOO = rowOO.fromStdString(to_string(rowO));
    QString colOO= colOO.fromStdString(to_string(colO));
    QString rowDD = rowDD.fromStdString(to_string(rowD));
    QString colDD= colDD.fromStdString(to_string(colD));
    ui->label_passe->setText("Throw from: "+ rowOO +"-"+colOO +" to: "+ rowDD +"-"+colDD);
    ui->label_move->setText("move from: "+ rowOO +"-"+colOO +" to: "+ rowDD+"-"+colDD);
}


void MainWindow::showWinner(){
    string winner = game_->getWinner();
    QString w = w.fromStdString(winner);
    QMessageBox msgBox;
    msgBox.setText("The Winner is: "+w);
    msgBox.exec();
}

void MainWindow::on_actionQuitter_triggered()
{
    quit();
}
