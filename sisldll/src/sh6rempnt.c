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
 * $Id: sh6rempnt.c,v 1.1 1994-04-21 12:10:42 boh Exp $
 *
 */


#define SH6REMOVEPT

#include "sislP.h"

#if defined(SISLNEEDPROTOTYPES)
void EXPORT_DLL  
      sh6removept(SISLIntpt *pt1,SISLIntpt *pt2,SISLIntpt *ptold,int *jstat)
#else
void EXPORT_DLL  sh6removept(pt1,pt2,ptold,jstat)
   SISLIntpt *pt1;
   SISLIntpt *pt2;
   SISLIntpt *ptold;
   int       *jstat;
#endif   
/*
*********************************************************************
*
*********************************************************************
*
* PURPOSE    : Remove the pt ptold from the list which contains
*              pt1,ptold,pt2 consecutively.
*              Error if there is no such list.
*              The list is repaired afterwards.
*
* INPUT      : pt1      - First point.
*              pt2      - Second point.
*              ptold    - Point to be removed between pt1 and pt2.
*              jstat    - Error flag.
*                         jstat =  0  => successful
*                         jstat = -1  => pt1,ptold,pt2 are not connected
*                         jstat <  0  => error in lower level routine
*
*
* METHOD     : 
*
* CALLS      : s6err      - Gives error message.
*
* REFERENCES :
*
* WRITTEN BY : Michael Floater, SI, Oslo, Norway. June 91.
*
*********************************************************************
*/
{
  int kstat;      /* Local status variables.          */
  
   *jstat = 0;
  


  sh6disconnect(pt1,ptold,&kstat);
  if(kstat < 0) goto error;

  sh6disconnect(pt2,ptold,&kstat);
  if(kstat < 0) goto error;

  sh6connect(pt1,pt2,&kstat);
  if(kstat < 0) goto error;

  
  goto out;
  


/* Error in subfunction. */

error:  *jstat = kstat;
        s6err("sh6removept",*jstat,0);
        goto out;


   out:
      return;
}
