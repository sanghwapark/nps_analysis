#include <iostream>
#include <fstream>
#include <string>

#include "TCaloGeometry.h"

using namespace std;

//_____________________________________________
TCaloGeometry::TCaloGeometry()
{
  fNBlocks = 0;
  fNRow = 0;
  fNCol = 0;

  fXStep = 0;
  fYStep = 0;
  fZStep = 0;

  fXFront = 0;
  fYFront = 0;
  fZFront = 0;

  fIsInitGeometry = 0;

  // Default geometry input file
  fCaloGeoFilename = "nps_geom.param";
}

//_____________________________________________
void TCaloGeometry::ReadGeometry()
{
  string line;
  ifstream ifstr(fCaloGeoFilename.c_str());
  if(ifstr.is_open())
    {
      while(getline(ifstr, line))
	{
	  // skip commented out lines
	  if(line.find(";") != string::npos)
	    continue;

	  // parse geo information
	  // FIXME: use try..catch to handle exception
	  if(line.find("nrows") != string::npos) {
	    fNRow = std::stoi(line.substr(line.find("=")+1));
	  } else if(line.find("ncolumns") != string::npos) {
	    fNCol = std::stoi(line.substr(line.find("=")+1));
	  } else if(line.find("front_x") != string::npos) {
	    fXFront = std::stoi(line.substr(line.find("=")+1));
	  } else if(line.find("front_y") != string::npos) {
	    fYFront = std::stoi(line.substr(line.find("=")+1));
	  } else if(line.find("front_z") != string::npos) {
	    fZFront = std::stoi(line.substr(line.find("=")+1));
	  } else if(line.find("xstep") != string::npos) {
	    fXStep = std::stoi(line.substr(line.find("=")+1));
	  } else if(line.find("ystep") != string::npos) {
	    fYStep = std::stoi(line.substr(line.find("=")+1));
	  } else if(line.find("zstep") != string::npos) {
	    fZStep = std::stoi(line.substr(line.find("=")+1));
	  } else {
	    continue;
	  }

	}// while readline
    }

  fNBlocks = fNRow * fNCol;

}

//_____________________________________________
void TCaloGeometry::InitGeometry()
{
  if(fNBlocks == 0)
    ReadGeometry();

  // numbering scheme: left to right, bottom to top
  for(int i=0; i<fNRow; i++)
    {
      for(int j=0; j<fNCol; j++)
	{
	  int blockid = j*30 + i;
	  m_BlockID.push_back(blockid);
	  double xpos = fXFront - (fNCol-1)*fXStep/2 + fXStep*j;
	  double ypos = fYFront - (fNRow-1)*fYStep/2 + fYStep*i;
	  double zpos = fZFront;

	  m_BlockXPos.push_back(xpos);
	  m_BlockYPos.push_back(ypos);

	}
    }

  // Find neighbors, loop over all blocks
  // FIXME: This is inefficient..
  /*
  for(auto& it : m_XY)
    {
      

    }

  for(int id = 0; id<fNBlocks; id++)
    {
      int m_iX = blockid%fNCol;
      int m_iY = blockid/fNCol;
      for(int ix=(m_iX > 0 ? m_iX-1 : 0); ix<=(m_iX == fNCol-1 ? fNCol-1 : m_iX+1); ix++)
	for(int iy=(m_iY > 0 ? m_iY-1 : 0); iy<=(m_iY == fNRow-1 ? fNRow-1 : m_iY+1); iy++)
	  {
	    m_XY.find(make_pair(ix, iy))
    
    }
  */

  fIsInitGeometry = 1;
}
