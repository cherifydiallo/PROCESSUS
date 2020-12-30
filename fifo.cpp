#include "fifo.h"
#include "ui_fifo.h"


Fifo::Fifo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fifo)
{
    ui->setupUi(this);
    this->setFixedSize(600,600);
}

Fifo::~Fifo()
{
    delete ui;
}







void Fifo::graphique_fifo(QVector<QVector<int> > tab)
{

    QPen bic;
       QGraphicsSimpleTextItem  *text;
       QGraphicsScene *scene=new QGraphicsScene(this);
       QGraphicsView *visualiser=new QGraphicsView(this);
       visualiser->setFixedSize(600,500);
       visualiser->setScene(scene);
       bic.setColor(Qt::black);
       bic.setWidth(5);

       this->show();


       scene->addLine(50,10,50,400,bic);

       scene->addLine(50,400,500,400,bic);

         int x1,x2,y1,som;
         QString proces,val;
         bic.setWidth(10);

         som=0;

         int c,c1,c2;

         for(int i=0;i<tab.size();i++)
         {
           proces="Pro "+QString::number(i+1);

           som=som+tab[i][0];


           QEventLoop eventLoop;
           QTimer::singleShot (1500, &eventLoop, SLOT (quit ()));
           eventLoop.exec ();

          if(i==0)
          {
              val=QString::number(som);
              y1=346;
              x1=58;
              x2=x1+(tab[i][0]*15);
              text=scene->addSimpleText(proces);
              text->setPos(15,y1-5);
              text=scene->addSimpleText(val);
              text->setPos(x2,410);
          }
          else
          {
              val=QString::number(som);
              y1-=50;
              x1=x2+10;
              x2=x1+(tab[i][0]*15);
              text=scene->addSimpleText(proces);
              text->setPos(15,y1-5);
              text=scene->addSimpleText(val);
              text->setPos(x2,410);
          }


          c2=y1/2;
          c=(y1+255)/4;
          c1=(y1+255)/3;
          bic.setColor(QColor(c1,c2,c));
          scene->addLine(x1,y1,x2,y1,bic);

     }
}


























void Fifo::diagramme_gant_fifo(QVector<QVector<int> > tab)
{


    int val3;
    val3=0;
    QTableWidget* table = new QTableWidget(1,tab.size());
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
    for(int i=0;i<tab.size();i++)
                  {
      var="P "+QString::number(i+1);
      QTableWidgetItem *col = new QTableWidgetItem(var);
      col->setForeground(Qt::blue);
      col->setFont(QFont("Britannic Bold", 9));
      table->setHorizontalHeaderItem(i, col);
                     }


   int somme=0;
      for(int k=0;k<tab.size();k++){

         val3=somme+tab[k][0];
         QString var=QString::number(val3);
         table->setItem(0,k,new QTableWidgetItem(var));
         somme+=tab[k][0];

                                }


table->show();



}


QWidget *Fifo::le_parent_fifo()
{
    return this;
}
