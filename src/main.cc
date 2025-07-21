#include <string>
#include <iostream>
#include "lib/httplib.h"
#include "header/server.hh"

int main(void) {
   using namespace httplib;

   Server server;

   ServerPort svr = {
      "0.0.0.0",
      8000
   }

   server.Get("/", [](const Request &, Response &res) {
      std::cout << "Index Page Load" << std::endl;
      res.set_content("<h1>Index</h1>", "text/html");
   });

   std::cout << "Server started at " << svr.host << ':' << svr.port << std::endl;
   server.listen(svr.host, svr.port);
   return 0;
}