#ifndef __TCaloCalibration__
#define __TCaloCalibration__

// Skeleton of calibraiton class
class TCaloCalibration : public TObject
{
 private:
  int fInit;
  
 public:
  TCaloCalibration() {};
  ~TCaloCalibration() {};

  //void Print()
  int Init() { return fInit; }

  ClassDef(TCaloCalibration,1)

};

#endif /* TCaloCalibration_h */
