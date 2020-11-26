
// // license___here

#include "ViewsListWidget.h"

#include "resource/ImgResource.h"

#include "qt/QTutil.h"

#include "MainWindow.h"

#include "view/ViewSettings.h"

#include "events/FacsanaduEvent.h"

#include "FacsanaduProject.h"

#include "gates/gate-info.h"
#include "data/Dataset.h"
#include "data/ChannelInfo.h"

#include "gates/GateSet.h"


#include <QDebug>

#include <QHeaderView>

#define connect_this(x, y, z) connect(y, &x, \
   this, &ViewsListWidget::z);


ViewsListWidget::ViewsListWidget(MainWindow* mw)
 :  mw_(mw)
{
 main_layout_ = new QVBoxLayout;

 tableViews_ = new QTableWidget(this);

 //? main_layout_->setSpacing(0);
 
 //? setMargin(0);
  
 tableViews_->verticalHeader()->hide();
 tableViews_->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
 tableViews_->horizontalHeader()->setSectionResizeMode(
   QHeaderView::ResizeMode::ResizeToContents);
 tableViews_->horizontalHeader()->setStretchLastSection(true); 

//? tableViews_->selectionModel().selectionChanged.connect(this,"dothelayout()");
 
 connect_this(QItemSelectionModel ::selectionChanged 
   ,tableViews_->selectionModel() ,dothelayout) 


 QPushButton* bSelectAllViews = new QPushButton(tr("Select all"), this);
 QPushButton* bNewView = new QPushButton(tr("New view"), this);

 QPushButton* bRemoveView = new QPushButton(tr("Remove view"), this);

//QIcon(ImgResource::icon_delete()),   "", this);

// connect(bNewView, &QPushButton::clicked,
 //  this, &ViewsListWidget::actionNewView);

// connect(bRemoveView, &QPushButton::clicked,
//   this, &ViewsListWidget::actionRemoveView);

 connect_this(QPushButton ::clicked ,bNewView ,actionNewView) 
 connect_this(QPushButton ::clicked ,bRemoveView ,actionRemoveView) 
 connect_this(QPushButton ::clicked ,bSelectAllViews ,actionSelectAllViews) 

// bNewView.clicked.connect(this,"actionNewView()");
// bRemoveView.clicked.connect(this,"actionRemoveView()");
// bSelectAllViews.clicked.connect(this,"actionSelectAllViews()");

 main_layout_->addWidget(tableViews_);

 main_layout_->addLayout(QTutil::layoutHorizontal({bSelectAllViews, bNewView, bRemoveView}));

 tableViews_->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

 setLayout(main_layout_);
}
 
void ViewsListWidget::dothelayout()
{
 mw_->handleEvent(new EventViewsChanged()); //possible overkill?
}
 
void ViewsListWidget::actionSelectAllViews()
{
 tableViews_->selectAll();
}

// // Get selected views
LinkedList<ViewSettings*> ViewsListWidget::getSelectedViews()
{
 LinkedList<ViewSettings*> selviews; // =new LinkedList<ViewSettings>();
 
 if(tableViews_->rowCount() == 0)
   return selviews;

/* for(QModelIndex in : tableViews_->selectionModel()->selectedRows())
 {
  selviews.append((ViewSettings*) tableViews_->item(in.row(), 0)->data(Qt::ItemDataRole::UserRole).value<void*>());
 }
*/

 // for testing, always select first row ...

 selviews.append((ViewSettings*) tableViews_->item(0, 0)->data(Qt::ItemDataRole::UserRole).value<void*>());
 return selviews;
}

void ViewsListWidget::test_update_views(Dataset* ds, u1 x_col, u1 y_col)
{
 qDebug() << "test_update_views ...";
 if(ds->current_column_names())
 {

  tableViews_->setRowCount(1); 
  tableViews_->setColumnCount(1);

  QVector<QString>& current_column_names = *ds->current_column_names();
  QString temp = "root";
  QString showname;
  if(x_col == y_col)
  {
   showname = QString("%1:%2").arg(temp).arg(current_column_names[x_col]);
  }
  else
  {
   showname = QString("%1:%2/%3").arg(temp).arg(current_column_names[x_col])
     .arg(current_column_names[y_col]);
  }
  qDebug() << "showname = " << showname; 
  QTableWidgetItem* qtwi = new QTableWidgetItem(showname);  //QTutil::createReadOnlyItem(showname);
  //qtwi->setData(Qt::ItemDataRole::UserRole, QVariant::fromValue( (void*)vs ));
  tableViews_->setItem(0, 0, qtwi);

  QTableWidgetItem* qtwi1 = new QTableWidgetItem("showname");  //QTutil::createReadOnlyItem(showname);
  //qtwi->setData(Qt::ItemDataRole::UserRole, QVariant::fromValue( (void*)vs ));
  tableViews_->setItem(1, 0, qtwi1);

 }
}

