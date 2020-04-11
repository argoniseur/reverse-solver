// computing of the formula

//we define det(a,b) only if we have acc(a)&&(att(a,b))
// it means that a has defeated b 
//lets presume that we've defined it

//classes à definir (parser)

#include "compute_formula_stable.h"

using namespace std;
//idée de comment récupérer les differents vectors
//vector<vector<int>> attacks = AttMap::getAttacks();
//vector<vector<int>> dets = DetMap::getDets();
//vector<int> accs = AccMap::intVars();

//pour les args et les accs prendre la methode intVars de la classe VarMapP (mapping "normal" int-string)

 void Compute_formula_stable(VarMapP vm, VarMapAtt am, VarMapP cm, VarMapDet dm){

	vector<int>* args = vm.intVars();
	int n_args = args->size();
	vector<vector<int> > attacks = am.getAttacks();
	vector<int>* accs = cm.intVars();
	vector<vector<int> > dets = dm.getDets();

//nombre de variables (autant qu'il y a de att de acc et de det)
	int nb_variables = (attacks.size() + accs->size() + dets.size()) ;

//initialisation of the solver
	MaxSATSolver maxsat(nb_variables, 0);
  cout << " solver: " << maxsat.getSolverName () << " implementing version " << maxsat.getVersion() << endl;

//1rst part of the formula (conflict freeset)
// pour tout a,b dans args non att(a,b) ou non acc(a) ou non acc(b)

	for (int a=0;a<n_args;a++){
		for(int b=0;b<n_args;b++){
			vector<int> lits;
			lits.push_back(-attacks[a][b]);
			lits.push_back(-accs->at(a));
			lits.push_back(-accs->at(b));
		maxsat.addClause(lits);
		}
	}
	

//2nd part of the formula
	for (int a=0;a<n_args;a++){
	vector<int> lits;
	lits.push_back(a);
		for(int b=0;b<n_args;b++){
			lits.push_back(dets[a][b]);
		}
	maxsat.addClause(lits);
	}
	

//3rd part of the formula (phi_det)
//???


//integration of all the clauses

//solving
std::vector<int> model;
  uint64_t core = 0;
  MaxSATSolver::ReturnCode ret = maxsat.compute_maxsat(model, core);

	if(ret == MaxSATSolver::ReturnCode::SATISFIABLE)
		cout << "satisfiable" << endl;
  	else 
		if(ret == MaxSATSolver::ReturnCode::UNSATISFIABLE)
		cout << "unsatisfiable" << endl;
  	else 
		if(ret == MaxSATSolver::ReturnCode::UNKNOWN)
		cout << "unknown" << endl;
  	else 
		if(ret == MaxSATSolver::ReturnCode::OPTIMAL)
		cout << "optimal" << endl;
 	else
		cout << "unknown result" << endl;

  cout << "returned core of size " << model.size() << endl;

  assert (ret == MaxSATSolver::ReturnCode::OPTIMAL);
  assert (model.size() == 4 && "first for elements");
}

