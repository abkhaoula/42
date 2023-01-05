#include "Account.hpp"
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalAmount = 0;

std::string GetCurrentTime() {
    std::stringstream ss;
    time_t rawtime;
    char buffer[80];
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "%Y%m%d_%H%M%S", timeinfo);
    ss << buffer;
    
    return ss.str();
}

Account::Account( int initial_deposit ) {
    _accountIndex = _nbAccounts;
    _nbAccounts += 1;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    std::cout << "[" << GetCurrentTime() << "] " << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account( void ) {

}

int Account::getNbAccounts( void ) {

    return (0);
}

int	Account::getTotalAmount( void ) {

    return (0);
}

int	Account::getNbDeposits( void ) {

    return (0);
}

int	Account::getNbWithdrawals( void ) {

    return (0);
}

void	Account::displayAccountsInfos( void ) {
    std::cout << "[" << GetCurrentTime() << "] " << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
    std::cout << "[" << GetCurrentTime() << "] " << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits += 1;
    _totalNbDeposits += 1;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    std::cout << "[" << GetCurrentTime() << "] " << "index:" << _accountIndex << ";p_amount:" << _amount;
    if (withdrawal > _amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (0);
    }
    std::cout << ";withdrawal:" << withdrawal;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals += 1;
    _totalNbWithdrawals += 1;
    std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (1);
}

int		Account::checkAmount( void ) const {

    return (0);
}

void	Account::displayStatus( void ) const {
    std::cout << "[" << GetCurrentTime() << "] " << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

Account::~Account( void ) {
    std::cout << "[" << GetCurrentTime() << "] " << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}