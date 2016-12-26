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

    void loadFile(const QString &fileName);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void open();

private:
    Ui::MainWindow *ui;
    void createActions();
    void setCurrentFile(const QString &fileName);
};

#endif // MAINWINDOW_H
