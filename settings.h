#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QtGui>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT
    
public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    bool DelDir(const QString &path);

private slots:
    void ongambitliulan();
    void onfluentliulan();
    void writebatfile();

private:
    Ui::Settings *ui;

    QString fileNameGambit;
    QString fileNameFluent;

};

#endif // SETTINGS_H
