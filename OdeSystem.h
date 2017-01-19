#include "Dense"
#include <fstream>

class OdeSystem
{
  protected:
    // vecteur f
    Eigen::Matrix<Eigen::VectorXd, Eigen::Dynamic, Eigen::Dynamic> _f;

  public:
    // Constructeur par défaut
    OdeSystem();

    // Destructeur par défaut
    virtual ~OdeSystem();

    // Pour récupérer _f
    const Eigen::Matrix<Eigen::VectorXd, Eigen::Dynamic, Eigen::Dynamic>  GetF() const;

    // Pour construire _f en fonction de votre système
    virtual void BuildF(double a, double G, const double& t,double dx, double dy, double dt,
    const Eigen::Matrix<Eigen::VectorXd, Eigen::Dynamic, Eigen::Dynamic> sol) = 0;
};

class AmontScheme : public OdeSystem
{
 public:
   virtual void BuildF(double a, double G, const double& t,double dx, double dy, double dt,
   const Eigen::Matrix<Eigen::VectorXd, Eigen::Dynamic, Eigen::Dynamic> sol);
};
