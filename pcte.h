#ifndef PCTE_H
#define PCTE_H
#include <QVector>
#include <QWidget>
#include <QInputDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include "Processus.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVector>
#include <QMainWindow>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPen>
#include <QTimer>
#include <QEventLoop>
#include <QGraphicsSimpleTextItem>
#include <QWidget>
#include <QWidget>
#include <QDialog>
#include <QDebug>



#include "fifo.h"
namespace Ui {
class PCTE;
}

class PCTE : public QDialog
{
    Q_OBJECT

public:
    explicit PCTE(QWidget *parent = 0);


    void trier_execution(QVector < QVector <int> > tab);
    void graphique_PCTE(QVector < QVector <int> > tab);
    void diagramme_gant_PCTE(QVector <QVector <int> > tab);
    QWidget * le_parent_pcte();


    ~PCTE();

private:
    Ui::PCTE *ui;
};

#endif // PCTE_H
