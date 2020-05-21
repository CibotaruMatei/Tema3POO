#pragma once
#include <list>
#include <iostream>

class Animal {
protected:
	std::string nume;
	int greutate;
public:
	Animal() :
		nume(""), greutate(0) {}

	Animal(std::string nume, int greutate) :
		nume(nume), greutate(greutate) {}

	virtual ~Animal() = 0;
	
	Animal(const Animal& a) :
		nume(a.nume), greutate(a.greutate) {}

	const Animal& operator= (const Animal& a) {
		nume = a.nume;
		greutate = a.greutate;
		return *this;
	}

	std::string getNume() { return nume; }
	int getGreutate() { return greutate; }
};

class Vertebrata : public Animal {
public:
	virtual ~Vertebrata() = 0;

	Vertebrata() :
		Animal() {}

	Vertebrata(std::string nume, int greutate) :
		Animal(nume, greutate) {}

	Vertebrata(const Vertebrata& x) :
		Animal(x.nume, x.greutate) {}

	const Vertebrata& operator= (const Vertebrata& x) {
		nume = x.nume;
		greutate = x.greutate;
		return *this;
	}
};

class Nevertebrata : public Animal {
private:
	static const float aparitie;
	static int count;
public:
	~Nevertebrata() { count--; }

	Nevertebrata() :
		Animal() {
		count++;
	}
	
	Nevertebrata(std::string nume, int greutate) :
		Animal(nume, greutate) {
		count++;
	}

	Nevertebrata(const Nevertebrata& x) :
		Animal(x.nume, x.greutate) {
		count++;
	}

	const Nevertebrata& operator= (const Nevertebrata& x) {
		nume = x.nume;
		greutate = x.greutate;
		return *this;
	}

	friend std::istream& operator>> (std::istream& in, Nevertebrata& x) {
		return in >> x.nume >> x.greutate;
	}

	friend std::ostream& operator<< (std::ostream& out, Nevertebrata& x) {
		return out << x.nume << "\n" << x.greutate << "\n";
	}

	static const float getAparitie() { return aparitie; }
	static int getCount() { return count; }
};

class Peste : public Vertebrata {
private:
	static const float aparitie;
	static int count;
	double lungime;
	bool rapitor;
public:
	~Peste() { count--; }

	Peste() :
		Vertebrata(), lungime(0), rapitor(false) {
		count++;
	}

	Peste(std::string nume, int greutate, double lungime, bool rapitor) :
		Vertebrata(nume, greutate), lungime(lungime), rapitor(rapitor) {
		count++;
	}

	Peste(const Peste& x) :
		Vertebrata(x.nume, x.greutate), lungime(x.lungime), rapitor(x.rapitor) {
		count++;
	}

	const Peste& operator= (const Peste& x) {
		nume = x.nume;
		greutate = x.greutate;
		lungime = x.lungime;
		rapitor = x.rapitor;
		return *this;
	}

	friend std::istream& operator>> (std::istream& in, Peste& x) {
		return in >> x.nume >> x.greutate >> x.lungime >> x.rapitor;
	}

	friend std::ostream& operator<< (std::ostream& out, Peste& x) {
		return out << x.nume << "\n" << x.greutate << "\n" << x.lungime << "\n" << x.rapitor << "\n";
	}

	static const float getAparitie() { return aparitie; }
	static int getCount() { return count; }
	double getLungime() { return lungime; }
	bool getRapitor() { return rapitor; }
};

class Pasare : public Vertebrata {
private:
	static const float aparitie;
	static int count;
	bool nocturn;
public:
	~Pasare() { count--; }

	Pasare() :
		Vertebrata(), nocturn(false) {
		count++;
	}

	Pasare(std::string nume, int greutate, bool nocturn) :
		Vertebrata(nume, greutate), nocturn(nocturn) {
		count++;
	}

	Pasare(const Pasare& x) :
		Vertebrata(x.nume, x.greutate), nocturn(x.nocturn) {
		count++;
	}

	const Pasare& operator= (const Pasare& x) {
		nume = x.nume;
		greutate = x.greutate;
		nocturn = x.nocturn;
		return *this;
	}

	friend std::istream& operator>> (std::istream& in, Pasare& x) {
		return in >> x.nume >> x.greutate >> x.nocturn;
	}

	friend std::ostream& operator<< (std::ostream& out, Pasare& x) {
		return out << x.nume << "\n" << x.greutate << "\n" << x.nocturn << "\n";
	}

	static const float getAparitie() { return aparitie; }
	static int getCount() { return count; }
	bool getNocturn() { return nocturn; }
};

