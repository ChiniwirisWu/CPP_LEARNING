#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H
#include "dataPaths.h"
#include <iostream>
#include <fstream> // this is to create a conection to read files.

class DataController{
private:
  std::fstream m_connection;

  void startConnection(const std::string& filename){

    m_connection.open(filename, std::ios::in);

    if(!m_connection.is_open()){
      std::cerr << "Error opening the file: " << filename;
    } else {
      std::cout << "Connection successfull. \n";
    }
  }

  //void closeConnection(std::string& filename){
    //m_connection.close();
    //if(m_connection.is_open()){
      //std::cerr << "There was an error closing the connection. \n"; 
    //} else {
      //std::cout << "The connection was closed successfully. \n";
    //}
  //}

public: 

  void getUsername() {
    startConnection(DataPaths::username);
  }
};

#endif
