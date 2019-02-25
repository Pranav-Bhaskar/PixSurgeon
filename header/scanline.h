#include<algorithm>
#include<math.h>
class EdgeTable{
	public:
	double xmin, ymin, ymax;
	double  minv;
	EdgeTable();
	EdgeTable(int, int, int, double);
};

EdgeTable::EdgeTable(int a, int b, int c, double d){
	this->xmin = a;
	this->ymin = b;
	this->ymax = c;
	this->minv = d;
}

EdgeTable::EdgeTable(){}

bool EdgeTable_sort(EdgeTable& a, EdgeTable& b){
	if(a.ymin < b.ymin)
		return true;
	if(a.ymin > b.ymin)
		return false;
	if(a.xmin < b.xmin)
		return true;
	return false;
}

class ScanLine{
	std::vector<EdgeTable> et, aet;
	double darkFactor;
	bool callColourSetter;
	void colourSetter(double, double);
	public:
	ScanLine(std::vector<int>, std::vector<int>, bool, double);
};

void ScanLine::colourSetter(double x, double y){
	double dis_r, dis_g, dis_b;
	dis_b = (pow(1220 - x, 2) + pow(200 - y, 2))/16900;
	dis_g = (pow(1350 - x, 2) + pow(200 - y, 2))/16900;
	dis_r = (pow(1285 - x, 2) + pow(313 - y, 2))/16900;
	glColor3d((1 - dis_r)*darkFactor, (1 - dis_g)*darkFactor, (1 - dis_b)*darkFactor);
}

ScanLine::ScanLine(std::vector<int> x_cord, std::vector<int> y_cord, bool cs = false, double df = 1.0000){
	this->callColourSetter = cs;
	this->darkFactor = df;
	int xmin, ymin, ymax;
	double minv;
	x_cord.push_back(x_cord[0]);
	y_cord.push_back(y_cord[0]);
	for(int i=1;i<x_cord.size();++i){
		if(y_cord[i] == y_cord[i - 1])
			continue;
		if(y_cord[i] >= y_cord[i - 1]){
			ymin = y_cord[i - 1];
			xmin = x_cord[i - 1];
			ymax = y_cord[i];
			if(x_cord[i] == x_cord[i - 1])
				minv = 0.0000;
			else
				minv = (double)(x_cord[i - 1] - x_cord[i])/(y_cord[i - 1] - y_cord[i]);
			et.push_back(EdgeTable(xmin, ymin, ymax, minv));
			continue;
		}
		ymin = y_cord[i];
		xmin = x_cord[i];
		ymax = y_cord[i - 1];
		if(x_cord[i] == x_cord[i - 1])
			minv = 0.0000;
		else
			minv = (double)(x_cord[i - 1] - x_cord[i])/(y_cord[i - 1] - y_cord[i]);
		et.push_back(EdgeTable(xmin, ymin, ymax, minv));
	}
	sort(et.begin(), et.end(), EdgeTable_sort);
	aet.clear();
	int yminima = et[0].ymin - 1;
	for(double y=yminima;(et.size() + aet.size()) != 0;++y){
		while(et.size()){
			if(et[0].ymin == y){
				aet.push_back(et[0]);
				et.erase(et.begin());
			}
			else
				break;
		}
		for(int j=0;j<aet.size();++j)
			if(aet[j].ymax <= y)
				aet.erase(aet.begin() + j--);
		for(int j=0;j<aet.size();j += 2){
			glBegin(GL_POINTS);
			for(double x=aet[j].xmin;x<=aet[j + 1].xmin;++x){
				if(callColourSetter)
					colourSetter(x, y);
				glVertex2d(x, y);
			}
			glEnd();
			aet[j].xmin += aet[j].minv;
			aet[j + 1].xmin += aet[j + 1].minv;
		}
	}
}
