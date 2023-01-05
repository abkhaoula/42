#ifndef __HARL_H__
#define __HARL_H__

#include <vector>
#include <map>
#include <string>

class Harl {
    private:
        std::map<std::string, void (Harl::*)()> levels;
        //std::unordered_map<std::string, std::string> levels;
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        Harl();
        ~Harl();
        void complain( std::string level );
};

#endif /* __HARL_H__ */