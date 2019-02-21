//The poly class is used to draw a polygon.
class Poly: public Mode{
	unsigned int sides;
	int *cord_x;
	int *cord_y;
	public:
	void left_click(int, int);
	void right_click(int, int);
	Poly();
};

Poly::Poly(){
	set_mode(2);
}

void Poly::left_click(int, int){
	
}
