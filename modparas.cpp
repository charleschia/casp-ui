#include "modparas.h"
#include "ui_modparas.h"

ModParas::ModParas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModParas)
{
    ui->setupUi(this);

   /* number=ui->number->text();
    chang=ui->chang->text();
    kuan=ui->kuan->text();
    gao=ui->gao->text();
    var1=ui->var1->text();
    var2=ui->var2->text();
    var3=ui->var3->text();
    var4=ui->var1->text();
    var5=ui->var1->text();
    var6=ui->var1->text();
    var7=ui->var1->text();
    var8=ui->var1->text();
    var9=ui->var1->text();
    var10=ui->var1->text();
    var11=ui->var1->text();
    var12=ui->var1->text();
    var13=ui->var1->text();
    var14=ui->var1->text();
    var15=ui->var15->text();*/

    connect(ui->donebutton,SIGNAL(clicked()),this,SLOT(ondone()));

}

ModParas::~ModParas()
{
    delete ui;
}

void ModParas::replace(QString path, QString strList[])
{
    QFile file(path);
    file.open(QFile::ReadOnly|QIODevice::Text);
    QTextStream in(&file);

    QFile fileout("C:\\casp\\gambitjoufile.jou");
    fileout.open(QFile::WriteOnly|QIODevice::Text);
    QTextStream out(&fileout);

    int i=0;
    int strListLength=19;   //模型参数strList[]的个数

    while(!in.atEnd())  //替换Gambit-jou字符串
    {

        QString str = in.readLine();
        if(str.startsWith("$")&&strListLength>0)
        {
            str=str.left(str.indexOf("=")+1);

            str.append(strList[i]);
            out<<str<<"\n";
            i++;
            strListLength--;
        }
        else
        out<<str<<"\n";

    }
    out.flush();
}

void ModParas::ondone()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);   //设置鼠标状态为等待

    number=ui->number->text();
    chang=ui->chang->text();
    kuan=ui->kuan->text();
    gao=ui->gao->text();
    var1=ui->var1->text();
    var2=ui->var2->text();
    var3=ui->var3->text();
    var4=ui->var4->text();
    var5=ui->var5->text();
    var6=ui->var6->text();
    var7=ui->var7->text();
    var8=ui->var8->text();
    var9=ui->var9->text();
    var10=ui->var10->text();
    var11=ui->var11->text();
    var12=ui->var12->text();
    var13=ui->var13->text();
    var14=ui->var14->text();
    var15=ui->var15->text();

    n=ui->n->text();

    QString strList[]={number,chang,kuan,gao,var1,var2,var3,var4,var5,var6,var7,
                       var8,var9,var10,var11,var12,var13,var14,var15};
    qDebug()<<var1;qDebug()<<n;

    QDir dir;
    path=dir.currentPath();
    int integer=n.toInt();
    switch(integer)
    {
    case 5:
        path=path+"/5.jou";break;
    case 6:
        path=path+"/6.jou";
        qDebug()<<path;break;
    case 7:
        path=path+"/7.jou";break;
    default:
        qDebug()<<"path plus fail!!!";
    }
//    QMessageBox::warning(0,"PATH",path,QMessageBox::Yes);
    qDebug()<<path;

    replace(path,strList);

    QProcess *pro=new QProcess;
    pro->start("C:/casp/runGambit.bat");     //运行.bat文件启动Gambit
    QMessageBox::information(this, tr("提示"),tr("模型正在生成中，\n请稍后..."));

    QApplication::restoreOverrideCursor();   //取消鼠标等待
}
