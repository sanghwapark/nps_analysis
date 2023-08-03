#ifndef __TCaloGeometry__
#define __TCaloGeometry__

#include <vector>
#include <map>
#include <TObject.h>

class TCaloGeometry : public TObject
{
 protected:
  int fNBlocks;                     // number of blocks
  int fNrow;                        // number of rows
  int fNcol;                        // number of columns 
  std::vector<int> m_BlockID;       // block IDs
  std::vector<double> m_BlockXPos;  // block X Position
  std::vector<double> m_BlockYPos;  // block Y Position
  std::map<int, int> m_Neighbors;   // neighbor block ids, up to 8

 public:
  TCaloGeometry();
  virtual ~TCaloGeometry() {};
  
  int GetNBlocks() { return fNBlocks; }
  int GetNrow() { return fNrow; }
  int GetNcol() { return fNcol; }

  double GetBlockXPos(int id) { return m_BlockXPos[id]; }
  double GetBlockYPos(int id) { return m_BlockXPos[id]; }
  void GetGeometry();
  
  //std::vector<int> GetNeighborBlocks(int id)

  ClassDef(TCaloGeometry,1);

};

#endif /* TCaloGeometry_h */
