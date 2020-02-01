/* Compiple with: $cc users.c -o b -lssl -lcrypto -lncurses -lsqlite3 */

//TODO: Rewrite Sqlite Open Code
//(So its not plagiarized AHEM!)
#include <sqlite3.h>
#include <stdio.h>
#include <openssl/sha.h>
#include "main.h"

int callback(void *NotUsed, int argc, char **argv, 
                    char **azColName);

void create_user(sqlite3 *db, char * name, const unsigned char password[64]);
void sign_in(sqlite3 *db, char * name, const unsigned char password[64]);
void sign_out(sqlite3 *db, char * username);
int is_signed_in(sqlite3 *db, char * username);
int user_balance(sqlite3 *db, char * username);
void set_user_balance(sqlite3 *db, char * username, int bal);
int callback(void *NotUsed, int argc, char **argv, char **azColName);
int user_exists(sqlite3 *db, char * u);


char * name;
unsigned char password[64];
/*
int main(void) 
{
    sqlite3 *db;    // database object
    sqlite3_stmt *res;  // SQL statement
    
    int rc = sqlite3_open("users.db", &db);
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    rc = sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION()", -1, &res, 0);        
    rc = sqlite3_step(res);
    
    if (rc == SQLITE_ROW) {
        printf("SQLITE3 version: %s\n", sqlite3_column_text(res, 0));
    }

    create_user(db, "usrsads", "helo");
    sign_out(db, "usr");
    sign_in(db, "usr", "hello");

    is_signed_in(db, "usr");
    is_signed_in(db, "test_ur");

    set_user_balance(db, "usr", 1000);
    user_balance(db, "usr");
    set_user_balance(db, "usr", 10);
    user_balance(db, "usr");


    sqlite3_finalize(res);
    sqlite3_close(db);
    
    return 0;
    
}
*/
sqlite3* create_db()
{
    sqlite3 *db;    // database object
    sqlite3_stmt *res;  // SQL statement
    
    int rc = sqlite3_open("users.db", &db);

    return db;

}


int callback(void *NotUsed, int argc, char **argv, 
                    char **azColName) {
    
    NotUsed = 0;
    /*
    for (int i = 0; i < argc; i++) {

        // printf("%s = %s\n", azColName[i], argv[i]);
    }
    */
    printf("\n\n\n");
    
    return 0;
}

void create_user(sqlite3 *db, char * name, const unsigned char password[64])
{
    unsigned char *d = SHA256(password, strlen(password), 0);
    int rc;
    sqlite3_stmt *res;
    int ret;
    char * statement[256];
 //   printf("Adding user: %s\nWith password: %s\n", name, d);
    sprintf(statement, "INSERT INTO users (username, password_hash) VALUES (\"%s\", \"%s\");", name, d);
    printf(BLU"%s\n"RESET, statement);

    rc = sqlite3_prepare_v2(db, statement, 256, &res, 0);
    if (rc != SQLITE_OK) // SQLITE_DONE
    {
        printf(RED"Error preparing statement %d: \"%s\"\n"RESET, ret, sqlite3_errmsg(db));
    } else {
        printf(GRN"Successfuly prepared statement\n"RESET);
    }

    ret = sqlite3_step(res);
    if (ret != SQLITE_DONE) // SQLITE_DONE
    {
        printf(RED"Error inserting user - error code %d: \"%s\"\n"RESET, ret, sqlite3_errmsg(db));
    } else {
        printf(GRN"Success adding user\n"RESET);
    }
    sqlite3_finalize(res);
}

void sign_in(sqlite3 *db, char * username, const unsigned char Upassword[64])
{
    char * sql[256];
    unsigned char *d = SHA256(Upassword, strlen(Upassword), 0);

    sprintf(sql, "UPDATE users SET signed_in=true WHERE (username = \"%s\") AND (password_hash = \"%s\");", username, d);
    printf(BLU"%s"RESET"\n", sql);
    char * err_msg;
    int rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
}  

void sign_out(sqlite3 *db, char * username)
{
    char * sql[256];
    sprintf(sql, "UPDATE users SET signed_in=false WHERE (username = \"%s\");", username);
    printf(BLU"%s\n"RESET, sql);
    char * err_msg;
    int rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
 //   printf("%d\n", rc);
  //  printf("%s\n", err_msg);
} 

int is_signed_in(sqlite3 *db, char * username)
{
    sqlite3_stmt *res;
    char * sql[256];
    sprintf(sql, "SELECT \"signed_in\" FROM \"users\" WHERE (\"username\" = \"%s\");", username);
    printf(BLU"%s"RESET"\n", sql);

    char * err_msg;
    int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    rc = sqlite3_step(res);
    
    char * result = sqlite3_column_text(res, 0);

    if (rc == SQLITE_ROW) {
      //  printf("Signed in Result: %s\n", result);
    }

    if (strcmp(result, "1") == 0)
    {
        return true;
    } else {
        return false;
    }
    sqlite3_finalize(res);
}
 
int user_balance(sqlite3 *db, char * username)
{
    sqlite3_stmt *res;
    char * sql[256];
    sprintf(sql, "SELECT \"user_balance\" FROM \"users\" WHERE (\"username\" = \"%s\");", username);
    printf(BLU"%s"RESET"\n", sql);

    int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    rc = sqlite3_step(res);
    printf("Getting res\n");
    char *result = sqlite3_column_text(res, 0);
    printf("Got res\n");
    if (rc == SQLITE_ROW) {
       printf("bal Result: %s\n", result);
    }
    sqlite3_finalize(res);
    int out = atoi("1010");
    printf("bal Result num: %d\n", out);
    return out;

}
 
void set_user_balance(sqlite3 *db, char * username, int bal)
{
    char * sql[256];
    sprintf(sql, "UPDATE users SET user_balance=%d WHERE (username = \"%s\");", bal, username);
    printf(BLU"%s"RESET"\n", sql);
    char * err_msg;
    int rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    printf("%d\n", rc);
  //  printf("%s\n", err_msg);

}

int user_exists(sqlite3 *db, char * u)
{
    sqlite3_stmt *res;
    char * sql[256];
    sprintf(sql, "SELECT username FROM user WHERE (username = \"%s\");", u);
    printf(BLU"%s"RESET"\n", sql);

    char * err_msg;
    int rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    rc = sqlite3_step(res);
    
    char * result = sqlite3_column_text(res, 0);

    printf("Exists: %s\n", result);

    if (strcmp(result, "1") == 0)
    {
        return true;
    } else {
        return false;
    }
    sqlite3_finalize(res);
}