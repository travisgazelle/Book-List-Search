// Travis Cassell
// Assignment 4
// CS 201_03
// 05 05 2021

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

// Book class declaration
class Book
{
    // Member variables
    private:
        string title;
        string author;
        string publisher;
        string publication_date;
        string category;
    
    // Member functions
    public:
        // 'Set' member functions (mutator)
        void setTitle(string book_name)
            { title = book_name; }
    
        void setAuthor(string author_name)
            { author = author_name; }
    
        void setPublisher(string publisher_name)
            { publisher = publisher_name; }
    
        void setPublishDate(string pub_date)
            { publication_date = pub_date; }
    
        void setCategory(string type)
            { category = type; }
    
        // 'Get' member functions (accessor)
        string getTitle() const
            { return title; }
    
        string getAuthor() const
            { return author; }
    
        string getPublisher() const
            { return publisher; }
    
        string getPublishDate() const
            { return publication_date; }
    
        string getCategory() const
            { return category;}
    
};

// Constant variables for arrays
const int ROWS = 40;
const int COLS = 5;

// Function prototypes
int displayMenu();
string category();

// Main Program
int main()
{
    char again;
    
    // Array of strings 'data'
    string data[][5]=
    {{"A Breath of Snow and Ashes","Diana Gabaldon","Delacorte","10/16/2005","Fiction"},
    {"A Common Life","Jan Karon","Viking","4/29/2001","Fiction"},
    {"A Dance With Dragons","George R. R. Martin","Bantam","7/31/2011","Non Fiction"},
    {"A Day Late and a Dollar Short","Terry McMillan","Viking","2/4/2001","Fiction"},
    {"A Feast For Crows","George R. R. Martin","Bantam","11/27/2005","Fiction"},
    {"A Lion Is In the Streets","Adria Locke Langley","McGraw","7/1/1945","Non Fiction"},
    {"A Man In Full","Tom Wolfe","Farrar","11/22/1998","Fiction"},
    {"A Painted House","John Grisham","Doubleday","2/25/2001","Non Fiction"},
    {"A Perfect Spy","John le Carre","Knopf","5/4/1986","Fiction"},
    {"A Rage to Live","John O'Hara","Random House","9/18/1949","Fiction"},
    {"A Shade of Difference","Allen Drury","Doubleday","10/28/1962","Non Fiction"},
    {"A Thousand Splendid Suns","Khaled Hosseini","Riverhead","6/10/2007","Fiction"},
    {"A Tree Grows In Brooklyn","Betty Smith","Harper","1/2/1944","Fiction"},
    {"A Widow For One Year","John Irving","Random House","6/14/1998","Non Fiction"},
    {"Accident","Danielle Steel","Delacorte","2/27/1994","Fiction"},
    {"Acheron","Sherrilyn Kenyon","St. Martin's","8/24/2008","Non Fiction"},
    {"Across the River and Into the Trees","Ernest Hemingway","Scribner's","10/15/1950","Fiction"},
    {"Advise and Consent","Allen Drury","Doubleday","10/4/1959","Non Fiction"},
    {"Against All Enemies","Tom Clancy","Putnam","7/3/2011","Non Fiction"},
    {"Airframe","Michael Crichton","Knopf","12/29/1996","Fiction"},
    {"Airport","Arthur Hailey","Doubleday","4/7/1968","Non Fiction"},
    {"Alaska","James Michener","Random House","7/3/1988","Fiction"},
    {"Alex Cross's Trial","James Patterson","Brown","9/13/2009","Non Fiction"},
    {"American Assassin","Vince Flynn","Atria","10/31/2010","Fiction"},
    {"An Indecent Obsession","Colleen McCullough","Harper","11/15/1981","Fiction"},
    {"Anansi Boys","Neil Gaiman","Morrow","10/9/2005","Fiction"},
    {"Anathem","Neal Stephenson","William Morrow","9/28/2008","Fiction"},
    {"Anatomy of a Murder","Robert Traver","St. Martin's","3/9/1958","Non Fiction"},
    {"And Now Tomorrow","Rachel Field","MacMillan","8/9/1942","Non Fiction"},
    {"Andersonville","McKinley Kantor","World Publishing","1/1/1956","Fiction"},
    {"Angels Fall","Nora Roberts","Putnam","7/30/2006","Fiction"},
    {"Answered Prayers","Danielle Steel","Delacorte","11/17/2002","Fiction"},
    {"Arch of Triumph","Erich Maria Remarque","Appleton-Century","3/10/1946","Fiction"},
    {"Armageddon","Tim LaHaye","Tyndale","4/27/2003","Fiction"},
    {"At First Sight","Nicholas Sparks","Warner","11/6/2005","Non Fiction"},
    {"Bad Moon Rising","Sherrilyn Kenyon","St. Martin's","8/23/2009","Non Fiction"},
    {"Bag of Bones","Stephen King","Scribner","10/11/1998","Non Fiction"},
    {"Beach Music","Pat Conroy","Talese/Doubleday","7/16/1995","Fiction"},
    {"Before I Say Goodbye","Mary Higgins Clark","Simon & Schuster","5/7/2000","Fiction"},
    {"Best Friends Forever","Jennifer Weiner","Atria","8/2/2009","Fiction"}};
    
    // Array of integers 'yrs' for range search
    int yrs[ROWS]={
    2005, 2001, 2011, 2001, 2005,
    1945, 1998, 2001, 1986, 1949,
    1962, 2007, 1944, 1998, 1994,
    2008, 1950, 1959, 2011, 1996,
    1968, 1988, 2009, 2010, 1981,
    2005, 2008, 1958, 1942, 1956,
    2006, 2002, 1946, 2003, 2005,
    2009, 1998, 1995, 2000, 2009};
    
    // Array of Book objects 'books' created from array of strings 'data'
    Book books[ROWS][COLS];
    string x;
    for(int i = 0; i < ROWS; i++)
    {
        x = data[i][0];
        books[i][0].setTitle(x);
    
        x = data[i][1];
        books[i][1].setAuthor(x);
    
        x = data[i][2];
        books[i][2].setPublisher(x);
    
        x = data[i][3];
        books[i][3].setPublishDate(x);
    
        x = data[i][4];
        books[i][4].setCategory(x);
    }
    
    // Do while loop to allow user to make multiple searches
    do
    {
        // Display the menu from function displayMenu, return choice
        int choice = displayMenu();
        // Variables for switch cases
        int begin, end;
        string author;
        string display;
        bool check1 = false;
        bool check2 = false;
        
        // Process the user input
        switch(choice)
        {
            // Display all books in a year range
            // Prompt user for 2 years (starting year/ending year) display all books published b/w 2 years (inclusive)
            case 1:
                cout << "Enter the beginning year for your search: ";
                cin >> begin;
                cout << "\nEnter the ending year for your search: ";
                cin >> end;
                cout << "\nPublications between " << begin << " and " << end << " include: \n\n";
                
                // Looop through array to find matching years, display any applicable results
                for(int i = begin; i <= end; i++)
                {
                    for(int j = 0; j < ROWS; j++)
                    {
                        if(i == yrs[j])
                        {
                            check1 = true; // If a match is found, bool variable set to true
                            cout << "\"" << books[j][0].getTitle() << "\" (" << i << ")\n" ;
                        }
                    }
                }
                // If bool variable still false, no results found, inform user
                if(check1 == false)
                {
                    cout << "No Results Found";
                }
                cout << endl;
                
                break;
            
            // Search for an author
            // Prompt user for a string, display all books whose author’s name contains that string (regardless of case)
            case 2:
                cin.ignore();
                cout << "Enter the author's name that you would like to search for: ";
                getline(cin, author);
            
                // Convert all characters to lower case for comparison
                for_each(author.begin(), author.end(), []
                (char & c) {
                c = tolower(c);
                });
                author.c_str();
                
                // Search array for matches, display results
                for(int i = 0; i <= ROWS; i++)
                {
                    string tempAuthor = books[i][1].getAuthor();
                    for_each(tempAuthor.begin(), tempAuthor.end(), []
                    (char & c) {
                    c = tolower(c);
                    });
                    tempAuthor.c_str();
                    if(author == tempAuthor)
                    {
                        check1 = true;
                        if(check2 == false)
                        {
                            cout << author << "'s books: \n";
                            check2 = true;
                        }
                        cout << "\"" << books[i][0].getTitle() << "\"\n" ;
                    }
                }
                // If no results found, inform user
                if(check1 == false)
                {
                    cout << "No results found for author: " << author << endl;
                }
                cout << endl;
                
                break;
             
            // Display all books for a category
            // Prompt user for a string, display all books whose category matches user input
            case 3:
                string choice = category();
                // If user input invalid, re-call function
                while(choice == "Error")
                {
                    choice = category();
                }
                // Display results if search is fiction
                if(choice == "Fiction")
                {
                    for(int i = 0; i < ROWS; i++)
                    {
                        string tempCategory = books[i][4].getCategory();
                        if(choice == tempCategory)
                        {
                            check1 = true;
                            if(check2 == false)
                            {
                                cout << "Search results for fiction include: \n";
                                check2 = true;
                            }
                            cout << "\""<< books[i][0].getTitle() << "\"" << endl;
                        }
                    }
                }
                // Display results if search is non-fiction
                else if(choice == "Non Fiction")
                {
                    for(int i = 0; i < ROWS; i++)
                    {
                        string tempCategory = books[i][4].getCategory();
                        if(choice == tempCategory)
                        {
                            check1 = true;
                            if(check2 == false)
                            {
                                cout << "Search results for non-fiction include: \n";
                                check2 = true;
                            }
                            cout << "\""<< books[i][0].getTitle() << "\"" << endl;
                        }
                    }
                }
                break;
        }
        
        // Ask user if they would like to make another search
        cout << "\n\nWould you like to make another search? \n";
        cout << "Enter 'y' for yes or 'q' to quit. \n\n";
        cin >> again;
        
        // If 'q' for quit then quit program
        if(toupper(again) == 'Q')
            return 0;
        
    // If 'y' for yes, repeat loop
    } while(toupper(again) == 'Y');
    
    // If user input is invalid (not 'y' to continue or 'q' to quit):
    cout << "Error, invalid choice. Please restart the program \n";

    return 0;
}

// Function definitions
int displayMenu()
{
    int choice = 0;
    
    // Menu options for user selection
    cout << "\nWelcome to the book search! \n\n";
    cout << "Please select from the following menu: \n";
    cout << "Enter 1 to display all books within a range of years. \n";
    cout << "Enter 2 to search by author name. \n";
    cout << "Enter 3 to display all books by category (fiction / non-fiction) \n\n";
    cin >> choice;
    cout << endl;
    
    // If input invalid, prompt user for re-selection
    while(choice < 1 || choice > 3)
    {
        cout << "Error, please make a valid selection: \n";
        choice = displayMenu();
    }
    
    return choice;
}

string category()
{
    // Get category choice from user, validate input
    char choice;
    cout << "Please enter 'f' for fiction or 'n' for non-fiction: ";
    cin >> choice;
    cout << endl;
    if(toupper(choice) == 'F')
    {
        return "Fiction";
    }
    else if(toupper(choice) == 'N')
    {
        return "Non Fiction";
    }
    else
    {
        cout << "Invalid input, please try again.\n\n";
        return "Error";
    }
}

