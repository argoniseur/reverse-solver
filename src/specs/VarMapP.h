#ifndef VAR_MAP_PROJECT
#define VAR_MAP_PROJECT

#include <vector>
#include <map>
#include <iterator>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

/**
 * \class VarMapP
 * \brief Mapping between the names of the arguments in the input file and the Boolean variables in the solver
 */
class VarMapP {

 public:
  /**
   * \fn VarMap
   * \brief Constructor
   */
  VarMapP();

  /**
   * \fn addEntry
   * \brief Adds a new variables in the map
   * \param name : the name of the new variable
   */
  void addEntry(string name);

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
  int getVar(string name);

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
  vector<int>* intVars();

  /**
   * \fn nVars
   * \brief Returns the number of variables the map contains
   * \return an integer indicating the number of variables the map contains
   */
  long nVars();

  void addExtension(vector<int> x);

	vector<vector<int> > getExtensions();
  
  vector<int> getArgs();

  void setArgs(vector<int> a);
  
 private:
  map<int, string> varToName; /**< Mapping from Boolean variables to their names */
  map<string, int> nameToVar; /**< Mapping from the names to the Boolean variables */
  int nvars; /**< The number of variables */
	vector<vector<int> > extensions;
  vector<int> args;
};

// prevoir aussi def et det et att dans la map
#endif
