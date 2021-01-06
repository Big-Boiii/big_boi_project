#ifndef __DATATOOLS_H
#define __DATATOOLS_H

void init_data (int m, 		/* number of rows               */
                int n, 		/* number of columns            */
		double **A 	/* two-dim array of size m-by-n */
               );

double ** malloc_2d(int m, 	/* number of rows               */
                    int n	/* number of columns            */
		   );

void free_2d(double **A);       /* free data allocated by malloc_2d */
#endif
