#include "TWaveform.h"

//________________________________________________________
TWaveform::TWaveform()
{
  fNPulse = 0;

}

//________________________________________________________
TWaveform::~TWaveform()
{

}

//________________________________________________________
double TWaveform::GetAmplitude(unsigned from, unsigned to)
{

  // FIXME: define baseline
  double baseline = 0.0;
  double amp = 0;

  for(unsigned ismp=0; ismp<m_Data.size(); ismp++)
    {
      if( ismp < from || ismp > to ) continue;
      amp += m_Data[ismp] - baseline;
    }      

  return amp;
}

//________________________________________________________
double TWaveform::GetChi2(int iPulse)
{
  //By default, return the first pulse value
  if(iPulse < (int)m_Chi2.size())
    return m_Chi2[iPulse];
  else
    return NOCHI2SAVED;
}

//________________________________________________________
double TWaveform::GetPeakTime(int iPulse)
{
  //By default, return the first pulse value
  if( iPulse < fNPulse )
    return m_PeakTime[iPulse];
  else
    return NOCHI2SAVED;
}

//________________________________________________________
int TWaveform::PulseFinder()
{

  return fNPulse;
}

