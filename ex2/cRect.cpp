#include "cRect.h"

Point cRect::getPoint(int x) {
	Point temp;
	switch (x)
	{
	case 0:
		cout << "Point #0 value is: (" << this->_lu.getX() << "," << this->_lu.getY() << ") " << endl;
		return this->_lu;
	case 1:
		temp.setX(this->_rd.getX());
		temp.setY(this->_lu.getY());
		cout << "Point #1 value is: (" << this->_rd.getX() << "," << this->_lu.getY() << ") "<<endl;
		return temp;
	case 2:
		cout << "Point #2 value is: (" << this->_rd.getX() << "," << this->_rd.getY() << ") " << endl;
		return this->_rd;

	case 3:
		temp.setX(this->_lu.getX());
		temp.setY(this->_rd.getY());
		cout << "Point #3 value is: (" << this->_lu.getX() << "," << this->_rd.getY() << ") " << endl;
		return temp;
	default:
		cout << "Error: The pion doesn't exsist" << endl;
		break;	
	}
}

void cRect::setPoint(int loc, Point p)
{
	switch (loc)
	{
	case 0:
		this->_lu.setPoint(p.getX(),p.getY());
		this->getPoint(0);
		break;
	case 1:
		this->_rd.setX(p.getX());
		this->_lu.setY(p.getY());
		this->getPoint(1);
		break;
	case 2:
		this->_rd.setPoint(p.getX(), p.getY());
		this->getPoint(2);
		break;
	case 3:
		this->_lu.setX(p.getX());
		this->_rd.setY(p.getY());
		this->getPoint(3);
		break;
	default:
		cout << "Error: The piont doesn't exsist." << endl << "Setting as #0 Point." << endl;
		this->_lu.setPoint(p.getX(), p.getY());
		break;
		break;
	}

}

void cRect::printRect()
{
	void printPoint();
	cout << "The Points Of The Rectangle are: " << endl;
	cout << "#0: (" << this->_lu.getX() << "," << this->_lu.getY() << ") "
		<<	"#1: (" << this->_rd.getX() << "," << this->_lu.getY() << ") "
		<<	"#2: (" << this->_rd.getX() << ", " << this->_rd.getY() << ") "
		<<	"#3: (" << this->_lu.getX() << "," << this->_rd.getY() << ") " 
		<<	endl;
}

int cRect::calcArea()
{
	int vertic, horizen;
	vertic = abs((this->_lu.getY()) - (this->_rd.getY()));
	horizen = abs((this->_rd.getX()) - (this->_lu.getX()));
	cout << "The Rectangle area is:" << vertic * horizen << endl;
	return vertic*horizen;
}
