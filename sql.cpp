#include "sql.h"

sql::sql()
{
    count = 0;
}
void sql::connect(){
    if(!QFile("C:/Users/podmi/Desktop/VP/kurs/bok.db").exists()){
        restoreDataBase();
    }
    else {
        openDataBase();
        createTable();
        createFavTable();
    }
}

bool sql::restoreDataBase(){
    if(openDataBase()) return (createTable()) ? true:false;
    else {
        qDebug() << "Не удалось восстановить бд";
        return false;
    }
    return false;
}

bool sql::openDataBase(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("book");
    db.setDatabaseName("C:/Users/podmi/Desktop/VP/kurs/bok.db");
    if(db.open()) return true;
    else return false;
}

void sql::closeDataBase(){
    db.close();
}

bool sql::createTable(){
    QSqlQuery query;
    if(!query.exec("CREATE TABLE IF NOT EXISTS Recipe(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT,ingr TEXT,pic TEXT,spos TEXT,cook TEXT,time INT);")){
        qDebug() << "DataBase: error of create";
        qDebug() << query.lastError().text();
        return false;
    }
    else return true;
    return false;
}
bool sql::createFavTable(){
    QSqlQuery query;
    if(!query.exec("CREATE TABLE IF NOT EXISTS Favorite1(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT);")){
        qDebug() << "DataBase: error of create";
        qDebug() << query.lastError().text();
        return false;
    }
    else return true;
    return false;
}
bool sql::insert(QString name,QString ingr, QString pic,QString spos, QString cook, int time){
    QSqlQuery query;
    query.prepare("INSERT INTO Recipe (name, ingr, pic, spos,cook,time) "
              "VALUES (?, ?, ?, ?,?,?)");
       query.addBindValue(name);
       query.addBindValue(ingr);
       query.addBindValue(pic);
       query.addBindValue(spos);
       query.addBindValue(cook);
       query.addBindValue(time);
       query.exec();
     return true;
}
/*int sql::getId(){
    QSqlQuery query = QSqlQuery(db);
    query.exec("SELECT TOP 1 * FROM Recipe5 ORDER BY id DESC");
    query.first();
    return query.value(0).toInt()+1;
}*/
QString sql::getIngr(int id){
    QSqlQuery query = QSqlQuery(db);
    query.exec("SELECT ingr FROM Recipe WHERE id = '" + Q2I(id) + "';");
    query.first();
    return query.value(0).toString();
}

QString sql::getSpos(int id){
    QSqlQuery query = QSqlQuery(db);
    query.exec("SELECT spos FROM Recipe WHERE id = '" + Q2I(id) + "';");
    query.first();
    return query.value(0).toString();
}
QString sql::getImage(int id){
    QSqlQuery query=QSqlQuery(db);
    query.exec("SELECT pic FROM Recipe WHERE id = '" + Q2I(id) + "';");
    query.first();
    return query.value(0).toString();
}

bool sql::deleteRow(int id){
    QSqlQuery query;
    query.prepare("DELETE FROM Recipe WHERE id = '" + Q2I(id) + "';");
    //query.prepare("INSERT INTO Recipe7 TOP id -1");
    //query.prepare("ALTER Recipe AUTO_INCREMENT = 0");
    query.exec();
    query.first();
    return true;
}
bool sql::insertToFav(QString name){
    QSqlQuery query;
    query.prepare("INSERT INTO Favorite1 (name) "
              "VALUES (?)");
       query.addBindValue(name);
       query.exec();
     return true;
}
QString sql::getName(int id){
    QSqlQuery query;
    query.exec("SELECT name FROM Recipe WHERE id = '" + Q2I(id) + "';");
    query.first();
    return query.value(0).toString();
}
QString sql::getNamefromFav(int id){
    QSqlQuery query;
    query.exec("SELECT name FROM Favorite1 WHERE id = '" + Q2I(id) + "';");
    query.first();
    return query.value(0).toString();
}
/*int sql::getIdMax(){
    QSqlQuery query;
    query.exec("SELECT MAX FROM Favorite");
    return query.value(0).toInt();
}*/
bool sql::deleteRowFromFav(int id){
    QSqlQuery query;
    query.prepare("DELETE FROM Favorite1 WHERE id = '" + Q2I(id) + "';");
    query.exec();
    query.first();
    return true;
}
QString sql::searchName(QString name){
    QSqlQuery query;
    query.exec("SELECT name FROM Recipe WHERE (name='" + name + "');");
    query.first();
    return query.value(0).toString();
}
QString sql::searchIngr(QString ingr){
    QSqlQuery query;
    query.exec("SELECT name FROM Recipe WHERE (ingr='" + ingr + "');");
    query.first();
    return query.value(0).toString();
}

QString sql::searchCookName(QString cook, QString name){
    QSqlQuery query;
    query.exec("SELECT name FROM Recipe WHERE (cook='" + cook + "') AND (name='" + name + "');");
    query.first();
    return query.value(0).toString();
}
QString sql::searchTime(int time){
    QSqlQuery query;
    query.exec("SELECT name FROM Recipe WHERE (time='" + Q2I(time) + "');");
    query.first();
    return query.value(0).toString();
}
