#ifndef __TWaveform__
#define __TWaveform__

#include <vector>

#define NOCHI2SAVED (-1)

class TWaveform
{
 private:
  std::vector<double> m_Data;         // samples

  // Pulse information
  int fNPulse;                        // number of pulses
  std::vector<double> m_Chi2;         // chi2 values for pulse 0, 1, 2 ..
  std::vector<double> m_Amp;          // peak amplitude for pulse 0, 1, 2, ..
  std::vector<double> m_PeakTime;     // peak time for pulses

 public:
  TWaveform();
  ~TWaveform();
  
  // FIXME: define AddWave
  void AddWave();

  int GetNPluse() { return fNPulse; }

  double GetChi2(int iPulse);
  double GetPeakTime(int iPulse);
  double GetAmplitude(int iPulse);
  double GetAmplitude(void) { return m_Amp[0]; }
  double GetAmplitude(unsigned from, unsigned to);

 private:
  int PulseFinder();
  
};

#endif /* TWaveform_h */
