#ifndef BONDCONS_H
#define BONDCONS_H

#include <QWidget>

namespace Ui {
class BondCons;
}

class BondCons : public QWidget
{
    Q_OBJECT
    
public:
    explicit BondCons(QWidget *parent = 0);
    ~BondCons();
    
private:
    Ui::BondCons *ui;
};

#endif // BONDCONS_H
