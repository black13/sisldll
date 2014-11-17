/*
 * Copyright (C) 1998, 2000-2007, 2010, 2011, 2012, 2013 SINTEF ICT,
 * Applied Mathematics, Norway.
 *
 * Contact information: E-mail: tor.dokken@sintef.no                      
 * SINTEF ICT, Department of Applied Mathematics,                         
 * P.O. Box 124 Blindern,                                                 
 * 0314 Oslo, Norway.                                                     
 *
 * This file is part of SISL.
 *
 * SISL is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version. 
 *
 * SISL is distributed in the hope that it will be useful,        
 * but WITHOUT ANY WARRANTY; without even the implied warranty of         
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License along with SISL. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * In accordance with Section 7(b) of the GNU Affero General Public
 * License, a covered work must retain the producer line in every data
 * file that is created or manipulated using SISL.
 *
 * Other Usage
 * You can be released from the requirements of the license by purchasing
 * a commercial license. Buying such a license is mandatory as soon as you
 * develop commercial activities involving the SISL library without
 * disclosing the source code of your own applications.
 *
 * This file may be used in accordance with the terms contained in a
 * written agreement between you and SINTEF ICT. 
 */

#include "sisl-copyright.h"

/*
 *
 * $Id: s1792.c,v 1.1 1994-04-21 12:10:42 boh Exp $
 *
 */


#define S1792

#include "sislP.h"

#if defined(SISLNEEDPROTOTYPES)
double EXPORT_DLL  
s1792(double et[],int ik,int in)
#else
double EXPORT_DLL  s1792(et,ik,in)
     double et[];
     int    ik;
     int    in;
#endif
/*
*********************************************************************
*
*********************************************************************
*                                                                   
* PURPOSE    : Finding a good subdividing parametric value.
*
*
*
* INPUT      : et[]     - The knot vector.
*              ik       - The order of the spline function.
*              in       - The number of basic spline function.
*
*
*
* OUTPUT     : s1792    - The subdivision value.
*
*
* METHOD     : This function is written to match s1791().
*
*
* REFERENCES :
*
*
* WRITTEN BY : Arne Laksaa, SI, 89-04.
*
*********************************************************************
*/                                     
{
  if (in > ik)
    {
      int kpar = (in + ik)/2;
      
      if (DNEQUAL(et[ik-1],et[kpar]) || DNEQUAL(et[in],et[kpar]))
        return  et[kpar];
    }
  
  return (et[ik-1]+et[in])*(double)0.5;
}
