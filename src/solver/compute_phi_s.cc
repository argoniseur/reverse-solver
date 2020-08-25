#include "compute_phi_s.h"


//rappel de la formule:
// phi_s = disjonction des phi_ei
// chaque phi_ei = inter : acc(a) (pour a appartient a Ei) inter inter -acc(a) pour a n'appartenant pas a Ei

vector<vector<int> > phi_S(VarMapP arguments){

vector<vector<int> > extensions = arguments.getExtensions();
vector<vector<int> > result;
vector<int> args = arguments.getArgs();
int n_args = args.size();
int n_extensions = extensions.size();

	for ( int i=0;i<n_extensions;i++){
		vector<int> ei;
		vector<int> ext = extensions[i];
		int ext_size = ext.size();
		
		for (int j=0;j<ext_size;j++){
			ei.push_back(extensions[i][j]);
		}
		for (int k=1;k < n_args+1;k++){
			if ((find(ei.begin()-1, ei.end(), k) == ei.end())) {
				ei.push_back(-k);
			} 
		}
		//affichage de ei
		/*cout<<"e"<<i<<":";
		for (unsigned int l = 0;l<ei.size();l++){
			cout<<" "<<ei[l];
		}*/
	result.push_back(ei);
	}

return result;

}


/*
function: compute the tseytin transformation (transform a dnf into a cnf)
params: vector<vector<int> dnf : the dnf to transform
return: vecor<vector<int>> cnf: the cnf corresponding
*/
vector<vector<int> > transformationTseytin(int ti, vector<vector<int> > dnf){

//let remain that a dnf is a disjunction of cubes
//with a cube: a conjunction of literals

//idea of the transformation : for each cube create a new variable(int) tî
//end of the formula : (-l1 -l2... tî) inter (-tî l1) inter ... inter (-tî lk) inter (ti1 ... tik)

vector<vector<int> > cnf;

	vector<int> clauseti;
	for (unsigned int i=0;i<dnf.size();i++){
		vector<int> cube = dnf[i];
		vector<int> clause;

		clause.push_back(ti);
		clauseti.push_back(ti);
		for (unsigned int k=0;k<cube.size();k++){
			clause.push_back(-cube[k]);
			vector<int> cl;
			cl.push_back(-ti);
			cl.push_back(cube[k]);
			cnf.push_back(cl);
		}
		cnf.push_back(clause);
		clause.clear();
		++ti;
	}
	cnf.push_back(clauseti);

return cnf;

}


vector<vector<int> > phi_sigma_S(VarMapP arguments, VarMapAtt attacks, VarMapDet dets){


vector<vector<int> > phi_sigma_S;
//getting of the formulas
vector<vector<int> > phi_sigma = Compute_formula_stable(arguments, attacks, dets);
vector<vector<int> > phi_s = phi_S(arguments);

//creating of new variables (int) such that xs <-> phi_S and xsigma <-> phi_sigma and xs<->xsigma

// arguments : 1 -> n
//attcks : n+1-> n2+n
//dets : n2+n+1->2n2+n
//on defini xs = 2*n2 + n + 1 et xsigma 2*n2 + n + 3 dans le soucis de ne pas utiliser quelquechose de deja pris

int n_args = arguments.nVars();
int xs = (2*n_args*n_args + n_args + 1);
int xsigma = xs + 1;


//equivalence des variables

vector<int> cl1;
cl1.push_back(-xs);
cl1.push_back(xsigma);
vector<int> cl2;
cl2.push_back(xs);
cl2.push_back(-xsigma);

phi_sigma_S.push_back(cl1);
phi_sigma_S.push_back(cl2);


// equivalence entre xsigma et phi_sigma

//partie -xsigma ou phi_sigma 
//injecter -xsigma dans chaque clause de phi_sigma

	for (unsigned int i=0;i<phi_sigma.size();i++){
		vector<int> clause = phi_sigma[i];
		clause.push_back(-xsigma);
		phi_sigma_S.push_back(clause);
	}

//partie xsigma ou -phi_sigma
//calcul de -phi_sigma

vector<vector<int> > part2;
	for(unsigned int i=0; i<phi_sigma.size();i++){
		vector<int> cube = phi_sigma[i];
		for (unsigned int j=0;j<cube.size();j++){
			cube[j] = -cube[j];
		}
		part2.push_back(cube);
	}
	part2.push_back({xsigma});

//la DNF xsigma ou -phi_sigma est créé
//transforming this dnf into a cnf
//int ti1 = (2*n_args*n_args + n_args +4);
int ti1 = (xsigma + 1);
vector<vector<int> > cnfPart2 = transformationTseytin(ti1, part2);
//incorporate to the phi_sigma_S
for(unsigned int i=0;i<cnfPart2.size();i++){
	phi_sigma_S.push_back(cnfPart2[i]);
}


//equivalence entre phi_S et xs

//partie -xs ou phi_S (DNF)
vector<vector<int> > part3 = phi_s;
part3.push_back({-xs});
int ti2 = (ti1 + part2.size());
vector<vector<int> > cnfPart3 = transformationTseytin(ti2, part3);
for(unsigned int i=0;i<cnfPart3.size();i++){
	phi_sigma_S.push_back(cnfPart3[i]);
}

//partie xs ou -phi_s
//calcul de -phi_s et injection de xs a chaque clause

	for (unsigned int i=0;i<phi_s.size();i++){
		vector<int> clause = phi_s[i];
		for (unsigned int j=0;j<clause.size();j++){
		clause[j] = -clause[j];
		}
		clause.push_back(xs);
		phi_sigma_S.push_back(clause);
	}



return phi_sigma_S;
}




















