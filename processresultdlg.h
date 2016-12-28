#ifndef PROCESSRESULTDLG_H
#define PROCESSRESULTDLG_H

#include <QDialog>

namespace Ui {
class ProcessResultDlg;
}

class ProcessResultDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ProcessResultDlg(QWidget *parent = 0);
    ~ProcessResultDlg();

private:
    Ui::ProcessResultDlg *ui;
    QImage *resultImage;
};

#endif // PROCESSRESULTDLG_H
