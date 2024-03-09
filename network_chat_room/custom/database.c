#include "database.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

/*
    创建一个数据库
*/
int create_database(const char * filename)
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;

   rc = sqlite3_open(filename, &db);

   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return -1;
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }
   sqlite3_close(db);
   return 0;
}

/*
    在指定的数据库中执行指定的指令
*/
int run_intruction(const char * filename, const char *sql)
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    //1.打开数据库
    rc = sqlite3_open(filename, &db);
    if( rc ){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return -1;
    }else{
        fprintf(stderr, "Opened database successfully\n");
    }
    //2.执行对应的命令
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout, "Table created successfully\n");
    }
    //3.关闭数据库
    sqlite3_close(db);
}

/*
    在指定数据库中创建一个好友信息表格
*/
int create_frimsg_table(const char * filename, const char * tablename)
{
    int rc;
    char sql[256] = {0};
    sprintf(sql, "CREATE TABLE '%s'(content TEXT NOT NULL,time TEXT NOT NULL);", tablename);
    rc = run_intruction(filename, sql);
    return rc;
}

/*
    向好友消息表格中插入一条信息
*/
int insert_into_frimsg(const char *filename, const char *table, const char *name, const char *time)
{
    int rc;
    char sql[256] = {0};
    sprintf(sql, "INSERT INTO %s (content, time) VALUES(%s, %s);", table, name, time);
    rc = run_intruction(filename, sql);
    return rc;
}