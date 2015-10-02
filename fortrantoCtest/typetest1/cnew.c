/* C  code accessing module data */
extern float a[3];
extern int i1, i2;
extern struct {
    int x;
    float y[3];
} mytype;

struct fcallsc{
    int yy[3];
};

void pythagoras (float *c){
//    *c = sqrt(a[0]*a[0] + a[1]*a[1]);
    *c = sqrt(mytype.y[0]*a[0] + a[1]*a[1]);
}


/*
void init(float *bb){
   a[0] = 3;
   a[1] = 4;
   a[2] = 5;
   mytype.y[0] = 0.1;
   mytype.y[1] = 0.2;
   mytype.y[2] = 0.3;

   i1 = 1;
   i2 = 2;
   *bb = 0;
}
*/

void initfo(float *aa){
     *aa = a[0]+a[1]+a[2];
//    examp_mp_mydata.intfo[0] = 6;
//    examp_mp_mydata.intfo[1] = 7;
//    examp_mp_mydata.intfo[2] = 8;
}

void ftoc_(struct fcallsc *v){
	int t;
	t = v->yy[0];
	v->yy[0] = v->yy[1];
	v->yy[1] = t;
	v->yy[2] = -2.*(v->yy[2]);
}
	

/*
int main(){
    examp_mp_i1_ = 1; 
    examp_mp_i2_ = 2;
    FUNC_();
//    float a;
//    printf("EXAMP_N=%i \n",examp_mp_mydata.n);
//    examp_mp_mydata.n = 55;
//    printf("EXAMP_N=%i \n",examp_mp_mydata.n);
//    pythagoras(3.0,4.0, &a);
//    printf("the number is %f\n",a);
    return 0;
}
*/
