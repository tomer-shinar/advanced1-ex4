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
   while(string(buffer).find('\n') == string::npos || string(buffer).find('\n') > this->bytesRead) {
     //haven't received \n yet
    this->bytesRead += read(clientSocket, buffer + this->bytesRead, 1024 - bytesRead);
   }
   string line(buffer);
   strcpy(buffer, line.substr(line.find('\n')).c_str());
   this->bytesRead -= line.find('\n');
   return line.substr(0, line.find('\n') - 1);
}

void AbstractClientHandler::FinishReading() {
  /**
   * delete all data read after finished connection with client
   */
   this->bytesRead = 0;
}

