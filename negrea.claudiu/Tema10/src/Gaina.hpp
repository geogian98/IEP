#include "Pasare.hpp"


class Gaina: public Pasare{
	private:
		static int numar_gaini;
		Gaina();
	public:
		~Gaina();
		static Gaina* creareGaina();
		static int getGaini();
		static void decrementare();
		void zboara();
		std::string sunet();
		void vanzare(Pasare& p);
};
