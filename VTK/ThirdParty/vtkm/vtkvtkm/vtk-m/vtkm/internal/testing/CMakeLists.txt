##============================================================================
##  Copyright (c) Kitware, Inc.
##  All rights reserved.
##  See LICENSE.txt for details.
##
##  This software is distributed WITHOUT ANY WARRANTY; without even
##  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
##  PURPOSE.  See the above copyright notice for more information.
##============================================================================

set(unit_tests
  UnitTestArrayPortalBasic.cxx
  UnitTestArrayPortalValueReference.cxx
  UnitTestConfigureFor32.cxx
  UnitTestConfigureFor64.cxx
  #UnitTestFunctionInterface.cxx #FIXME
  UnitTestVariant.cxx
  )
vtkm_unit_tests(SOURCES ${unit_tests})
