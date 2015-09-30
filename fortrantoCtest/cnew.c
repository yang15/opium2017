/* C  code accessing module data */
extern float a[3];
//extern int __declspec(dllimport) examp_mp_i1, __declspec(dllimport) examp_mp_i2;
extern int examp_mp_i1, examp_mp_i2;
extern char examp_mp_line[80];
//extern void usemodule();
extern struct {
    int n;
    char info[30];
} mydata;

void pythagoras (float *c){
    *c = (float) sqrt(a[0]*a[0] + a[1]*a[1]);
}



void init(float *b){
   a[0] = 3;
   a[1] = 4;
   a[2] = 5;
   *b = 0;
}


void initfo(float *aa){
     *aa = a[0]+a[1]+a[2];
//    examp_mp_mydata.intfo[0] = 6;
//    examp_mp_mydata.intfo[1] = 7;
//    examp_mp_mydata.intfo[2] = 8;
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
