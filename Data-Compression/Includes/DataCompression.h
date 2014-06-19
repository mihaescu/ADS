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
    void on_Browse_clicked();

    void on_Huffman_clicked();

    void on_LZW_clicked();

    void on_RLE_clicked();

private:
    Ui::DC *ui;
};

#endif // DATACOMPRESSION_H
