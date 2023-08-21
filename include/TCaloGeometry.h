#ifndef __TCaloGeometry__
#define __TCaloGeometry__

#include <string>
#include <vector>
#include <map>

#include <TObject.h>

#include "TCaloBlock.h"

class 

class TCaloGeometry : public TObject
{
 protected:
  int fNBlocks;                     // number of blocks
  int fNRow;                        // number of rows
  int fNCol;                        // number of columns 
  std::vector<int> m_BlockID;       // block IDs
  std::vector<double> m_BlockXPos;  // block X Position
  std::vector<double> m_BlockYPos;  // block Y Position
  std::map<int, vector<int>> m_Neighbors;   // neighbor block ids, up to 8

  double fXStep;
  double fYStep;
  double fZStep;

  double fXFront;
  double fYFront;
  double fZFront;

  std::string fCaloGeoFilename;

 public:
  TCaloGeometry();
  virtual ~TCaloGeometry() {};
  
  int GetNBlocks() { return fNBlocks; }
  int GetNRow() { return fNRow; }
  int GetNCol() { return fNCol; }

  double GetBlockXPos(int id) { return m_BlockXPos[id]; }
  double GetBlockYPos(int id) { return m_BlockXPos[id]; }

  void GetGeometry();
  void InitGeometry();
  void AddGeoParamFile(std::string fin) { fCaloGeoFilename = fin; }

  void SetXYZStep(double xstep, double ystep, double zstep) { fXStep = xstep; fYStep = ystep; fZStep = zstep; }
  void SetXYZFront(double xfront, double yfront, double zfront) { fXFront = xfront; fYFront = yfront; fZFront = zfront; }
    
  std::vector<int> GetNeighbors(int id){ return m_Neighbors[id]; }

  std::vector<TCaloBlock*> m_CaloBlocks;

  ClassDef(TCaloGeometry,1);

};

#endif /* TCaloGeometry_h */
