#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#define window_size_x 670
#define window_size_y 540
#define max_window_size_x 1050 //da capire la risoluzione del pc
#define max_window_size_y 680 //da capire la risoluzione del pc
#define max_resize 10
#define min_resize 0
#define default_resize 5
#define version 1.7

//Questa classe √® quella principale
//Da qui gestisce tutte le altre classi e tutti i dati in loro contenuti
//Gestisce in particolar modo la gui e tutte le operazione ad essa commesse

using namespace std;

//costruttore
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);

    set_initial_gui();

    connect(&display,SIGNAL(onLineDraw(QList<DisplayImage::shape>)),this,SLOT(onDrawLine(QList<DisplayImage::shape>)));
    connect(&display,SIGNAL(setTuple(QString)),this,SLOT(getTuple(QString)));
    connect(&optionsDialog,SIGNAL(ColorsThickness(int,int,int,int,int,int,int,int,int,int,int)),
                     this,SLOT(getColorsThickness(int,int,int,int,int,int,int,int,int,int,int)));
}

//distruttore
MainWindow::~MainWindow(){
    delete ui; //distruge in particola modo l'interfaccia
}

//metodo che setter√  l'interfaccia grafica all'avvio
void MainWindow::set_initial_gui(){
    //qui viene disattivata tutta la gui e viene ben definita l-istanza display
    ui->actionCreate_List->setDisabled(true);
    ui->Square->setDisabled(true);
    ui->Ellipse->setDisabled(true);
    ui->Polygon->setDisabled(true);
    ui->ClearSelected->setDisabled(true);
    ui->ClearLast->setDisabled(true);
    ui->ClearAll->setDisabled(true);
    ui->ObjectListView->setDisabled(true);
    ui->InstanceListView->setDisabled(true);
    ui->NumberListView->setDisabled(true);
    ui->EndProject->setDisabled(true);
    ui->LoadNext->setDisabled(true);
    ui->LoadPrevious->setDisabled(true);
    ui->Save->setDisabled(true);
    ui->Highlight->setDisabled(true);
    ui->ResizeSlider->setDisabled(true);
    ui->ResizeSlider->setMinimum(min_resize);
    ui->ResizeSlider->setMaximum(max_resize);
    ui->ResizeSlider->setValue(default_resize);
    ctrlIsPressed=false;
    shiftIsPressed=false;

    sizew=window_size_x;
    sizeh=window_size_y;
    display.setParent(ui->scrollContents);
    ui->scrollContents->resize(0,0);
    display.setGeometry(0,0,0,0);
    display.setObjectName(QString::fromUtf8("ImageDisplayWidget"));

    QString title="Image Annotation Tool (v."+QString::number(version)+")";
    QMainWindow::setMinimumSize(sizew,sizeh);
    QMainWindow::setWindowTitle(title);
}

//metodo che esegue il backUp dei dati
void MainWindow::makeBackUp(){
    backUpHere.workspace=workspace;
    backUpHere.image_filename_path=image_filename_path;
    backUpHere.list_filename_path=list_filename_path;
    backUpHere.txt_filename_path=txt_filename_path;
    backUpHere.project_filename_path=project_filename_path;
    backUpHere.ShapeID=shapeID;
    backUpHere.mapObjectInstance=mapObjectInstance;
    backUpHere.mapInstanceNumber=mapInstanceNumber;
    backUpHere.background=background;
    backUpHere.scaledEdits=scaledEdits;
    backUpHere.sizeh=sizeh;
    backUpHere.sizew=sizew;
    backUpHere.resize_factor=resize_factor;
    backUpHere.title=QMainWindow::windowTitle();
}

//metodo legato al comando Options
void MainWindow::on_actionOptions_triggered(){
    if(optionsDialog.exec()>0){} //viene eseguito il programma options
}

//metodo attivato dal signal colorsThickness presente in Options
void MainWindow::getColorsThickness(int radius, int thickness, int myRed, int myGreen, int MyBlue, int sqRed, int sqGreen, int sqBlue, int shapeRed, int shapeGreen, int shapeBlue){
    //quando viene attivato il compito di MainWindow e quello di fare da tramite e cambiare i colori in display con il metodo pubblico setClororThickness
    display.setColorsThickness(radius, thickness, myRed, myGreen, MyBlue, sqRed, sqGreen, sqBlue, shapeRed, shapeGreen, shapeBlue);
}

//metodo legato al comando Create List (WIP)
void MainWindow::on_actionCreate_List_triggered(){
    if(listToolDialog.exec()>0){}
}

