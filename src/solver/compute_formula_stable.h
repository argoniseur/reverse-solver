#ifndef COMPUTE_FORMULA_H
#define COMPUTE_FORMULA_H

#include "VarMapP.h"
#include "VarMapAtt.h"
#include "VarMapDet.h"
#include "Accepted.h"
#include "Defeated.h"
#include "Attacks.h"
#include "MaxSATSolver.h"
#include <iostream>
#include <vector>

 void Compute_formula_stable(VarMapP vm, VarMapAtt am, VarMapP cm, VarMapDet dm );

#endif