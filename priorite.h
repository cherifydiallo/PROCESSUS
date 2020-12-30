#ifndef PRIORITE_H
#define PRIORITE_H
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
#include <QDialog>

namespace Ui {
class Priorite;
}

class Priorite : public QDialog
{
    Q_OBJECT

public:
    explicit Priorite(QWidget *parent = 0);
    ~Priorite();
     void graphique_Priorite(QVector <QVector<int> > tab);
     void trier_propriete(QVector <QVector<int> > tab);
     void diagramme_gant_priorite(QVector <QVector<int> > tab);
     QWidget *le_parent_priorite();
private:
    Ui::Priorite *ui;

};

#endif // PRIORITE_H
