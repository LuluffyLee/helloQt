#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindlg.h"
#include "processresultdlg.h"
#include <QtWidgets>
#include <QObject>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->image = new QImage();
    statusBar()->showMessage(tr("就绪"));

    QObject::connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(open()));
    QObject::connect(ui->actionCount,SIGNAL(triggered()),this,SLOT(count()));

}

MainWindow::~MainWindow()
{
    delete image;
    delete ui;
}

void MainWindow::count()
{
    QDialog *dlg = new QDialog(this);
    dlg->show();
//    ProcessResultDlg *prdlg=new ProcessResultDlg();
//    prdlg->show();
}


void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,"open image file",".",
                "Image files (*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)");
    if (!fileName.isEmpty())
        showImage(fileName);
}

void MainWindow::showImage(const QString &fileName)
{
    //显示图片
    if(image->load(fileName))
    {
        statusBar()->showMessage(tr("加载中..."));

        QGraphicsScene *scene = new QGraphicsScene;
        scene->addPixmap(QPixmap::fromImage(*image));
        ui->graphicsView->setScene(scene);
        ui->graphicsView->resize(image->width() + 10, image->height() + 10);
        resize(image->width() + 30,image->height() + 100);
        ui->graphicsView->show();
        //showImage(image);

        statusBar()->showMessage(tr("加载完成"), 2000);
    }else
    {
        statusBar()->showMessage(tr("加载失败"), 2000);
    }
}

//void MainWindow::showImage(QImage *image)
//{
//    QGraphicsScene *scene = new QGraphicsScene;
//    scene->addPixmap(QPixmap::fromImage(*image));
//    ui->graphicsView->setScene(scene);
//    ui->graphicsView->resize(image->width() + 10, image->height() + 10);
//    resize(image->width() + 30,image->height() + 100);
//    ui->graphicsView->show();
//}

//QImage *MainWindow::greyScale(QImage * origin){
//    QImage * newImage = new QImage(origin->width(), origin->height(), QImage::Format_ARGB32);

//    QRgb * line;

//    for(int y = 0; y<newImage->height(); y++){
//        QRgb * line = (QRgb *)origin->scanLine(y);

//        for(int x = 0; x<newImage->width(); x++){
//            int average = (qRed(line[x]) + qGreen(line[x]) + qRed(line[x]))/3;
//            newImage->setPixel(x,y, qRgb(average, average, average));
//        }
//    }

//    return newImage;
//}
