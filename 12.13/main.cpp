#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <vector>

#include "CheckingAccount.h"
#include "SavingsAccount.h"

using namespace std;

int main() {

   vector< Account* > accounts{
      new SavingsAccount{ 100.0, 3.0 },
      new CheckingAccount{ 10.0, 0.5 },
   };

   cout << fixed << setprecision( 2 );

   for ( Account* accountPtr : accounts ) {

      double amount;

      cout << "El balance es $" << accountPtr->getBalance() << " ("
         << typeid( *accountPtr ).name() << ")\nMonto del retiro: $";
      cin >> amount;
      accountPtr->debit( amount );

      cout << "Monto del depósito: $";
      cin >> amount;
      accountPtr->credit( amount );

      SavingsAccount* derivedPtr{ dynamic_cast< SavingsAccount* >( accountPtr ) };

      if ( derivedPtr ) {
         cout << "Sumando los intereses al saldo" << endl;
         derivedPtr->credit( derivedPtr->calculateInterest() );
      }

      if ( accountPtr )
         cout << "Balance actulizado es $" << accountPtr->getBalance() << "\n\n";
   }

   return 0;
}