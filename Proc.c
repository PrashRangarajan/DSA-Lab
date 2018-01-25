#include "Proc.h"

void Pil(void){
	int pil;
	printf("Pilani - %p\n", &pil);
	Goa();
	Hyd();

}
void Goa(void){
	int goa;
	printf("Goa - %p\n", &goa);
	Dub();

}
void Hyd(void){
	int hyd;
	printf("Hyd - %p\n", &hyd);
	Goa();

}
void Dub(void){
	int dub;
	printf("Dub - %p\n", &dub);

}
