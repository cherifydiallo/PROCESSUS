#include "tourniquet.h"
#include "ui_tourniquet.h"

Tourniquet::Tourniquet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tourniquet)
{
    ui->setupUi(this);
    this->setFixedSize(600,600);
}

Tourniquet::~Tourniquet()
{
    delete ui;
}




void Tourniquet::graphique_Tourniquet(QVector<QVector<int> > tab){





    int q,r;
    bool ok;
    le_parent_tour()->move(480,100);

         q=QInputDialog::getInt(le_parent_tour(),"QUANTUM","Donner le Quantum",0,-50,50,1,&ok);


          if(q<=0){

              r=QMessageBox::warning(le_parent_tour(),"ATTENTION", "Le quantum doit etre superieur  a 0!!\n Voulez-vous fermer le logiciel",QMessageBox::Yes,QMessageBox::No);

                      if(r==QMessageBox::Yes)le_parent_tour()->close();

                     }


        QPen bic;
               QGraphicsSimpleTextItem  *text;
               QGraphicsScene *scene=new QGraphicsScene(this);
               QGraphicsView *visualiser=new QGraphicsView(this);
               visualiser->setFixedSize(600,500);
               visualiser->setScene(scene);
               bic.setColor(Qt::black);
               bic.setWidth(5);

              le_parent_tour()->show();


               scene->addLine(50,10,50,400,bic);

               scene->addLine(50,400,500,400,bic);



                 int i,j;


               QVector < int > t(3);
               //CREATION D UNE AUTRE TABLEAU
               QVector < QVector<int> > tab2;

               //COPIE DES ELEMENTS VERS LE NOUVEAU TABLEAU
             for(i=0;i<tab.size();i++)
             {
                for(j=0;j<3;j++)  t[j]=tab[i][j];
                tab2.append(t);
             }








    int y2;


    QVector <int> t1;

    int pos;
    pos=350/(tab2.size()+1);
    int vale=345;
    for(i=0;i<tab2.size();i++){
          t1.append(vale);
          vale=vale-pos;
                     }

    QString proces;

    for(int i=0;i<tab2.size();i++){
                                 proces="Pro "+QString::number(i+1);
                                 if(i==0)  y2=346;
                                 else y2-=pos;
                                 text=scene->addSimpleText(proces);
                                 text->setPos(15,y2-5);
                                 QEventLoop unepause;
                                 QTimer::singleShot (500, &unepause, SLOT (quit ()));
                                 unepause.exec();
                                 }



    int nbre,x1,x2,y1;
    int som;
    QString val;
    bic.setWidth(10);
    int fin=0;
    int it=0;
    int c,c1,c2;
    som=0;
    while(nbre!=tab2.size()){

    nbre=0;


    for(i=0;i<tab2.size();i++){

    if(tab2[i][0]>=q){

                    bic.setColor(Qt::blue);
                    som=som+q;


                    QEventLoop eventLoop;
                    QTimer::singleShot (1500, &eventLoop, SLOT (quit ()));
                    eventLoop.exec ();


                    if(i==0){

                             val=QString::number(som);
                             y1=t1[i];
                             if(it==0) x1=58;
                             else x1=fin+10;
                             x2=x1+(q*15);
                             text=scene->addSimpleText(val);
                             text->setPos(x2,410);
                            }
                     else
                            {

                             val=QString::number(som);
                             y1=t1[i];
                             x1=x2+10;
                             x2=x1+(q*15);
                             text=scene->addSimpleText(val);
                             text->setPos(x2,410);
                            }

                    c2=y1/2;
                    c=(y1+255)/4;
                    c1=(y1+255)/3;
                    bic.setColor(QColor(c1,c2,c));

                      scene->addLine(x1,y1,x2,y1,bic);
                      tab2[i][0]=tab2[i][0]-q;

                       }

    else
             {
                     if(tab2[i][0]==0) nbre++;
                     else {
                                bic.setColor(Qt::blue);
                                som=som+tab2[i][0];


                                QEventLoop eventLoop;
                                QTimer::singleShot (1500, &eventLoop, SLOT (quit ()));
                                eventLoop.exec ();

                                if(i==0)
                                          {

                                          val=QString::number(som);
                                          y1=t1[i];
                                          if(it==0) x1=58;
                                          else x1=fin+10;
                                          x2=x1+(tab2[i][0]*15);
                                          text=scene->addSimpleText(val);
                                          text->setPos(x2,410);
                                          }
                                else
                                          {

                                          val=QString::number(som);
                                          y1=t1[i];
                                          x1=x2+10;
                                          x2=x1+(tab2[i][0]*15);
                                          text=scene->addSimpleText(val);
                                          text->setPos(x2,410);
                                          }

                                c2=y1/2;
                                c=(y1+255)/4;
                                c1=(y1+255)/3;
                                bic.setColor(QColor(c1,c2,c));
                                scene->addLine(x1,y1,x2,y1,bic);
                                tab2[i][0]=0;

                            }

            }


        if (i==tab2.size()-1) fin=x2;

         }

    it++;


    }



    t1.clear();
    tab2.clear();







}












void Tourniquet::diagramme_gant_tourniquet(QVector<QVector<int> > tab)
{












}



void Tourniquet::trier(QVector<QVector<int> > tab)
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

QWidget *Tourniquet::le_parent_tour()
{
    return this;
}




