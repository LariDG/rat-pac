/**
 * @class DS::MCPhoton
 * Data Structure: Photoelectron generated at PMT.
 *
 * @author Stan Seibert <sseibert@hep.upenn.edu>
 *
 * This class represents a single photoelectron generated at the
 * photocathode of the PMT.  The time jitter and delay in transit to the
 * anode are not included here, but the distribution of charge is,
 * which is slightly incongruous.
 *
 * Note that we require that the photon generates a photoelectron.
 * Absorbed photons are not included here.
 */

#ifndef __RAT_DS_MCPhoton__
#define __RAT_DS_MCPhoton__

#include <TObject.h>
#include <TVector3.h>

namespace RAT {
  namespace DS {

class MCPhoton : public TObject {
public:
  MCPhoton() : TObject(), isDarkHit(false) {}
  virtual ~MCPhoton() {}

  /** Time of photon hit at photocathode relative to event start time (ns). */
  virtual Double_t GetHitTime() const { return hitTime; }
  virtual void SetHitTime(Double_t _hitTime) { hitTime = _hitTime; }

  /** Time of pulse arriving at front-end electronics. */
  virtual Double_t GetFrontEndTime() const { return frontEndTime; }
  virtual void SetFrontEndTime(Double_t _frontEndTime) {
    frontEndTime = _frontEndTime;
  }
  
  /** Location of photon hit in local PMT coordinates (mm). */
  virtual TVector3 GetPosition() const { return pos; }
  virtual void SetPosition(const TVector3 &_pos) { pos = _pos; }

  /** Wavelength of photon (mm). */
  virtual Float_t GetLambda() const { return lambda; }
  virtual void SetLambda(Float_t _lambda) { lambda = _lambda; }

  /** Momentum of photon (MeV/c). */
  virtual TVector3 GetMomentum() const { return mom; }
  virtual void SetMomentum(const TVector3 &_mom) { mom = _mom; }

  /** Polarization vector. */
  virtual TVector3 GetPolarization() const { return pol; }
  virtual void SetPolarization(const TVector3 &_pol) { pol = _pol; }

  /** Charge created by photon in photoelectron (pe) units.
   *
   *  One pe is defined to be the peak of the single photoelectron
   *  charge distribution for this PMT.
   */
  virtual Float_t GetCharge() const { return charge; }
  virtual void SetCharge(Float_t _charge) { charge = _charge; }

  /** Is this photoelectron due to a dark hit? */
  virtual void SetDarkHit(Bool_t _isDarkHit){ isDarkHit = _isDarkHit;}
  virtual Bool_t IsDarkHit() const { return isDarkHit; }

  /** Track ID of photon which generated this photoelectron */
  virtual void SetTrackID(Int_t _trackID){ trackID = _trackID;}
  virtual Int_t GetTrackID() const { return trackID; }

  /** Name of physics process acting at endpoint of the MCTrackStep
   * that created this photon hit. 
   */
  virtual std::string GetProcess() const { return process; }
  virtual void SetProcess(const std::string &_process) { process = _process; }

  ClassDef(MCPhoton, 2) 

protected:
  Double_t hitTime;
  Double_t frontEndTime;
  Double_t lambda;
  TVector3 pos;
  TVector3 mom;
  TVector3 pol;

  Float_t charge;
  Bool_t isDarkHit;
  Int_t trackID;
  std::string process;
};

  } // namespace DS
} // namespace RAT

#endif

