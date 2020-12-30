#include "processus.h"
#include "ui_processus.h"

Processus::Processus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Processus)
{
    ui->setupUi(this);
}

Processus::~Processus()
{
    delete ui;
}


Processus::Processus()
{
    temps_exec=0;
    date_soum=0;
    priorite=0;
}



Processus::Processus(int a, int b, int c)
{
    temps_exec=a;
    date_soum=b;
    priorite=c;

}



QWidget *Processus::le_parent_pro()
{
   return this;
}



void Processus::remplir(int t_e, int d_s, int pri)
{

   temps_exec=t_e;
   date_soum=d_s;
   priorite=pri;

}



int Processus::temps_d_execution()
{
    return temps_exec;
}



int Processus::date_soumission()
{
    return date_soum;
}



int Processus::la_priorite()
{
    return priorite;
}




void Processus::on_VALIDER_clicked()
{
    QString val1=ui->lineEdit->text();
    QString val2=ui->lineEdit_2->text();
    QString val3=ui->lineEdit_3->text();

    int a,b,c,r;





  bool ok1,ok2,ok3;
    if((val1!=NULL)&&(val2!=NULL)&&(val3!=NULL))
        {

          a=val1.toInt(&ok1);
          b=val2.toInt(&ok2);
          c=val3.toInt(&ok3);
          if(!ok1 || !ok2 || !ok3) {

                                     r=QMessageBox::warning(this,"ATTENTION", "Veuillez saisir des ENTIERS seulement !!\n Voulez-vous quitter la CREATION DE PROCESSUS",QMessageBox::Yes,QMessageBox::No);

                                     if(r==QMessageBox::Yes) this->close();

                                    }
         else      {
                    remplir(a,b,c);
                    temps_exec=a;
                    date_soum=b;
                    priorite=c;
                    this->close();
                    }

        }




}
