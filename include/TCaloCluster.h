#ifndef __TCaloCluster__
#define __TCaloCluster__

#include "TCaloBase.h"
#include "TCaloBlock.h"

class TCaloCluster : public TCaloBase
{
 private:
  int fClusSize;      // number of blocks in the cluster
  double fEnergy;     // cluster energy
  double fX;          // cluster x position
  double fY;          // cluster y position  
  std::vector<TCaloBlock*> m_Blocks;
  
 public:
  TCaloCluster();
  ~TCaloCluster();

  void AddBlock(TCaloBlock* block){ m_Blocks.push_back(block); } // FIXME: should check duplicate
  std::vector<TCaloBlock*> GetBlocks() { return m_Blocks; }

  double GetEnergy() { return fEnergy; }
  void SetEnergy(double energy) { fEnergy = energy; }
  int GetClusSize() { return fClusSize; }
  void SetClusSize(int size) { fClusSize = size; }
  void DoSomething();

  double GetX() { return fX; }
  double GetY() { return fY; }  
  double GetE() { return fEnergy; }  

  ClassDef(TCaloCluster,1)

};

#endif /* TCaloCluster_h */
