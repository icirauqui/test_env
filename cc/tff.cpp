/*
 * Demo of libpq.
 * Build: g++ libpq-demo.cc -o libpq-demo -lpq
 * Run: ./libpq-demo
 */

#include <arpa/inet.h>
#include <iostream>
#include <sstream>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "postgres.h"
#include "libpq-fe.h"







int main() {
  std::cout << " a " << std::endl;
/*
  const char conninfo[] =
      "postgresql://postgres@localhost?port=5432&dbname=postgres";
  PGconn *conn = PQconnectdb(conninfo);
  if (PQstatus(conn) != CONNECTION_OK) {
    std::cout << "Connection to database failed: " << PQerrorMessage(conn)
              << std::endl;
    PQfinish(conn);
    return 1;
  } else {
    std::cout << "Connection to database succeed." << std::endl;
  }



  PGresult *res = NULL;



  res = PQexec(conn, "select * from e;");
  if (PQresultStatus(res) != PGRES_TUPLES_OK) {
    std::cout << "Select failed: " << PQresultErrorMessage(res) << std::endl;
  } else {
    std::cout << "Get " << PQntuples(res) << "tuples, each tuple has "
              << PQnfields(res) << "fields" << std::endl;
    // print column name
    for (int i = 0; i < PQnfields(res); i++) {
      std::cout << PQfname(res, i) << "              ";
    }
    std::cout << std::endl;
    // print column values
    for (int i = 0; i < PQntuples(res); i++) {
      for (int j = 0; j < PQnfields(res); j++) {
        std::cout << PQgetvalue(res, i, j) << "   ";
      }
      std::cout << std::endl;
    }
  }
  PQclear(res);




  PQfinish(conn);
  */
  return 0;
}