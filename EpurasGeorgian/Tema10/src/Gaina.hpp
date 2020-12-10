#include "Pasare.hpp"


class Gaina: public Pasare{
	private:
		static int gaini;
		Gaina();
	public:
		~Gaina();
		static Gaina* newGaina();
		static int getGaini();
		static void decrementare();
		void zboara();
		void sunet();
		void vanzare(Pasare& pasare);
};
