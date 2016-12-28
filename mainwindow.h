#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
class QMenu;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    //MainWindow();

    void showImage(const QString &fileName);
    void showNewImage(QImage &image);
    ~MainWindow();

private slots:
    void open();
    void count();

private:
    Ui::MainWindow *ui;
    QImage *image;
    //QImage *MainWindow::greyScale(QImage *origin)();
};

#endif // MAINWINDOW_H
