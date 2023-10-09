// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                            avtH5NimrodFileFormat.h                        //
// ************************************************************************* //

#ifndef AVT_H5Nimrod_FILE_FORMAT_H
#define AVT_H5Nimrod_FILE_FORMAT_H

#include <avtMTSDFileFormat.h>

// Define this symbol BEFORE including hdf5.h to indicate the HDF5 code
// in this file uses version 1.6 of the HDF5 API. This is harmless for
// versions of HDF5 before 1.8 and ensures correct compilation with
// version 1.8 and thereafter. When, and if, the HDF5 code in this file
// is explicitly upgraded to the 1.8 API, this symbol should be removed.
#define H5_USE_16_API
#include <vtk_hdf5.h>
#include "H5utils.h"

#include <vector>
#include <string>


// ****************************************************************************
//  Class: avtH5NimrodFileFormat
//
//  Purpose:
//      Reads in H5Nimrod files as a plugin to VisIt.
//
//  Programmer: cristina -- generated by xml2avt
//  Creation:   Fri Feb 9 08:26:27 PDT 2007
//
// ****************************************************************************

class avtH5NimrodFileFormat : public avtMTSDFileFormat
{
  public:
                       avtH5NimrodFileFormat(const char *);
    virtual           ~avtH5NimrodFileFormat() {;};

    //
    // This is used to return unconvention data -- ranging from material
    // information to information about block connectivity.
    //
    // virtual void      *GetAuxiliaryData(const char *var, const char *type,
    //                                     int timestep, void *args, 
    //                                     DestructorFunction &);
    //

    //
    // If you know the times and cycle numbers, overload this function.
    // Otherwise, VisIt will make up some reasonable ones for you.
    //
    virtual void        GetCycles(std::vector<int> &c);
    virtual void        GetTimes(std::vector<double> &t);
    //

    virtual int            GetNTimesteps(void);

    virtual const char    *GetType(void)   { return "H5Nimrod"; };
    virtual void           FreeUpResources(void); 

    virtual vtkDataSet    *GetMesh(int, const char *);
    virtual vtkDataArray  *GetVar(int, const char *);
    virtual vtkDataArray  *GetVectorVar(int, const char *);

  protected:
    // DATA MEMBERS
    std::string                      fname;
    int                              nsteps;
    std::vector<std::string >        stepnames;
    std::vector<int>                 cycles;
    std::vector<double>              times;
    int                              structured;
    int                              ndims;
    hsize_t                          grid_dims[3];
    std::vector<float>               points;
    int                              nscalarvars;
    std::vector<std::vector<float> > scalarvars;
    std::vector<std::string >        scalarvarnames;
    int                              nvectorvars;
    std::vector<std::vector<float> > vectorvars;
    std::vector<std::string >        vectorvarnames;
    std::vector<int>                 vectorvardims;

    virtual void   PopulateDatabaseMetaData(avtDatabaseMetaData *, int);
};


#endif
