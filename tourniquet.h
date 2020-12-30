#ifndef TOURNIQUET_H
#define TOURNIQUET_H
#include <QDebug>
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
#include <QDialog>

namespace Ui {
class Tourniquet;
}

class Tourniquet : public QDialog
{
    Q_OBJECT

public:
    explicit Tourniquet(QWidget *parent = 0);
    ~Tourniquet();
     void graphique_Tourniquet(QVector < QVector < int > > tab);
     void diagramme_gant_tourniquet(QVector < QVector < int > > tab);
     void trier(QVector < QVector < int > > tab);
     QWidget *le_parent_tour();
private:
    Ui::Tourniquet *ui;
};

#endif // TOURNIQUET_H
