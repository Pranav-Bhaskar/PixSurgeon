//The PolyNom class is used to draw a Polygon.
class PolyNom: public Mode{
	unsigned int sides;
	
	int *cord_x;
	int *cord_y;
	public:
	void leftClick(int, int);
	void rightClick(int, int);
	PolyNom();
};

PolyNom::PolyNom(){
	set_mode(2);
}

void PolyNom::rightCick(int, int){
	
}

void PolyNom::left_click(int, int){
	
}
