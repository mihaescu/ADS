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

/* All buttons and text browsers were placed using QtCreator's drag & drop */

void DC::on_Browse_clicked()
{
      /* Get the path of the .txt file; 
         Browsing window starts in the app's folder */
      QString fileName = QFileDialog::getOpenFileName(this,
               tr("Open Text File"), "..//DCompression//", tr("Text Files (*.*)"));
      
      /* Open the file */    
      QFile file(fileName);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return;
      
      /* content is a QString; stores the content of the .txt file */
      content = file.readAll();
      
      /* in order to call the compression functions, QString must be converted to regular std::string */
      input = content.toLocal8Bit().constData();

      file.close();
      
      /* InputText is a text browser where the input text is displayed */
      ui->InputText->setText(content);
      
      /* Both the button and the text browser were added and placed using QtCreator's drag and drop */

}

void DC::on_Huffman_clicked()
{
        /* Calling the Huffman encoding function; it returns a string */
        string HuffmanEncoded = MHuffman(input);
        
        /* In order to display the string in a text browser it must be converted to QString */
        QString HuffEnc = QString::fromStdString(HuffmanEncoded);
        
        /* Display the encoded text in a text browser */
        ui->EncodedText->setText(HuffEnc);

        /* Alternative:
        Displaying the encoded text in a message box;
        
        QMessageBox msgBox;
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

       /* Alternative:
       Displaying the encoded text in a message box;
       
       QMessageBox msgBox;
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

       /* Alternative:
        Displaying the encoded text in a message box;
        
        QMessageBox msgBox;
        msgBox.setWindowTitle("RLE Encoding");
        msgBox.addButton(QMessageBox::Ok);
        msgBox.setText(RLEEnc);
        msgBox.exec(); */
}

