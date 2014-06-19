#include "DataCompression.h"
#include "DC.h"
#include "ui_DataCompression.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

QString content;
string input;

DC::DC(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DC)
{
    ui->setupUi(this);
}

DC::~DC()
{
    delete ui;
}

void DC::on_Browse_clicked()
{
      QString fileName = QFileDialog::getOpenFileName(this,
               tr("Open Text File"), "..//DCompression//", tr("Text Files (*.*)"));

      QFile file(fileName);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return;

      content = file.readAll();
      input = content.toLocal8Bit().constData();

      file.close();

      ui->InputText->setText(content);

}

void DC::on_Huffman_clicked()
{
        string HuffmanEncoded = MHuffman(input);
        QString HuffEnc = QString::fromStdString(HuffmanEncoded);
        ui->EncodedText->setText(HuffEnc);

       // Displaying output in a message box

        /*  QMessageBox msgBox;
        msgBox.setWindowTitle("Huffman Encoding");
        msgBox.addButton(QMessageBox::Ok);
        msgBox.setText(HuffEnc);
        msgBox.exec(); */
}

void DC::on_LZW_clicked()
{
       string LZWEncoded = MLZW(input);
       QString LZWEnc = QString::fromStdString(LZWEncoded);
       ui->EncodedText->setText(LZWEnc);

       // Displaying output in a message box

       /* QMessageBox msgBox;
       msgBox.setWindowTitle("LZW Encoding");
       msgBox.addButton(QMessageBox::Ok);
       msgBox.setText(LZWEnc);
       msgBox.exec(); */
}

void DC::on_RLE_clicked()
{
        string RLEEncoded = MRLE(input);
        QString RLEEnc = QString::fromStdString(RLEEncoded);
        ui->EncodedText->setText(RLEEnc);

        // Displaying output in a message box

        /* QMessageBox msgBox;
        msgBox.setWindowTitle("RLE Encoding");
        msgBox.addButton(QMessageBox::Ok);
        msgBox.setText(RLEEnc);
        msgBox.exec(); */
}
