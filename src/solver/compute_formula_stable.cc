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

 vector<vector<int> > Compute_formula_stable(VarMapP vm, VarMapAtt am, VarMapDet dm){

	vector<int>* args = vm.intVars();
	int n_args = args->size();
	vector<vector<int> > attacks = am.getAttacks();
	
	vector<vector<int> > dets = dm.getDets();

//nombre de variables (autant qu'il y a de att de acc et de det)
	//int nb_variables = (attacks.size() + accs->size() + dets.size()) ;

//initialisation of the solver
	//MaxSATSolver maxsat(nb_variables, 0);
  //cout << " solver: " << maxsat.getSolverName () << " implementing version " << maxsat.getVersion() << endl;

vector<vector<int> > phi_sigma;

//1rst part of the formula (conflict freeset)
// pour tout a,b dans args non att(a,b) ou non acc(a) ou non acc(b)

	for (int a=1;a<n_args+1;a++){
		for(int b=1;b<n_args+1;b++){
			vector<int> lits;
			lits.push_back(-attacks[a-1][b-1]);
			lits.push_back(-a);
			lits.push_back(-b);
			phi_sigma.push_back(lits);
		//maxsat.addClause(lits);
		}
	}
	

//2nd part of the formula
	for (int a=1;a<n_args+1;a++){
	vector<int> lits;
	lits.push_back(a);
		for(int b=1;b<n_args+1;b++){
			lits.push_back(dets[a-1][b-1]);
		}
	phi_sigma.push_back(lits);
	//maxsat.addClause(lits);
	}
	

//3rd part of the formula (phi_det)
//pour tout a pour tout b (les 3 clauses)
	for (int a=1;a<n_args+1;a++){
		vector<int> clause1, clause2, clause3;
		clause1.push_back(a);
		clause3.push_back(-a);
		for (int b =1; b<n_args+1;b++){
			clause1.push_back(-dets[a-1][b-1]);
			clause2.push_back(-dets[a-1][b-1]);
			clause2.push_back(attacks[a-1][b-1]);
			clause3.push_back(-attacks[a-1][b-1]);
			clause3.push_back(dets[a-1][b-1]);
			//adding of the close to the solver
			phi_sigma.push_back(clause1);
			phi_sigma.push_back(clause2);
			phi_sigma.push_back(clause3);
			
			//maxsat.addClause(clause1);
			//maxsat.addClause(clause2);
			//maxsat.addClause(clause3);
		}
	}
			
			

//solving
/*
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
 // assert (model.size() == 4 && "first for elements");*/
return phi_sigma;
}

