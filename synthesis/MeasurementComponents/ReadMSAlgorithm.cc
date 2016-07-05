#include <casa/BasicSL/String.h>
#include <casa/Arrays/Array.h>
#include <casa/Arrays/ArrayMath.h>
#include <casa/Arrays/Array.h>
#include <lattices/Lattices/ArrayLattice.h>
#include <lattices/Lattices/PagedArray.h>
#if defined(casacore)
#include <lattices/LEL/LatticeExpr.h>
#include <lattices/LEL/LatticeExprNode.h>
#else
#include <lattices/Lattices/LatticeExpr.h>
#include <lattices/Lattices/LatticeExprNode.h>
#endif
#include <casa/OS/File.h>
#include <casa/Exceptions/Error.h>
#include <casa/BasicSL/String.h>
#include <casa/Utilities/Assert.h>
#include <msvis/MSVis/VisSet.h>
#include <msvis/MSVis/VisSetUtil.h>
#include <msvis/MSVis/VisibilityIterator.h>
#include <msvis/MSVis/VisBuffer.h>
#include <casa/sstream.h>
#include <casa/Logging/LogMessage.h>
#include <casa/Logging/LogIO.h>
#include <casa/Logging/LogSink.h>
#include <ms/MeasurementSets/MeasurementSet.h>
#include <ms/MeasurementSets/MSColumns.h>
#include <synthesis/MeasurementComponents/ReadMSAlgorithm.h>
#include <casa/OS/Time.h>

namespace casa { //# NAMESPACE CASA - BEGIN

ReadMSAlgorithm::ReadMSAlgorithm() : msid(0), myName("Test Parallel Read")
{
  
};
ReadMSAlgorithm::~ReadMSAlgorithm(){

};

void ReadMSAlgorithm::get(){

applicator.get(msName);

};

void ReadMSAlgorithm::put(){

applicator.put(status);

};

String& ReadMSAlgorithm::name(){

return myName;
};

void ReadMSAlgorithm::task(){

status = 0; 
Time starttime;

//if(msid==0)
// msName="3C273XC1.ms";

cout <<" In task() " << endl;  

try{
    MeasurementSet ms(msName, TableLock(TableLock::UserNoReadLocking), Table::Update);
  /*MeasurementSet ms(msName, Table::Old);
	Block<int> sort(4);
	sort[0] = MS::FIELD_ID;
	sort[1] = MS::ARRAY_ID;
	sort[2] = MS::DATA_DESC_ID
	sort[3] = MS::TIME; */
        Block<Int> sort(0);
	Matrix<Int> noselection;


Double interval=10.0;
//        ms.lock();
VisSet vs(ms, sort, noselection, interval);

 if(vs.numberAnt())
  status = 1;
ROVisIter& vi(vs.iter());
VisBuffer vb(vi);

vi.origin(); 

Int nchunk=0; 

    for (vi.originChunks();vi.moreChunks();vi.nextChunk()) {
      for (vi.origin();vi.more();vi++) {
	Int nRow=vb.nRow();
	Int nChan=vb.nChannel();
	for (Int row=0; row<nRow; row++) {
	  for (Int chn=0; chn<nChan; chn++) {
	    if(!vb.flag()(chn,row)) {
	      Float f=vb.frequency()(chn)/C::c;
	      Float u=vb.uvw()(row)(0)*f;
	      Float v=vb.uvw()(row)(1)*f;
	      Float w=vb.uvw()(row)(2)*f;
              Double wt=vb.imagingWeight()(chn,row);
	    }
	  } 
	}
      }

    }
	      /*for (vi.originChunks(); vi.moreChunks(); vi.nextChunk()){
  //  cout << "Chunk No " << nchunk++ << " Nchannel " << "Oh"  << endl; 
  

  }*/
    // ms.unlock();

    cout << "Doing a dummy uvw/weight read" << endl;


}catch (AipsError x) {
    cout <<  "Exceptionally yours: " << x.getMesg() << endl;
 } 

cout << "seconds elapsed since start: " << starttime.age () << endl;
};





} //# NAMESPACE CASA - END

