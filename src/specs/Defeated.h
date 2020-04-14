/**
 * \file Defeated.h
 * \brief The defeated relation of the argumentation framework
 * \author Salomé Attar 
 * \version 0.1
 * \date 3/4/2019
 */

#ifndef __DEFEATED_H__
#define __DEFEATED_H__

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "VarMapP.h"

using namespace std;

/**
 * \class Defeated
 * \brief The defeated relation of the argumentation framework
 */
class Defeated {
  
 public:
  /**
   * \fn Defeated
   * \brief Constructor
   * \param vm : the variables concerned by the attack relation
   */
  Defeated(VarMapP *vm);

  /**
   * \fn addDefeated
   * \brief Adds a defeated argument in the formula
   * \param from : the name of the accepted argument
   * \param to : the name of the attacked (defeated) argument
   */
  void addDefeated(string from, string to);

  /**
   * \fn getDefeatedBy
   * \brief Gets the list of variables corresponding to the defeated by the parameter
   * \param var : the variable
   * \return the defeated arguments by the var
   */
  vector<int> *getDefeatedBy(int var);

  /**
   * \fn nDefeats
   * \brief return the number of attacks the problem contains
   * \return the number of attacks
   */
  unsigned int nDefeats();

  

 protected :
  /** The variables on which is built the defeated relation */
  VarMapP& varMap;

  /** The mapping from the arguments to their defeats */
  map<int,vector<int> > defeats;

 private:
  unsigned int nbDefeats;

  
};

#endif