#include "stdio.h"
#include "sqlite3.h"

int main(void)
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;

   rc = sqlite3_open("1.db", &db);

   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return -1;
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }
   sqlite3_close(db);
   return 0;
}
