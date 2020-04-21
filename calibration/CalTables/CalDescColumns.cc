//# CalDescColumns.cc: Implementation of CalDescColumns.h
//# Copyright (C) 1996,1997,1998,2001,2002,2003
//# Associated Universities, Inc. Washington DC, USA.
//#
//# This library is free software; you can redistribute it and/or modify it
//# under the terms of the GNU Library General Public License as published by
//# the Free Software Foundation; either version 2 of the License, or (at your
//# option) any later version.
//#
//# This library is distributed in the hope that it will be useful, but WITHOUT
//# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
//# License for more details.
//#
//# You should have received a copy of the GNU Library General Public License
//# along with this library; if not, write to the Free Software Foundation,
//# Inc., 675 Massachusetts Ave, Cambridge, MA 02139, USA.
//#
//# Correspondence concerning AIPS++ should be addressed as follows:
//#        Internet email: aips2-request@nrao.edu.
//#        Postal address: AIPS++ Project Office
//#                        National Radio Astronomy Observatory
//#                        520 Edgemont Road
//#                        Charlottesville, VA 22903-2475 USA
//#
//# $Id$
//----------------------------------------------------------------------------

#include <calibration/CalTables/CalDescColumns.h>

namespace casacore { //# NAMESPACE CASACORE - BEGIN

//----------------------------------------------------------------------------

ROCalDescColumns::ROCalDescColumns (const CalTable& calTable) 
{
// Construct from a calibration table
// Input:
//    calTable         const CalTable&                Calibration table
// Output to private data:
//    numSpw_p         ScalarColumn<Int>            No. spw 
//    numChan_p        ArrayColumn<Int>             No. chan
//    numReceptors_p   ScalarColumn<Int>            No. receptors
//    nJones_p         ScalarColumn<Int>            Jones matrix size
//    spwId_p          ArrayColumn<Int>             Spw. id.'s
//    chanFreq_p       ArrayColumn<Double>          Chan. freq.
//    chanFreqMeas_p   ArrayMeasColumn<MFrequency>  Chan. freq. as Measure
//    measFreqRef_p    ScalarColumn<Int>            Freq. measures ref.
//    chanWidth_p      ArrayColumn<Double>          Chan. width
//    chanWidthQuant_p ArrayQuantColumn<Double>     Chan. width as Quanta
//    chanRange_p      ArrayColumn<Int>             Chan. range
//    polznType_p      ArrayColumn<String>          Polzn. type
//    jonesType_p      ScalarColumn<String>         Jones matrix type
//    msName_p         ScalarColumn<String>         MeasurementSet name
//
  // Attach all the column accessors (including required and
  // optional columns)
  attach (calTable, numSpw_p, MSC::NUM_SPW);
  attach (calTable, numChan_p, MSC::NUM_CHAN);
  attach (calTable, numReceptors_p, MSC::NUM_RECEPTORS);
  attach (calTable, nJones_p, MSC::N_JONES);
  attach (calTable, spwId_p, MSC::SPECTRAL_WINDOW_ID);
  attach (calTable, chanFreq_p, MSC::CHAN_FREQ);
  attach (calTable, chanFreqMeas_p, MSC::CHAN_FREQ);
  attach (calTable, measFreqRef_p, MSC::MEAS_FREQ_REF);
  attach (calTable, chanWidth_p, MSC::CHAN_WIDTH);
  attach (calTable, chanWidthQuant_p, MSC::CHAN_WIDTH);
  attach (calTable, chanRange_p, MSC::CHAN_RANGE);
  attach (calTable, polznType_p, MSC::POLARIZATION_TYPE);
  attach (calTable, msName_p, MSC::MS_NAME);

};

//----------------------------------------------------------------------------

void ROCalDescColumns::attach (const CalTable& calTable, 
			       TableColumn& tabCol, 
			       MSCalEnums::colDef colEnum, 
			       const Bool& optional)
{
// Attach a column accessor to the calibration table
// Input:
//    calTable         const CalTable&      Calibration table
//    tabCol           TableColumn&       Table column accessor
//    colEnum          MSCalEnums::colDef   Column enum
//    optional         const Bool&          True if optional column
// Output to private data:
//
  // Convert to column name
  String colName = MSC::fieldName (colEnum);

  // Check if an optional column
  if (optional) {
    if (calDescAsTable(calTable).tableDesc().isColumn(colName)) {
      tabCol.attach (calDescAsTable(calTable), colName);
    };
  } else {
    tabCol.attach (calDescAsTable(calTable), colName);
  };
};

//----------------------------------------------------------------------------

void ROCalDescColumns::attach (const CalTable& calTable, 
			       TableMeasColumn& tabCol, 
			       MSCalEnums::colDef colEnum, 
			       const Bool& optional)
{
// Attach a column accessor to the calibration table
// Input:
//    calTable         const CalTable&      Calibration table
//    tabCol           TableMeasColumn&   Table measures column accessor
//    colEnum          MSCalEnums::colDef   Column enum
//    optional         const Bool&          True if optional column
// Output to private data:
//
  // Convert to column name
  String colName = MSC::fieldName (colEnum);

  // Check if an optional column
  if (optional) {
    if (calDescAsTable(calTable).tableDesc().isColumn(colName)) {
      tabCol.attach (calDescAsTable(calTable), colName);
    };
  } else {
    tabCol.attach (calDescAsTable(calTable), colName);
  };
};

//----------------------------------------------------------------------------

void ROCalDescColumns::attach (const CalTable& calTable, 
			       ArrayQuantColumn<Double>& tabCol, 
			       MSCalEnums::colDef colEnum, 
			       const Bool& optional)
{
// Attach a column accessor to the calibration table
// Input:
//    calTable         const CalTable&              Calibration table
//    tabCol           ArrayQuantColumn<Double>&  Table quanta column
//                                                  accessor
//    colEnum          MSCalEnums::colDef           Column enum
//    optional         const Bool&                  True if optional column
// Output to private data:
//
  // Convert to column name
  String colName = MSC::fieldName (colEnum);

  // Check if an optional column
  if (optional) {
    if (calDescAsTable(calTable).tableDesc().isColumn(colName)) {
      tabCol.attach (calDescAsTable(calTable), colName);
    };
  } else {
    tabCol.attach (calDescAsTable(calTable), colName);
  };
};

//----------------------------------------------------------------------------

CalDescColumns::CalDescColumns (CalTable& calTable) 
{
// Construct from a calibration table
// Input:
// Input:
//    calTable         CalTable&                    Calibration table
// Output to private data:
//    numSpw_p         ScalarColumn<Int>            No. spw 
//    numChan_p        ArrayColumn<Int>             No. chan
//    numReceptors_p   ScalarColumn<Int>            No. receptors
//    nJones_p         ScalarColumn<Int>            Jones matrix size
//    spwId_p          ArrayColumn<Int>             Spw. id.'s
//    chanFreq_p       ArrayColumn<Double>          Chan. freq.
//    chanFreqMeas_p   ArrayMeasColumn<MFrequency>  Chan. freq. as Measure
//    measFreqRef_p    ScalarColumn<Int>            Freq. measures ref.
//    chanWidth_p      ArrayColumn<Double>          Chan. width
//    chanWidthQuant_p ArrayQuantColumn<Double>     Chan. width as Quanta
//    chanRange_p      ArrayColumn<Int>             Chan. range
//    polznType_p      ArrayColumn<String>          Polzn. type
//    jonesType_p      ScalarColumn<String>         Jones matrix type
//    msName_p         ScalarColumn<String>         MeasurementSet name
//
  // Attach all the column accessors (including required and
  // optional columns)
  attach (calTable, numSpw_p, MSC::NUM_SPW);
  attach (calTable, numChan_p, MSC::NUM_CHAN);
  attach (calTable, numReceptors_p, MSC::NUM_RECEPTORS);
  attach (calTable, nJones_p, MSC::N_JONES);
  attach (calTable, spwId_p, MSC::SPECTRAL_WINDOW_ID);
  attach (calTable, chanFreq_p, MSC::CHAN_FREQ);
  attach (calTable, chanFreqMeas_p, MSC::CHAN_FREQ);
  attach (calTable, measFreqRef_p, MSC::MEAS_FREQ_REF);
  attach (calTable, chanWidth_p, MSC::CHAN_WIDTH);
  attach (calTable, chanWidthQuant_p, MSC::CHAN_WIDTH);
  attach (calTable, chanRange_p, MSC::CHAN_RANGE);
  attach (calTable, polznType_p, MSC::POLARIZATION_TYPE);
  attach (calTable, msName_p, MSC::MS_NAME);
};

//----------------------------------------------------------------------------

void CalDescColumns::attach (CalTable& calTable, 
			     TableColumn& tabCol, 
			     MSCalEnums::colDef colEnum, 
			     const Bool& optional)
{
// Attach a column accessor to the calibration table
// Input:
//    calTable         CalTable&            Calibration table
//    tabCol           TableColumn&       Table column accessor
//    colEnum          MSCalEnums::colDef   Column enum
//    optional         const Bool&          True if optional column
// Output to private data:
//
  // Convert to column name
  String colName = MSC::fieldName (colEnum);

  // Check if an optional column
  if (optional) {
    if (calDescAsTable(calTable).tableDesc().isColumn(colName)) {
      tabCol.attach (calDescAsTable(calTable), colName);
    };
  } else {
    tabCol.attach (calDescAsTable(calTable), colName);
  };
};

//----------------------------------------------------------------------------

void CalDescColumns::attach (CalTable& calTable, 
			     TableMeasColumn& tabCol, 
			     MSCalEnums::colDef colEnum, 
			     const Bool& optional)
{
// Attach a column accessor to the calibration table
// Input:
//    calTable         CalTable&            Calibration table
//    tabCol           TableMeasColumn&   Table measures column accessor
//    colEnum          MSCalEnums::colDef   Column enum
//    optional         const Bool&          True if optional column
// Output to private data:
//
  // Convert to column name
  String colName = MSC::fieldName (colEnum);

  // Check if an optional column
  if (optional) {
    if (calDescAsTable(calTable).tableDesc().isColumn(colName)) {
      tabCol.attach (calDescAsTable(calTable), colName);
    };
  } else {
    tabCol.attach (calDescAsTable(calTable), colName);
  };
};

//----------------------------------------------------------------------------

void CalDescColumns::attach (CalTable& calTable, 
			     ArrayQuantColumn<Double>& tabCol, 
			     MSCalEnums::colDef colEnum, 
			     const Bool& optional)
{
// Attach a column accessor to the calibration table
// Input:
//    calTable         CalTable&                    Calibration table
//    tabCol           ArrayQuantColumn<Double>&  Table quanta 
//                                                  column accessor
//    colEnum          MSCalEnums::colDef           Column enum
//    optional         const Bool&                  True if optional column
// Output to private data:
//
  // Convert to column name
  String colName = MSC::fieldName (colEnum);

  // Check if an optional column
  if (optional) {
    if (calDescAsTable(calTable).tableDesc().isColumn(colName)) {
      tabCol.attach (calDescAsTable(calTable), colName);
    };
  } else {
    tabCol.attach (calDescAsTable(calTable), colName);
  };
};

//----------------------------------------------------------------------------



} //# NAMESPACE CASACORE - END