//metodo legato al comando Annotate Single Image
void MainWindow::on_actionAnnotate_Single_Image_triggered(){
    //all-inizio viene chiesto all-untente se vuole salvare il lavoro svolto fino al quel momento (se necessario)
    QMessageBox::StandardButton reply = QMessageBox::No;
    if(ui->Save->isEnabled()){ //il tasto save √® il pi√π adatto falg di controllo
        reply = QMessageBox::question(this,"Question","Do you want to save before annotate a new image?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No);
    }
    if(reply!=QMessageBox::Cancel){
        if(reply==QMessageBox::Yes) on_Save_clicked();
        makeBackUp(); //si esegue un backup in quanto l-utente potrebbe interrompere il processo e rendere necessario un ripristino dei dati
        if(workspace.isEmpty()) workspace=qApp->applicationDirPath();
        QString filters = "Images (*.jpg *.png *.bmp)";
        QFileDialog qdialog;
        image_filename_path=qdialog.getOpenFileName(this,"Open Image",workspace,filters);
        if(!image_filename_path.isNull()){ //se √® stata scelta l-immagine
            if(!project_filename_path.isEmpty()&&imageSequence.indexOf(image_filename_path)!=-1){
                //questo codice viene attivato solo se si st√  lavorando in un progetto e per questo project_filename_path √® il miglior flag
                //qui dentro si entra se l-utente st√  caricando un-immagine gi√  annotata durante il progetto
                //quindi per avere tutte le annotazioni precedenti si esce dal contesto e si passa a caricare
                //il file di annotazione tramite load_annotation
                txt_filename_path=pwizard.projectpath+"/"+pwizard.projectName+"/";
                QString imageName=image_filename_path;
                int pos;
                for(pos=imageName.size(); imageName[pos]!='/'; --pos);
                imageName.remove(0,pos+1);
                imageName.remove(imageName.size()-4,4);
                imageName+=".txt";
                txt_filename_path+=imageName;
                load_annotation(); //load_annotation per lavorare richiede un txt_filename_path che qui viene creato
            }
            else{
                load_image(); //viene invocato load_image che passer√  a processare l-immagine scelta
                //viene chiesto se si vuole caricare una nuova lista in caso affermativo viene invocasto load_List
                QMessageBox::StandardButton reply = QMessageBox::Yes;
                if(!list_filename_path.isEmpty()) reply=QMessageBox::question(this,"Question!","Do you want to load a new list?",QMessageBox::Yes|QMessageBox::No);
                if(reply==QMessageBox::Yes){
                    QFileDialog qdialog;
                    list_filename_path=qdialog.getOpenFileName(this,"Open List",qApp->applicationDirPath(),"*.lst");
                }
                if(!list_filename_path.isEmpty()){
                    load_list();
                    defaultView();
                }
                else doBackUp(); //in caso di interruzione viene cancellato tutte ed eseguito il ripristino dei dati
            }
        }
        else doBackUp(); //in caso di interruzione viene cancellato tutte ed eseguito il ripristino dei dati
    }
}

//metodo legato al comando Annotate Multiple Image
void MainWindow::on_actionAnnotate_Multiple_Image_triggered(){
    //viene chiesto se si vuole salvare
    QMessageBox::StandardButton reply = QMessageBox::No;
    if(ui->Save->isEnabled()){
        reply = QMessageBox::question(this,"Question","Do you want to save before load an annotation file?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No);
    }
    if(reply!=QMessageBox::Cancel){
        if(reply==QMessageBox::Yes) on_Save_clicked();
        makeBackUp(); //viene eseguito un backup
        if(pwizard.exec()>0){
            //viene eseguito il wizard che chieder√  di dare un nome al progetto
            //e di specificare dove si vuole creare la cartella con quel nome
            QDir dir(pwizard.projectpath);
            dir.mkdir(pwizard.projectName);
            project_filename_path=pwizard.projectpath; //attiviamo il flag
            on_actionAnnotate_Single_Image_triggered();
            ui->LoadNext->setDisabled(false);
            ui->EndProject->setDisabled(false);
            ui->actionAnnotate_Single_Image->setDisabled(true);
            ui->actionAnnotate_Multiple_Image->setDisabled(true);
            ui->actionLoad_annotations->setDisabled(true);
        }
        else doBackUp(); //in caso di interruzioni
    }
}

//metodo legato al comando Load Annotation
void MainWindow::on_actionLoad_annotations_triggered(){
    //viene chiesto se si vuole salvare
    QMessageBox::StandardButton reply = QMessageBox::No;
    if(ui->Save->isEnabled()){
        reply = QMessageBox::question(this,"Question","Do you want to save before load an annotation file?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No);
    }
    if(reply!=QMessageBox::Cancel){
        if(reply==QMessageBox::Yes) on_Save_clicked();
        makeBackUp(); //si esegue un backup
        if(workspace.isEmpty()) workspace=qApp->applicationDirPath();
        QFileDialog qdialog;
        txt_filename_path = qdialog.getOpenFileName(this,"Load Annotation",workspace,"*.txt");
        if(!txt_filename_path.isNull()){
            if(!load_annotation()) doBackUp(); //ripristino in caso di interruzioni
        }
        else doBackUp(); //si esegue il ripristino in caso di interruzioni
    }
}

//metodo legato al comando Instructions
void MainWindow::on_actionInstructions_triggered(){
    QMessageBox::information(this,"Instructions",
                             QString("Select 'Annotate Single Image' to start annotating a single image.\n")+
                             QString("Select 'Annotate Multiple Image' to start annotating a sequence of images.\n")+
                             QString("When you are annotating multiple images, use 'Load Next' and 'Load Previous' to navigate and 'End Project' to terminate.\n")+
                             QString("Select 'Load Annotations' to open a previously annotated image.\n\n")+
                             QString("Select the 'Shape' of the annotation and select the 'Object' and the 'Instance' before edit.\n")+
                             QString("Use Left-button to make the annotation.\n")+
                             QString("Hold down the Right-button inside the annotation or over its reference squares to move them.\n")+
                             QString("'Highlight' lights the reference Squares when passing over them.\n\n")+
                             QString("Shortcuts:\nAnnotate Single Image\t\tCtrl+N\nAnnotate Multiple\t\tCtrl+M\nLoad Annotation\t\tCtrl+L\n")+
                             QString("Quit\t\t\tCtrl+Q\nOptions\t\t\tCtrl+O\nInstructions\t\t\tCtrl+I\nSquare\t\t\tCtrl+Shift+S\nEllipse\t\t\tCtrl+Shift+E\nPolygon\t\t\tCtrl+Shift+P\n")+
                             QString("Highlight\t\t\tCtrl+Shift+H\nClear Selected\t\t\tCanc\nClear Last\t\t\tCtrl+Canc\nClear All\t\t\tCtrl+Shift+Canc\n")+
                             QString("Terminate Project\t\tCtrl+T\nLoad Next\t\t\tCtrl+PagUp\nLoad Previous\t\t\tCtrl+PagDown\nSave\t\t\tCtrl+S\n")+
                             QString("Zoom in\t\t\tCtrl+Plus\nZoom out\t\t\tCtrl+Minus\n"));
}

//metodo che prepara la finestra a stampare la nuova immagine
void MainWindow::load_image(){
    cleanWindow(); //si esegue una pulizia dei dati e della finestra
    QFileInfo qfile(image_filename_path);
    workspace=qfile.absolutePath();
    QString title="Image Annotation Tool (v."+QString::number(version)+") - ";
    if(project_filename_path.isNull()) title+=image_filename_path;
    else title+=pwizard.projectpath+"/"+pwizard.projectName;
    QMainWindow::setWindowTitle(title);

    display.clear_image(); //si pulisce anche display
    ui->ResizeSlider->setValue(default_resize);
    resizeMethod(default_resize); //questo √® il metodo che processa l-immagne
}

//metodo che processa la lista scelta dall'utente e la carica
void MainWindow::load_list(){
    QFile file(list_filename_path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    //una volta che la lista √® stata caricata si procede alla lettura ed a popolare le mappe
    QStringList objectList;
    while(!file.atEnd()){
        QString line = file.readLine();
        line.toStdString();
        int i;
        QString object;
        for(i=0; line[i]!='\t'; ++i) object.append(line[i]);
        QString instance;
        for(i=i+1; (line[i]!='\n'&&i<line.size()); ++i) instance.append(line[i]);
        bool findObject=false;
        for(int j=0;j<objectList.size();++j) if(object==objectList.at(j)) findObject=true;
        bool findInstance=false;
        if(findObject){
            QList<QString> correlatedInstance=mapObjectInstance.values(object);
            for(int j=0; j<correlatedInstance.size(); ++j) if(instance == correlatedInstance.at(j)) findInstance=true;
        }
        if(!findObject){
            objectList<<object;
            mapObjectInstance.insert(object,instance);
        }
        if(findObject&&!findInstance) mapObjectInstance.insert(object,instance);
    }
    ui->ObjectListView->addItems(objectList); //dalla lettura si prendono i valori da caricare nella prima colonna
    file.close();
    ui->Save->setDisabled(false); //il save viene abilitato
}

//metodo che processa il file di annotazione scelto dall'utente
bool MainWindow::load_annotation(){
    //questo metodo √® stato reso booleano perch√® pu√≤ fallire per vari motivi
    cleanWindow();
    if(project_filename_path.isEmpty()){ //modifica di comportamento
        QFileInfo qfile(txt_filename_path);
        workspace=qfile.absolutePath();
    }
    else{
        QFileInfo qfile(image_filename_path);
        workspace=qfile.absolutePath();
    }
    QString title="Image Annotation Tool (v."+QString::number(version)+") - ";
    if(project_filename_path.isEmpty()) title+=workspace;
    else title+=pwizard.projectpath+"/"+pwizard.projectName;
    QMainWindow::setWindowTitle(title);
    QFile file(txt_filename_path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return false;
    QString line = file.readLine();
    if(!(line=="133518122014\n")) return false;
    //questo √® il "magic number" per scongiurare il fatto che l-utente carichi un file non coerente con il contesto
    line=file.readLine();
    if(project_filename_path.isEmpty()){ //modifica di comportamento
        if(line.at(1)==':') image_filename_path=line;
        else{
            image_filename_path=txt_filename_path;
            image_filename_path.remove(image_filename_path.size()-4,4);
            int pos;
            for(pos=line.size(); line[pos]!='.';--pos);
            line.remove(0,pos);
            image_filename_path+=line;
        }
    }
    else image_filename_path=line;
    image_filename_path.remove(image_filename_path.size()-1,1);
    //viene creato image_filename_path che avr√  il compito di indicare a resizeMethod quale immagine caricare
    QList<DisplayImage::shape> outEdits;
    QStringList objectList;
    //qui il file viene processato
    while(!file.atEnd()){
        //fino a qui vengono lette object ed instance
        line=file.readLine();
        line.toStdString();
        int i;
        DisplayImage::shape another;
        QString object;
        for(i=0; line[i]!='\t';++i) object.append(line[i]);
        QString instance;
        for(i=i+1; line[i]!='\t'&&line[i]!='\n'&&i<line.size();++i) instance.append(line[i]);
        bool findObject=false;
        for(int j=0;j<objectList.size();++j) if(object==objectList.at(j)) findObject=true;
        bool findInstance=false;
        if(findObject){
            QList<QString> correlatedInstance=mapObjectInstance.values(object);
            for(int j=0; j<correlatedInstance.size(); ++j) if(instance == correlatedInstance.at(j)) findInstance=true;
        }
        //se la linea non √® finita
        if((i+1)>=line.size()){//+1 per sicurezza
            //viene letto il nome della shape
            if(!findObject){
                objectList<<object;
                mapObjectInstance.insert(object,instance);
            }
            if(findObject&&!findInstance) mapObjectInstance.insert(object,instance);
        }
        //si procede a popolare le mappe
        else{
            QString number;
            for(i=i+1;line[i]!='\t';++i) number.append(line[i]);
            if(!findObject){
                objectList<<object;
                mapObjectInstance.insert(object,instance);
                mapInstanceNumber.insert(object+":"+instance,number);
            }
            if(findObject&&!findInstance){
                mapObjectInstance.insert(object,instance);
                mapInstanceNumber.insert(object+":"+instance,number);
            }
            if(findObject&&findInstance) mapInstanceNumber.insert(object+":"+instance,number);
            another.id=object+":"+instance+":"+number;
            //si legge il tipo di shape e si procede a copiare i punti
            QString type;
            for(i=i+1; line[i]!=':'; ++i) type.append(line[i]);
            if(type=="Square") another.form=square;
            if(type=="Ellipse") another.form=ellipse;
            if(type=="Polygon") another.form=polygon;
            i+=2; //salta : e \t
            while(i<line.size()){
                QString x;
                QString y;
                for(i=i; line[i]!=','; ++i) x.append(line[i]);
                int rx=x.toInt();
                for(i=i+1; line[i]!=':' && i<line.size(); ++i) y.append(line[i]);
                int ry=y.toInt();
                ++i;
                another.shapePoints<<QPoint(rx,ry);
            }
            outEdits<<another;
            scaledEdits<<another; //qui viene caricata la shape ottenuta
        }
    }
    //viene popolata la prima colonna della gui
    ui->ObjectListView->addItems(objectList);
    file.close();
    ui->ResizeSlider->setValue(default_resize);
    //se l-immagine non viene trovata
    if(!resizeMethod(default_resize)){
        //si procede a cercarla nella cartella dove si trova il file txt
        QString path=txt_filename_path;
        path.remove(path.size()-4,4);
        int pos;
        for(pos=image_filename_path.size(); image_filename_path[pos]!='.';--pos);
        image_filename_path.remove(0,pos);
        image_filename_path=path+image_filename_path;
        if(!resizeMethod(default_resize)) return false;
    }
    if(!outEdits.isEmpty()){
        display.setEdits(outEdits);
        display.resizeEdits(default_resize);
        ui->ClearAll->setDisabled(false);
        ui->ClearLast->setDisabled(false);
    }
    defaultView();
    return true;
}

//metodo che esegue il ripristino dei dati
void MainWindow::doBackUp(){
    ui->ObjectListView->clear();
    ui->InstanceListView->clear();
    ui->NumberListView->clear();
    workspace=backUpHere.workspace;
    image_filename_path=backUpHere.image_filename_path;
    list_filename_path=backUpHere.list_filename_path;
    txt_filename_path=backUpHere.txt_filename_path;
    project_filename_path=backUpHere.project_filename_path;
    mapObjectInstance=backUpHere.mapObjectInstance;
    mapInstanceNumber=backUpHere.mapInstanceNumber;
    background=backUpHere.background;
    scaledEdits=backUpHere.scaledEdits;
    sizeh=backUpHere.sizeh;
    sizew=backUpHere.sizew;
    resize_factor=backUpHere.resize_factor;
    QStringList objects;
    QList<QString> uniqueKeys = mapObjectInstance.uniqueKeys();
    for(int i=0; i<uniqueKeys.size(); ++i){
        objects<<uniqueKeys.at(i);
    }
    ui->ObjectListView->addItems(objects);
    ui->ResizeSlider->setValue(resize_factor);
    resizeMethod(resize_factor);
    display.setEdits(scaledEdits);
    if(!scaledEdits.isEmpty()) display.resizeEdits(resize_factor);
    QMainWindow::setWindowTitle(backUpHere.title);
}

//metodo che resetta il programma preparandolo ad un nuovo processo
void MainWindow::cleanWindow(){
    ui->ObjectListView->clear();
    ui->InstanceListView->clear();
    ui->NumberListView->clear();
    scaledEdits.clear();
    mapObjectInstance.clear();
    mapInstanceNumber.clear();
    display.setNameSelected(false);
    display.setShapeSelected("");
    display.clear_image();
}

//metodo che porta il programma ad una situazione standard
void MainWindow::defaultView(){
    ui->Square->setDisabled(false);
    ui->Ellipse->setDisabled(false);
    ui->Polygon->setDisabled(false);
    ui->ResizeSlider->setDisabled(false);
    ui->Highlight->setDisabled(false);
    ui->ObjectListView->setDisabled(false);
    ui->InstanceListView->setDisabled(false);
    ui->NumberListView->setDisabled(false);
}

//metodo legato allo slider che gestisce lo zoom
void MainWindow::on_ResizeSlider_sliderMoved(int position){
    if(!scaledEdits.isEmpty()){
        display.setEdits(scaledEdits);
        display.resizeEdits(position);
    }
    resizeMethod(position);
}

//metodo che processa l'immagine, fa il resize se necessario e la stampa
bool MainWindow::resizeMethod(int value){
    //booleano, cos- si pu√≤ intervenire in caso di errore
    //la formula per le nuove dimensioni √® cos√¨ composta:
    //190 √® la massima percentuale di zoom a cui si pu√≤ arrivare, 10 √® la minima
    //lo zoom attuale si ottiene quindi facendo 190 meno 18 moltiplicato per il valore dello slider, resize, che gestisce lo zoom nell'interfaccia
    //lo slider varia tra 0 e quindi 190% di zoom fino a 10, ovvero il 10% di zoom
    //trovato il valore si fa una proprozione per trovare il nuovo valore
    if(background.load(image_filename_path)){
        resize_factor=value;
        sizew=background.size().width()/(100.0/(190-resize_factor*18));
        sizeh=background.size().height()/(100.0/(190-resize_factor*18));
        QImage scaled=background.scaled(sizew,sizeh,Qt::KeepAspectRatio, Qt::FastTransformation);
        display.resize(sizew,sizeh);
        display.setView(scaled);
        ui->scrollContents->resize(sizew,sizeh);
        return true;
    }
    return false;
}

//metodo attivato dal signal setTuple presente in DisplayImage
void MainWindow::getTuple(QString shapeID){
    //quando riceve l-id, cerca l-object nella prima colonna e simula il click
    //cerca l-instance nella seconda colonna e simula il click
    //cerca il number nella terza colonna e simula il click
    this->shapeID=shapeID;
    shapeID.toStdString();
    int i;
    QString object;
    for(i=0; shapeID[i]!=':';++i) object.append(shapeID[i]);
    QString instance;
    for(i=i+1; shapeID[i]!=':';++i) instance.append(shapeID[i]);
    QString number;
    for(i=i+1; i<shapeID.size();++i) number.append(shapeID[i]);
    int j=0;
    do{
        ui->ObjectListView->setCurrentRow(j);
        j++;
    }while(ui->ObjectListView->currentItem()->text()!=object);
    on_ObjectListView_clicked();
    j=0;
    do{
        ui->InstanceListView->setCurrentRow(j);
        j++;
    }while(ui->InstanceListView->currentItem()->text()!=instance);
    on_InstanceListView_clicked();
    j=0;
    do{
        ui->NumberListView->setCurrentRow(j);
        j++;
    }while(ui->NumberListView->currentItem()->text()!=number);
    on_NumberListView_clicked();
    ui->ClearSelected->setDisabled(false);
}

//metodo legato alla prima colonna
void MainWindow::on_ObjectListView_clicked(){
    //quando un valore viene selezionato il metodo provvede a far comparire nella seconda colonna i valori subordinati
    display.setNameSelected(false);
    display.setShapeSelected("");
    ui->ClearSelected->setDisabled(true);
    ui->InstanceListView->clear();
    ui->NumberListView->clear();
    QList<QString> instances;
    QList<QString> correlatedInstance = mapObjectInstance.values(ui->ObjectListView->currentItem()->text());
    //per evitare l-inversione della lista rispetto al file originale
    for(int i=correlatedInstance.size()-1;i>=0;--i) instances<<correlatedInstance.at(i);
    ui->InstanceListView->addItems(instances);
}

//metodo legato alla seconda colonna
void MainWindow::on_InstanceListView_clicked(){
    //quando un valore viene selezionato il metodo provvede a far comparire nella terza colonna i valori subordinati
    display.setNameSelected(true);
    display.setShapeSelected("");
    ui->ClearSelected->setDisabled(true);
    ui->NumberListView->clear();
    QList<QString> numbers;
    numbers<<mapInstanceNumber.values(ui->ObjectListView->currentItem()->text()+":"+ui->InstanceListView->currentItem()->text());
    for(int i=0;i<numbers.size()/2;++i) numbers.swap(i,numbers.size()-(i+1));
    ui->NumberListView->addItems(numbers);
}

//metodo legato alla terza colonnna
void MainWindow::on_NumberListView_clicked(){
    //quando un valore viene selezionato il metodo provvede a mandare un segnale a display colorando diversamente la relativa shape
    display.setShapeSelected(ui->ObjectListView->currentItem()->text()+":"+ui->InstanceListView->currentItem()->text()+":"+ui->NumberListView->currentItem()->text());
    shapeID=ui->ObjectListView->currentItem()->text()+":"+ui->InstanceListView->currentItem()->text()+":"+ui->NumberListView->currentItem()->text();
    ui->ClearSelected->setDisabled(false);
}

//metodo legato al bottone circolare con a fianco il testo Square
void MainWindow::on_Square_clicked(){
    display.reset();
    display.enableSquareDraw(); //informa display che deve mostrare shape di forma rettangolare
}

//metodo legato al bottone circolare con a fianco il testo Ellipse
void MainWindow::on_Ellipse_clicked(){
    display.reset();
    display.enableEllipseDraw(); //informa display che deve mostrare shape di forma circolare
}

//metodo legato al bottone circolare con a fianco il testo Polygon
void MainWindow::on_Polygon_clicked(){
    display.reset();
    display.enablePolygonDraw(); //informa display che deve mostrare shape di forma pligonale
}

//metodo legato al bottone quadrato con a fianco il testo Highlight
void MainWindow::on_Highlight_clicked(bool checked){
    display.enableHighlight(checked); //informa display che deve mostrare il bordo grigio intorno al quadratino
}

//metodo attivato dal signal onLineDraw presente in DisplayImage
void MainWindow::onDrawLine(QList<DisplayImage::shape> edits){
    //questo metodo viene invocato per nature diverse
    //ma riesce a capire se si st√  aggiunggendo una shape o se ne sta modificando/spostando una gi√  presente
    for(int i=0; i<edits.size(); ++i){
        DisplayImage::shape another;
        if(edits.at(i).id.isEmpty()){ //se √® vero allora √® stata aggiunta una nuova shape
            QString object=ui->ObjectListView->currentItem()->text();
            QString instance=ui->InstanceListView->currentItem()->text();
            QString number;
            bool ok;
            do{
                number=QInputDialog::getText(this,"Need a Shape Name","Text here the Shape Name",QLineEdit::Normal,QString(),&ok,0);
                if(ok){
                    if(!number.isEmpty()){
                        QList<QString> numbers;
                        numbers<<mapInstanceNumber.values(object+":"+instance);
                        for(int j=0;j<numbers.size();++j) if(number==numbers.at(j)) ok=false;
                    }
                    else ok=false;
                }
                else ok=true;
            }while(!ok);
            if(!number.isEmpty()){
                another.id=object+":"+instance+":"+number;
                another.form=edits.at(i).form;
                for(int j=0; j<edits.at(i).shapePoints.size(); ++j){
                    QPoint scaled_point=coordinate_scaling(edits.at(i).shapePoints.at(j));
                    another.shapePoints<<scaled_point;
                }
                scaledEdits<<another;
                mapInstanceNumber.insert(object+":"+instance,number);
                on_InstanceListView_clicked();
                ui->NumberListView->setCurrentRow(ui->NumberListView->count()-1);
                on_NumberListView_clicked();
                ui->Save->setDisabled(false);
            }
        }
        if(shapeID!="" && shapeID==edits.at(i).id){
            //tramite l-id so quale shape √® stata modificata e quindi sostituirla con quella nuova
            another.id=edits.at(i).id;
            another.form=edits.at(i).form;
            for(int j=0; j<edits.at(i).shapePoints.size(); ++j){
                QPoint new_current_point=coordinate_scaling(edits.at(i).shapePoints.at(j));
                another.shapePoints<<new_current_point;
            }
            scaledEdits.replace(i,another);
            ui->Save->setDisabled(false);
        }
    }
    display.setEdits(scaledEdits);
    display.resizeEdits(resize_factor);
    if(scaledEdits.size()>1){
        ui->ClearLast->setDisabled(false);
        ui->ClearAll->setDisabled(false);
    }
}

//metodo che calcola il resize dei punti apparteneti alle shape
QPoint MainWindow::coordinate_scaling(QPoint init_point){
    QPoint new_point;
    new_point.rx()=init_point.rx()*(100.0/(190-resize_factor*18));
    new_point.ry()=init_point.ry()*(100.0/(190-resize_factor*18));
    return new_point;
}

//metodo legato al bottone rettangolare con il nome Clear Selected
void MainWindow::on_ClearSelected_clicked(){
    //toglier√  tutti i dati relativi alla shape selezionata
    QString temp=shapeID;
    if(scaledEdits.size()>1){
        for(int i=0; i<scaledEdits.size(); ++i) if(scaledEdits.at(i).id==shapeID) scaledEdits.removeAt(i);
        display.setEdits(scaledEdits);
        display.resizeEdits(resize_factor);
        display.reset();
    }
    else{
        scaledEdits.clear();
        display.clear_image();
    }
    int i;
    QString object;
    for(i=0;temp[i]!=':';++i) object.append(temp[i]);
    QString instance;
    for(i=i+1;temp[i]!=':';++i) instance.append(temp[i]);
    QString number;
    for(i=i+1;i<temp.size();++i) number.append(temp[i]);
    mapInstanceNumber.remove(object+":"+instance,number);
    shapeID.clear();
    ui->ClearSelected->setDisabled(true);
    if(scaledEdits.isEmpty()){
        ui->ClearLast->setDisabled(true);
        ui->ClearAll->setDisabled(true);
    }
    ui->Save->setDisabled(false);
    if(ui->InstanceListView->isItemSelected(ui->InstanceListView->currentItem())&&ui->InstanceListView->currentItem()->text()==instance) on_InstanceListView_clicked();
}

//metodo legato al bottone rettangolare con il nome Clear Last
void MainWindow::on_ClearLast_clicked(){
    //toglier√  tutti i dati relativi all-ultima shape disegnata
    display.clearLastEdits();
    QString temp=scaledEdits.last().id;
    int i;
    QString object;
    for(i=0;temp[i]!=':';++i) object.append(temp[i]);
    QString instance;
    for(i=i+1;temp[i]!=':';++i) instance.append(temp[i]);
    QString number;
    for(i=i+1;i<temp.size();++i) number.append(temp[i]);
    mapInstanceNumber.remove(object+":"+instance,number);
    scaledEdits.removeLast();
    display.reset();
    if(scaledEdits.isEmpty()){
        ui->ClearLast->setDisabled(true);
        ui->ClearAll->setDisabled(true);
    }
    ui->Save->setDisabled(false);
    if(ui->InstanceListView->isItemSelected(ui->InstanceListView->currentItem())&&ui->InstanceListView->currentItem()->text()==instance) on_InstanceListView_clicked();
}

//metodo legato al bottone rettangolare con il nome Clear All
void MainWindow::on_ClearAll_clicked(){
    //pulir√  l-immagine da tutte le shape cancellando i relativi dati
    display.clear_image();
    if(!scaledEdits.isEmpty()) scaledEdits.clear();
    if(scaledEdits.isEmpty()){
        ui->ClearLast->setDisabled(true);
        ui->ClearAll->setDisabled(true);
    }
    ui->NumberListView->clear();
    mapInstanceNumber.clear();
    ui->Save->setDisabled(false);
}

//metodo legato al bottone rettangolare con il nome End Project
void MainWindow::on_EndProject_clicked(){
    //quando premuto, interrompre il progetto cancellando il valore nel flag project_filename_path
    QMessageBox::StandardButton reply = QMessageBox::No;
    if(ui->Save->isEnabled()){
        reply = QMessageBox::question(this,"Question","Do you want to save before load an annotation file?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No);
    }
    if(reply!=QMessageBox::Cancel){
        if(reply==QMessageBox::Yes) on_Save_clicked();
        project_filename_path.clear();
        ui->actionAnnotate_Single_Image->setDisabled(false);
        ui->actionAnnotate_Multiple_Image->setDisabled(false);
        ui->actionLoad_annotations->setDisabled(false);
        cleanWindow();
        set_initial_gui();
    }
}

//metodo legato al bottone rettangolare con il nome Load Next
void MainWindow::on_LoadNext_clicked(){
    //permette all-utente di navigare tra le immagini annotate fino a quel momento
    //dopo aver caricato l-ultima, se ripremuto avvier√  il processo per annotare una nuova immagine
    //attiva e disattiva il tasto load_previous
    QMessageBox::StandardButton reply = QMessageBox::No;
    if(ui->Save->isEnabled()){
        reply = QMessageBox::question(this,"Question","Do you want to save before?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No);
    }
    if(reply!=QMessageBox::Cancel){
        if(reply==QMessageBox::Yes){
            on_Save_clicked();
            if(imageSequence.indexOf(image_filename_path)==-1) imageSequence.append(image_filename_path);
        }
        if(imageSequence.indexOf(image_filename_path)==imageSequence.size()-1) on_actionAnnotate_Single_Image_triggered();
        else{
            QString imageName=image_filename_path=imageSequence.at(imageSequence.indexOf(image_filename_path)+1);
            int pos;
            for(pos=imageName.size(); imageName[pos]!='/'; --pos);
            imageName.remove(0,pos+1);
            imageName.remove(imageName.size()-4,4);
            imageName+=".txt";
            txt_filename_path=project_filename_path+"/"+pwizard.projectName+"/"+imageName;
            load_annotation();
        }
        if(imageSequence.indexOf(image_filename_path)==0) ui->LoadPrevious->setDisabled(true);
        else ui->LoadPrevious->setDisabled(false);
    }
}

//metodo legato al bottone rettangolare con il nome Load Previous
void MainWindow::on_LoadPrevious_clicked(){
    //permette all-utente di navigare tra le immagini annotate fino a quel momento
    //dopo aver caricato la prima il bottone si disattiva
    QMessageBox::StandardButton reply = QMessageBox::No;
    if(ui->Save->isEnabled()){
        reply = QMessageBox::question(this,"Question","Do you want to save before?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No);
    }
    if(reply!=QMessageBox::Cancel){
        if(reply==QMessageBox::Yes){
            on_Save_clicked();
            if(imageSequence.indexOf(image_filename_path)==-1) imageSequence.append(image_filename_path);
        }
        QString imageName=image_filename_path=imageSequence.at(imageSequence.indexOf(image_filename_path)-1);
        int pos;
        for(pos=imageName.size(); imageName[pos]!='/'; --pos);
        imageName.remove(0,pos+1);
        imageName.remove(imageName.size()-4,4);
        imageName+=".txt";
        txt_filename_path=project_filename_path+"/"+pwizard.projectName+"/"+imageName;
        load_annotation();
        if(imageSequence.indexOf(image_filename_path)-1<0) ui->LoadPrevious->setDisabled(true);
    }
}

//metodo legato al bottone rettangolare con il nome Save
void MainWindow::on_Save_clicked(){
    //metodo che salva su file tutte le annotazioni eseguite in scala 1:1
    QString filename;
    if(project_filename_path.isEmpty()){
        filename=image_filename_path;
        filename.remove(image_filename_path.size()-4,4);
        filename+=".txt";
    }
    else{
        filename=project_filename_path+"/"+pwizard.projectName+"/";
        QString imageName=image_filename_path;
        int pos;
        for(pos=imageName.size(); imageName[pos]!='/'; --pos);
        imageName.remove(0,pos+1);
        QString saveName=imageName;
        imageName.remove(imageName.size()-4,4);
        imageName+=".txt";
        filename+=imageName;
        QFile::copy(image_filename_path,project_filename_path+"/"+pwizard.projectName+"/"+saveName);
        if(imageSequence.indexOf(image_filename_path)==-1) imageSequence.append(image_filename_path);
    }
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    QTextStream ofs(&file);
    ofs<<"133518122014\n";
    QString imageName=image_filename_path;
    if(project_filename_path.isEmpty()){
        int pos;
        for(pos=imageName.size(); imageName[pos]!='/'; --pos);
        imageName.remove(0,pos+1);
    }
    ofs<<imageName<<"\n";
    if(!scaledEdits.isEmpty()){
        for(int i=0; i<scaledEdits.size(); ++i){
            QString temp=scaledEdits.at(i).id;
            temp.toStdString();
            for(int j=0;j<temp.size();++j) if(temp[j]==':') temp[j]='\t';
            temp[temp.size()]='\t';
            ofs<<temp;
            if(scaledEdits.at(i).form==square) ofs <<"Square:\t";
            if(scaledEdits.at(i).form==ellipse) ofs <<"Ellipse:\t";
            if(scaledEdits.at(i).form==polygon) ofs <<"Polygon:\t";
            for(int j=0; j<scaledEdits.at(i).shapePoints.size()-1; ++j){
                QPoint point=scaledEdits.at(i).shapePoints.at(j);
                ofs<<point.rx()<<","<<point.ry()<<":";
            }
            QPoint point=scaledEdits.at(i).shapePoints.at(scaledEdits.at(i).shapePoints.size()-1);
            ofs<<point.rx()<<","<<point.ry()<<"\n";
        }
    }
    QList<QString> uniqueKeys = mapInstanceNumber.uniqueKeys();
    for(int i=0; i<ui->ObjectListView->count(); ++i){
        QList<QString> correlatedItems = mapObjectInstance.values(ui->ObjectListView->item(i)->text());
        for(int j=correlatedItems.size()-1;j>=0;--j){
            bool find=false;
            for(int k=0; k<uniqueKeys.size(); ++k) if(ui->ObjectListView->item(i)->text()+":"+correlatedItems.at(j) == uniqueKeys.at(k)) find=true;
            if(!find) ofs<<ui->ObjectListView->item(i)->text()+"\t"+correlatedItems.at(j)+"\n";
        }
    }
    file.close();
    ui->Save->setDisabled(true);
}

//metodo legato al comando Quit
void MainWindow::on_actionQuit_triggered(){
    close();
}

//metodo per la gestione della chiusura della finestra
void MainWindow::closeEvent(QCloseEvent *event){
    QMessageBox::StandardButton reply = QMessageBox::No;
    if(ui->Save->isEnabled()){
        reply = QMessageBox::question(this,"Question","Do you want to save before quit?",QMessageBox::Cancel|QMessageBox::Yes|QMessageBox::No);
    }
    if(reply!=QMessageBox::Cancel){
        if(reply==QMessageBox::Yes) on_Save_clicked();
        event->accept();
    }
}

//metodo per la gestione del resize della finestra
void MainWindow::resizeEvent(QResizeEvent *event){
    QSize temp=event->size();
    ui->scrollArea->resize(temp.rwidth()-20,temp.rheight()-250);
}

//metodo per la gestione della pressione di determinati tasti mentre √® attiva la finestra
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Control) ctrlIsPressed=true;
    if(ctrlIsPressed&&event->key()==Qt::Key_Shift) shiftIsPressed=true;

    if(ui->ClearSelected->isEnabled()&&!ctrlIsPressed&&!shiftIsPressed&&event->key()==Qt::Key_Cancel) on_ClearSelected_clicked();

    if(ui->actionAnnotate_Single_Image->isEnabled()&&ctrlIsPressed&&event->key()==Qt::Key_N) on_actionAnnotate_Single_Image_triggered();
    if(ui->actionAnnotate_Multiple_Image->isEnabled()&&ctrlIsPressed&&event->key()==Qt::Key_M) on_actionAnnotate_Multiple_Image_triggered();
    if(ui->actionLoad_annotations->isEnabled()&&ctrlIsPressed&&event->key()==Qt::Key_L) on_actionLoad_annotations_triggered();
    if(ctrlIsPressed&&!shiftIsPressed&&event->key()==Qt::Key_Q) on_actionQuit_triggered();
    if(ctrlIsPressed&&event->key()==Qt::Key_O) on_actionOptions_triggered();
    if(ctrlIsPressed&&event->key()==Qt::Key_I) on_actionInstructions_triggered();
    if(ui->ClearLast->isEnabled()&&ctrlIsPressed&&!shiftIsPressed&&event->key()==Qt::Key_Cancel) on_ClearLast_clicked();
    if(ui->Save->isEnabled()&&ctrlIsPressed&&!shiftIsPressed&&event->key()==Qt::Key_S) on_Save_clicked();
    if(ui->ResizeSlider->isEnabled()&&resize_factor>0&&ctrlIsPressed&&!shiftIsPressed&&event->key()==Qt::Key_Plus){
        ui->ResizeSlider->setValue(resize_factor-=1);
        on_ResizeSlider_sliderMoved(resize_factor);
    }
    if(ui->ResizeSlider->isEnabled()&&resize_factor<10&&ctrlIsPressed&&!shiftIsPressed&&event->key()==Qt::Key_Minus){
        ui->ResizeSlider->setValue(resize_factor+=1);
        on_ResizeSlider_sliderMoved(resize_factor);
    }

    if(ui->EndProject->isEnabled()&&ctrlIsPressed&&!shiftIsPressed&&event->key()==Qt::Key_T) on_EndProject_clicked();
    if(ui->LoadNext->isEnabled()&&ctrlIsPressed&&!shiftIsPressed&&event->key()==Qt::Key_PageUp) on_LoadNext_clicked();
    if(ui->LoadPrevious->isEnabled()&&ctrlIsPressed&&!shiftIsPressed&&event->key()==Qt::Key_PageDown) on_LoadPrevious_clicked();
    if(ui->Square->isEnabled()&&ctrlIsPressed&&shiftIsPressed&&event->key()==Qt::Key_S) ui->Square->click();
    if(ui->Ellipse->isEnabled()&&ctrlIsPressed&&shiftIsPressed&&event->key()==Qt::Key_E) ui->Ellipse->click();
    if(ui->Polygon->isEnabled()&&ctrlIsPressed&&shiftIsPressed&&event->key()==Qt::Key_P) ui->Polygon->click();
    if(ui->Highlight->isEnabled()&&ctrlIsPressed&&shiftIsPressed&&event->key()==Qt::Key_H) ui->Highlight->click();
    if(ui->ClearAll->isEnabled()&&ctrlIsPressed&&shiftIsPressed&&event->key()==Qt::Key_Cancel) on_ClearAll_clicked();
}

//metodo per la gestione del rilascio di determinati tasti mentre √® attiva la finestra
void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Escape) display.reset(); //esc
    if(event->key()==Qt::Key_Control) ctrlIsPressed=false; //ctrl
    if(event->key()==Qt::Key_Shift) shiftIsPressed=false; //shift
}

//metodo per la gestione del movimento della rotella mentre √® attiva la finestra
void MainWindow::wheelEvent(QWheelEvent *event){
    if(ctrlIsPressed&&ui->ResizeSlider->isEnabled()){
        if(event->delta()>0 && resize_factor>0){
            ui->ResizeSlider->setValue(resize_factor-=1);
            on_ResizeSlider_sliderMoved(resize_factor);
        }
        if(event->delta()<0 && resize_factor<10){
            ui->ResizeSlider->setValue(resize_factor+=1);
            on_ResizeSlider_sliderMoved(resize_factor);
        }
    }
}

//tentare di adattare a questa tipologia
//QAction openAct(tr("&Open"),this);
//openAct.setShortcut(tr("Ctrl+N"));
//connect(&openAct,SIGNAL(triggered()), this, SLOT(on_actionAnnotate_Single_Image_triggered()));
//#include <QShortcutEvent>
//#include <QShortcut>
/*QShortcut *image = new QShortcut(QKeySequence("Ctrl+N"), this);
(*image).setAutoRepeat(true);
QObject::connect(image, SIGNAL(activated()), this, SLOT(on_actionAnnotate_Single_Image_triggered()));
QShortcut *multiple = new QShortcut(QKeySequence("Ctrl+M"), this);
(*multiple).setAutoRepeat(true);
QObject::connect(multiple, SIGNAL(activated()), this, SLOT(on_actionAnnotate_Multiple_Image_triggered()));
*/

