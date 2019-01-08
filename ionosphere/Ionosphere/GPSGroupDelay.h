#ifndef IONOSPHERE_GPSGROUPDELAY_H
#define IONOSPHERE_GPSGROUPDELAY_H

#include <casacore/casa/stdio.h>
#include <casacore/casa/Arrays/Matrix.h>
#include <casacore/casa/Arrays/Vector.h>
#include <casacore/casa/Quanta/MVPosition.h>
#include <casacore/casa/Quanta/MVDirection.h>
    
#include <ionosphere/Ionosphere/GPS.h>
    
namespace casacore { //# NAMESPACE CASACORE - BEGIN

// <summary>
// Holds GPS group delays. Deprecated, use GPSDCB instead.
// </summary>

class GPSGroupDelay
{
protected:
// begin and end epochs
  Double mjd1_,mjd2_;
// vector of SVN-valid flags
  Vector<Bool> svn_valid;
// vector of group delays  
  Vector<Double> tgd_;

public:
// constructor. Loads TGD file    
  GPSGroupDelay( const char *filename );  

// Loads TGD file
  Int import (const char *filename);

// do we have a group delay for this SVN?
  Bool svnValid ( uInt svn ) const      { return svn<=svn_valid.nelements() && svn_valid(svn); }
  const Vector<Bool> & svnValid () const { return svn_valid; }

// data accessors  
  Double tgd    ( uInt svn ) const     { return tgd_(svn); }
  const Vector<Double> & tgd () const   { return tgd_; }
  
  Double ep_begin () const            { return mjd1_; }
  Double ep_end   () const            { return mjd2_; }

//  static Int debug_level;
};


} //# NAMESPACE CASACORE - END

#endif
