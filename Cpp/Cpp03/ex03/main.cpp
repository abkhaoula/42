#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
    DiamondTrap a( "A" );
    DiamondTrap c( ash );
    DiamondTrap b("B");

    a.whoAmI();
    c.whoAmI();
    b = ash;
    b.whoAmI();

    a.attack( "D" );
    a.takeDamage( 10 );
    a.beRepaired( 10 );

    return 0;
}
