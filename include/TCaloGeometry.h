#ifndef __TCaloGeometry__
#define __TCaloGeometry__

#include <string>
#include <vector>
#include <map>

#include <TObject.h>

class TCaloGeometry : public TObject
{
 protected:
  int fNBlocks;                     // number of blocks
  int fNRow;                        // number of rows
  int fNCol;                        // number of columns 
  std::vector<int> m_BlockID;       // block IDs
  std::vector<double> m_BlockXPos;  // block X Position
  std::vector<double> m_BlockYPos;  // block Y Position

  double fXStep;
  double fYStep;
  double fZStep;

  double fXFront;
  double fYFront;
  double fZFront;

  std::string fCaloGeoFilename;

  void ReadGeometry();

 public:
  TCaloGeometry();
  virtual ~TCaloGeometry() {};
  
  int fIsInitGeometry;

  int GetNBlocks() { return fNBlocks; }
  int GetNRow() { return fNRow; }
  int GetNCol() { return fNCol; }

  double GetBlockXPos(int id) { return m_BlockXPos[id]; }
  double GetBlockYPos(int id) { return m_BlockXPos[id]; }

  void InitGeometry();
  void AddGeoParamFile(std::string fin) { fCaloGeoFilename = fin; }

  void SetXYZStep(double xstep, double ystep, double zstep) { fXStep = xstep; fYStep = ystep; fZStep = zstep; }
  void SetXYZFront(double xfront, double yfront, double zfront) { fXFront = xfront; fYFront = yfront; fZFront = zfront; }
    
  //std::vector<int> GetNeighbors(int id){ return m_Neighbors[id]; }

  ClassDef(TCaloGeometry,1);

};

#endif /* TCaloGeometry_h */
