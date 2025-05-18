#ifndef WRITER_H
#define WRITER_H
#include "project.h"
#include "currentTime.h"
#include <fstream>
#include <iostream>
#include <vector>


class Writer{
private:
  std::ofstream m_myFile { "summary.txt" }; // opens and creates a .txt file.
  
  void writeEntry(std::string_view title, std::string& content){
    //security check
    if(!m_myFile.is_open()){
      std::cerr << "It was unable to open the file." << std::endl;
      return;
    }
    //then run
    m_myFile << title << std::endl << content << std::endl; 
  }

  void writeMultipleEntries(std::string_view title, std::vector<std::string>& entries){
    //security check
    if(!m_myFile.is_open()){
      std::cerr << "It was unable to open the file." << std::endl;
      return;
    } 
    //then run
    for(int i = 0; i < entries.size(); i++){
      m_myFile << (i + 1) << ") " << entries[i] << std::endl;      
    }
  }
public:
  void writeTitle(Project& project){
    writeEntry("Title", project.getTitle());
  }

  void writeDescription(Project& project){
    writeEntry("Description", project.getDescription());
  }

  void writeFunctionalObjectives(Project& project){
    writeMultipleEntries("Functional Objectives", project.getFunctionalObjectives());
  }

  void writeTechnicalObjectives(Project& project){
    writeMultipleEntries("Technical Objectives", project.getTechnicalObjectives());
  }

  void writeCurrentTime(){
    //security check
    if(!m_myFile.is_open()){
      std::cerr << "It was unable to open the file." << std::endl;
      return;
    }
    //then run
    m_myFile << "Created date" << std::endl << CurrentTime::getCurrentTime() << std::endl;
  }

  void closeFile(){
    m_myFile.close();
  }
};

#endif
