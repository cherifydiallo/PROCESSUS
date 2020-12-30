#ifndef FIFO_H
#define FIFO_H

#include <QDialog>
#include <QColor>
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



namespace Ui {
class Fifo;
}

class Fifo : public QDialog
{
    Q_OBJECT

public:
    explicit Fifo(QWidget *parent = 0);
    ~Fifo();

      void graphique_fifo(QVector < QVector <int> > tab);
      void diagramme_gant_fifo(QVector <QVector <int> > tab);
      QWidget *le_parent_fifo();


private:
    Ui::Fifo *ui;
};

#endif // FIFO_H
