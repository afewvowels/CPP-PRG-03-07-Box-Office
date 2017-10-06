//
//  main.cpp
//  PRG-3-7-Box-Office
//
//  Created by Keith Smith on 10/6/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  A movie theater only keeps a percentage of the revenue earned from ticket sales. The
//  remainder goes to the movie distributor. Write a program that calculates a theater's
//  gross and net box office profit for a night. The program should ask for the name of the
//  movie, and how many adult and child tickets were sold. (The price of an adult ticket is
//  $10.00 and a child's ticket is $6.00.) It should display a report similar to:
//
//  Movie Name:                         "Wheels of Fury"
//  Adult Tickets Sold:                 382
//  Child Tickets Sold:                 127
//  Gross Box Office Profit:            $4,582.00
//  Net Box Office Profit:              $916.40
//  Amount Paid to Distributor:         $3,665.60

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    string strMovieTitle;
    
    //Declare tickets sold for later user input
    int intTicketsSoldAdult,
        intTicketsSoldChild;
    
    //Initialize fixed ticket cost
    float fltTicketsCostAdult = 10.00f,
          fltTicketsCostChild = 6.00f,
    
          fltTicketsProfitAdult,
          fltTicketsProfitChild,
          fltTicketsProfitTotal,
    
          //Set up gross income for theater
          //Net income for theater
          //And total paid to the distributor
          fltTheaterPayGross,
          fltTheaterPayNet,
          fltTheaterPayDistributor,
    
          // Initialize variable
          fltTheaterPayPercentage = 0.20f;
    
    
    //Get user inputs for title of movie and number of adult and child tickets sold + data validation
    cout << "Please enter the title of the movie: " << endl;
    cin >> strMovieTitle;
    
    cout << "Please enter the total number of adult tickets sold for " << strMovieTitle << ": " << endl;
    cin >> intTicketsSoldAdult;
    while(!cin || intTicketsSoldAdult < 0 || intTicketsSoldAdult > 10000)
    {
        cout << "Please enter a number of adult tickets between 0 and 10,000:\n";
        cin.clear();
        cin.ignore();
        cin >> intTicketsSoldAdult;
    }
    
    cout << "Please enter the total number of child tickets sold for " << strMovieTitle << ": " << endl;
    cin >> intTicketsSoldChild;
    while(!cin || intTicketsSoldChild < 0 || intTicketsSoldChild > 10000)
    {
        cout << "Please enter a number of child tickets between 0 and 10,000:\n";
        cin.clear();
        cin.ignore();
        cin >> intTicketsSoldChild;
    }
    
    //Calculate ticket income for adults, then children,
    //then adds the two for total income
    fltTicketsProfitAdult = fltTicketsCostAdult * intTicketsSoldAdult;
    fltTicketsProfitChild = fltTicketsCostChild * intTicketsSoldChild;
    fltTicketsProfitTotal = fltTicketsProfitAdult + fltTicketsProfitChild;
    
    //Calculate gross, net and distributor pay from inputs
    fltTheaterPayGross = fltTicketsProfitTotal;
    fltTheaterPayNet = fltTheaterPayGross * fltTheaterPayPercentage;
    fltTheaterPayDistributor = fltTheaterPayGross * (1.00f - fltTheaterPayPercentage);
    
    // Configure decimal for dollar amount, two points of precision
    cout << setprecision(2) << fixed << showpoint;
    
    //Output in an ordered format
    cout << left << setw(35) << "Movie Name:"
         << right << setw(25) << strMovieTitle << endl;
    
    cout << left << setw(35) << "Adult Tickets Sold:"
         << right << setw(25) << intTicketsSoldAdult << endl;
    
    cout << left << setw(35) << "Child Tickets Sold:"
         << right << setw(25) << intTicketsSoldChild << endl;
    
    cout << left << setw(35) << "Gross Box Office Profit:"
         << right << setw(24) << "$" << fltTheaterPayGross << endl;
    
    cout << left << setw(35) << "Net Box Office Profit:"
         << right << setw(24) << "$" << fltTheaterPayNet << endl;
    
    cout << left << setw(35) << "Amount Paid to Distributor"
         << right << setw(24) << "$" << fltTheaterPayDistributor << endl;
    
    return 0;
}


