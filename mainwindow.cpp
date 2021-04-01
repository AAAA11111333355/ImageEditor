#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("choose"), "", tr("Images (*.png *.jpg *.jpeg)"));

    if(QString::compare(filename, QString()) !=0){
        QImage image;
        bool valid = image.load(filename);

        if(valid){
            image = image.scaledToWidth(ui->label_image->width(), Qt::SmoothTransformation);
            ui->label_image->setPixmap(QPixmap::fromImage(image));
        } else{
            // error handle
        }
    }
}
