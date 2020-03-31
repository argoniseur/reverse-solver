#include "IParser.h"
#include "ParserFactory.h"

using namespace std;

int main(int argc, char** argv){

  cout << "Ces fdp de marseillais de con" << endl;

  cout << "run unsat test ..." << endl;
  vector<int> lits;
  MaxSATSolver maxsat(3, 0);
  lits = {1, 2};
  maxsat.addClause(lits);
  lits = {1, -2};
  maxsat.addClause(lits);
  lits = {-1, -2};
  maxsat.addClause(lits);
  lits = {-1, 2};
  maxsat.addClause(lits);

  std::vector<int> model;
  uint64_t cost = 0;
  MaxSATSolver::ReturnCode ret = maxsat.compute_maxsat(model, cost);

  if(ret == MaxSATSolver::ReturnCode::SATISFIABLE)
	cout << "satisfiable" << endl;
  else if(ret == MaxSATSolver::ReturnCode::UNSATISFIABLE)
	cout << "unsatisfiable" << endl;
  else if(ret == MaxSATSolver::ReturnCode::UNKNOWN)
	cout << "unknown" << endl;
}
