// computing of the formula

//we define det(a,b) only if we have acc(a)&&(att(a,b))
// it means that a has defeated b 
//lets presume that we've defined it

//classes à definir (parser)

#include "compute_formula_stable.h"

using namespace std;


 vector<vector<int> > Compute_formula_stable(VarMapP vm, VarMapAtt am, VarMapDet dm){

	vector<int>* args = vm.intVars();
	int n_args = args->size();
	vector<vector<int> > attacks = am.getAttacks();
	vector<vector<int> > dets = dm.getDets();
	vector<vector<int> > phi_sigma;

//1rst part of the formula (conflict freeset)
//for each a,b in args not att(a,b) or not acc(a) or not acc(b)

	for (int a=1;a<n_args+1;a++){
		for(int b=1;b<n_args+1;b++){
			vector<int> lits;
			lits.push_back(-attacks[a-1][b-1]);
			lits.push_back(-a);
			lits.push_back(-b);
			phi_sigma.push_back(lits);
			lits.clear();
		}
	}
	

//2nd part of the formula
	for (int a=1;a<n_args+1;a++){
		vector<int> lits;
		lits.push_back(a);
		for(int b=1;b<n_args+1;b++){
			lits.push_back(dets[b-1][a-1]);
		}
		phi_sigma.push_back(lits);
		lits.clear();
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
			//adding of the close to the phi_sigma formula
			phi_sigma.push_back(clause1);
			phi_sigma.push_back(clause2);
			phi_sigma.push_back(clause3);
			//clear les clauses et recommencer 
			clause1.clear();
			clause3.clear();
			clause2.clear();
			clause1.push_back(a);
			clause3.push_back(-a);
			
		}
	}
			
			


return phi_sigma;
}

