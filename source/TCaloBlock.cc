#include "TCaloBlock.h"

//__________________________________________
TCaloBlock::TCaloBlock()
{
  // Constructor
  fBlockID = -1;
  fBlockEnergy = -1;
  fBlockTime = -1;
  fX = -999;
  fY = -999;
  fZ = -999;
}

//__________________________________________
TCaloBlock::~TCaloBlock()
{
  // Destructor
}

//__________________________________________

ClassImp(TCaloBlock);
