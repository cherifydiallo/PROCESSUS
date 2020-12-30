#include "pcte.h"
#include "ui_pcte.h"

PCTE::PCTE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PCTE)
{
    ui->setupUi(this);
    this->setFixedSize(600,600);
}





PCTE::~PCTE()
{
    delete ui;
}







QWidget *PCTE::le_parent_pcte()
{
    return this;

}








void PCTE::graphique_PCTE(QVector<QVector<int> > tab)
{    



    QVector <QVector <int> > tab1;
     QVector <QVector <int> > t_elu;
      QVector <QVector <int> > t_att;
    QVector <int> l(3),elu(3);
    int i;
    l[0]=l[1]=l[2]=0;
    elu[0]=elu[1]=elu[2]=0;

  for(i=0;i<tab.size();i++)
  {
     l[0]=tab[i][0];//RECUPERATION DES TEMPS D EXECUTION
     l[1]=tab[i][1];//RECUPERATION DES DATES DE SOUMISSIN
     l[2]=i;//RECUPERATION DU NOM DU PROCESSUS
     tab1.append(l);
  }



  int deb,fin,sortir;
  deb=0;
  elu[0]=tab1[0][0];
  elu[1]=tab1[0][1];
  elu[2]=tab1[0][2];
  t_elu.append(elu);
  if(tab1.size()!=0) tab1.remove(elu[2]);
  sortir=0;

    while(sortir==0){

                        fin=deb+elu[0];

                        if(t_att.size()!=0) t_att.clear();
                        for(i=0;i<tab1.size();i++) {
                                                           if((tab1[i][1]<=fin)){
                                                                        l[0]=tab1[i][0];
                                                                        l[1]=tab1[i][1];
                                                                        l[2]=tab1[i][2];
                                                                        t_att.append(l); //AJOUT DANS LA LISTE DES PROCESSUS EN ATTENTES
                                                                                                   }
                                                    }

                        if(t_att.size()!=0)     {
                                                    int ds,pos;
                                                    int min=t_att[0][0];
                                                    ds=t_att[0][1];
                                                    pos=t_att[0][2];
                                                    for(int i=1;i<t_att.size();i++){
                                                     if (min>t_att[i][0]) {
                                                                            min=t_att[i][0];
                                                                            ds=t_att[i][1];
                                                                            pos=t_att[i][2];
                                                                            }
                                                                                     }

                                                elu[0]=min;//RECUPERATION DU TEMPS D EXECUTION MINIMUM
                                                elu[1]=ds;//RECUPERATION DE SA DATE DE SOUMISSION
                                                elu[2]=pos;//RECUPERATION DE SA POSITION
                                                                                                                                           deb=fin;
                                                t_elu.append(elu);



                                                for(int v=0;v<tab1.size();v++) {
                                                    if(tab1[v][0]==elu[0] && tab1[v][2]==elu[2] ) tab1.remove(v);
                                                                                 }
                                                sortir=0;

                                               }

                        if(t_att.size()==0)       sortir=1;





                                        }




         if(tab1.size()!=0) {trier_execution(tab1);

                             for(i=0;i<tab1.size();i++){
                                                  elu[0]=tab1[i][0];
                                                  elu[1]=tab1[i][1];
                                                  elu[2]=tab1[i][2];
                                                  t_elu.append(elu);

                                                      }
                             tab1.clear();
                             }



         int   position=350/(t_elu.size()+1);
    for(int k=0;k<t_elu.size();k++){

    t_elu[k][2]=345-t_elu[k][2]*position;

    }






int c1,c2,c;



         QPen bic;
          QGraphicsSimpleTextItem  *text;
          QGraphicsScene *scene=new QGraphicsScene(le_parent_pcte());
          QGraphicsView *visualiser=new QGraphicsView(le_parent_pcte());
          visualiser->setFixedSize(600,500);
          visualiser->setScene(scene);
          bic.setColor(Qt::black);
          bic.setWidth(5);

          le_parent_pcte()->show();


          scene->addLine(50,10,50,400,bic);

          scene->addLine(50,400,500,400,bic);

           int x1,x2,y1,som;
           QString proces,val;
           bic.setWidth(10);


           int y2;


           for(int i=0;i<t_elu.size();i++){
                                         proces="Pro "+QString::number(i+1);
                                         if(i==0)  y2=346;
                                         else y2-=position;
                                         text=scene->addSimpleText(proces);
                                         text->setPos(15,y2-5);
                                         QEventLoop unepause;
                                         QTimer::singleShot (500, &unepause, SLOT (quit ()));
                                         unepause.exec();
                                         }



           som=0;

        for(int i=0;i<t_elu.size();i++)

            {
              bic.setColor(Qt::blue);
              som=som+t_elu[i][0];


              QEventLoop eventLoop;
              QTimer::singleShot (1500, &eventLoop, SLOT (quit ()));
              eventLoop.exec ();

             if(i==0)
             {
                 val=QString::number(som);
                 y1=t_elu[i][2];
                 x1=58;
                 x2=x1+(t_elu[i][0]*15);
                 text=scene->addSimpleText(val);
                 text->setPos(x2,410);
             }
             else
             {
                 val=QString::number(som);
                 y1=t_elu[i][2];
                 x1=x2+10;
                 x2=x1+(t_elu[i][0]*15);
                 text=scene->addSimpleText(val);
                 text->setPos(x2,410);
             }

             c2=y1/2;
             c=(y1+255)/4;
             c1=(y1+255)/3;
             bic.setColor(QColor(c1,c2,c));
             scene->addLine(x1,y1,x2,y1,bic);


            }







t_elu.clear();
l.clear();
elu.clear();
tab1.size();

















}





























