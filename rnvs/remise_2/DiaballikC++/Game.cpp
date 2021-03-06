
#include <iostream>
#include <list>

#include "Game.h"
#include "Observable.h"


namespace GameSpace
{

using namespace std;
using namespace ObservableSpace;


Game::Game(int width, int height):
    board_ (Board(width, height)),
    currentPlayer_ (Players("", Color::NO)),
    winner_(Players("", Color::NO))
{}

Game::~Game()
{
    for (Observer * o : observers_)
    {
        delete [] o;
    }
}

bool Game::isPossibleToAdd()
{
    return players_.size() < 2;
}

void Game::addPlayer(string player)
{
    if (players_.size() == 0)
    {
        players_.push_back(Players(player, Color::BLACK));
    }
    else
    {
        players_.push_back(Players(player, Color::WHITE));
    }
}

Players Game::getCurrentPlayer()
{
    return currentPlayer_;
}

void Game::swapPlayer()
{
    if (currentPlayer_.getName() == players_.front().getName())
    {
        currentPlayer_ = players_.back();

    }
    else
    {
        currentPlayer_ = players_.front();
    }
}

void Game::start()
{
    if (!isPossibleToAdd())
    {
        board_.initBoard();
        currentPlayer_ = players_.front();
        cout << endl;
        cout << "game started : " << endl;
    }
    this->notifyObservers();
}

ostream & Game::showBoard(ostream & c)
{
    return board_.showBoard(c);
}


bool Game::isOver()
{
    bool finish = false;
    for (int i = 0; i < board_.getWidth(); i++)
    {
        if (board_.getPiece(0, i).getColor() == Color::WHITE &&
                board_.getPiece(0, i).isInside())
        {
            finish = true;
            winner_ = players_.back();
        }
        if (board_.getPiece(6, i).getColor() == Color::BLACK &&
                board_.getPiece(6, i).isInside())
        {
            finish = true;
            winner_ = players_.front();
        }
    }
    return finish;
}

Players Game::getWinner()
{
    return  winner_;
}

bool Game::antiGame(Players currentPlayer)
{

    bool find = true;

    Piece opPiece = Piece(Color::NO);
    int x = 0;
    int limit = 1;
    int count = 0;

    for (int i = 0; i < board_.getWidth(); i++)
    {
        if (board_.getPiece(i, 0).getColor() == getOppoColor(currentPlayer))
        {
            opPiece = board_.getPiece(i, 0);
            x = i;
        }
    }


    while (find && limit < board_.getHeight() && x >= 0)
    {
        if (board_.getPiece(x - 1,
                            limit - 1).getColor() == currentPlayer.getColor())
        {
            count++;
        }


        if (board_.getPiece(x - 1, limit).getColor() ==  opPiece.getColor())
        {
            x = x - 1;
            limit++;
        }
        else if (board_.getPiece(x + 1,
                                 limit).getColor() == opPiece.getColor())
        {
            x = x + 1;
            limit++;
        }

        else if (board_.getPiece(x, limit).getColor() == opPiece.getColor())
        {
            limit ++;
        }
        else
        {
            find = false;
        }

    }
    if (find && count == 3)
    {
        winner_ = currentPlayer;
    }

    return  find ;

}

Color Game::getOppoColor(Players currentPlayer)
{
    if (currentPlayer.getColor() == players_.front().getColor())
    {
        return players_.back().getColor();
    }
    else
    {
        return players_.front().getColor();
    }
}


void Game::restart()
{
    start();
}

void Game::move(int ox, int oy, int dx, int dy)
{
    if (ox == (int)ox && oy == (int)oy && dx == (int)dx && dy == (int)dy)
    {
        board_.move(ox, oy, dx, dy, currentPlayer_.getColor());
        this->notifyObservers();
    }
    else
    {
        throw string(" les valeurs entr??es ne sont pas conforme, veuillez r??essayer ");
    }
}


void Game::passe(int dx, int dy)
{
    if (dx == (int)dx && dy == (int)dy)
    {
        board_.passe(dx, dy, currentPlayer_);
        this->notifyObservers();
    }
    else
    {
        throw string ("les valeurs entr??es ne sont pas conforme, veuillez r??essayer");
    }

}

void Game::registerObserver(Observer * observer)
{
    observers_.insert(observer);
}

void Game::unregisterObserver(Observer * observer)
{
    observers_.erase(observer);
}

void Game::notifyObservers()
{
    for (Observer * o : observers_)
    {
        o->update();
    }
}


}

