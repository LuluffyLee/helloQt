#include "processresultdlg.h"
#include "ui_processresultdlg.h"

ProcessResultDlg::ProcessResultDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProcessResultDlg)
{
    ui->setupUi(this);
    this->resultImage = new QImage();
}

ProcessResultDlg::~ProcessResultDlg()
{
    delete ui;
    delete resultImage;
}