void PCTE::diagramme_gant_PCTE(QVector<QVector<int> > tab)
{




    QVector <QVector <int> > tab1;
     QVector <QVector <int> > t_elu;
      QVector <QVector <int> > t_att;
    QVector <int> l(3),elu(3);
    int i;
    l[0]=l[1]=l[2]=0;
    elu[0]=elu[1]=elu[2]=0;

  for(i=0;i<tab.size();i++)
  {
     l[0]=tab[i][0];//RECUPERATION DES TEMPS D EXECUTION
     l[1]=tab[i][1];//RECUPERATION DES DATES DE SOUMISSIN
     l[2]=i;//RECUPERATION DU NOM DU PROCESSUS
     tab1.append(l);
  }



  int deb,fin,sortir;
  deb=0;
  elu[0]=tab1[0][0];
  elu[1]=tab1[0][1];
  elu[2]=tab1[0][2];
  t_elu.append(elu);
  if(tab1.size()!=0) tab1.remove(elu[2]);
  sortir=0;

    while(sortir==0){

                        fin=deb+elu[0];

                        if(t_att.size()!=0) t_att.clear();
                        for(i=0;i<tab1.size();i++) {
                                                           if((tab1[i][1]<=fin)){
                                                                        l[0]=tab1[i][0];
                                                                        l[1]=tab1[i][1];
                                                                        l[2]=tab1[i][2];
                                                                        t_att.append(l); //AJOUT DANS LA LISTE DES PROCESSUS EN ATTENTES
                                                                                                   }
                                                    }

                        if(t_att.size()!=0)     {
                                                    int ds,pos;
                                                    int min=t_att[0][0];
                                                    ds=t_att[0][1];
                                                    pos=t_att[0][2];
                                                    for(int i=1;i<t_att.size();i++){
                                                     if (min>t_att[i][0]) {
                                                                            min=t_att[i][0];
                                                                            ds=t_att[i][1];
                                                                            pos=t_att[i][2];
                                                                            }
                                                                                     }

                                                elu[0]=min;//RECUPERATION DU TEMPS D EXECUTION MINIMUM
                                                elu[1]=ds;//RECUPERATION DE SA DATE DE SOUMISSION
                                                elu[2]=pos;//RECUPERATION DE SA POSITION
                                                                                                                                           deb=fin;
                                                t_elu.append(elu);



                                                for(int v=0;v<tab1.size();v++) {
                                                    if(tab1[v][0]==elu[0] && tab1[v][2]==elu[2] ) tab1.remove(v);
                                                                                 }
                                                sortir=0;

                                               }

                        if(t_att.size()==0)       sortir=1;





                                        }




         if(tab1.size()!=0) {trier_execution(tab1);

                             for(i=0;i<tab1.size();i++){
                                                  elu[0]=tab1[i][0];
                                                  elu[1]=tab1[i][1];
                                                  elu[2]=tab1[i][2];
                                                  t_elu.append(elu);

                                                      }
                             tab1.clear();
                             }



         int   position=350/(t_elu.size()+1);
    for(int k=0;k<t_elu.size();k++){

    t_elu[k][2]=345-t_elu[k][2]*position;

    }












      int val3;
      val3=0;
      QTableWidget* table = new QTableWidget(1,t_elu.size());
      table->setFixedSize(500,400);

      table->setStyleSheet(
                         "spacing: 10px;"

                         "background-color: rgb(100,14,25);"

                          "color:white ;"

                         "border: 1px solid red;"

                         "margin: 1px;"

                         "text-align: right;"

                        "font-family: arial;"

                         "font-size: 12px;"

                  );



     QString var;

      for(int i=0;i<t_elu.size();i++)
                      {
          int pro=(345-t_elu[i][2])/position+1;
          var="P "+QString::number(pro);
        QTableWidgetItem *col = new QTableWidgetItem(var);
        col->setForeground(Qt::blue);
        col->setFont(QFont("Britannic Bold", 9));
        table->setHorizontalHeaderItem(i, col);
                       }


     int somme=0;
        for(int k=0;k<t_elu.size();k++){

           val3=somme+t_elu[k][0];
           QString var=QString::number(val3);
           table->setItem(0,k,new QTableWidgetItem(var));
           somme+=t_elu[k][0];

                                  }


  table->show();






l.clear();
elu.clear();
 tab1.clear();
  t_elu.clear();





}









void PCTE::trier_execution(QVector<QVector<int> > tab)
{
    int i,j,imin;
    for(j=0;j<tab.size()-1;j++)

     {
         imin=j;
         for( i=j+1;i<tab.size();i++)
         {
             if(tab[i][0]<tab[imin][0])
             {
                 imin=i;
             }
             else
                 if(tab[i][0]==tab[imin][0])
                 {
                     if(tab[i][1]<tab[imin][1])
                     {
                         imin=i;
                      }
                 }
             }
                  int p;
                  //PERMUTATIONS DES TEMPS D EXECUTION
                 p=tab[imin][0];
                 tab[imin][0]=tab[j][0];
                 tab[j][0]=p;
                 //RECUPERATION DES POSITIONS
                 p=tab[imin][2];
                 tab[imin][2]=tab[j][2];
                 tab[j][2]=p;
                 //PERMUTATIONS DES DATES SOUMISSIONS
                 p=tab[imin][1];
                 tab[imin][1]=tab[j][1];
                 tab[j][1]=p;

    }
}



