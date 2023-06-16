#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextCursor>
#include "mainwindow2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionC_triggered();

    void on_actionPaste_triggered();

    void on_actionSelect_All_triggered();

    void on_actionSelect_None_triggered();

    void on_actionToolbar_Top_triggered();

    void on_actionToolbar_Bottom_triggered();

    void on_actionToolbar_Right_triggered();

    void on_actionToolbar_Left_triggered();

    void on_actionToolbar_Floatable_triggered();

    void on_actionToolbar_Movable_triggered();

    void on_actionOpen_Form_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
