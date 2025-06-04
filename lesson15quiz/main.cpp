#include "monsterGenerator.h"



int main(){
  Monster m{ MonsterGenerator::generate() };
  m.print();
	return 0;
}
