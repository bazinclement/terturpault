#include "OdeSystem.h"

using namespace Eigen;

// Constructeur par défaut
OdeSystem::OdeSystem()
{
}

// Destructeur par défaut
OdeSystem::~OdeSystem()
{
}


// Pour récupérer _f
const Matrix<VectorXd, Dynamic, Dynamic>  OdeSystem::GetF() const
{
  return _f;
}


/***********************
******AmontScheme*******
***********************/


void AmontScheme::BuildF(double a, double G, const double& t,double dx, double dy, double dt,
const Matrix<VectorXd, Eigen::Dynamic, Eigen::Dynamic> sol)
{
for(int i=0; i<sol.rows(); i++)
{
  for(int j=0; j<sol.cols(); j++)  // ux   >  0 et uy   >  0
  {
  _f(i,j) = sol(i,j)*(-dt*(1./dx+1./dy)*(a+2*G))  // F(U) = u*U  // G =cte
       +sol(i-1,j)*(dt/dx*(a+G))
       +sol(i,j-1)*(dt/dy*(a+G))
       +sol(i+1,j)*(dt/dx*G)
       +sol(i,j+1)*(dt/dy*G);
  }
}
}
