struct {
	int i1, i2;
	/* Note: "char" might be signed or unsigned.  */
	signed char i3;
	double d1;
	float _Complex c1;
	char str[5];
} mt;

void init(float *a){
	*a = 1;
}
void initt(float *a){
	*a = 1;
	mt.i1 = 1;
}