class Mamifer : public Vertebrata {
private:
	static const float aparitie;
	static int count;
	int membre;
public:
	~Mamifer() { count--; }

	Mamifer() :
		Vertebrata(), membre(0) {
		count++;
	}

	Mamifer(std::string nume, int greutate, int membre) :
		Vertebrata(nume, greutate), membre(membre) {
		count++;
	}

	Mamifer(const Mamifer& x) :
		Vertebrata(x.nume, x.greutate), membre(x.membre) {
		count++;
	}

	const Mamifer& operator= (const Mamifer& x) {
		nume = x.nume;
		greutate = x.greutate;
		membre = x.membre;
		return *this;
	}

	friend std::istream& operator>> (std::istream& in, Mamifer& x) {
		return in >> x.nume >> x.greutate >> x.membre;
	}

	friend std::ostream& operator<< (std::ostream& out, Mamifer& x) {
		return out << x.nume << "\n" << x.greutate << "\n" << x.membre << "\n";
	}

	static const float getAparitie() { return aparitie; }
	static int getCount() { return count; }
	int getMembre() { return membre; }
};

class Reptila : public Vertebrata {
private:
	static const float aparitie;
	static int count;
public:
	~Reptila() { count--; }

	Reptila() :
		Vertebrata() {
		count++;
	}

	Reptila(std::string nume, int greutate) :
		Vertebrata(nume, greutate) {
		count++;
	}

	Reptila(const Reptila& x) :
		Vertebrata(x.nume, x.greutate) {
		count++;
	}

	const Reptila& operator= (const Reptila& x) {
		nume = x.nume;
		greutate = x.greutate;
		return *this;
	}

	friend std::istream& operator>> (std::istream& in, Reptila& x) {
		return in >> x.nume >> x.greutate;
	}

	friend std::ostream& operator<< (std::ostream& out, Reptila& x) {
		return out << x.nume << "\n" << x.greutate << "\n";
	}

	static const float getAparitie() { return aparitie; }
	static int getCount() { return count; }
};

template <class T>
class AtlasZoologic {
private:
	std::list<T*> atlas;
public:
	AtlasZoologic() {}

	AtlasZoologic(AtlasZoologic& x) :
		atlas(x.atlas) {}

	const AtlasZoologic& operator=(const AtlasZoologic& x) {
		atlas = x.atlas;
	}

	~AtlasZoologic() {
		for (auto& i : atlas) {
			delete i;
		}
		atlas.clear();
	}

	friend std::istream& operator>>(std::istream& in, AtlasZoologic x) {
		int n;
		in >> n;
		for (int i = 0; i < n; i++) {
			try {
				T* animal = new T();
				in >> *animal;
				bool exista = false;
				for (auto& j : x.atlas) {
					if (j->getNume() == animal->getNume()) {
						exista = true;
						break;
					}
				}
				if (exista) throw "Animal deja existent\n";
				else x.atlas.push_back(animal);
			}
			catch (const char* e) {
				std::cout << e;
			}
		}
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, AtlasZoologic x) {
		for (auto& i : x.atlas) {
			out << *i;
		}
		return out;
	}
};

template<>
class AtlasZoologic<Peste> {
private:
	std::list<Peste*> atlas;
public:
	AtlasZoologic() {}

	AtlasZoologic(AtlasZoologic& x) :
		atlas(x.atlas) {}

	const AtlasZoologic& operator=(const AtlasZoologic& x) {
		atlas = x.atlas;
	}

	~AtlasZoologic() {
		for (auto& i : atlas) {
			delete i;
		}
		atlas.clear();
	}

	friend std::istream& operator>>(std::istream& in, AtlasZoologic x) {
		int n;
		in >> n;
		for (int i = 0; i < n; i++) {
			try {
				Peste* animal = new Peste();
				in >> *animal;
				bool exista = false;
				for (auto& j : x.atlas) {
					if (j->getNume() == animal->getNume()) {
						exista = true;
						break;
					}
				}
				if (exista) throw "Animal deja existent\n";
				else x.atlas.push_back(animal);
			}
			catch (const char* e) {
				std::cout << e;
			}
		}
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, AtlasZoologic x) {
		int count = 0;
		for (auto& i : x.atlas) {
			out << *i;
			try {
				if (Peste* p = dynamic_cast<Peste*>(i)) {
					if (p->getLungime() > 1 && p->getRapitor()) count++;
				}
				else throw "Non peste in atlas";
			}
			catch (const char* e) {
				std::cout << e;
			}
		}
		out << "Au fost cititi " << count << " pesti rapitori mai mari de un metru\n";
		return out;
	}
};