#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Ekranı buyutup kuculttugumuzde plaintText'te buyuyup kucuyor.
    this->setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    ui->plainTextEdit->clear();
    ui->statusbar->showMessage("Yeni dosya acildi!");
}


void MainWindow::on_actionOpen_triggered()
{
    QString dosyaYolu =QFileDialog::getOpenFileName(this, "Yeni dosya acildi!");
    QFile dosya(dosyaYolu);
    if(!dosya.open(QIODevice::ReadOnly)){   // ReadOnly modunda yani okuma modunda dosya acildi.
        // QFile'dan urettigimiz dosya acilmazsa uretilen hata mesajini errorString() metoduyla yazariz.
        QMessageBox::critical(this, "Hata", dosya.errorString());
        return;
    }
    // stream, dosyadan veri okumak ve veri yazmak icin kullanilan bir nesnedir.
    QTextStream stream(&dosya);
    ui->plainTextEdit->setPlainText(stream.readAll());
    dosya.close();
    // Acilan dosyanin yolu statusBar'da gosterildi.
    ui->statusbar->showMessage(dosyaYolu);
}


void MainWindow::on_actionSave_triggered()
{
    QString dosyaYolu=QFileDialog::getSaveFileName(this, "Dosyayi Kaydet!");
    QFile dosya(dosyaYolu);
    if(!dosya.open(QIODevice::WriteOnly)){  // WriteOnly modunda yani yazma modunda dosya acildi.
        QMessageBox::critical(this, "Hata", dosya.errorString());
        return;
    }
    // stream, dosyadan veri okumak ve veri yazmak icin kullanilan bir nesnedir.
    QTextStream stream(&dosya);
    stream << ui->plainTextEdit->toPlainText();
    dosya.close();
    // Acilan dosyanin yolu statusBar'da gosterildi.
    ui->statusbar->showMessage(dosyaYolu);
}


void MainWindow::on_actionExit_triggered()
{
    this->close();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}


void MainWindow::on_actionC_triggered()
{
    ui->plainTextEdit->cut();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}


void MainWindow::on_actionSelect_All_triggered()
{
    ui->plainTextEdit->selectAll();
}


void MainWindow::on_actionSelect_None_triggered()
{
//  cursor, imlec demektir.
//  // FERDA HOCA'NIN YAPTIGI KISIM
//  QTextCursor cursor = ui->plainTextEdit->textCursor();
//  cursor.movePosition(QTextCursor::End);
//  ui->plainTextEdit->setTextCursor(cursor);
//  ui->plainTextEdit->moveCursor(QTextCursor::End);
    QTextCursor imlec = ui->plainTextEdit->textCursor();
    int position = imlec.position();
    imlec.clearSelection();
    imlec.setPosition(position, QTextCursor::MoveMode::KeepAnchor);
    ui->plainTextEdit->setTextCursor(imlec);
//  cursor, imlecin kaldigi yere denir.
}


void MainWindow::on_actionToolbar_Top_triggered()
{
    addToolBar(Qt::TopToolBarArea, ui->toolBar);
}


void MainWindow::on_actionToolbar_Bottom_triggered()
{
    addToolBar(Qt::BottomToolBarArea, ui->toolBar);
}


void MainWindow::on_actionToolbar_Right_triggered()
{
    addToolBar(Qt::RightToolBarArea, ui->toolBar);
}


void MainWindow::on_actionToolbar_Left_triggered()
{
    addToolBar(Qt::LeftToolBarArea, ui->toolBar);
}


void MainWindow::on_actionToolbar_Floatable_triggered()
{
    // toolBar plainText'in disinda cikmiyor.
    ui->toolBar->setFloatable(false);
}


void MainWindow::on_actionToolbar_Movable_triggered()
{
    // toolBar'in yerini sabit kiliyor yani degistirilemiyor.
    ui->toolBar->setMovable(false);
}


void MainWindow::on_actionOpen_Form_triggered()
{
    MainWindow2 *ikinciEkran = new MainWindow2(this);
    ikinciEkran->show();
}

