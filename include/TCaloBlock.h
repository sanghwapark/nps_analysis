#ifndef __TCaloBlock__
#define __TCaloBlock__

#include "TCaloBase.h"

class TCaloBlock : public TCaloBase
{
 private:
  int fBlockID;
  double fBlockEnergy;     // energy deposit in the block
  double fBlockTime;       // block time
  double fX;               // block x-pos
  double fY;               // block y-pos
  double fZ;

 public:
  TCaloBlock();
  TCaloBlock(int blockid, double x, double y, double z);
  virtual ~TCaloBlock();
  //add copy
  
  void SetBlockEnergy(double benergy) { fBlockEnergy = benergy; }
  void SetBlockTime(double btime){ fBlockTime = btime; }
  void SetBlockID(int bid) { fBlockID = bid; }
  void SetBlockPos(double x, double y, double z) { fX = x; fY = y; fZ = z; }
  int GetBlockID() { return fBlockID; }
  double GetBlockEnergy() { return fBlockEnergy; }
  double GetBlockTime() { return fBlockTime; }
  double GetX() { return fX; }
  double GetY() { return fY; }
  double GetZ() { return fZ; }
  //TClonesArray GetPos() { return fPos; }

  ClassDef(TCaloBlock,1)

};

#endif // TCaloBlock_h
