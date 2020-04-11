#ifndef VAR_MAP_DETS
#define VAR_MAP_DETS

#include <vector>
#include <map>
#include <iterator>
#include <string>
#include <cassert>
#include <iostream>
#include "VarMapP.h"

using namespace std;

/**
 * \class VarMapDet
 * \brief Mapping between the names of the arguments in the input file and the Boolean variables in the solver
 */
 class VarMapDet {

 public:
  /**
   * \fn VarMap
   * \brief Constructor
   */
  VarMapDet(VarMapP vm);

  /**
   * \fn addEntry
   * \brief Adds a new variables in the map
   * \param name : the name of the new variable
   */
  void addEntry(VarMapP vm, string a, string b);

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
  int getVar(VarMapP vm, string a, string b);
	

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
  vector<vector<int> > getDets();

  /**
   * \fn nVars
   * \brief Returns the number of variables the map contains
   * \return an integer indicating the number of variables the map contains
   */
  long nVars();
  
  
 private:
  map<int, string> varToName; /**< Mapping from Boolean variables to their names */
  map<string, int > nameToVar; /**< Mapping from the names to the Boolean variables */
	vector<vector<int> > dets;/**<Saving of attacks*/
  int nvars; /**< The number of variables */
  
};




#endif
