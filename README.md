# ATM Controller

## Instructions

1. Download source files using `git clone https://github.com/junggeehoon/ATM-controller.git`
2. Navigate to folder you downloaded.
3. To test ATM controller, compile using gcc command.
`g++ -std=c++11 check_atm.cpp atm.cpp bank_system.cpp -o test_atm`
4. Run compiled test code.
`./test_atm`
5. To test Bank System, compile using gcc command.
`g++ -std=c++11 check_bankSystem.cpp bank_system.cpp -o test_bank`
6. Run compiled test code.
`./test_bank`


## Completion Log

Generally, ATM would have some controller to control actual hardware related to the ATM. 
This will includes reading card information from a card reader, and receiving data from keypads and touch screens.

Also, it needs to communicate with the Bank system to retrieve user information. 
Actual data would be stored into Bank's database securly with encryptions. 
ATM would not store actual information and needs to communicate Bank's server to get/store data.

So, I divided project into two parts: 1. ATM controller to interact with user. 2. Bank system to receive request from ATM and send respond.

In real ATM controllers, rather than directly calling methods from bank system, ATM controller would make a API request to a server and server will handle data within a database.

### Bank System
Each account has account number associated with, and balance remaining.

Each card will be stored into map with cardnumber as key and pin number as value.

Each account will be stored into map with accountNumber as key and account as value.


### ATM Controller
ATM will communicate with the bank system (server) to retrieve information such as remaining balance.

It has internal variables to track current card information and account number. (Similiar to token or cookie in frontend that can store information inside the browser.)

When user inserts card and select account, it will save these data temporarily, and send request to bank system. (server)