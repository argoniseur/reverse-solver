#include "Attacks.h"

using namespace std;


Attacks::Attacks(VarMapP *vm) : varMap(*vm) {
  nbAttacks = 0;
  nMaxAttacks = 0;
}


void Attacks::addAttack(string from, string to) {
  int fromVar = varMap.getVar(from);
  int toVar = varMap.getVar(to);
  attacks[toVar].push_back(fromVar);
  ++nbAttacks;
  if (attacks[toVar].size() > nMaxAttacks) nMaxAttacks = attacks[toVar].size();
}

vector<int> *Attacks::getAttacksTo(int var) {
  return &attacks[var];
}

unsigned int Attacks::nAttacks() {
  return nbAttacks;
}

unsigned int Attacks::maxAttacks() {
  return nMaxAttacks;
}
