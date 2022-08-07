//---------------------------------------------------------------------------

#ifndef Cord3DH
#define Cord3DH
#include <vector>
#include "uPonto.h"


//---------------------------------------------------------------------------


class Cord3D : public Ponto{
	public:
		std::vector <Cord3D> cord3d;
		double z;

		Cord3D();
		Cord3D(double nx, double ny ,double nz);

		UnicodeString toString();




};
#endif
