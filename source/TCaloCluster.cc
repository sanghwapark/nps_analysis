#include "TCaloCluster.h"

//___________________________________________
TCaloCluster::TCaloCluster()
{

  fClusSize = 0;
  fEnergy = 0;
  fX = -999;
  fY = -999;

}

//___________________________________________
TCaloCluster::~TCaloCluster()
{

}

//___________________________________________
void TCaloCluster::DoSomething()
{
  // do nothing now

}

ClassImp(TCaloCluster);
