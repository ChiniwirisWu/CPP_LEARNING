#include "dataPaths.h"
#include <iostream>
#include <fstream> // this is to create a conection to read files.

int main(){

  std::fstream m_connection;

  m_connection.open(DataPaths::username);

  if(!m_connection.is_open()){
    std::cerr << "There was an error accessing to the file. \n";
  } else {
    std::cout << "Connection successfull. \n";
  }
}
