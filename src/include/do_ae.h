/*
 * Copyright (c) 1998-2012 The OPIUM Group
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include "parameter.h"

int do_ae(param_t *param, char *logfile);
void do_ae_report(FILE *fp);
void startae(param_t *param, int); 
//void relorbae(param_t *param, int, char *); 
void nrelorbae(param_t *param, int, char *); 
char * write_reportae(param_t *param, char *rp,int,double temp_eigen[], double temp_norm[],int);
//void writeAE(param_t *param);
//void dftsolve_(double  *, int * ,double *, int * , int *, int *, int *, int *, int *);
//void hfsolve_(double  *, int * ,double *, int * , int *, int *, int *, int *);
//void dfsolve_(double  *, int * ,double *, int * , int *, int *, int *, int *);
//void atm_(double *, int *, int *);
//void average_(int *, double *, int *);
//void getpcc_(int *);
//void denkcomp_(char *, double[3], int[3] );
static char report[8000];