void ViewsListWidget::update_view_names()
{
 FacsanaduProject* project = mw_->project();

 for(int row = 0; row < tableViews_->rowCount(); ++row) 
 {
  for(int col = 0; col < tableViews_->columnCount(); ++col) 
  {
   QTableWidgetItem* qtwi = tableViews_->item(row, col);
   ViewSettings* vs = (ViewSettings*) qtwi->data(Qt::ItemDataRole::UserRole)
     .value<void*>();

   QString showname = vs->gate()->name() + ": ";
   if( !project->datasets().isEmpty() )
   {
    Dataset* ds = project->datasets().first();

    if(vs->indexX() == vs->indexY() )
      showname += ds->getChannelInfo().value( vs->indexX() )->getShortestName();
    else
      showname += ds->getChannelInfo().value( vs->indexX() )->getShortestName() + 
      " / " + ds->getChannelInfo().value( vs->indexY() )->getShortestName();
   }

   qtwi->setText(showname);
   
  }
 }

 
}

// // Update list with views
void ViewsListWidget::updateViewsList()
{
 qDebug() << "updateViewsList()";

 LinkedList<ViewSettings*> selviews = getSelectedViews();
 
 FacsanaduProject* project = mw_->project();
 bool wasUpdating = isUpdating_;
 isUpdating_ = true;
 tableViews_->clear(); //clears title?
 
 tableViews_->setColumnCount(1);
 tableViews_->setHorizontalHeaderLabels({tr("View")}); //Arrays.asList(tr("View")));

 tableViews_->setRowCount(project->views().size());

 int row = 0;

 for(ViewSettings* vs : project->views())
 {
  QString showname = vs->gate()->name() + ": ";
  if( !project->datasets().isEmpty() )
  {
   Dataset* ds = project->datasets().first();

   if(vs->indexX() == vs->indexY() )
     showname += ds->getChannelInfo().value( vs->indexX() )->getShortestName();
   else
     showname += ds->getChannelInfo().value( vs->indexX() )->getShortestName() + 
     " / " + ds->getChannelInfo().value( vs->indexY() )->getShortestName();
  }
  
  QTableWidgetItem* qtwi = QTutil::createReadOnlyItem(showname);

  qDebug() << "show name: " << showname;  

  qtwi->setData(Qt::ItemDataRole::UserRole, QVariant::fromValue( (void*)vs ));
  tableViews_->setItem(row, 0, qtwi);
  if(selviews.contains(vs))
    tableViews_->selectionModel()->select(tableViews_->model()->index(row, 0),
    (QItemSelectionModel::SelectionFlag::Rows |
      QItemSelectionModel::SelectionFlag::Select) );
  ++row;
 }
  
 isUpdating_ = wasUpdating;
}

 

// // Action: Remove selected views
void ViewsListWidget::actionRemoveView()
{
 FacsanaduProject* project = mw_->project();

  // //    project->views().removeAll(getSelectedViews());
 for(ViewSettings* v : getSelectedViews())
   project->views().removeAll(v);

 updateViewsList();
}

 
// // Action: Create a new view
void ViewsListWidget::actionNewView()
{
 FacsanaduProject* project = mw_->project();
 ViewSettings* vs = new ViewSettings();

   //? 
 vs->set_gate( project->gateset()->getRootGate() );

 vs->set_indexX(0);
 vs->set_indexY(1);                                                    

 if( project-> getNumChannels() > vs->indexX() )
   vs->set_indexX(0);

 if( project->getNumChannels() > vs->indexY() )
   vs->set_indexY(0);
 
 //autoscale here the first time?
 
 project->views().append(vs);
 updateViewsList();
}

