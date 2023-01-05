#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>

class Zombie {
    private:
        std::string name;
    public:
        Zombie(std::string s);
        ~Zombie();
        void announce( void );
};

#endif /* __ZOMBIE_H__ */