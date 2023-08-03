#ifndef __TCaloBase__
#define __TCaloBase__

#include <iostream>

#include "TCaloGeometry.h"
#include "TCaloCalibration.h"

class TCaloBase : public TObject
{
 protected:
  TCaloGeometry fGeometry;
  TCaloCalibration fCalibration;
  int fInitGeometry;

 public:
  TCaloBase();                   // Constructor
  virtual ~TCaloBase();
  
  TCaloGeometry* GetGeometry(void) { return &fGeometry; }
  TCaloCalibration* GetCalibration(void) { return &fCalibration; }
  
  ClassDef(TCaloBase,1)

};

#endif /* TCaloBase_H */
