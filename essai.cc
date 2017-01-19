
#include <string>
#include <iostream>
#include <fstream>


using namespace std;
using namespace Eigen;


int main()
{


void classe::operator*(double dt, Matrix<VectorXd, Eigen::Dynamic, Eigen::Dynamic> A)
{Matrix<VectorXd, Eigen::Dynamic, Eigen::Dynamic> B;
  int tailleligne=A.rows;
  int taillecollone=A.cols;
  for (int i=0;i<tailleligne;i++)
  for (int j=0;j<taillecols;j++)
  {
    B(i,j,0)=dt*A(i,j,0);
    B(i,j,1)=dt*A(i,j,1)
  }

}

template<class T>
inline std::ostream& operator<<(std::ostream& out, std::vector<T>& v)
{
  for (int i = 0; i < v.size(); i++)
    out << v[i] << '\n';

  return out;
}
}
