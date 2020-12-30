#ifndef PROCESSUS_H
#define PROCESSUS_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Processus;
}

class Processus : public QDialog
{
    Q_OBJECT

public:
    explicit Processus(QWidget *parent = 0);
    ~Processus();
     Processus();
     Processus(int a,int b,int c);
private:
    Ui::Processus *ui;

private:

     int temps_exec;
     int date_soum;
     int priorite;

public:

        QWidget* le_parent_pro();
        void remplir(int t_e,int d_s,int pri);

        int temps_d_execution();
        int date_soumission();
        int la_priorite();

   private slots:
        void on_VALIDER_clicked();




};

#endif // PROCESSUS_H
