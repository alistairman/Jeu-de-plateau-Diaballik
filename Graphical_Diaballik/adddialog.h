#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "Game.h"

using namespace GameSpace;

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

private slots:
    void on_buttonBox_accepted(Game game);
    //void addPlayers(Game game);

private:
    Ui::addDialog *ui;
};

#endif // ADDDIALOG_H
