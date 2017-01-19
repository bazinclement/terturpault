#include "TimeScheme.h"
#include <iostream>

using namespace Eigen;
using namespace std;

// Constructeur avec le systeme d'edo a resoudre
TimeScheme::TimeScheme(OdeSystem& sys) : _sys(sys)
{}

// Destructeur (car on a des fonctions virtuelles)
TimeScheme::~TimeScheme()
{}

// Initialisation de vos différentes variables
void TimeScheme::Initialize(double a, double G, double t0, double dx, double dy, double dt, Matrix<VectorXd, Dynamic, Dynamic>& sol0)
{
  _a = a; _G = G;
  _dt = dt; _dx = dx; _dy = dy;
  _t = t0;
  _sol = _sol0;
}

// Renvoie _sol (pratique pour vérifier la résolution)
const Matrix<VectorXd, Dynamic, Dynamic> & TimeScheme::GetIterateSolution() const
{
  return _sol;
}

void operator*=(Matrix<VectorXd, Eigen::Dynamic, Eigen::Dynamic> A)
{
  int dt;
 int tailleligne=A.rows;
 int taillecollone=A.cols;
 for (int i=0;i<tailleligne;i++)
 for (int j=0;j<taillecollone;j++)
 {
   A(i,j)=dt*A(i,j);
 }
}
// Euler Explicite
void EulerScheme::Advance()
{

  _t += _dt;
  _sys.BuildF(_a,_G,_t,_dx,_dy,_dt,_sol);
  _sol *=_sys.GetF();
}
