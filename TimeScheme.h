#include "OdeSystem.h"

class TimeScheme
{
 protected:

  // Temps en cours
  double _t, _a, _G,_dx,_dy, _dt, t0;

  // Vecteur initial et vecteur solution
  Eigen::Matrix<Eigen::VectorXd, Eigen::Dynamic, Eigen::Dynamic> _sol, _sol0;

  // Reference vers le systeme d'EDO
  OdeSystem& _sys;

 public:
  // Constructeur avec le systeme d'EDO
  TimeScheme(OdeSystem& sys);

  // Destructeur par défaut - Si la classe ne contient pas de destructeur par défaut
  // alors le compilateur en génère un implicitement.
  virtual ~TimeScheme();

  // Initialisation de vos différentes variables
  void Initialize(double a, double G, double t0, double dx, double dy, double dt, Eigen::Matrix<Eigen::VectorXd, Eigen::Dynamic, Eigen::Dynamic>& sol0);

  // Une étape du schéma en temps
  virtual void Advance() = 0;

  // Permet de récupérer _sol
  const Eigen::Matrix<Eigen::VectorXd, Eigen::Dynamic, Eigen::Dynamic> & GetIterateSolution() const;
};


class EulerScheme : public TimeScheme
{
 public:
 EulerScheme(OdeSystem& sys) : TimeScheme(sys) {}
void operator*=(Eigen::Matrix<Eigen::VectorXd, Eigen::Dynamic, Eigen::Dynamic> A);


  // Une étape du schéma en temps
  void Advance();
};
