#include "tableau.h"
#include "ui_tableau.h"

tableau::tableau(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tableau)
{
    ui->setupUi(this);
    setFixedSize(600,500);



}

tableau::~tableau()
{

    delete ui;
}





tableau::tableau()
{

taille=0;


}

QWidget * tableau::le_parent_tab()
{
    return this;

}






int tableau::la_taille()
{
    return taille;
}






void tableau::creer_processus()
{
   QWidget * fenetre=new QWidget;
    bool ok;
    fenetre->move(470,150);

    int r,nbre;

         nbre=QInputDialog::getInt(fenetre,"Nombre de PROCESSUS","Donner le nbre de processus",0,-50,50,1,&ok);


          if(nbre<=0){

              r=QMessageBox::warning(fenetre,"ATTENTION", "Le nbre doit etre superieur  a !!\n Voulez-vous fermer le logiciel",QMessageBox::Yes,QMessageBox::No);

                      if(r==QMessageBox::Yes) this->close();

                     }
  taille=nbre;
int a,b,c;
for(int i=0;i<nbre;i++){


       QEventLoop eventLoop;
       QTimer::singleShot (500, &eventLoop, SLOT (quit ()));
       eventLoop.exec ();


       Processus  *pro=new Processus(le_parent_tab());
       pro->move(600,250);
       pro->exec();
       a=pro->temps_d_execution();
       b=pro->date_soumission();
       c=pro->la_priorite();
       QVector<int> t(3);
       t[0]=a;
       t[1]=b;
       t[2]=c;
       tab.append(t);

                          }




}











void tableau::afficher_tableau()
{

    int i,j,k;


    int val1,val2,val3;
    val1=val2=val3=0;
    QTableWidget* table = new QTableWidget(tab.size(),3);
    table->setFixedSize(500,400);



   QTableWidgetItem *col0 = new QTableWidgetItem("Temps d'execution");
   col0->setForeground(Qt::blue);
   col0->setFont(QFont("Britannic Bold", 9));
   table->setHorizontalHeaderItem(0, col0);



   QTableWidgetItem *col1 = new QTableWidgetItem("Date soumission");
   col1->setForeground(Qt::blue);
   col1->setFont(QFont("Britannic Bold", 9));
   table->setHorizontalHeaderItem(1, col1);

   QTableWidgetItem *col2= new QTableWidgetItem("Priorité");
   col2->setForeground(Qt::blue);
   col2->setFont(QFont("Britannic Bold", 9));
   table->setHorizontalHeaderItem(2, col2);









    for (i=0;i<tab.size();i++){


          val1=tab[i][0];
          QString  var=QString::number(val1);
          table->setItem(i,0,new QTableWidgetItem(var));

                               }


    for(j=0;j<tab.size();j++){

         val2=tab[j][1];
         QString   var=QString::number(val2);
         table->setItem(j,1,new QTableWidgetItem(var));

                             }


    for(k=0;k<tab.size();k++){

      val3=tab[k][2];
       QString    var=QString::number(val3);
       table->setItem(k,2,new QTableWidgetItem(var));


    }


table->show();

}








void tableau::ajouter_un_processus()
{
    int a,b,c;
    Processus  *pro=new Processus(le_parent_tab());
    pro->move(600,250);
    pro->exec();
    a=pro->temps_d_execution();
    b=pro->date_soumission();
    c=pro->la_priorite();
    QVector<int> t(3);
    t[0]=a;
    t[1]=b;
    t[2]=c;
    tab.append(t);

}





void tableau::supprimer_un_processus()
{


  QWidget * fenetre=new QWidget;
  fenetre->move(470,150);
   int rep1;
     bool ok;
     rep1=QInputDialog::getInt(fenetre,"Suppression","Donner le processus a Supprimer",0,-50,50,1,&ok);




   if(ok) {    if(rep1<=0 || rep1>tab.size()) ;
               else tab.remove(rep1-1);



           }
}



void tableau::supprimer_tout()
{

 tab.clear();

}






QVector<QVector<int> > tableau::mon_tableau()
{
   return tab;
}



void tableau::Gantt_fifo()
{

Fifo * f=new Fifo(this);
f->diagramme_gant_fifo(this->mon_tableau());

}



void tableau::Gantt_pcte()
{


    PCTE * f=new PCTE(this);
    f->diagramme_gant_PCTE(this->mon_tableau());

}



void tableau::grap_fifo()
{

    
Fifo * f=new Fifo(this);
f->graphique_fifo(this->mon_tableau());
  


}



void tableau::grap_pcte()
{

    PCTE * f=new PCTE(this);
     f->graphique_PCTE(this->mon_tableau());
  
}



void tableau::grap_tourniquet()
{

 Tourniquet *f=new Tourniquet(this);
 f->graphique_Tourniquet(this->mon_tableau());

}

void tableau::Gantt_tourniquet()
{
    Tourniquet *f=new Tourniquet(this);
    f->diagramme_gant_tourniquet(this->mon_tableau());
}


















void tableau::grap_priorite()
{

   Priorite * f=new Priorite(this);
   f->graphique_Priorite(this->mon_tableau());

}

void tableau::Gantt_priorite()
{
    Priorite * f=new Priorite(this);
    f->diagramme_gant_priorite(this->mon_tableau());
}




