#ifndef MODPARAS_H
#define MODPARAS_H

#include <QWidget>
#include <QtGui>

namespace Ui {
class ModParas;
}

class ModParas : public QWidget
{
    Q_OBJECT
    
public:
    explicit ModParas(QWidget *parent = 0);
    ~ModParas();
    void replace(QString path, QString strList[]);

public slots:
    void ondone();

private:
    Ui::ModParas *ui;
    QString number;
    QString chang;
    QString kuan;
    QString gao;
    QString n;
    QString var1;
    QString var2;
    QString var3;
    QString var4;
    QString var5;
    QString var6;
    QString var7;
    QString var8;
    QString var9;
    QString var10;
    QString var11;
    QString var12;
    QString var13;
    QString var14;
    QString var15;

    QString path;
};

#endif // MODPARAS_H
