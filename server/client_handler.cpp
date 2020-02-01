//
// Created by tomer on 25/01/2020.
//

#include <unistd.h>
#include "client_handler.h"
#include <cstring>

string AbstractClientHandler::ReadFromClient(int clientSocket) {
  /**
   * read from one line from the client
   */
   while(string(buffer).substr(0, bytesRead).find('\n') == string::npos) {
     //haven't received \n yet
    this->bytesRead += read(clientSocket, buffer + this->bytesRead, 1024 - bytesRead);
   }
   string line = string(buffer).substr(0, bytesRead);
   strcpy(buffer, line.substr(line.find('\n') + 1).c_str());
   this->bytesRead -= line.find('\n') + 1;
   return line.substr(0, line.find('\n'));
}

void AbstractClientHandler::FinishReading() {
  /**
   * delete all data read after finished connection with client
   */
   this->bytesRead = 0;
}

