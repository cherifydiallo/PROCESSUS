#ifndef TABLEAU_H
#define TABLEAU_H
#include <QInputDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include "Processus.h"
#include <QWidget>
#include <QVector>
#include <QMainWindow>
#include <QDialog>
#include <QTimer>
#include <QEventLoop>


#include "tourniquet.h"
#include "fifo.h"
#include "priorite.h"
#include "pcte.h"

namespace Ui {
class tableau;
}

class tableau : public QWidget
{
    Q_OBJECT

public:
    explicit tableau(QWidget *parent = 0);
    ~tableau();
     tableau();
private:
    Ui::tableau *ui;
private:
   QVector< QVector<int> > tab;
   int taille;

public:


      QWidget *le_parent_tab();
      int la_taille();
      void creer_processus();
      void ajouter_processus();
      void afficher_tableau();
      void ajouter_un_processus();
      void supprimer_un_processus();
      void supprimer_tout();
      void Gantt_fifo();
      void Gantt_pcte();
      void grap_fifo();
      void grap_pcte();
      void grap_tourniquet();
      void Gantt_tourniquet();
      void grap_priorite();
      void Gantt_priorite();
      QVector< QVector<int> > mon_tableau();
};


#endif // TABLEAU_H
