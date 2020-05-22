#ifndef COMPUTE_PHI_S
#define COMPUTE_PHI_S

#include "VarMapP.h"
#include "compute_formula_stable.h"
#include <iostream>
#include <vector>

vector<vector<int> > phi_S(VarMapP arguments);

vector<vector<int> > transformationTseytin(vector<vector<int> > dnf);

vector<vector<int> > phi_sigma_S(VarMapP arguments, VarMapAtt attacks, VarMapDet dets);

#endif
