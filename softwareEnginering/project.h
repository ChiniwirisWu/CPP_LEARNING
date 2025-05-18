#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
#include "C-essentials/input.h"
class Project{
private:
  std::string m_title {}; 
  std::string m_description {};
  std::vector<std::string> m_functionalObjectives {};
  std::vector<std::string> m_technicalObjectives {};

public:
  Project() = default;

  void setTitle(){
    m_title = getInput<std::string>();
  }
  void setDescription(){
    m_description = getInput<std::string>();
  }
  void setFunctionalObjectives(){
    m_functionalObjectives.push_back(getInput<std::string>());
  }
  void setTechnicalObjectives(){
    m_technicalObjectives.push_back(getInput<std::string>());
  }

  std::string& getTitle () {
    return m_title;
  }

  std::string& getDescription () {
    return m_description;
  }

  std::vector<std::string>& getFunctionalObjectives(){
    return m_functionalObjectives;
  }

  std::vector<std::string>& getTechnicalObjectives(){
    return m_technicalObjectives;
  }
};

#endif
