#ifndef DATACOMPRESSION_H
#define DATACOMPRESSION_H
#include <QMainWindow>

using namespace std;

namespace Ui {
class DC;
}

class DC : public QMainWindow
{
    Q_OBJECT

public:
    explicit DC(QWidget *parent = 0);
    ~DC();
	
private slots:

    /* App's buttons:
    Browse - browse for a .txt file and open it
    Huffman - calls the Huffman Encoding function
    LZW - calls the LZW Encoding function
    RLE - calls the  RLE Encoding function */
    
    void on_Browse_clicked();

    void on_Huffman_clicked();

    void on_LZW_clicked();

    void on_RLE_clicked();

private:
    Ui::DC *ui;
};

#endif // DATACOMPRESSION_H
