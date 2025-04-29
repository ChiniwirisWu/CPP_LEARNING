#include <iostream>
#include <string>
#include <random>


void ignoreLine(){
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showMenu(){
  std::cout << "Daily Log application" << '\n';
  std::cout << "1) Insert new log" << '\n';
  std::cout << "2) Show logs" << '\n';
  std::cout << "3) Quit application" << '\n';
}

void askUserPage(const int min_limit, const int max_limit, int& pageOut){
  while(true){
    showMenu();
    std::cin >> pageOut;
    if(!std::cin){
      //limpio el cin despues de detectar un error.
      std::cout << "Insertar valores entre " << min_limit << " y " << max_limit << '\n';
      std::cin.clear();
      ignoreLine();
      continue;
    }
    // revisar que los datos insertados esten en el rango.
    if(pageOut < 0 || pageOut > 3){
      std::cout << "Insertar valores entre " << min_limit << " y " << max_limit << '\n';
      continue;
    }   
    return;
  }
}

void insertPage(std::string& logs,int& page){
  std::cout << "Insert new log: ";  
  std::string log = "";
  std::getline(std::cin >> std::ws, log);
  logs += "\n" + log;
  //goes back to menu.
  page = 0;
}

void showLogsPage(std::string_view logs, int& page){
  std::string skip;
  std::cout << "Daily logs: " << '\n';
  std::cout << logs << '\n';
  std::cin >> skip;
  //goes back to menu.
  page = 0;
}

int main(){
  // mostrar menu principal.
  // elegir entre insertar nueva input, mostrar lo que ya esta guardado, y salir. 
  //  modificare una variable que se encargue de guardar toda la input.
  //  usare esa misma variable para mostrar lo que esta guardado
  // insertar nueva input
  // mostar lo guardado
  // salir de la aplicacion
  constexpr int min_limit = 1;
  constexpr int max_limit = 3;
  std::string logs = "";
  bool static run = true; 
  int static page = 0; //page 0 means "menu".
  while(run){
    askUserPage(min_limit, max_limit, page);
    switch(page){
      case 0:
        //main menu
        continue;
      break;
      case 1:
        //insert new log 
        insertPage(logs, page);
      break;
      case 2:
        // show log
        showLogsPage(logs, page);
      break;
      case 3:
        //quit
        run = false;
      break;
      default:
        continue;
      break;
    }
  }
  std::cout << "See you later!" << std::endl;
}
