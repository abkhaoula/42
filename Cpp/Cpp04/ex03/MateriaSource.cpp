#include "MateriaSource.hpp"


MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!materias[i]) {
            materias[i] = m->clone();
            break;
        }
    }
}
AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (materias[i] && materias[i]->getType() == type) {
            return materias[i]->clone();
        }
    }
    return NULL;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
    {
        if (materias[i])
            delete materias[i];
    }
}