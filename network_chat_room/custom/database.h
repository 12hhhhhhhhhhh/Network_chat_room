#ifndef _DATABASE_H_
#define _DATABASE_H_

#include "custom.h"

int create_database(const char* filename);
int run_intruction(const char * filename, const char *sql);
int create_frimsg_table(const char * filename, const char * tablename);
int insert_into_frimsg(const char *filename, const char *table, const char *name, const char *time);

#endif