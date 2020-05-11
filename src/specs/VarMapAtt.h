#ifndef VAR_MAP_ATTACKS
#define VAR_MAP_ATTACKS

#include <vector>
#include <map>
#include <iterator>
#include <string>
#include <cassert>
#include <iostream>
#include "VarMapP.h"

using namespace std;

/**
 * \class VarMapAtt
 * \brief Mapping between the names of the arguments in the input file and the Boolean variables in the solver
 */
class VarMapAtt {

 public:
  /**
   * \fn VarMap
   * \brief Constructor
   */
  VarMapAtt(VarMapP vm);

  /**
   * \fn addEntry
   * \brief Adds a new variables in the map
   * \param name : the name of the new variable
   */
  void addEntry(string a, string b);

  /**
   * \fn getName
   * \brief Gives the name of a Boolean variable
   * \param var : the Boolean variable
   * \return the name corresponding to var
   */
  string getName(int var);

  /**
   * \fn getVar
   * \brief Gives the Boolean variable associated to a name
   * \param name : the name of the variable
   * \return the Boolean variable associated to name
   */
  int getVar(string a, string b);
	

  /**
   * \fn contains
   * \brief Checks if the map contains a variables corresponding to a name
   * \param name : the name to be checked
   * \return true iff name corresponds to a variable
   */
  bool contains(string name);

  /**
   * \fn intVars
   * \brief To iterate over the integer variables corresponding to the string variables
   * \return a vector containing the integer variables
   */
  vector<vector<int> > getAttacks();

  /**
   * \fn nVars
   * \brief Returns the number of variables the map contains
   * \return an integer indicating the number of variables the map contains
   */
  long nVars();

	VarMapP getVm();
  
  
 private:
  map<int, string> varToName; /**< Mapping from Boolean variables to their names */
  map<string, int > nameToVar; /**< Mapping from the names to the Boolean variables */
	vector<vector<int> > attacks;/**<Saving of the attacks*/
  int nvars; /**< The number of variables */
	VarMapP vm;
  
};




#endif
