//
// Created by Gregory Graham on 17/5/20.
//

#ifndef KCF_MULTISCALE_MULTIFEATURE_GRADIENT_H
#define KCF_MULTISCALE_MULTIFEATURE_GRADIENT_H


void gradMag( float *I, float *M, float *O, int h, int w, int d, bool full );
void gradHist( float *M, float *O, float *H, int h, int w,
               int bin, int nOrients, int softBin, bool full );
void hog( float *M, float *O, float *H, int h, int w, int binSize,
          int nOrients, int softBin, bool full, float clip );
void fhog( float *M, float *O, float *H, int h, int w, int binSize,
           int nOrients, int softBin, float clip );


#endif //KCF_MULTISCALE_MULTIFEATURE_GRADIENT_H
