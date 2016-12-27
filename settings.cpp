#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    connect(ui->gambitliulan,SIGNAL(clicked()),this,SLOT(ongambitliulan()));
    connect(ui->fluentliulan,SIGNAL(clicked()),this,SLOT(onfluentliulan()));
    connect(ui->done,SIGNAL(clicked()),this,SLOT(writebatfile()));
}

Settings::~Settings()
{
    delete ui;
}

bool Settings::DelDir(const QString &path)
{
    if (path.isEmpty()){
        return false;
    }
    QDir dir(path);
    if(!dir.exists()){
        return true;
    }
    dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot); //设置过滤
    QFileInfoList fileList = dir.entryInfoList(); // 获取所有的文件信息
    foreach (QFileInfo file, fileList){ //遍历文件信息
        if (file.isFile()){ // 是文件，删除
            file.dir().remove(file.fileName());
        }else{ // 递归删除
            DelDir(file.absoluteFilePath());
        }
    }
    return dir.rmpath(dir.absolutePath()); // 删除文件夹
}

void Settings::ongambitliulan()
{
    fileNameGambit = QFileDialog::getOpenFileName(this,
                                    "Open File", QDir::currentPath());   //设置Gambit启动目录
    if (!fileNameGambit.isEmpty())
    {
       ui->gambitlineedit->setText(fileNameGambit);

    }
    qDebug()<<fileNameGambit;
}

void Settings::onfluentliulan()
{
    fileNameFluent = QFileDialog::getOpenFileName(this,
                                    "Open File", QDir::currentPath());
    if (!fileNameFluent.isEmpty())
    {
        ui->fluentlineedit->setText(fileNameFluent);
    }
}

void Settings::writebatfile()
{
    bool okd = DelDir("c:/casp/");
    qDebug()<<"DelDir "+okd;

    QDir dir;
    dir.mkdir("c:/casp");

    QFile file("C:/casp/runGambit.bat");
    bool ok=file.open(QFile::WriteOnly|QIODevice::Text);
    if(ok)
        qDebug()<<"true";
    QTextStream in(&file);

    QString name=fileNameGambit;
    if (!name.isEmpty())
    {
        in<<name<<" "<<"-input"<<" "<<"C:\\casp\\gambitjoufile.jou";
        qDebug()<<"true";
    }

    else
        qDebug()<<"name is empty!!!"<<fileNameGambit;
}

